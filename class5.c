#include<lpc214x.H>
#define PLOCK 0x00000400
void led_on()
{
	IO0SET=0x0000FFFF;
}
void led_off()
{
	IO0CLR=0x0000FFFF;
}
void delay(int count)
{
	int i;
	for(i=0;i<count;i++);
}
int main(void)
{
	PLL0CON=0x01;
	PLL0CFG=0x24;
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	while(!(PLL0STAT & PLOCK));
	PLL0CON=0x03;
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	PINSEL0=0x00000000;
	IO0DIR=0x0000FFFF;
	while(1)
	{
		led_on();
		delay(12000000);
		led_off();
		delay(12000000);
	}
}
