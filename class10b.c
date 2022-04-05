#include<LPC214x.h>
int main(void)
{
	PINSEL0 = 0X20008;
	PWMPCR = 0X1800;
	PWMMR0 = 25000;
	PWMMR3 = 7500;
	PWMMR4 = 15000;
	while(1)
	{
		PWMMCR = 0X02;
		PWMLER = 0X06;
		PWMTCR = 0X0A;
		PWMTCR = 0X09;
	}
}
