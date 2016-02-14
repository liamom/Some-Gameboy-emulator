#pragma once

#include <array>
#include <bitset>

using namespace std;

class Registers
{
public:
  enum register_name : unsigned char
  {
    A = 0,
    B,
    D,
    H,
    F,
    C,
    E,
    L
  };

  enum register_name_16 : unsigned char
  {
    AF = 0,
    BC,
    DE,
    HL
  };

public:
  void set(register_name reg, char value);
  void set(register_name_16 reg, short value);
  unsigned char get(register_name a);
  unsigned short get(register_name_16 register_group);
	unsigned short get_pc();
	unsigned short get_sp();
	void set_pc(unsigned short a);
	void set_sp(unsigned short a);

private:
  array<unsigned char, 8> registers_ = {0,0,0,0,0,0,0,0};
  bitset<8> flag_reg_;
  unsigned short PC_ = 0x100;  //program counter
  unsigned short SP_ = 0xFFFE; //stack pointer
};

