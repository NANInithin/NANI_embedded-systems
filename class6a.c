#include<lpc214x.h>
#include<stdio.h>
unsigned char RxD()
{
 while(!(U0LSR & 0x01));
 return(U0RBR);
}
void TxD (unsigned char c)
{
 while(!(U0LSR & 0x20));
 U0THR = c;
}
int main()
{
 unsigned char ch;
 PINSEL0 = 5;
 U0LCR = 0x83;
 U0DLM = 0x00;
 U0DLL = 97;
 U0LCR = 0x03;
 while(1)
 {
 ch=RxD();
 TxD (ch);
 }
}

