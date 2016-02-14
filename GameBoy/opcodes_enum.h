
enum opcodes {
	NOP            = 0x00,//NOP cycles: 1  4 registers: - - - -
	LD_BC_d16      = 0x01,//LD BC,d16 cycles: 3  12 registers: - - - -
	LD_pBCp_A      = 0x02,//LD (BC),A cycles: 1  8 registers: - - - -
	INC_BC         = 0x03,//INC BC cycles: 1  8 registers: - - - -
	INC_B          = 0x04,//INC B cycles: 1  4 registers: Z 0 H -
	DEC_B          = 0x05,//DEC B cycles: 1  4 registers: Z 1 H -
	LD_B_d8        = 0x06,//LD B,d8 cycles: 2  8 registers: - - - -
	RLCA           = 0x07,//RLCA cycles: 1  4 registers: 0 0 0 C
	LD_pa16p_SP    = 0x08,//LD (a16),SP cycles: 3  20 registers: - - - -
	ADD_HL_BC      = 0x09,//ADD HL,BC cycles: 1  8 registers: - 0 H C
	LD_A_pBCp      = 0x0A,//LD A,(BC) cycles: 1  8 registers: - - - -
	DEC_BC         = 0x0B,//DEC BC cycles: 1  8 registers: - - - -
	INC_C          = 0x0C,//INC C cycles: 1  4 registers: Z 0 H -
	DEC_C          = 0x0D,//DEC C cycles: 1  4 registers: Z 1 H -
	LD_C_d8        = 0x0E,//LD C,d8 cycles: 2  8 registers: - - - -
	RRCA           = 0x0F,//RRCA cycles: 1  4 registers: 0 0 0 C
	STOP_0         = 0x10,//STOP 0 cycles: 2  4 registers: - - - -
	LD_DE_d16      = 0x11,//LD DE,d16 cycles: 3  12 registers: - - - -
	LD_pDEp_A      = 0x12,//LD (DE),A cycles: 1  8 registers: - - - -
	INC_DE         = 0x13,//INC DE cycles: 1  8 registers: - - - -
	INC_D          = 0x14,//INC D cycles: 1  4 registers: Z 0 H -
	DEC_D          = 0x15,//DEC D cycles: 1  4 registers: Z 1 H -
	LD_D_d8        = 0x16,//LD D,d8 cycles: 2  8 registers: - - - -
	RLA            = 0x17,//RLA cycles: 1  4 registers: 0 0 0 C
	JR_r8          = 0x18,//JR r8 cycles: 2  12 registers: - - - -
	ADD_HL_DE      = 0x19,//ADD HL,DE cycles: 1  8 registers: - 0 H C
	LD_A_pDEp      = 0x1A,//LD A,(DE) cycles: 1  8 registers: - - - -
	DEC_DE         = 0x1B,//DEC DE cycles: 1  8 registers: - - - -
	INC_E          = 0x1C,//INC E cycles: 1  4 registers: Z 0 H -
	DEC_E          = 0x1D,//DEC E cycles: 1  4 registers: Z 1 H -
	LD_E_d8        = 0x1E,//LD E,d8 cycles: 2  8 registers: - - - -
	RRA            = 0x1F,//RRA cycles: 1  4 registers: 0 0 0 C
	JR_NZ_r8       = 0x20,//JR NZ,r8 cycles: 2  12/8 registers: - - - -
	LD_HL_d16      = 0x21,//LD HL,d16 cycles: 3  12 registers: - - - -
	LD_pHLplusp_A  = 0x22,//LD (HL+),A cycles: 1  8 registers: - - - -
	INC_HL         = 0x23,//INC HL cycles: 1  8 registers: - - - -
	INC_H          = 0x24,//INC H cycles: 1  4 registers: Z 0 H -
	DEC_H          = 0x25,//DEC H cycles: 1  4 registers: Z 1 H -
	LD_H_d8        = 0x26,//LD H,d8 cycles: 2  8 registers: - - - -
	DAA            = 0x27,//DAA cycles: 1  4 registers: Z - 0 C
	JR_Z_r8        = 0x28,//JR Z,r8 cycles: 2  12/8 registers: - - - -
	ADD_HL_HL      = 0x29,//ADD HL,HL cycles: 1  8 registers: - 0 H C
	LD_A_pHLplusp  = 0x2A,//LD A,(HL+) cycles: 1  8 registers: - - - -
	DEC_HL         = 0x2B,//DEC HL cycles: 1  8 registers: - - - -
	INC_L          = 0x2C,//INC L cycles: 1  4 registers: Z 0 H -
	DEC_L          = 0x2D,//DEC L cycles: 1  4 registers: Z 1 H -
	LD_L_d8        = 0x2E,//LD L,d8 cycles: 2  8 registers: - - - -
	CPL            = 0x2F,//CPL cycles: 1  4 registers: - 1 1 -
	JR_NC_r8       = 0x30,//JR NC,r8 cycles: 2  12/8 registers: - - - -
	LD_SP_d16      = 0x31,//LD SP,d16 cycles: 3  12 registers: - - - -
	LD_pHLminp_A   = 0x32,//LD (HL-),A cycles: 1  8 registers: - - - -
	INC_SP         = 0x33,//INC SP cycles: 1  8 registers: - - - -
	INC_pHLp       = 0x34,//INC (HL) cycles: 1  12 registers: Z 0 H -
	DEC_pHLp       = 0x35,//DEC (HL) cycles: 1  12 registers: Z 1 H -
	LD_pHLp_d8     = 0x36,//LD (HL),d8 cycles: 2  12 registers: - - - -
	SCF            = 0x37,//SCF cycles: 1  4 registers: - 0 0 1
	JR_C_r8        = 0x38,//JR C,r8 cycles: 2  12/8 registers: - - - -
	ADD_HL_SP      = 0x39,//ADD HL,SP cycles: 1  8 registers: - 0 H C
	LD_A_pHLminp   = 0x3A,//LD A,(HL-) cycles: 1  8 registers: - - - -
	DEC_SP         = 0x3B,//DEC SP cycles: 1  8 registers: - - - -
	INC_A          = 0x3C,//INC A cycles: 1  4 registers: Z 0 H -
	DEC_A          = 0x3D,//DEC A cycles: 1  4 registers: Z 1 H -
	LD_A_d8        = 0x3E,//LD A,d8 cycles: 2  8 registers: - - - -
	CCF            = 0x3F,//CCF cycles: 1  4 registers: - 0 0 C
	LD_B_B         = 0x40,//LD B,B cycles: 1  4 registers: - - - -
	LD_B_C         = 0x41,//LD B,C cycles: 1  4 registers: - - - -
	LD_B_D         = 0x42,//LD B,D cycles: 1  4 registers: - - - -
	LD_B_E         = 0x43,//LD B,E cycles: 1  4 registers: - - - -
	LD_B_H         = 0x44,//LD B,H cycles: 1  4 registers: - - - -
	LD_B_L         = 0x45,//LD B,L cycles: 1  4 registers: - - - -
	LD_B_pHLp      = 0x46,//LD B,(HL) cycles: 1  8 registers: - - - -
	LD_B_A         = 0x47,//LD B,A cycles: 1  4 registers: - - - -
	LD_C_B         = 0x48,//LD C,B cycles: 1  4 registers: - - - -
	LD_C_C         = 0x49,//LD C,C cycles: 1  4 registers: - - - -
	LD_C_D         = 0x4A,//LD C,D cycles: 1  4 registers: - - - -
	LD_C_E         = 0x4B,//LD C,E cycles: 1  4 registers: - - - -
	LD_C_H         = 0x4C,//LD C,H cycles: 1  4 registers: - - - -
	LD_C_L         = 0x4D,//LD C,L cycles: 1  4 registers: - - - -
	LD_C_pHLp      = 0x4E,//LD C,(HL) cycles: 1  8 registers: - - - -
	LD_C_A         = 0x4F,//LD C,A cycles: 1  4 registers: - - - -
	LD_D_B         = 0x50,//LD D,B cycles: 1  4 registers: - - - -
	LD_D_C         = 0x51,//LD D,C cycles: 1  4 registers: - - - -
	LD_D_D         = 0x52,//LD D,D cycles: 1  4 registers: - - - -
	LD_D_E         = 0x53,//LD D,E cycles: 1  4 registers: - - - -
	LD_D_H         = 0x54,//LD D,H cycles: 1  4 registers: - - - -
	LD_D_L         = 0x55,//LD D,L cycles: 1  4 registers: - - - -
	LD_D_pHLp      = 0x56,//LD D,(HL) cycles: 1  8 registers: - - - -
	LD_D_A         = 0x57,//LD D,A cycles: 1  4 registers: - - - -
	LD_E_B         = 0x58,//LD E,B cycles: 1  4 registers: - - - -
	LD_E_C         = 0x59,//LD E,C cycles: 1  4 registers: - - - -
	LD_E_D         = 0x5A,//LD E,D cycles: 1  4 registers: - - - -
	LD_E_E         = 0x5B,//LD E,E cycles: 1  4 registers: - - - -
	LD_E_H         = 0x5C,//LD E,H cycles: 1  4 registers: - - - -
	LD_E_L         = 0x5D,//LD E,L cycles: 1  4 registers: - - - -
	LD_E_pHLp      = 0x5E,//LD E,(HL) cycles: 1  8 registers: - - - -
	LD_E_A         = 0x5F,//LD E,A cycles: 1  4 registers: - - - -
	LD_H_B         = 0x60,//LD H,B cycles: 1  4 registers: - - - -
	LD_H_C         = 0x61,//LD H,C cycles: 1  4 registers: - - - -
	LD_H_D         = 0x62,//LD H,D cycles: 1  4 registers: - - - -
	LD_H_E         = 0x63,//LD H,E cycles: 1  4 registers: - - - -
	LD_H_H         = 0x64,//LD H,H cycles: 1  4 registers: - - - -
	LD_H_L         = 0x65,//LD H,L cycles: 1  4 registers: - - - -
	LD_H_pHLp      = 0x66,//LD H,(HL) cycles: 1  8 registers: - - - -
	LD_H_A         = 0x67,//LD H,A cycles: 1  4 registers: - - - -
	LD_L_B         = 0x68,//LD L,B cycles: 1  4 registers: - - - -
	LD_L_C         = 0x69,//LD L,C cycles: 1  4 registers: - - - -
	LD_L_D         = 0x6A,//LD L,D cycles: 1  4 registers: - - - -
	LD_L_E         = 0x6B,//LD L,E cycles: 1  4 registers: - - - -
	LD_L_H         = 0x6C,//LD L,H cycles: 1  4 registers: - - - -
	LD_L_L         = 0x6D,//LD L,L cycles: 1  4 registers: - - - -
	LD_L_pHLp      = 0x6E,//LD L,(HL) cycles: 1  8 registers: - - - -
	LD_L_A         = 0x6F,//LD L,A cycles: 1  4 registers: - - - -
	LD_pHLp_B      = 0x70,//LD (HL),B cycles: 1  8 registers: - - - -
	LD_pHLp_C      = 0x71,//LD (HL),C cycles: 1  8 registers: - - - -
	LD_pHLp_D      = 0x72,//LD (HL),D cycles: 1  8 registers: - - - -
	LD_pHLp_E      = 0x73,//LD (HL),E cycles: 1  8 registers: - - - -
	LD_pHLp_H      = 0x74,//LD (HL),H cycles: 1  8 registers: - - - -
	LD_pHLp_L      = 0x75,//LD (HL),L cycles: 1  8 registers: - - - -
	HALT           = 0x76,//HALT cycles: 1  4 registers: - - - -
	LD_pHLp_A      = 0x77,//LD (HL),A cycles: 1  8 registers: - - - -
	LD_A_B         = 0x78,//LD A,B cycles: 1  4 registers: - - - -
	LD_A_C         = 0x79,//LD A,C cycles: 1  4 registers: - - - -
	LD_A_D         = 0x7A,//LD A,D cycles: 1  4 registers: - - - -
	LD_A_E         = 0x7B,//LD A,E cycles: 1  4 registers: - - - -
	LD_A_H         = 0x7C,//LD A,H cycles: 1  4 registers: - - - -
	LD_A_L         = 0x7D,//LD A,L cycles: 1  4 registers: - - - -
	LD_A_pHLp      = 0x7E,//LD A,(HL) cycles: 1  8 registers: - - - -
	LD_A_A         = 0x7F,//LD A,A cycles: 1  4 registers: - - - -
	ADD_A_B        = 0x80,//ADD A,B cycles: 1  4 registers: Z 0 H C
	ADD_A_C        = 0x81,//ADD A,C cycles: 1  4 registers: Z 0 H C
	ADD_A_D        = 0x82,//ADD A,D cycles: 1  4 registers: Z 0 H C
	ADD_A_E        = 0x83,//ADD A,E cycles: 1  4 registers: Z 0 H C
	ADD_A_H        = 0x84,//ADD A,H cycles: 1  4 registers: Z 0 H C
	ADD_A_L        = 0x85,//ADD A,L cycles: 1  4 registers: Z 0 H C
	ADD_A_pHLp     = 0x86,//ADD A,(HL) cycles: 1  8 registers: Z 0 H C
	ADD_A_A        = 0x87,//ADD A,A cycles: 1  4 registers: Z 0 H C
	ADC_A_B        = 0x88,//ADC A,B cycles: 1  4 registers: Z 0 H C
	ADC_A_C        = 0x89,//ADC A,C cycles: 1  4 registers: Z 0 H C
	ADC_A_D        = 0x8A,//ADC A,D cycles: 1  4 registers: Z 0 H C
	ADC_A_E        = 0x8B,//ADC A,E cycles: 1  4 registers: Z 0 H C
	ADC_A_H        = 0x8C,//ADC A,H cycles: 1  4 registers: Z 0 H C
	ADC_A_L        = 0x8D,//ADC A,L cycles: 1  4 registers: Z 0 H C
	ADC_A_pHLp     = 0x8E,//ADC A,(HL) cycles: 1  8 registers: Z 0 H C
	ADC_A_A        = 0x8F,//ADC A,A cycles: 1  4 registers: Z 0 H C
	SUB_B          = 0x90,//SUB B cycles: 1  4 registers: Z 1 H C
	SUB_C          = 0x91,//SUB C cycles: 1  4 registers: Z 1 H C
	SUB_D          = 0x92,//SUB D cycles: 1  4 registers: Z 1 H C
	SUB_E          = 0x93,//SUB E cycles: 1  4 registers: Z 1 H C
	SUB_H          = 0x94,//SUB H cycles: 1  4 registers: Z 1 H C
	SUB_L          = 0x95,//SUB L cycles: 1  4 registers: Z 1 H C
	SUB_pHLp       = 0x96,//SUB (HL) cycles: 1  8 registers: Z 1 H C
	SUB_A          = 0x97,//SUB A cycles: 1  4 registers: Z 1 H C
	SBC_A_B        = 0x98,//SBC A,B cycles: 1  4 registers: Z 1 H C
	SBC_A_C        = 0x99,//SBC A,C cycles: 1  4 registers: Z 1 H C
	SBC_A_D        = 0x9A,//SBC A,D cycles: 1  4 registers: Z 1 H C
	SBC_A_E        = 0x9B,//SBC A,E cycles: 1  4 registers: Z 1 H C
	SBC_A_H        = 0x9C,//SBC A,H cycles: 1  4 registers: Z 1 H C
	SBC_A_L        = 0x9D,//SBC A,L cycles: 1  4 registers: Z 1 H C
	SBC_A_pHLp     = 0x9E,//SBC A,(HL) cycles: 1  8 registers: Z 1 H C
	SBC_A_A        = 0x9F,//SBC A,A cycles: 1  4 registers: Z 1 H C
	AND_B          = 0xA0,//AND B cycles: 1  4 registers: Z 0 1 0
	AND_C          = 0xA1,//AND C cycles: 1  4 registers: Z 0 1 0
	AND_D          = 0xA2,//AND D cycles: 1  4 registers: Z 0 1 0
	AND_E          = 0xA3,//AND E cycles: 1  4 registers: Z 0 1 0
	AND_H          = 0xA4,//AND H cycles: 1  4 registers: Z 0 1 0
	AND_L          = 0xA5,//AND L cycles: 1  4 registers: Z 0 1 0
	AND_pHLp       = 0xA6,//AND (HL) cycles: 1  8 registers: Z 0 1 0
	AND_A          = 0xA7,//AND A cycles: 1  4 registers: Z 0 1 0
	XOR_B          = 0xA8,//XOR B cycles: 1  4 registers: Z 0 0 0
	XOR_C          = 0xA9,//XOR C cycles: 1  4 registers: Z 0 0 0
	XOR_D          = 0xAA,//XOR D cycles: 1  4 registers: Z 0 0 0
	XOR_E          = 0xAB,//XOR E cycles: 1  4 registers: Z 0 0 0
	XOR_H          = 0xAC,//XOR H cycles: 1  4 registers: Z 0 0 0
	XOR_L          = 0xAD,//XOR L cycles: 1  4 registers: Z 0 0 0
	XOR_pHLp       = 0xAE,//XOR (HL) cycles: 1  8 registers: Z 0 0 0
	XOR_A          = 0xAF,//XOR A cycles: 1  4 registers: Z 0 0 0
	OR_B           = 0xB0,//OR B cycles: 1  4 registers: Z 0 0 0
	OR_C           = 0xB1,//OR C cycles: 1  4 registers: Z 0 0 0
	OR_D           = 0xB2,//OR D cycles: 1  4 registers: Z 0 0 0
	OR_E           = 0xB3,//OR E cycles: 1  4 registers: Z 0 0 0
	OR_H           = 0xB4,//OR H cycles: 1  4 registers: Z 0 0 0
	OR_L           = 0xB5,//OR L cycles: 1  4 registers: Z 0 0 0
	OR_pHLp        = 0xB6,//OR (HL) cycles: 1  8 registers: Z 0 0 0
	OR_A           = 0xB7,//OR A cycles: 1  4 registers: Z 0 0 0
	CP_B           = 0xB8,//CP B cycles: 1  4 registers: Z 1 H C
	CP_C           = 0xB9,//CP C cycles: 1  4 registers: Z 1 H C
	CP_D           = 0xBA,//CP D cycles: 1  4 registers: Z 1 H C
	CP_E           = 0xBB,//CP E cycles: 1  4 registers: Z 1 H C
	CP_H           = 0xBC,//CP H cycles: 1  4 registers: Z 1 H C
	CP_L           = 0xBD,//CP L cycles: 1  4 registers: Z 1 H C
	CP_pHLp        = 0xBE,//CP (HL) cycles: 1  8 registers: Z 1 H C
	CP_A           = 0xBF,//CP A cycles: 1  4 registers: Z 1 H C
	RET_NZ         = 0xC0,//RET NZ cycles: 1  20/8 registers: - - - -
	POP_BC         = 0xC1,//POP BC cycles: 1  12 registers: - - - -
	JP_NZ_a16      = 0xC2,//JP NZ,a16 cycles: 3  16/12 registers: - - - -
	JP_a16         = 0xC3,//JP a16 cycles: 3  16 registers: - - - -
	CALL_NZ_a16    = 0xC4,//CALL NZ,a16 cycles: 3  24/12 registers: - - - -
	PUSH_BC        = 0xC5,//PUSH BC cycles: 1  16 registers: - - - -
	ADD_A_d8       = 0xC6,//ADD A,d8 cycles: 2  8 registers: Z 0 H C
	RST_00H        = 0xC7,//RST 00H cycles: 1  16 registers: - - - -
	RET_Z          = 0xC8,//RET Z cycles: 1  20/8 registers: - - - -
	RET            = 0xC9,//RET cycles: 1  16 registers: - - - -
	JP_Z_a16       = 0xCA,//JP Z,a16 cycles: 3  16/12 registers: - - - -
	PREFIX_CB      = 0xCB,//PREFIX CB cycles: 1  4 registers: - - - -
	CALL_Z_a16     = 0xCC,//CALL Z,a16 cycles: 3  24/12 registers: - - - -
	CALL_a16       = 0xCD,//CALL a16 cycles: 3  24 registers: - - - -
	ADC_A_d8       = 0xCE,//ADC A,d8 cycles: 2  8 registers: Z 0 H C
	RST_08H        = 0xCF,//RST 08H cycles: 1  16 registers: - - - -
	RET_NC         = 0xD0,//RET NC cycles: 1  20/8 registers: - - - -
	POP_DE         = 0xD1,//POP DE cycles: 1  12 registers: - - - -
	JP_NC_a16      = 0xD2,//JP NC,a16 cycles: 3  16/12 registers: - - - -
	CALL_NC_a16    = 0xD4,//CALL NC,a16 cycles: 3  24/12 registers: - - - -
	PUSH_DE        = 0xD5,//PUSH DE cycles: 1  16 registers: - - - -
	SUB_d8         = 0xD6,//SUB d8 cycles: 2  8 registers: Z 1 H C
	RST_10H        = 0xD7,//RST 10H cycles: 1  16 registers: - - - -
	RET_C          = 0xD8,//RET C cycles: 1  20/8 registers: - - - -
	RETI           = 0xD9,//RETI cycles: 1  16 registers: - - - -
	JP_C_a16       = 0xDA,//JP C,a16 cycles: 3  16/12 registers: - - - -
	CALL_C_a16     = 0xDC,//CALL C,a16 cycles: 3  24/12 registers: - - - -
	SBC_A_d8       = 0xDE,//SBC A,d8 cycles: 2  8 registers: Z 1 H C
	RST_18H        = 0xDF,//RST 18H cycles: 1  16 registers: - - - -
	LDH_pa8p_A     = 0xE0,//LDH (a8),A cycles: 2  12 registers: - - - -
	POP_HL         = 0xE1,//POP HL cycles: 1  12 registers: - - - -
	LD_pCp_A       = 0xE2,//LD (C),A cycles: 2  8 registers: - - - -
	PUSH_HL        = 0xE5,//PUSH HL cycles: 1  16 registers: - - - -
	AND_d8         = 0xE6,//AND d8 cycles: 2  8 registers: Z 0 1 0
	RST_20H        = 0xE7,//RST 20H cycles: 1  16 registers: - - - -
	ADD_SP_r8      = 0xE8,//ADD SP,r8 cycles: 2  16 registers: 0 0 H C
	JP_pHLp        = 0xE9,//JP (HL) cycles: 1  4 registers: - - - -
	LD_pa16p_A     = 0xEA,//LD (a16),A cycles: 3  16 registers: - - - -
	XOR_d8         = 0xEE,//XOR d8 cycles: 2  8 registers: Z 0 0 0
	RST_28H        = 0xEF,//RST 28H cycles: 1  16 registers: - - - -
	LDH_A_pa8p     = 0xF0,//LDH A,(a8) cycles: 2  12 registers: - - - -
	POP_AF         = 0xF1,//POP AF cycles: 1  12 registers: Z N H C
	LD_A_pCp       = 0xF2,//LD A,(C) cycles: 2  8 registers: - - - -
	DI             = 0xF3,//DI cycles: 1  4 registers: - - - -
	PUSH_AF        = 0xF5,//PUSH AF cycles: 1  16 registers: - - - -
	OR_d8          = 0xF6,//OR d8 cycles: 2  8 registers: Z 0 0 0
	RST_30H        = 0xF7,//RST 30H cycles: 1  16 registers: - - - -
	LD_HL_SPplusr8 = 0xF8,//LD HL,SP+r8 cycles: 2  12 registers: 0 0 H C
	LD_SP_HL       = 0xF9,//LD SP,HL cycles: 1  8 registers: - - - -
	LD_A_pa16p     = 0xFA,//LD A,(a16) cycles: 3  16 registers: - - - -
	EI             = 0xFB,//EI cycles: 1  4 registers: - - - -
	CP_d8          = 0xFE,//CP d8 cycles: 2  8 registers: Z 1 H C
	RST_38H        = 0xFF,//RST 38H cycles: 1  16 registers: - - - -
};
