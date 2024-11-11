# Interrupt_configuration
<br>
In this project  I use  Level-Trigger to generate the interrupt signal and in this project I program for the highest  priority interrupt External hardware interrupt 0 (INT0). I connect a switch on port P3.2( pin no.-12).And a lcd connect to the port 2 ,which is parallelly  communicate with microcontroller .
<br>
The Interrupt is the method to indicate the microcontroller by sending an interrupt signal. After receiving an interrupt, the microcontroller interrupts whatever it is doing and serves the device. The program associated with the interrupt is called the interrupt service routine (ISR). When an interrupt is invoked, the microcontroller runs the interrupt service routine. For every interrupt, there is a fixed location set aside to hold the addresses of ISRs.
<br>
Six interrupts in the 8051:
Interrupts Name                                      ROM Location (Hex)    Pin           Flag Clearing
<br>
 Reset						                                        0000              9	               AUTO
 <br>
 External hardware interrupt 0 (INT0)                     0003              P3.2(12)	       AUTO
 <br>
Timer 0 interrupt (TF0)                                   000B				                       AUTO
<br>
External hardware interrupt 1 (INTI)                      0013              P3.3(13)	       AUTO
<br>
Timer 1 interrupt (TF1) 			                            001B			                         AUTO
<br>
Serial COM interrupt (RI and TI)                          0023				                  Programmer Clear it.

<br>
All interrupts are disable, meaning that known will be responded to by the microcontroller if they are activated. The Interrupt must be enabled by software in order for microcontroller to respond to them there is a Special function Register called “IE” that is responsible for enabling and disabling the interrupts. 

         EA         --          ET2     ES          ET1      EX1    ET0       EX0
         <br>
					                      IE Register
  <br>                         
The 8051 has two external hardware interrupts PIN 12 (P3.2) and Pin 13 (P3.3), designated as INT0 and INT1.
<br>
External interrupts are mainly two types :
1)Level-Triggered Interrupt 
2)Edge -Triggered Interrupt
<br>
Interrupt priority:-
Interrupt                                     Name           Numbers used by 8051 C
<br>
External interrupt 0                          (INT0)                   0
<br>
Timer interrupt 0                              (TFO)		               1
<br>
External interrupt 1                          (INT1)                   2
<br>
Timer interrupt 1                              (TF1) 	                 3
<br>
Serial COM interrupt                      (RI and TI)                  4	

