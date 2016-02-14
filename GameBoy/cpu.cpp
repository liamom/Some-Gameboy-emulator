#include "cpu.h"

Cpu::Cpu(string filename) : cart_(filename), mem_(cart_), reg_()
{
    //ctor
}

Cpu::Cpu(Cartridge &cart) : cart_(cart), mem_(cart_),reg_(){

}

Cpu::~Cpu()
{
    //dtor
}

void Cpu::execute_instruction(char instruction){
	//char instruction = instruction >> 24;
  typedef Registers reg;

	switch (instruction){
  //row3
  case 
	//row 4
	case LD_B_B:    ld_reg_to_reg(reg::B,  reg::B); break;
	case LD_B_C:    ld_reg_to_reg(reg::B,  reg::C); break;
	case LD_B_D:    ld_reg_to_reg(reg::B,  reg::D); break;
	case LD_B_E:    ld_reg_to_reg(reg::B,  reg::E); break;
	case LD_B_H:    ld_reg_to_reg(reg::B,  reg::H); break;
	case LD_B_L:    ld_reg_to_reg(reg::B,  reg::L); break;
	case LD_B_pHLp:	ld_mem_to_reg(reg::B,  reg::HL); break;
	case LD_B_A:    ld_reg_to_reg(reg::B,  reg::A); break;
	case LD_C_B:    ld_reg_to_reg(reg::C,  reg::B); break;
	case LD_C_C:    ld_reg_to_reg(reg::C,  reg::C); break;
	case LD_C_D:    ld_reg_to_reg(reg::C,  reg::D); break;
	case LD_C_E:    ld_reg_to_reg(reg::C,  reg::E); break;
	case LD_C_H:    ld_reg_to_reg(reg::C,  reg::H); break;
	case LD_C_L:    ld_reg_to_reg(reg::C,  reg::L); break;
	case LD_C_pHLp:	ld_mem_to_reg(reg::C,  reg::HL); break;
	case LD_C_A:    ld_reg_to_reg(reg::C,  reg::A); break;
	//row 5
	case LD_D_B:    ld_reg_to_reg(reg::D,  reg::B); break;
	case LD_D_C:    ld_reg_to_reg(reg::D,  reg::C); break;
	case LD_D_D:    ld_reg_to_reg(reg::D,  reg::D); break;
	case LD_D_E:    ld_reg_to_reg(reg::D,  reg::E); break;
	case LD_D_H:    ld_reg_to_reg(reg::D,  reg::H); break;
	case LD_D_L:    ld_reg_to_reg(reg::D,  reg::L); break;
	case LD_D_pHLp: ld_mem_to_reg(reg::D,  reg::HL); break;
	case LD_D_A:    ld_reg_to_reg(reg::D,  reg::L); break;
	case LD_E_B:    ld_reg_to_reg(reg::E,  reg::B); break;
	case LD_E_C:    ld_reg_to_reg(reg::E,  reg::C); break;
	case LD_E_D:    ld_reg_to_reg(reg::E,  reg::D); break;
	case LD_E_E:    ld_reg_to_reg(reg::E,  reg::E); break;
	case LD_E_H:    ld_reg_to_reg(reg::E,  reg::H); break;
	case LD_E_L:    ld_reg_to_reg(reg::E,  reg::L); break;
	case LD_E_pHLp: ld_mem_to_reg(reg::E,  reg::HL); break;
	case LD_E_A:    ld_reg_to_reg(reg::E,  reg::L); break;
	//row 6
	case LD_H_B:    ld_reg_to_reg(reg::H,  reg::B); break;
	case LD_H_C:    ld_reg_to_reg(reg::H,  reg::C); break;
	case LD_H_D:    ld_reg_to_reg(reg::H,  reg::D); break;
	case LD_H_E:    ld_reg_to_reg(reg::H,  reg::E); break;
	case LD_H_H:    ld_reg_to_reg(reg::H,  reg::H); break;
	case LD_H_L:    ld_reg_to_reg(reg::H,  reg::L); break;
	case LD_H_pHLp: ld_mem_to_reg(reg::H,  reg::HL); break;
	case LD_H_A:    ld_reg_to_reg(reg::H,  reg::L); break;
	case LD_L_B:    ld_reg_to_reg(reg::L,  reg::B); break;
	case LD_L_C:    ld_reg_to_reg(reg::L,  reg::C); break;
	case LD_L_D:    ld_reg_to_reg(reg::L,  reg::D); break;
	case LD_L_E:    ld_reg_to_reg(reg::L,  reg::E); break;
	case LD_L_H:    ld_reg_to_reg(reg::L,  reg::H); break;
	case LD_L_L:    ld_reg_to_reg(reg::L,  reg::L); break;
	case LD_L_pHLp: ld_mem_to_reg(reg::L,  reg::HL); break;
	case LD_L_A:    ld_reg_to_reg(reg::L,  reg::L); break;
	//row 7
	case LD_pHLp_B: ld_reg_to_mem(reg::HL, reg::B); break;
	case LD_pHLp_C: ld_reg_to_mem(reg::HL, reg::C); break;
	case LD_pHLp_D: ld_reg_to_mem(reg::HL, reg::D); break;
	case LD_pHLp_E: ld_reg_to_mem(reg::HL, reg::E); break;
	case LD_pHLp_H: ld_reg_to_mem(reg::HL, reg::H); break;
	case LD_pHLp_L: ld_reg_to_mem(reg::HL, reg::L); break;
	case HALT:      throw invalid_argument("HALT instruction not implemented: " + (int)instruction); break;
	case LD_pHLp_A: ld_reg_to_mem(reg::HL, reg::A); break;
	case LD_A_B:    ld_reg_to_reg(reg::A,  reg::B); break;
	case LD_A_C:    ld_reg_to_reg(reg::A,  reg::C); break;
	case LD_A_D:    ld_reg_to_reg(reg::A,  reg::D); break;
	case LD_A_E:    ld_reg_to_reg(reg::A,  reg::E); break;
	case LD_A_H:    ld_reg_to_reg(reg::A,  reg::H); break;
	case LD_A_L:    ld_reg_to_reg(reg::A,  reg::L); break;
	case LD_A_pHLp: ld_mem_to_reg(reg::A,  reg::HL); break;
	case LD_A_A:    ld_reg_to_reg(reg::A,  reg::A); break;

	default:		throw invalid_argument("instruction not implemented: " + (int)instruction); break;
	}
}

//4 cycles
void Cpu::ld_reg_to_reg(Registers::register_name a, 
  Registers::register_name b)
{
	reg_.set(a, reg_.get(b));
}

//8 cycles
void Cpu::ld_mem_to_reg(Registers::register_name location, 
  Registers::register_name_16 register_with_address)
{
	reg_.set(location, mem_[reg_.get(register_with_address)]);
}

void Cpu::ld_reg_to_mem(Registers::register_name_16 register_with_address, 
  Registers::register_name value)
{
	mem_[reg_.get(register_with_address)] = value;
}