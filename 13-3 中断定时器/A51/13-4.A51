	ORG    0000H
       	LJMP MAIN
      	ORG 	0003H
       	LJMP  INT0P
       	ORG   001BH
       	LJMP   T1P
     	ORG   0100H
MAIN:   MOV  SP,#60H
        MOV  TMOD,#20H
        MOV  TL1,#06H
        MOV   TH1,#06H
        SETB  ET1
        SETB  IT0
	SETB  EX0
        SETB  EA
HERE:   SJMP  HERE
INT0P:  SETB  TR1
	CLR	  P1.0
        RETI
T1P:   	CPL  P1.0
 	RETI
        END
