#include "memory.h"

Word_16& Memory::read_word_16(Word_16 address) {
  return reinterpret_cast<Word_16&>(mem_data_[address]);
};

Word& Memory::read_byte(const Word_16 index) { 
  return mem_data_[index]; 
};

void Memory::write_byte(const Word_16 address, Word data) {
  mem_data_[address] = data;
}

void Memory::write(const Word_16 address, Word_16 data) {
  read_word_16(address) = data;
}