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
  void ExecuteInstruction(Word instruction);
  void ExecuteTwoByteInstruction(Word instruction);

private:
  inline void Decrement(Word &reg);
  inline void Increment(Word &reg);
  inline void Add(Word &reg1, const Word &reg2);
  inline void Double(Word &reg);
  inline void AddWithCarry(Word &reg1, const Word &reg2);
  inline void DoubleWithCarry(Word &reg);
  inline void Subtract(Word &reg1, const Word &reg2);
  inline void SubtractSelf(Word &reg1);
  inline void SubtractWithCarry(Word &reg1, const Word &reg2);
  inline void And(Word &reg1, const Word &reg2);
  inline void Xor(Word &reg1, const Word &reg2);
  inline void Or(Word &reg1, const Word &reg2);
  inline void Compare(const Word &reg1, const Word &reg2);
private:
  Cartridge cart_;
  Memory    memory_;
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
    };
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
  int cpu_ticks = 0; //not sure yet
};

#endif // CPU_H
