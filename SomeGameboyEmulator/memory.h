#ifndef MEMORY_H
#define MEMORY_H

#include <array>
#include <bitset>
#include "cartridge.h"

using namespace std;

class memory
{
    public:
        memory(cartridge cart_rom);
        virtual ~memory();
    protected:
    private:
        static const int mem_size_ = 65536;
        array<char,mem_size_> mem_data_;
        bitset<8> flag_reg_;
        char A_,B_,C_,D_,E_,F_,L_,H_;
        unsigned short PC_, SP_;
        // char* mem_data[];

};

#endif // MEMORY_H
