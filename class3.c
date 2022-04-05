#include<lpc21xx.h>
#include<stdio.h>
void delay()
{
	int i;
	for(i=0;i<=0xefff;i++);
}
int main()
{
	PINSEL1=0x00000000;
	IO1DIR=0x00ff0000;
	while(1)
	{
		IO1SET=0x00ff0000;
		delay();
		IO1CLR=0x00ff0000;
		delay();
	}
}
