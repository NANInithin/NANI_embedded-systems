#include<LPC21xx.h>
void delay(void);
unsigned int i,j,k;
unsigned int ar[11] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88};
int main()
{
	PINSEL0 = 0X00000000;
	IO0DIR = 0X000000FF;
	while(1)
	{
		for(i=0;i<11;i++)
		{
			IO0SET = ar[i];
			delay();
			IO0CLR = ar[i];
		}
	}
}
void delay()
{
	for(j=0;j<1000;j++)
	for(k=0;k<400;k++);
}
