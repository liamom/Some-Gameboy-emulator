#ifndef CPU_H
#define CPU_H

#include <array>
#include <bitset>

#include "cartridge.h"
#include "memory.h"
#include "registers.h"

using namespace std;

class Cpu
{
public:
  Cpu(string filename);
  Cpu(Cartridge &cart);
  virtual ~Cpu();
protected:
  void execute_instruction(char instruction);
  void ld_reg_to_reg(Registers::register_name a, Registers::register_name b);
  void ld_mem_to_reg(Registers::register_name location, Registers::register_name_16 register_with_address);
  void ld_reg_to_mem(Registers::register_name_16 register_with_address, Registers::register_name value);
private:
  Cartridge cart_;
  Memory    mem_;
  Registers reg_;
     
  #include "opcodes_enum.h";

  //TODO
  enum prefix_cb{};
};

#endif // CPU_H
