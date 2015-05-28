#ifndef CPU_H
#define CPU_H

#include <array>
#include <bitset>

#include "cartridge.h"
#include "memory.h"
#include "registers.h"

using namespace std;

class cpu
{
    public:
		cpu(string filename);
		cpu(cartridge &cart);
        virtual ~cpu();
    protected:
		void execute_instruction(char instruction);
		void ld_reg_to_reg(register_name a, register_name b);
		void ld_mem_to_reg(register_name location, register_name_16 register_with_address);
		void ld_reg_to_mem(register_name_16 register_with_address, register_name value);
    private:
		cartridge cart_;
		memory mem_;
		registers reg_;

		#include "opcodes_enum.h";

		//TODO
		enum prefix_cb{};
};

#endif // CPU_H
