#include "cpu.h"

cpu::cpu(string filename) : cart_(filename), mem_(cart_), reg_()
{
    //ctor
}

cpu::cpu(cartridge &cart) : cart_(cart), mem_(cart_),reg_(){

}

cpu::~cpu()
{
    //dtor
}

void cpu::exicute_instruction(char instruction){
	//char instruction = instruction >> 24;

	switch (instruction){
	//row 4
	case LD_B_B:	ld_reg_to_reg(B, B); break;
	case LD_B_C:	ld_reg_to_reg(B, C); break;
	case LD_B_D:	ld_reg_to_reg(B, D); break;
	case LD_B_E:	ld_reg_to_reg(B, E); break;
	case LD_B_H:	ld_reg_to_reg(B, H); break;
	case LD_B_L:	ld_reg_to_reg(B, L); break;
	case LD_B__HL_:	ld_mem_to_reg(B, HL); break;
	case LD_B_A:	ld_reg_to_reg(B, A); break;
	case LD_C_B:	ld_reg_to_reg(C,B); break;
	case LD_C_C:	ld_reg_to_reg(C, C); break;
	case LD_C_D:	ld_reg_to_reg(C, D); break;
	case LD_C_E:	ld_reg_to_reg(C, E); break;
	case LD_C_H:	ld_reg_to_reg(C, H); break;
	case LD_C_L:	ld_reg_to_reg(C, L); break;
	case LD_C__HL_:	ld_mem_to_reg(C, HL); break;
	case LD_C_A:	ld_reg_to_reg(C, A); break;
	//row 5
	case LD_D_B:	ld_reg_to_reg(D, B); break;
	case LD_D_C:	ld_reg_to_reg(D, C); break;
	case LD_D_D:	ld_reg_to_reg(D, D); break;
	case LD_D_E:	ld_reg_to_reg(D, E); break;
	case LD_D_H:	ld_reg_to_reg(D, H); break;
	case LD_D_L:	ld_reg_to_reg(D, L); break;
	case LD_D__HL_:	ld_mem_to_reg(D, HL); break;
	case LD_D_A:	ld_reg_to_reg(D, L); break;
	case LD_E_B:	ld_reg_to_reg(E, B); break;
	case LD_E_C:	ld_reg_to_reg(E, C); break;
	case LD_E_D:	ld_reg_to_reg(E, D); break;
	case LD_E_E:	ld_reg_to_reg(E, E); break;
	case LD_E_H:	ld_reg_to_reg(E, H); break;
	case LD_E_L:	ld_reg_to_reg(E, L); break;
	case LD_E__HL_:	ld_mem_to_reg(E, HL); break;
	case LD_E_A:	ld_reg_to_reg(E, L); break;
	//row 6
	case LD_H_B:	ld_reg_to_reg(H, B); break;
	case LD_H_C:	ld_reg_to_reg(H, C); break;
	case LD_H_D:	ld_reg_to_reg(H, D); break;
	case LD_H_E:	ld_reg_to_reg(H, E); break;
	case LD_H_H:	ld_reg_to_reg(H, H); break;
	case LD_H_L:	ld_reg_to_reg(H, L); break;
	case LD_H__HL_:	ld_mem_to_reg(H, HL); break;
	case LD_H_A:	ld_reg_to_reg(H, L); break;
	case LD_L_B:	ld_reg_to_reg(L, B); break;
	case LD_L_C:	ld_reg_to_reg(L, C); break;
	case LD_L_D:	ld_reg_to_reg(L, D); break;
	case LD_L_E:	ld_reg_to_reg(L, E); break;
	case LD_L_H:	ld_reg_to_reg(L, H); break;
	case LD_L_L:	ld_reg_to_reg(L, L); break;
	case LD_L__HL_:	ld_mem_to_reg(L, HL); break;
	case LD_L_A:	ld_reg_to_reg(L, L); break;
	//row 7
	case LD__HL__B:	ld_reg_to_mem(HL, B); break;
	case LD__HL__C:	ld_reg_to_mem(HL, C); break;
	case LD__HL__D:	ld_reg_to_mem(HL, D); break;
	case LD__HL__E:	ld_reg_to_mem(HL, E); break;
	case LD__HL__H:	ld_reg_to_mem(HL, H); break;
	case LD__HL__L:	ld_reg_to_mem(HL, L); break;
	case HALT:		throw invalid_argument("HALT instruction not implemented: " + (int)instruction); break;
	case LD__HL__A:	ld_reg_to_mem(HL, A); break;
	case LD_A_B:	ld_reg_to_reg(A, B); break;
	case LD_A_C:	ld_reg_to_reg(A, C); break;
	case LD_A_D:	ld_reg_to_reg(A, D); break;
	case LD_A_E:	ld_reg_to_reg(A, E); break;
	case LD_A_H:	ld_reg_to_reg(A, H); break;
	case LD_A_L:	ld_reg_to_reg(A, L); break;
	case LD_A__HL_:	ld_mem_to_reg(A, HL); break;
	case LD_A_A:	ld_reg_to_reg(A, A); break;

	default:		throw invalid_argument("instruction not implemented: " + (int)instruction); break;
	}
}

//4 cycles
void cpu::ld_reg_to_reg(register_name a, register_name b){
	reg_.set(a, reg_.get(b));
}

//8 cycles
void cpu::ld_mem_to_reg(register_name location, register_name_16 register_with_address){
	reg_.set(location, mem_[reg_.get(register_with_address)]);
}

void cpu::ld_reg_to_mem(register_name_16 register_with_address, register_name value){
	mem_[reg_.get(register_with_address)] = value;
}