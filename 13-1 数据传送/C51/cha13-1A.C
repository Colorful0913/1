/*实验一，数据传送程序，文件名：CHA13-1A.c*/
#include<reg52.h>
#include<intrins.h>
#include <absacc.h>
#define uint unsigned int
#define uchar unsigned char 
uchar idata dADDR[16] _at_ 0x30;
uchar xdata xADDR[16] _at_ 0x3000;
uchar  xdata   *waddr;
uchar  data    count;
uchar i,n;
/************片内数据区初始化***************/
void Init(uchar lenth)
{
        uchar i;
        for(i=0;i<lenth;i++)
        {
                dADDR[i]=i+1;
        }
}
/******方法一：使用指针,片内数据传到片外*******/
void movxx(uchar *s_addr,uchar *d_addr, uchar lenth)
{
	uchar i;
		for(i=0;i<lenth;i++){
			d_addr[i]=s_addr[i];
		}
}
/************主函数****************/
void main()
{
       uint i;
	   uchar data *xram1;
	   uchar xdata *xram2;
	   xram1=0x30;xram2=0x3000; 
	   Init(16);
	   movxx(xram1,xram2,16);
 	   
	   while(1) 
	   {     
       for(i=0;i<17;i++)
	   {P1=	xADDR[i]; } 
	   }
}