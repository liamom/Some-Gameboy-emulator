#ifndef MEMORY_H
#define MEMORY_H

#include <array>
#include "cartridge.h"

class Memory
{
public:
  Word_16& read_word_16(Word_16 address);
  Word& read_byte(const Word_16 index);
  void write_byte(const Word_16 address, Word data);
  void write(const Word_16 address, Word_16 data);
  //Word& operator[](Word_16 index){ return read_byte(index); };

private:
  static const int mem_size_ = 65536;
  std::array<Word,mem_size_> mem_data_;
};

#endif // MEMORY_H
