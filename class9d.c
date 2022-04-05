#include <lpc214x.h>
#include <stdio.h>
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
T0CTCR=0X0000;
T0PR=599999;
T0MR0=1;
T0MCR=0x00000004;
T0TCR=0X02;
T0TCR=0X01;
while(T0TC!=T0MR0);
T0TCR=0x00;
T0TC=0x00;
}
int main(void)
{
int i;
PINSEL1=0x80000;
IODIR0=0x80000;
PLL();
while(1)
{
for(i=0;i<50;i++)
{
DACR=((i*10)<<6);
delay();
}
for(i=50;i>0;i--)
{
DACR=((i*10)<<6);
delay();
}
}
}
