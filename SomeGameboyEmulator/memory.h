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
        static const int mem_size = 65536;
        array<char,mem_size> mem_data;
        bitset<8> flag_reg;
        char A,B,C,D,E,F,L,H;
        unsigned short PC, SP;
        // char* mem_data[];

};

#endif // MEMORY_H
