#include <reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit key = P3^4;
sbit p1 = P1^0;
uchar tt;

void main ()
{
    EA = 1;
	  ET1 = 1;
    EX0=1;
	  TCON=0x01;
//		IT0=1;
    TMOD = 0x10;
	TH1 = (65536-500)/256;
	TL1 = (65536-500)%256;
    p1 = 1;
 while (1);
}
void exter0 () interrupt 0
{
    //EX0 = 0;
    //ET1 = 1;
    TR1 = 1;
	  p1 = 0;
		//EX0 = 1;
    
}
void timer1 () interrupt 3   // ¶¨Ê±Æ÷1ÖÐ¶Ï
{
	TH1=(65536-500)/256;
	TL1=(65536-500)%256;
        p1 = ~p1;
}
