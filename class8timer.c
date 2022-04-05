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
	void delay(int a)
	{
		T0CTCR = 0X00;
		T0TCR = 0X00;
		T0PR = 59999;
		T0TCR = 0X02;
		T0TCR = 0X01;
		while(T0TC<a);
		T0TCR = 0X00;
		T0TC = 0X00;
	}
int main(void)
{
	IO0DIR = 0X0000FFFF;
	PLL();
	while(1)
	{
		IO0SET = 0X0000FFFF;
		delay(1000);
		IO0CLR = 0X0000FFFF;
		delay(1000);
	}
}

