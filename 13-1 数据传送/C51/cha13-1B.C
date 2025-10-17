/*实验一，数据传送程序，文件名：CHA13-1.c*/
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
/******方法二：使用C51运行库中预定义宏进行片内数据传到片外********/
void    dxmov(uchar s_addr, uint d_addr,uchar lenth)
{
	uchar i;
		for(i=0;i<lenth;i++)
        {		
			XBYTE[d_addr+i]=DBYTE[s_addr+i];
        }
} 
/************主函数****************/
void main()
{
       uint i; 
	   Init(16);
 	   dxmov(0x30,0x3000,16);
	   while(1) 
	   {     
       for(i=1;i<17;i++)
	   {P1=	xADDR[i]; } 
	   }
}