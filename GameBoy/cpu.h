#ifndef CPU_H
#define CPU_H

#include <array>
#include <bitset>

#include "cartridge.h"
#include "memory.h"

class Cpu
{
public:
  Cpu(std::string filename);
  Cpu(Cartridge &cart);
protected:
  void ExecuteInstruction(char instruction);

private:
  Cartridge cart_;
  Memory    m_;
  union {
    struct {
      //In oposite order because the least significant byte is first
      Word F;
      Word A;

      Word C;
      Word B;

      Word E;
      Word D;

      Word L;
      Word H;
    };
    struct {
      Word_16 AF;
      Word_16 BC;
      Word_16 DE;
      Word_16 HL;
    } size_16;
  } registers_;

  struct {
    bool zero;
    bool subtract;
    bool half_carry;
    bool carry;
  } flags_;
  
  struct {
    Word_16 m;
    Word_16 t;
  } clock_, last_instr_clock_;
  
  Word_16 PC_ = 0x100;  //program counter
  Word_16 SP_ = 0xFFFE; //stack pointer
};

#endif // CPU_H
