#include<LPC214X.H>
int main(void)
{
	int x;
	PINSEL0 = 0X8002;
	PWMPCR = 0X600;
	PWMMR0 = 150000;
	while(1)
	{
		PWMMR1 = x;
		if(x>=PWMMR0)
			x = 0;
		x = x+1;
		PWMMCR = 0X02;
		PWMLER = 0X06;
		PWMTCR = 0X0A;
		PWMTCR = 0X09;
	}
}
