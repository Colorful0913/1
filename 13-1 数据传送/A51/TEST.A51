;/*实验一 数据传送,文件名：cha13-1.A51*/  
       ORG     0000H
NADDR  EQU     30H     ;片内数据区首地址  
WADDR  EQU     3000H   ;片外数据区首地址
COUNT  EQU     10H     ;传送数据大小，共32个字节

MAIN:           MOV     SP,#60H
                MOV             R0,#NADDR
               MOV             R2,#COUNT
             LCALL   Init
               MOV     R0,#NADDR
              MOV     DPTR,#WADDR
               MOV     R2,#COUNT
               LCALL   NWSEND
MAIN1: MOV     DPTR,#WADDR
               MOV     R2,#COUNT
               MOV     R0,#NADDR
               LCALL   DISPLAY
               SJMP MAIN1
;/*********片内数据区初始化子程序***********/            
Init:  MOV     A,#01H
LOOP1: MOV     @R0,A
               INC     A
               INC     R0
               DJNZ    R2,LOOP1
             RET
;/***********片内外数据传送子程序************
NWSEND:        MOV     A,@R0
       MOVX    @DPTR,A
       INC     R0
       INC     DPTR
       DJNZ    R2,NWSEND
       RET

                
;/**************LED显示子程序*****************/
               MOV             R0,#NADDR
               MOV             R2,#COUNT
                
DISPLAY:       MOVX    A,@DPTR
                       MOV     P1,A
                       LCALL   DELAY
                       INC     DPTR
                       DJNZ    R2,DISPLAY
                       MOV     P1,#0FFH
                       LCALL DELAY
                     RET
;/**********延时子程序************/
DELAY: MOV      R5,#0F4H
DL7:  MOV    R7,#0FFH
DL:   MOV    R6,#0FFH
DL6:  DJNZ   R6,DL6
      DJNZ   R7,DL
         DJNZ   R5,DL7
      RET           
         END

