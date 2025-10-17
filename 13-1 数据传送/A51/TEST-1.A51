;/*实验一 数据传送,文件名：cha13-1.A51*/  
       ORG     0000H
NADDR  EQU     30H     ;片内数据区首地址  
WADDR  EQU     3000H   ;片外数据区首地址
COUNT  EQU     20H     ;传送数据大小，共32个字节

MAIN:  			MOV	SP,#60H
				MOV             R0,#NADDR
               MOV             R2,#COUNT
Init:  MOV     A,#01H
LOOP1: MOV     @R0,A
               INC     A
               INC     R0
               DJNZ    R2,LOOP1

               MOV     R0,#NADDR
               MOV     DPTR,#WADDR
               MOV     R2,#COUNT
NWSEND:        MOV     A,@R0
       MOVX    @DPTR,A
       INC     R0
       INC     DPTR
       DJNZ    R2,NWSEND		    

MAIN1: MOV     DPTR,#WADDR
               MOV     R2,#COUNT
               MOV     R0,#NADDR
	                   
DISPLAY:       MOVX    A,@DPTR
                       MOV     P1,A
                       LCALL   DELAY
					    LCALL   DELAY
						 LCALL   DELAY
						  LCALL   DELAY 
						  LCALL   DELAY
                       INC     DPTR
                       DJNZ    R2,DISPLAY
                       MOV     P1,#0FFH	               
               SJMP MAIN1

/**********延时子程序************/
DELAY:	SETB	0D4H
		MOV		R3,#0FFH
DL11:		 MOV      R5,#0FFH
DL7:  MOV    R7,#0FFH
DL:   MOV    R6,#0FFH
DL6:  DJNZ   R6,DL6
      DJNZ   R7,DL
         DJNZ   R5,DL7
		 DJNZ	R3,DL11
		 CLR	0D4H
      RET           
         END

