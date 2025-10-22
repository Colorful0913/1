;先通过串口调试工具即PC发送字符给单片机，单片机接收数据后再发给PC， 
;再次通过串口调试工具观察传送结果，即实现了PC到单片机的收发
;由于本地仿真，需要安装虚拟串口，PC用COM1口，MCU的COMPIM设为COM2，波特率均为9600
		org 	0000h
		ajmp 	main
		org 	0023h
		ajmp 	aa
		org 	0030h
main:   mov 	scon,#50h	;设置单片机串口方式1接收
		mov 	tmod,#20h 		;定时器T1工作于定时方式2
		mov 	pcon,#00h		;串口波特率SMOD=0,Fosc=11.0592M
		mov 	th1,#0fdh   	;定时器T1初值=FDH，产生9600波特率
		mov 	tl1,#0fdh
		setb 	ea
		setb 	es	
		setb 	tr1
		CLR  	F0			;F0=0接收
		mov 	a,sbuf		;启动串口接收数据
		sjmp 	$			;等待串口中断
			
aa:		JB 		F0,TRS		;响应串口中断， 若F0=0为接收，若F0=1转发送
		SETB 	F0			;进入接收处理，将F0置1，为进入发送做准备
		clr 	ri			;进入中断即接收一个数据后，清除RI标志
		MOV 	scon,#40H  	;设置单片机串口方式1发送
		MOV 	sbuf,a	    ;启动串口发送数据
		RETI				
		
TRS:	CLR 	TI		    ;进入中断即发送一个数据后，清除TI标志
		CLR 	F0			;进入发送处理，将F0清0，为进入接收做准备
		MOV 	scon,#50H 	;设置单片机串口方式1接收
		mov 	a,sbuf  	;启动串口接收数据	
		RETI	
   		end