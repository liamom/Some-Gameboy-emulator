#include "word.h"

int to_int(Word w) {
  return w;
};

int to_int(Word_16 w) {
  return w;
};

char* get_char_ptr(Word &w) {
  return reinterpret_cast<char*>(&w);
};