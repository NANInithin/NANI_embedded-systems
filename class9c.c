#include<lpc214x.h>
#include<stdio.h>
void delay()
{
	int i;
	for(i=0;i<1000000;i++);
}
int main(void)
{
	int i;
	PINSEL1=0x80000;
	IODIR0=0x80000;
	while(1)
	{
		for(i=0;i<0x3FF;i++)
		DACR=(i<<6);
		for(i=0x3FF;i>=0;i--)
		DACR=(i<<6);
	}
}
