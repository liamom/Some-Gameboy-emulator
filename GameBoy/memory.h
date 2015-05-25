#ifndef MEMORY_H
#define MEMORY_H

#include <array>
#include "cartridge.h"

using namespace std;

class memory
{
    public:
        memory(cartridge &cart_rom);
        virtual ~memory();

		char& operator[](long index){ return mem_data_[index]; };
    protected:
    private:
        static const int mem_size_ = 65536;
        array<char,mem_size_> mem_data_;

        // char* mem_data[];

};

#endif // MEMORY_H
