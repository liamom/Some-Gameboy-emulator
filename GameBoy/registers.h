#pragma once

#include <array>

using namespace std;

enum register_name{ A = 0, B, D, H, F, C, E, L };
enum register_name_16{ AF = 0, BC, DE, HL };

class registers : protected array<unsigned char, 8>
{
public:
	registers() :PC_(0x100), SP_(0xFFFE){};
	virtual ~registers(){};
	
	void set(register_name reg, char value){ (*this)[reg] = value; };
	void set(register_name_16 reg, short value){ this->at(reg) = (char)(value >> 8); this->at(reg + 4) = (char)value; };
	unsigned char get(register_name a){ return this->at(a); };
	unsigned short get(register_name_16 register_group){ return (this->at(register_group) << 8) | this->at(register_group + 4);};
	unsigned short get_pc(){ return PC_; }
	unsigned short get_sp(){ return SP_; }
	void set_pc(unsigned short a){ PC_ = a; }
	void set_sp(unsigned short a){ SP_ = a; }

private:
	bitset<8> flag_reg_;
	unsigned short PC_, SP_;
};

