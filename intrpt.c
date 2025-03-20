
/*
External interrupt 0 (INT0)          0
Timer interrupt 0    (TFO)	     1
External interrupt 1 (INT1)          2
Timer interrupt 1    (TF1) 	     3
Serial COM interrupt (RI and TI)      4	
*/


#include<reg51.h>
#define DATA P2
unsigned int a,b,c,d,k;
sbit rs=P3^5;
sbit rw=P3^6;
sbit en=P3^7;
sbit into1=P3^0;
sbit into2=P3^1;

unsigned char intr[]={"INTERRUPT RUN"};
unsigned char cod[]={"MAIN CODE RUN"};

void delay(unsigned int x){

 unsigned int i,j;
	
	for(i=0;i<x;i++)
		for(j=0;j<1275;j++);

}

void lcddata(unsigned char dat) // Function for LCD data.
{
	DATA=dat;
	rs=1;
	rw=0;
	en=1;
	delay(10);
	en=0;	
}

void lcdcmd(unsigned char comnd) // Function for LCD Command.
{
DATA=comnd;
	rs=0;
	rw=0;
	en=1;
	delay(10);
	en=0;
}

void first_intrpt() interrupt 0{
	int y;
	lcdcmd(0x01);		
	delay(10);
	lcdcmd(0x80);
	delay(10);
	for (k = 0; intr[k] != '\0'; k++)
    {
        lcddata(intr[k]);
    }
		for(y=0;y<10;y++){
		delay(10);
		into1=1;
		into2=0;
		delay(100);
		into1=0;
		into2=1;
		delay(100);
		}
		into1=0;
		into2=0;
	lcdcmd(0x01);		
	delay(10);
	lcdcmd(0x80);
	delay(10);
		for (a = 0; cod[a] != '\0'; a++)
    {
        lcddata(cod[a]);
    }
		
}

int main(){

	IE=0x81;
	into1=0;
	into2=0;
	lcdcmd(0x38);
	delay(10);
	lcdcmd(0x0E);  
	delay(10);
	lcdcmd(0x01);		
	delay(10);
	lcdcmd(0x80);
	delay(10);
	for (a = 0; cod[a] != '\0'; a++)
    {
        lcddata(cod[a]);
    }
	while(1){
	
		P1=0xff;
		delay(100);
		P1=0x00;	
		delay(100);
	}
}

