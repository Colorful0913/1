/*实验一，数据传送程序，文件名：CHA13-1.c*/
#include<reg52.h>
#include<intrins.h>
#include <absacc.h>
#define uint unsigned int
#define uchar unsigned char
//#define XBYTE ((unsigned char volatile *)0x20000L)
//uchar  idata   naddr[16]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0f,0x10};
uchar idata NADDR[16] _at_ 0x50;
uchar  xdata   *waddr;
uchar  data    count;
uchar i,n;
/***********ms延时程序******************/
void delay(uint z)//延时函数
{
       uint i;
       for(i=0;i<z;i++);
}
/************片内数据区初始化***************/
void Init(uchar lenth)
{
        uchar i;
        for(i=1;i<lenth;i++)
        {
                NADDR[i]=i;
        }
}
/*****片内数据传到片外2000H开始连续32单元中********/
void    nwsend(uchar s_addr, uint d_addr,uchar lenth)
{
	uchar i;
		for(i=0;i<lenth;i++)
        {		
			XBYTE[d_addr+i]=NADDR[s_addr+i];
        }
}
/******方法一：使用指针****************/
void movxx(uchar *s_addr,uchar *d_addr, uchar lenth)
{
	uchar i;
		for(i=0;i<lenth;i++){
			d_addr[i]=s_addr[i];
		}
}
/*****方法二：使用C51运行库中预定义宏********/
void movxd(uchar s_addr,uchar d_addr, uchar lenth)
{
	uchar i;
		for(i=0;i<lenth;i++){
			DBYTE[d_addr+i]=XBYTE[s_addr+i];
			P1=	DBYTE[d_addr+i];
		        delay(20000);
		}
}

/*****方法三：使用C51扩展关键字 _at_ *
void movcd(uchar lenth)
{
	uchar i;
  code uchar codedata[16] _at_ 0x800;
  idata uchar idatadata[16] _at_ 0x80;
		for(i=0;i<lenth;i++){
			idatadata[i]=codedata[i];
		}
}


/*********LED显示子程序**************
void Display(uchar *s_addr,uchar i)
{
       
       {
//               	P1=i;
			    P1=	s_addr[i];
                delay(20000);
       }
}
/************主函数****************/
void main()
{
       uint i=0;
//	   uchar data *xram1;
//	   uchar xdata *xram2;
//	   xram1=0x50;xram2=0x2000;

	 
//	   movcd(16);
	   while(1) 
	   { 
	   i=0;    
       Init(32);
//	   movxx(xram1,xram2,16);	
	    movxd(0x50,0x3000,16);
//       nwsend(0x50,0x2000,16);
	   do
	   {
//       Display(0x2000,i);
//	   delay(2000);
	   i++;
	   }while (i<17);
	   }
}