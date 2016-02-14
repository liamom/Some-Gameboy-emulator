#include "registers.h"

void Registers::set(register_name reg, char value) 
{
  registers_[reg] = value;
}

void Registers::set(register_name_16 reg, short value) 
{
  registers_[reg] = (char)(value >> 8);
  registers_[reg + 4] = (char)value;    //truncate the latter 8 bits
}

unsigned char Registers::get(register_name a) 
{
  return registers_[a];
}

unsigned short Registers::get(register_name_16 register_group) 
{
  return (registers_[register_group] << 8) | registers_[register_group + 4];
}

unsigned short Registers::get_pc() 
{ 
  return PC_; 
}

unsigned short Registers::get_sp() 
{ 
  return SP_; 
}

void Registers::set_pc(unsigned short a) 
{ 
  PC_ = a; 
}

void Registers::set_sp(unsigned short a) 
{ 
  SP_ = a; 
}