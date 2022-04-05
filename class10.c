#include<LPC214x.h>
int main(void)
{
	PINSEL0 = 0X8002;
	PWMPCR = 0X600;
	PWMMR0 = 150000;
	PWMMR1 = 75000;
	PWMMR2 = 120000;
	while(1)
	{
		PWMMCR = 0X02;
		PWMLER = 0X06;
		PWMTCR = 0X0A;
		PWMTCR = 0X09;
	}
}
