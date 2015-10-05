# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
Addr	Code	Symbol	Mnemon	Operand
0000	890000		SUBX	0x0000,d
0003	900000		ANDA	0x0000,i
0006	910000		ANDA	0x0000,d
000F	A00000		ORA	0x0000,i
0012	A10000		ORA	0x0000,d
001B	B00000		CPA	0x0000,i
001E	B10000		CPA	0x0000,d
0027	C00000		LDA	0x0000,i
002A	C10000		LDA	0x0000,d
0033	D00000		LDBYTEA	0x0000,i
0036	D10000		LDBYTEA	0x0000,d
003F	E00000		STA	0x0000,i
0042	E10000		STA	0x0000,d
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x0001
Instruction Register (IR)	0x890000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x0004
Instruction Register (IR)	0x900000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x0007
Instruction Register (IR)	0x910000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x000A
Instruction Register (IR)	0x980000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x000D
Instruction Register (IR)	0x990000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x0010
Instruction Register (IR)	0xA00000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0001
Index register (X)		0x0000
Program counter (PC)		0x0013
Instruction Register (IR)	0xA10000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0001
Index register (X)		0x0000
Program counter (PC)		0x0016
Instruction Register (IR)	0xA80000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0001
Index register (X)		0x0000
Program counter (PC)		0x0019
Instruction Register (IR)	0xA90000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0001
Index register (X)		0x0000
Program counter (PC)		0x001C
Instruction Register (IR)	0xB00000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0001
Index register (X)		0x0000
Program counter (PC)		0x001F
Instruction Register (IR)	0xB10000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0001
Index register (X)		0x0000
Program counter (PC)		0x0022
Instruction Register (IR)	0xB80000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0001
Index register (X)		0x0000
Program counter (PC)		0x0025
Instruction Register (IR)	0xB90000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0001
Index register (X)		0x0000
Program counter (PC)		0x0028
Instruction Register (IR)	0xC00000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0001
Index register (X)		0x0000
Program counter (PC)		0x002B
Instruction Register (IR)	0xC10000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x002E
Instruction Register (IR)	0xC80000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x0031
Instruction Register (IR)	0xC90000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x0034
Instruction Register (IR)	0xD00000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x0037
Instruction Register (IR)	0xD10000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x003A
Instruction Register (IR)	0xD80000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x003D
Instruction Register (IR)	0xD90000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x0040
Instruction Register (IR)	0xE00000
----------------------------------------
Status bits (NZVC)		0 0 0 0
Accumulator (A)			0x0000
Index register (X)		0x0000
Program counter (PC)		0x0043
Instruction Register (IR)	0xE10000
----------------------------------------
EOF
pass;
