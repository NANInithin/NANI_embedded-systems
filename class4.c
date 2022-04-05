#include<lpc21xx.h>
#include<stdio.h>
void delay()
{
	int i;
	for(i=0;i<=0xeffff;i++);
}
int main()
{
	PINSEL0=0x00000000;
	IO0DIR=0x00000400;
	while(1)
	{
		IO0SET=0x00000400;
		delay();
		IO0CLR=0x00000400;
		delay();
	}
}
