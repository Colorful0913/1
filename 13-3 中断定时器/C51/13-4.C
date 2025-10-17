/*ÎÄ¼þÃû13-3.C*/
#include<reg52.h>
sbit  p10=P1^0;
sbit  p11=P1^1;
void  main()
{
	p11=0;
 	SP=0X60;
  	TMOD=0x20;
 	TL1=0x06;
  	TH1=0x06;
  	ET1=0;
    TR1=0;
	IT0=1;
	EX0=1;
  	EA=1;
	while(1){
 	;
 	}
}  
void    int0int(void) interrupt      0
{
        TR1=1;
		ET1=1;
	//	p10=0;
		
		p11=0;
	
}
void    timer1int(void) interrupt     3
{
       p10=!p10;
}
