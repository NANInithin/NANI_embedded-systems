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
IO1DIR=0xffffffff;
while(1)
{
	IO1SET=0x00f00000;
	delay();
	IO1CLR=0x00f00000;
	delay();
	IO1SET=0x000f0000;
	delay();
	IO1CLR=0x000f0000;
	delay();
}
}