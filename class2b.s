	AREA Program, CODE, READONLY
MAIN
	LDR R0, = Table
	EOR R1,R1,R1
	LDR R2, Length
	CMP R2,#0
	BEQ Done
Loop
	LDR R3,[R0]
	CMP R3,R1
	BCC Looptest
	MOV R1,R3
Looptest
	ADD R0,R0,#4
	SUBS R2,R2,#0x1
	BNE Loop
Done
	STR R1,Result
	SWI &11
Table
	DCW &A152
	ALIGN
	DCW &7F61
	ALIGN
	DCW &F123
	ALIGN
	DCW &8000
	ALIGN
TableEnd
Length
	DCW (TableEnd-Table)/4
	ALIGN
Result
	DCD 0
	END
