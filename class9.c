#include<lpc214x.h>
#include<stdio.h>
void delay()
{
	int i;
	for(i=0;i<1000000;i++);
}
int main(void)
{
	PINSEL1=0x80000;
	IODIR0=0x80000;
	while(1)
	{
		DACR=(0x3FF<<6);
		delay();
		DACR=(0x0000<<6);
		delay();
	}
}
