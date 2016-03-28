#include "cpu.h"

Cpu::Cpu(std::string filename) : cart_(filename){
    //ctor
}

Cpu::Cpu(Cartridge &cart) : cart_(cart){

}

inline void Cpu::Decrement(Word &reg) {
  --reg;
  flags_.zero = reg == 0;
  flags_.half_carry = (reg & 0xF) == 0xF;
  flags_.subtract = true;
}

inline void Cpu::Increment(Word &reg) {
  ++reg;
  flags_.zero = reg == 0;
  flags_.half_carry = (reg & 0xF) == 0;
  flags_.subtract = false;
}

inline void Cpu::Add(Word &reg1, const Word &reg2) {
  int sum = reg1 + reg2;
  flags_.half_carry = (sum & 0xF) < (reg1 & 0xF);
  flags_.carry      = sum > 0xFF;
  reg1              = sum;//truncate
  flags_.zero       = reg1 == 0;
  flags_.subtract   = false;
}

inline void Cpu::Double(Word &reg) {
  flags_.half_carry = (reg & 0x8) == 0x8;
  flags_.carry      = reg > 0x7F;
  reg = (reg << 1) & 0xFF;
  flags_.zero     = reg == 0;
  flags_.subtract = false;
}

inline void Cpu::AddWithCarry(Word &reg, const Word &reg2) {
  int sum = reg + reg2 + ((flags_.carry) ? 1 : 0);
  flags_.half_carry = ((reg & 0xF) + (reg2 & 0xF) + ((flags_.carry) ? 1 : 0) > 0xF);
  flags_.carry = (sum > 0xFF);
  reg = sum; //truncate
  flags_.zero = (reg == 0);
  flags_.subtract = false;
}

inline void Cpu::DoubleWithCarry(Word &reg) {
  //shift left register A one bit for some ops here as an optimization:
  int sum           = (reg << 1) | ((flags_.carry) ? 1 : 0);
  flags_.half_carry = (((reg << 1) & 0x1E) | ((flags_.carry) ? 1 : 0)) > 0xF;
  flags_.carry      = sum > 0xFF;
  reg               = sum; //truncate
  flags_.zero       = reg == 0;
  flags_.subtract   = false;
}

inline void Cpu::Subtract(Word &reg1, const Word &reg2) {
  int sum           = reg1 - reg2;
  flags_.half_carry = (reg1 & 0xF) < (sum & 0xF);
  flags_.carry      = sum < 0;
  reg1              = sum;//truncate
  flags_.zero       = sum == 0;
  flags_.subtract   = true;
}

inline void Cpu::SubtractSelf(Word &reg) {
  reg = 0;
  flags_.half_carry = false;
  flags_.carry = false;
  flags_.zero = true;
  flags_.subtract = true;
}

inline void Cpu::SubtractWithCarry(Word &reg1, const Word &reg2) {
  int sum = reg1 - reg2 - ((flags_.carry) ? 1 : 0);
  flags_.half_carry = (reg1 & 0xF) - (reg2 & 0xF) - ((flags_.carry) ? 1 : 0) < 0;
  flags_.carry      = sum < 0;
  reg1              = sum; //truncate
  flags_.zero       = reg1 == 0;
  flags_.subtract   = true;
}

inline void Cpu::And(Word &reg1, const Word &reg2) {
  reg1 &= reg2;
  flags_.zero       = reg1 == 0;
  flags_.half_carry = true;
  flags_.subtract   = false;
  flags_.carry      = false;
}

inline void Cpu::Xor(Word &reg1, const Word &reg2) {
  reg1 ^= reg2;
  flags_.zero       = reg1 == 0;
  flags_.subtract   = false;
  flags_.half_carry = false;
  flags_.carry      = false;
}

inline void Cpu::Or(Word &reg1, const Word &reg2) {
  reg1 |= reg2;
  flags_.zero       = reg1 == 0;
  flags_.subtract   = false;
  flags_.half_carry = false;
  flags_.carry      = false;
}

inline void Cpu::Compare(const Word &reg1, const Word &reg2) {
  int dirtySum      = reg1 - reg2;
  flags_.half_carry = ((dirtySum & 0xF) > (reg1 & 0xF));
  flags_.carry      = (dirtySum < 0);
  flags_.zero       = (dirtySum == 0);
  flags_.subtract   = true;
}

void Cpu::ExecuteInstruction(Word instruction){
	//char instruction = instruction >> 24;
  auto& reg = registers_;
  auto& mem = memory_;

	switch (instruction){
  case 0x00: break;//NOP
  case 0x01: //LD BC, nn
    reg.C = mem.read_byte(PC_); 
    reg.B = mem.read_byte(PC_ + 1); 
    PC_ += 2; 
    break;
  case 0x02: //LD (BC), A
    mem.write_byte(reg.BC, reg.A);
    break; 
  case 0x03: //INC BC
    reg.BC += 1;
    break;
  case 0x04: //INC B
    Increment(reg.B);
    break;
  case 0x05: //DEC B
    Decrement(reg.B);
    break;
  case 0x06: //LD B, n
    reg.B = mem.read_byte(PC_);
    ++PC_;
    break;
  case 0x07: //RLCA
    flags_.carry = reg.A > 0x7F;
    reg.A = (reg.A << 1) | (reg.A >> 7);//rotate byte
    flags_.zero       = false;
    flags_.subtract   = false;
    flags_.half_carry = false;
    break;
  case 0x08: //LD (nn), SP
    SP_ = mem.read_word_16(PC_);
    PC_ += 2;
    break;
  case 0x09: { //ADD HL, BC
    //needs to be bigger than 16 bits to check for overflow
    //this approach avoids branching
    uint32_t sum = reg.HL + reg.BC;
    flags_.half_carry = ((reg.HL & 0xFFF) > (sum & 0xFFF));
    flags_.carry      = sum > 0xFFFF;
    reg.HL      = sum;
    flags_.subtract   = false;
  }
    break;
  case 0x0A: //LD A, (BC)
    reg.A = mem.read_byte(reg.BC);
    break;
  case 0x0B: //DEC BC 
    --reg.BC;
    break;
  case 0x0C: //INC C
    Increment(reg.C);
    break;
  case 0x0D: //DEC C
    Decrement(reg.C);
    break;
  case 0x0E: //LD C, n
    reg.C = mem.read_byte(PC_);
    ++PC_;
    break;
  case 0x0F: //RRCA
    reg.A             = (reg.A >> 1) | ((reg.A & 1) << 7);
    flags_.carry      = (reg.A > 0x7F);
    flags_.zero       = false;
    flags_.subtract   = false;
    flags_.half_carry = false;
    break;
  case 0x10: //STOP
    //TODO
    throw std::invalid_argument("STOP instruction not implemented: " + (int)instruction);
    break;
  case 0x11: //LD DE, nn
    reg.DE = mem.read_word_16(PC_);
    PC_ += 2;
    break;
  case 0x12: //LD (DE), A
    mem.write(reg.DE,reg.A);
    break;
  case 0x13: //INC DE
    ++reg.DE;
    break;
  case 0x14: //INC D
    Increment(reg.D);
    break;
  case 0x15: //DEC D
    Decrement(reg.D);
    break;
  case 0x16: //LD D, n
    reg.D = mem.read_byte(PC_);
    ++PC_;
    break;
  case 0x17:{ //RLA
    //carry must be 1 or 0;
    assert(flags_.carry == 0 || flags_.carry == 1);//(flags_.carry & 0xFE == 0)

    bool carry_flag   = flags_.carry;
    flags_.carry      = (reg.A > 0x7F);
    reg.A             = (reg.A << 1) | carry_flag;
    flags_.zero       = false;
    flags_.subtract   = false;
    flags_.half_carry = false;}
    break;
  case 0x18: //JR n
    PC_ += mem.read_byte(PC_) + 1;
    break;
  case 0x19:{ //ADD HL, DE
    int sum = reg.HL + reg.DE;
    flags_.half_carry = ((reg.HL & 0xFFF) > (sum & 0xFFF));
    flags_.carry      = (sum > 0xFFFF);
    reg.HL    = sum & 0xFFFF;
    flags_.subtract   = false;}
    break;
  case 0x1A: //LD A, (DE)
    reg.A = mem.read_byte(reg.DE);
    break;
  case 0x1B: //DEC DE
    --reg.DE;
    break;
  case 0x1C: //INC E
    Increment(reg.E);
    break;
  case 0x1D: //DEC E
    Decrement(reg.E);
    break;
  case 0x1E: //LD E, n
    reg.E = mem.read_byte(PC_);
    ++PC_;
    break;
  case 0x1F: { //RRA
    Word carry   = flags_.carry ? 0x80 : 0;
    flags_.carry = ((reg.A & 1) == 1);
    reg.A        = (reg.A >> 1) | carry;

    flags_.zero       = false;
    flags_.subtract   = false;
    flags_.half_carry = false; }
    break;
  case 0x20: //JR NZ, n
    if (flags_.zero) {
      PC_ += mem.read_byte(PC_) + 1;
      cpu_ticks += 4;
    }
    else {
      ++PC_;
    }
    break;
  case 0x21: 
    reg.HL = mem.read_word_16(PC_);
    PC_ += 2;
    break;
  case 0x22: //LDI (HL), A
    mem.write_byte(reg.HL, reg.A);
    ++reg.HL;
    break;
  case 0x23: //INC HL
    ++reg.HL;
    break;
  case 0x24: //INC H
    Increment(reg.H);
    break;
  case 0x25: //DEC H
    Increment(reg.H);
    break;
  case 0x26: //LD H, n
    reg.H = mem.read_byte(PC_);
    ++PC_;
    break;
  case 0x27: //DAA - Binary Coded Decimal 
    if (!flags_.subtract) {
      if (flags_.carry || reg.A > 0x99) {
        reg.A = (reg.A + 0x60) & 0xFF;
        flags_.carry = true;
      }
      if (flags_.half_carry || (reg.A & 0xF) > 0x9) {
        reg.A = (reg.A + 0x06) & 0xFF;
        flags_.half_carry = false;
      }
    }
    else if (flags_.carry && flags_.half_carry) {
      reg.A = (reg.A + 0x9A) & 0xFF;
      flags_.half_carry = false;
    }
    else if (flags_.carry) {
      reg.A = (reg.A + 0xA0) & 0xFF;
    }
    else if (flags_.half_carry) {
      reg.A = (reg.A + 0xFA) & 0xFF;
      flags_.half_carry = false;
    }
    flags_.zero = (reg.A == 0);
    break;
  case 0x28: //JR Z, n
    if (flags_.zero) {
      PC_ += mem.read_byte(PC_) + 1;
      cpu_ticks += 4;
    }
    else {
      ++PC_;
    }
    break;
  case 0x29: //ADD HL, HL
    flags_.half_carry = (reg.HL & 0xFFF) > 0x7FF;
    flags_.carry      = reg.HL > 0x7FFF;
    reg.HL  <<= 1;
    flags_.subtract   = false;
    break;
  case 0x2A: //LDI A, (HL)
    reg.A = mem.read_byte(reg.HL);
    ++reg.HL;
    break;
  case 0x2B: //DEC HL
    --reg.HL;
    break;
  case 0x2C: //INC L
    Increment(reg.L);
    break;
  case 0x2D: //DEC L
    Decrement(reg.L);
    break;
  case 0x2E: //LD L, n
    reg.L = mem.read_byte(PC_);
    ++PC_;
    break;
  case 0x2F: //CPL
    reg.A = ~reg.A;
    flags_.subtract   = true;
    flags_.half_carry = true;
    break;
  case 0x30: //JR NC, n
    if (!flags_.carry) {
      PC_ += mem.read_byte(PC_) + 1;
      cpu_ticks += 4;
    }
    else {
      ++PC_;
    }
    break;
  case 0x31: //LD SP, nn
    SP_ = mem.read_word_16(PC_);
    PC_ += 2;
    break;
  case 0x32: //LDD (HL), A
    mem.write_byte(reg.HL, reg.A);
    --reg.HL;
    break;
  case 0x33: //INC SP
    ++SP_;
    break;
  case 0x34: { //INC (HL)
    Word temp = mem.read_byte(reg.HL) + 1;
    flags_.zero = temp == 0;
    flags_.half_carry = (temp & 0xF) == 0;
    flags_.subtract = false;
    mem.write_byte(reg.HL, temp); }
    break;
  case 0x35: { //DEC (HL)
    Word temp = mem.read_byte(reg.HL) - 1;
    flags_.zero = temp == 0;
    flags_.half_carry = (temp & 0xF) == 0xF;
    flags_.subtract = true;
    mem.write_byte(reg.HL, temp); }
    break;
  case 0x36: //LD (HL), n
    mem.write_byte(reg.HL, mem.read_byte(PC_));
    ++PC_;
    break;
  case 0x37: //SCF
    flags_.carry      = true;
    flags_.subtract   = false;
    flags_.half_carry = false;
    break;
  case 0x38: //JR C, n
    if (flags_.carry) {
      PC_ += mem.read_byte(PC_) + 1;
      cpu_ticks += 4;
    }
    else {
      ++PC_;
    }
    break;
  case 0x39: //ADD HL, SP
    uint32_t sum = reg.HL + SP_;
    flags_.half_carry = (reg.HL & 0xFFF) > (sum & 0xFFF);
    flags_.carry    = sum > 0xFFFF;
    reg.HL  = sum;
    flags_.subtract = false;
    break;
  case 0x3A: //LDD A, (HL)
    reg.A = mem.read_byte(reg.HL);
    --reg.HL;
    break;
  case 0x3B: //DEC SP
    --SP_;
    break;
  case 0x3C: //INC A
    Increment(reg.A);
    break;
  case 0x3D: //DEC A
    Decrement(reg.A);
    break;
  case 0x3E: //LD A, n
    reg.A = mem.read_byte(PC_);
    ++PC_;
    break;
  case 0x3F: //CCF
    flags_.carry     != flags_.carry;
    flags_.subtract   = false;
    flags_.half_carry = false;
    break;
	case 0x40: //LD B, B 
    //doesn't do anything
    break;
  case 0x41: //LD B, C
    reg.B = reg.C;
    break;
  case 0x42: //LD B, D
    reg.B = reg.D;
    break;
  case 0x43: //LD B, E
    reg.B = reg.E;
    break;
  case 0x44: //LD B, H
    reg.B = reg.H;
    break;
  case 0x45: //LD B, L
    reg.B = reg.L;
    break;
  case 0x46: //LD B, (HL)
    reg.B = mem.read_byte(reg.HL);
    break;
  case 0x47: //LD B, A
    reg.B = reg.A;
    break;
  case 0x48: //LD C, B
    reg.C = reg.B;
    break;
  case 0x49: //LD C, C
    //doesn't do anything
    break;
  case 0x4A: //LD C, D
    reg.C = reg.D;
    break;
  case 0x4B: //LD C, E
    reg.C = reg.E;
    break;
  case 0x4C: //LD C, H
    reg.C = reg.H;
    break;
  case 0x4D: //LD C, L
    reg.C = reg.L;
    break;
  case 0x4E: //LD C, (HL)
    reg.C = mem.read_byte(reg.HL);
    break;
  case 0x4F: //LD C, A
    reg.C = reg.A;
    break;
	case 0x50: //LD D, B
    reg.D = reg.B;
    break;
  case 0x51: //LD D, C
    reg.D = reg.C;
    break;
  case 0x52://LD D, D
    //doesn't no anything
    break;
  case 0x53: //LD D, E
    reg.D = reg.E;
    break;
  case 0x54: //LD D, H
    reg.D = reg.H;
    break;
  case 0x55: //LD D, L
    reg.D = reg.L;
    break;
  case 0x56: //LD D, (HL)
    reg.D = mem.read_byte(reg.HL);
    break;
  case 0x57: //LD D, A
    reg.D = reg.A;
    break;
  case 0x58: //LD E, B
    reg.E = reg.B;
    break;
  case 0x59: //LD E, C
    reg.E = reg.C;
    break;
  case 0x5A: //LD E, D
    reg.E = reg.D;
    break;
  case 0x5B: //LD E, E
    //nothing
    break;
  case 0x5C: //LD E, H
    reg.E = reg.H;
    break;
  case 0x5D: //LD E, L
    reg.E = reg.L;
    break;
  case 0x5E: //LD E, (HL)
    reg.E = mem.read_byte(reg.HL);
    break;
  case 0x5F: //LD E, A
    reg.E = reg.A;
    break;
	case 0x60: //LD H, B
    reg.H = reg.B;
    break;
  case 0x61: //LD H, C
    reg.H = reg.C;
    break;
  case 0x62: //LD H, D
    reg.H = reg.D;
    break;
  case 0x63: //LD H, E
    reg.H = reg.E;
    break;
  case 0x64: //LD H, H
    //nothing
    break;
  case 0x65: //LD H, L
    reg.H = reg.L;
    break;
  case 0x66: //LD H, (HL)
    reg.H = mem.read_byte(reg.HL);
    break;
  case 0x67: //LD H, A
    reg.H = reg.A;
    break;
  case 0x68: //LD L, B
    reg.L = reg.B;
    break;
  case 0x69: //LD L, C
    reg.L = reg.C;
    break;
  case 0x6A: //LD L, D 
    reg.L = reg.D;
    break;
  case 0x6B: //LD L, E
    reg.L = reg.E;
    break;
  case 0x6C: //LD L, H
    reg.L = reg.H;
    break;
  case 0x6D: //LD L, L
    //nothing
    break;
  case 0x6E: //LD L, (HL)
    reg.L = mem.read_byte(reg.HL);
    break;
  case 0x6F: //LD L, A
    reg.L = reg.A;
    break;
	case 0x70: //LD (HL), B
    mem.write(reg.HL, reg.B);
    break;
  case 0x71: //LD (HL), C
    mem.write_byte(reg.HL, reg.C);
    break;
  case 0x72: //LD (HL), D
    mem.write_byte(reg.HL, reg.D);
    break;
  case 0x73: //LD (HL), E
    mem.write_byte(reg.HL, reg.E);
    break;
  case 0x74: //LD (HL), H
    mem.write_byte(reg.HL, reg.H);
    break;
  case 0x75: //LD (HL), L
    mem.write_byte(reg.HL, reg.L);
    break;
  case 0x76: //HALT
    //TODO
    throw std::invalid_argument("STOP instruction not implemented: " + (int)instruction);
    break;
  case 0x77: //LD (HL), A
    mem.write_byte(reg.HL, reg.A);
    break;
  case 0x78: //LD A, B
    mem.write_byte(reg.HL, reg.B);
    break;
  case 0x79: //LD A, C
    reg.A = reg.C;
    break;
  case 0x7A: //LD A, D
    reg.A = reg.D;
    break;
  case 0x7B: //LD A, E
    reg.A = reg.E;
    break;
  case 0x7C: //LD A, H
    reg.A = reg.H;
    break;
  case 0x7D: //LD A, L
    reg.A = reg.L;
    break;
  case 0x7E: //LD, A, (HL)
    reg.A = mem.read_byte(reg.HL);
    break;
  case 0x7F: //LD A, A
    //nothing
    break;
  case 0x80: //ADD A, B
    Add(reg.A, reg.B);
    break;
  case 0x81: //ADD A, C
    Add(reg.A, reg.C);
    break;
  case 0x82: //ADD A, D
    Add(reg.A, reg.D);
    break;
  case 0x83: //ADD A, E
    Add(reg.A, reg.E);
    break;
  case 0x84: //ADD A, H
    Add(reg.A, reg.H);
    break;
  case 0x85: //ADD A, L
    Add(reg.A, reg.L);
    break;
  case 0x86: //ADD A, (HL)
    Add(reg.A, mem.read_byte(reg.HL));
    break;
  case 0x87: //ADD A, A
    Double(reg.A);
    break;
  case 0x88: 
    //ADC A, B
    AddWithCarry(reg.A, reg.B);
    break;
  case 0x89: //ADC A, C
    AddWithCarry(reg.A, reg.C);
    break;
  case 0x8A: //ADC A, D
    AddWithCarry(reg.A, reg.D);
    break;
  case 0x8B: //ADC A, E
    AddWithCarry(reg.A, reg.E);
    break;
  case 0x8C: //ADC A, H
    AddWithCarry(reg.A, reg.H);
    break;
  case 0x8D: //ADC A, L
    AddWithCarry(reg.A, reg.L);
    break;
  case 0x8E: //ADC A, (HL)
    AddWithCarry(reg.A, mem.read_byte(reg.HL));
    break;
  case 0x8F: //ADC A, A
    DoubleWithCarry(reg.A);
    break;
  case 0x90: //SUB A, B
    Subtract(reg.A, reg.B);
    break;
  case 0x91: //SUB A, C
    Subtract(reg.A, reg.C);
    break;
  case 0x92: //SUB A, D
    Subtract(reg.A, reg.D);
    break;
  case 0x93: //SUB A, E
    Subtract(reg.A, reg.E);
    break;
  case 0x94: //SUB A, H
    Subtract(reg.A, reg.H);
    break;
  case 0x95: //SUB A, L
    Subtract(reg.A, reg.L);
    break;
  case 0x96: //SUB A, (HL)
    Subtract(reg.A, mem.read_byte(reg.HL));
    break;
  case 0x97: //SUB A, A
    SubtractSelf(reg.A);
    break;
  case 0x98: //SBC A, B
    SubtractWithCarry(reg.A, reg.B);
    break;
  case 0x99: //SBC A, C
    SubtractWithCarry(reg.A, reg.C);
    break;
  case 0x9A: //SBC A, D
    SubtractWithCarry(reg.A, reg.D);
    break;
  case 0x9B: //SBC A, E
    SubtractWithCarry(reg.A, reg.E);
    break;
  case 0x9C: //SBC A, H
    SubtractWithCarry(reg.A, reg.H);
    break;
  case 0x9D: //SBC A, L
    SubtractWithCarry(reg.A, reg.L);
    break;
  case 0x9E: //SBC A, (HL)
    SubtractWithCarry(reg.A, mem.read_byte(reg.HL));
    break;
  case 0x9F: //SBC A, A
    SubtractWithCarry(reg.A, reg.A); //can optimize
    break;
  case 0xA0: //AND B
    And(reg.A, reg.B);
    break;
  case 0xA1: //AND C
    And(reg.A, reg.C);
    break;
  case 0xA2: //AND D
    And(reg.A, reg.D);
    break;
  case 0xA3: //AND E
    And(reg.A, reg.E);
    break;
  case 0xA4: //AND H
    And(reg.A, reg.H);
    break;
  case 0xA5: //AND L
    And(reg.A, reg.L);
    break;
  case 0xA6: //AND (HL)
    And(reg.A, mem.read_byte(reg.HL));
    break;
  case 0xA7: //AND A
    And(reg.A, reg.A);//can optimize
    break;
  case 0xA8: //XOR B
    Xor(reg.A, reg.B);
    break;
  case 0xA9: //XOR C
    Xor(reg.A, reg.C);
    break;
  case 0xAA: //XOR D
    Xor(reg.A, reg.D);
    break;
  case 0xAB: //XOR E
    Xor(reg.A, reg.E);
    break;
  case 0xAC: //XOR H
    Xor(reg.A, reg.H);
    break;
  case 0xAD: //XOR L
    Xor(reg.A, reg.L);
    break;
  case 0xAE: //XOR (HL)
    Xor(reg.A, mem.read_byte(reg.HL));
    break;
  case 0xAF: //XOR A
    Xor(reg.A, reg.A);
    break;
  case 0xB0: //OR B
    Or(reg.A, reg.B);
    break;
  case 0xB1: //OR C
    Or(reg.A, reg.C);
    break;
  case 0xB2: //OR D
    Or(reg.A, reg.D);
    break;
  case 0xB3: //OR E
    Or(reg.A, reg.E);
    break;
  case 0xB4: //OR H
    Or(reg.A, reg.H);
    break;
  case 0xB5: //OR L
    Or(reg.A, reg.L);
    break;
  case 0xB6: //OR (HL)
    Or(reg.A, mem.read_byte(reg.HL));
    break;
  case 0xB7: //OR A
    Or(reg.A, reg.A);
    break;
  case 0xB8: //CP B
    Compare(reg.A, reg.B);
    break;
  case 0xB9: //CP C
    Compare(reg.A, reg.C);
    break;
  case 0xBA: //CP D
    Compare(reg.A, reg.D);
    break;
  case 0xBB: //CP E
    Compare(reg.A, reg.E);
    break;
  case 0xBC: //CP H
    Compare(reg.A, reg.H);
    break;
  case 0xBD: //CP L
    Compare(reg.A, reg.L);
    break;
  case 0xBE: //CP (HL)
    Compare(reg.A, mem.read_byte(reg.HL));
    break;
  case 0xBF: //CP A
    Compare(reg.A, reg.A);
    break;
  case 0xC0: //RET !FZ
    if (!flags_.zero) {
      PC_ = mem.read_word_16(SP_);
      SP_ += 2;
      cpu_ticks += 12;
    }
    break;
  case 0xC1: //POP BC
    reg.BC = mem.read_word_16(SP_);
    SP_ += 2;
    break;
  case 0xC2: //JP !FZ, nn
    if (!flags_.zero) {
      PC_ = mem.read_word_16(PC_);
      cpu_ticks += 4;
    }
    else {
      PC_ += 2;
    }
    break;
  case 0xC3: //JP nn
    PC_ = mem.read_word_16(PC_);
    break;
  case 0xC4: //CALL !FZ, nn
    if (!flags_.zero) {
      Word_16 temp_pc = mem.read_word_16(PC_);
      PC_ += 2;
      SP_ -= 2;
      mem.write(SP_, PC_);
      PC_ = temp_pc;
      cpu_ticks += 12;
    }
    else {
      PC_ += 2;
    }
    break;
  case 0xC5: //PUSH BC
    SP_ -= 2;
    mem.write(SP_, reg.BC);
    break;
  case 0xC6: //ADD, n
    Add(reg.A, mem.read_byte(PC_));
    break;
  case 0xC7: //RST 0
    SP_ -= 2;
    mem.write(SP_, PC_);
    PC_ = 0;
    break;
  case 0xC8: //RET FZ
    if (flags_.zero) {
      PC_ = mem.read_word_16(SP_);
      SP_ += 2;
      cpu_ticks += 12;
    }
    break;
  case 0xC9: //RET
    PC_ = mem.read_word_16(SP_);
    SP_ += 2;
    break;
  case 0xCA: //JP FZ, nn
    if (flags_.zero) {
      PC_ = mem.read_word_16(PC_);
      cpu_ticks += 4;
    }
    else {
      PC_ += 2;
    }
    break;
  case 0xCB: //Secondary OP Code Set
    Word second_op_code = mem.read_byte(PC_);
    ++PC_;
    //todo figure this cpu tick thing out
    //cpu_ticks += something
    ExecuteTwoByteInstruction(second_op_code);
    break;
  case 0xCC: //CALL FZ, nn
    if (flags_.zero) {
      Word_16 temp_pc = mem.read_word_16(PC_);
      PC_ += 2;

      SP_ -= 2;
      mem.write(SP_, PC_);

      PC_ = temp_pc;
      cpu_ticks += 12;
    }
    else {
      PC_ += 2;
    }
    break;
  case 0xCD: //CALL nn
    Word_16 temp_pc = mem.read_word_16(PC_);
    PC_ += 2;
    SP_ -= 2;
    mem.write(SP_, PC_);
    PC_ = temp_pc;
    break;
  case 0xCE: //ADC A, n
    AddWithCarry(reg.A, mem.read_byte(PC_));
    ++PC_;
    break;
  case 0xCF: //RST 0x8
    SP_ -= 2;
    mem.write(SP_, PC_);
    PC_ = 0x8;
    break;
  case 0xD0: break;
  case 0xD1: break;
  case 0xD2: break;
  case 0xD4: break;
  case 0xD5: break;
  case 0xD6: break;
  case 0xD7: break;
  case 0xD8: break;
  case 0xD9: break;
  case 0xDA: break;
  case 0xDC: break;
  case 0xDE: break;
  case 0xDF: break;
  case 0xE0: break;
  case 0xE1: break;
  case 0xE2: break;
  case 0xE5: break;
  case 0xE6: break;
  case 0xE7: break;
  case 0xE8: break;
  case 0xE9: break;
  case 0xEA: break;
  case 0xEE: break;
  case 0xEF: break;
  case 0xF0: break;
  case 0xF1: break;
  case 0xF2: break;
  case 0xF3: break;
  case 0xF5: break;
  case 0xF6: break;
  case 0xF7: break;
  case 0xF8: break;
  case 0xF9: break;
  case 0xFA: break;
  case 0xFB: break;
  case 0xFE: break;
  case 0xFF: break;
  default:
    throw std::invalid_argument("instruction not implemented: " + (int)instruction); 
    break;
	}
}

void Cpu::ExecuteTwoByteInstruction(Word instruction) {
  //todo CB prefix instructions
}