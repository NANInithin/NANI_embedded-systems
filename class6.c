#include<lpc214x.h>
#include<stdio.h>
void TxD(unsigned char c)
{
	while(!(U0LSR & 0x20));
	U0THR = c;
}
int main()
{
	int i;
	unsigned char ch[5] = "hi...";
	PINSEL0 = 5;
	U0LCR=0x83;
	U0DLM=0x00;
	U0DLL=97;
	U0LCR=0x03;
	for(i=0;ch[i]!=0;i++)
	{
		TxD(ch[i]);
	}
}
