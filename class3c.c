#include<lpc21xx.h>
#include<stdio.h>
void delay()
{
	int i;
	for(i=0;i<=0xefff;i++);
}
int main()
{
	int i;
	while(1)
	{
		for(i=31;i>0;i--)
		{
			IO1SET=0x00000001<<i;
			delay();
			IO1CLR=0x00000001<<i;
			delay();
		}
	}
}
