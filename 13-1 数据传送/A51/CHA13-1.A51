/*实验一 数据传送,文件名：cha13-1.A51*/  
       ORG     0000H
	   LJMP 	MAIN
DADDR  EQU     30H     ;片内数据区首地址  
XADDR  EQU     3000H   ;片外数据区首地址
COUNT  EQU     10H     ;传送数据大小，共16个字节
		ORG		0100H
MAIN:   MOV     SP,#60H		;重置堆栈指针        
        LCALL   Init		;调用片内数据区数据初始化子程序
        LCALL   DXMOV
MAIN1: 	MOV     DPTR,#XADDR
        MOV     R2,#COUNT
LOOP1:	MOVX	A,@DPTR
		MOV     P1,A
		INC		DPTR
 		DJNZ	R2,LOOP1
        SJMP	MAIN1
 	
/*********片内数据区初始化子程序***********/            
Init:  	MOV     R0,#DADDR 	;片内数据区首地址送R0
       	MOV     R2,#COUNT	; 传送数据字节个数送R2
		MOV     A,#01H
LOOP2: 	MOV		@R0,A
       	INC     A
       	INC     R0
       	DJNZ    R2,LOOP2
       	RET
/***********片内外数据传送子程序************/
DXMOV:  MOV     R0,#DADDR
        MOV     DPTR,#XADDR
        MOV     R2,#COUNT       
LOOP3:	MOV     A,@R0
        MOVX    @DPTR,A
        INC     R0
        INC     DPTR
        DJNZ    R2,LOOP3
        RET
 		END