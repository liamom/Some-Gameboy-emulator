#ifndef MEMORY_H
#define MEMORY_H

#include <array>
#include "cartridge.h"

using namespace std;

class Memory
{
  public:
    Memory(Cartridge &cart_rom);
    virtual ~Memory();

		char& operator[](long index){ return mem_data_[index]; };
  protected:
  private:
    static const int mem_size_ = 65536;
    array<char,mem_size_> mem_data_;

    // char* mem_data[];

};

#endif // MEMORY_H
