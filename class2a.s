	AREA Program, CODE, READONLY
MAIN
	LDR R1, Value1
	LDR R2, Value2
	CMP R1, R2
	BHI Done
	MOV R3, R2
	B Store
Done
	MOV R3, R1
Store
	STR R3, Result
	SWI &11
Value1
	DCD &12345678
Value2
	DCD &87654321
Result
	DCD 0
	END
	