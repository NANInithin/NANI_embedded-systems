	AREA Program, CODE, READonly
MAIN
	LDR R1,VALUE1
	LDR R2,VALUE2
	ADD R3,R1,R2
	STR R3,RESULT
	SWI &11
VALUE1
	DCD &ABCDC123
	ALIGN
VALUE2
	DCD &111102AA
	ALIGN
RESULT
	DCD 0
	END