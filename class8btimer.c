#include<lpc214x.h>
#define PLOCK 0x00000400
void PLL(void)
{
		PLL0CON=0x01;
		PLL0CFG=0x24;
		PLL0FEED=0xAA; 
		PLL0FEED=0x55; 
		while(!(PLL0STAT&PLOCK));
		PLL0CON=0x03; 
		PLL0FEED=0xAA; 
		PLL0FEED=0x55;
		VPBDIV=0x01;
}
void delay()
{
		T1CTCR = 0X0000;
		T1PR  = 59;
		T1MR0=1000;
		T1MCR=0x00000004;
		T1TCR=0X02;
		T1TCR=0X01; 
		while(T1TC!=T1MR0); 
		T1TCR=0x00;
		T1TC=0x00;
}
int main(void)
{
		IO1DIR=0x00FF0000;
		PLL(); 
		while(1)
		{
			IO1SET=0x00FF0000;
			delay();
			IO1CLR=0x00FF0000; 
			delay();
		}
}
