#include<lpc214x.h>
#define PLOCK 0x00000400
void PLL(void)
{
	PLL0CON = 0X01;
	PLL0CFG = 0X24;
	PLL0FEED = 0XAA;
	PLL0FEED = 0X55;
	while(!(PLL0STAT & PLOCK));
	PLL0CON = 0X03;
	PLL0FEED = 0XAA;
	PLL0FEED = 0X55;
	VPBDIV =0X01;
}
	void delay()
	{
		T1CTCR = 0X0000;
		T1PR = 59999;
		T1MR0 = 5000;
		T1MCR = 0X00000004;
		T1TCR = 0X02;
		T1TCR = 0X01;
		while(T1TC!=T1MR0);
		T1TCR = 0X00;
		T1TC = 0X00;
	}
int main(void)
{
	IO0DIR = 0X00FF0000;
	PLL();
	while(1)
	{
		IO0SET = 0X00FF0000;
		delay();
		IO0CLR = 0X00FF0000;
		delay();
	}
}
