#include<lpc214x.H>
#define PLOCK 0x00000400
void led_on()
{
	IO0SET=0x00FFFF00;
}
void led_off()
{
	IO0CLR=0x00FFFF00;
}
void delay(int count)
{
	int i;
	for(i=0;i<count;i++);
}
int main(void)
{
	PLL0CON=0x01;
	PLL0CFG=0x20;
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	while(!(PLL0STAT & PLOCK));
	PLL0CON=0x03;
	PLL0FEED=0xAA;
	PLL0FEED=0x55;
	PINSEL0=0x00000000;
	IO0DIR=0x00FFFF00;
	while(1)
	{
		led_on();
		delay(12000000);
		led_off();
		delay(12000000);
	}
}