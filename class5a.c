#include<lpc214x.h>
#define PLOCK 0x00000400
void led_on()
{
IO1SET=0xFFFF0000;
}
void led_off()
{
IO1CLR=0xFFFF0000;
}
void delay(int count)
{
int i;
for(i=0;i<count;i++);
}
int main(void)
{
PLL0CON=0x01;
PLL0CFG=0X24;
PLL0FEED=0XAA;
PLL0FEED=0X55;
while(!(PLL0STAT & PLOCK));
PLL0CON=0x03;
PLL0FEED=0XAA;
PLL0FEED=0X55;
VPBDIV=0x01;
PINSEL0=0x0000000;
IO1DIR=0xFFFF0000;
while(1)
{
led_on();
delay(12000000);
led_off();
delay(12000000);
}
}