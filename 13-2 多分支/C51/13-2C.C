/*实验二，分支程序，文件名：13-2.c*/
#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uint numb;
uchar k,font;
/***********ms延时程序******************/
void delay(uint z)//延时函数
{
	uint i;
   	for(i=0;i<z;i++);
}
/*********显示子程序**************/
void Display(){
	P0=font;
   	delay(2000000);
}

/*********分支子程序**************/
void font_numb(numb){
 	switch(numb){
	case 0:{font=0xc0;Display();break;}
	case 1:{font=0xf9;Display();break;}
	case 2:{font=0xa4;Display();break;}
	case 3:{font=0xb0;Display();break;}
	default:{return;break;}
	}
}

/************主函数****************/
void main(){	
	while(1)  {	
		for(numb=0;numb<4;numb++){
			font_numb(numb);
		}
	}
}