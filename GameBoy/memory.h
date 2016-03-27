#ifndef MEMORY_H
#define MEMORY_H

#include <array>
#include "cartridge.h"

class Memory
{
public:
  Word_16& read_word_16(Word_16 address) {
    return reinterpret_cast<Word_16&>(mem_data_[address]);
  };
  Word& read_byte(Word_16 index) { return mem_data_[index]; };
  void write_byte(Word_16 address, Word data) {
    mem_data_[address] = data;
  }

  void write(Word_16 address, Word_16 data) {
    read_word_16(address) = data;
  }

  //Word& operator[](Word_16 index){ return read_byte(index); };

private:
  static const int      mem_size_ = 65536;
  std::array<Word,mem_size_> mem_data_;
};

#endif // MEMORY_H
