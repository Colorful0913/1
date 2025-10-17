/*实验一，数据传送程序，文件名：CHA13-1B.c*/
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
        for(i=0;i<lenth;i++)
        {
                dADDR[i]=i+1;
        }
}
/******方法三：使用C51扩展关键字 _at_*******/
/*******uchar idata dADDR[16] _at_ 0x30;******/
/*******uchar xdata xADDR[16] _at_ 0x3000;*******/
void movcd(uchar lenth)
{
	uchar i;
 		for(i=0;i<lenth;i++){
		xADDR[i]=dADDR[i];
		}
}
/************主函数****************/
void main()
{
       uint i; 
	   Init(4);
 	   movcd(4);;
	   while(1) 
	   {     
       for(i=0;i<5;i++)
	   {P1=	xADDR[i];delay(20000);P1=0xff; } 
	   }
}