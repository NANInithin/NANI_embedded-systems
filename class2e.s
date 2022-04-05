	TTL Ch6Ex1
CR EQU 0x0D
	AREA Program,CODE,READONLY
Main
	ADR R0,Data1
	EOR R1,R1,R1
Loop
	LDRB R2,[R0],#1
	CMP R2,#CR
	BEQ Done
	ADD R1,R1,#1
	B Loop
Done
	STR R1,CharCount
	SWI &11
Data1
	DCB "Namasthe",CR
	ALIGN
CharCount
	DCD 0
	ALIGN
	END
