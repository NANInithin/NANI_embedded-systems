#include<lpc21xx.h>
#include<stdio.h>
int main()
{
	IO0DIR=0x00000400;
	IO1DIR=0x00;
	while(1)
	{
		if((IO1PIN&(0x00010000))==0)
			IO0SET=0x00000400;
		else
			IO0CLR=0x00000400;
	}
}
