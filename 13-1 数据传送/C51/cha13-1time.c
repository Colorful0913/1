/*ʵ��һ�����ݴ��ͳ����ļ�����CHA13-1B.c*/
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
/***********ms��ʱ����******************/
void delay(uint z)//��ʱ����
{
       uint i;
       for(i=0;i<z;i++);
}
/************Ƭ����������ʼ��***************/
void Init(uchar lenth)
{
        uchar i;
        for(i=0;i<lenth;i++)
        {
                dADDR[i]=i+1;
        }
}
/******��������ʹ��C51��չ�ؼ��� _at_*******/
/*******uchar idata dADDR[16] _at_ 0x30;******/
/*******uchar xdata xADDR[16] _at_ 0x3000;*******/
void movcd(uchar lenth)
{
	uchar i;
 		for(i=0;i<lenth;i++){
		xADDR[i]=dADDR[i];
		}
}
/************������****************/
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