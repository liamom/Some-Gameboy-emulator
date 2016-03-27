#ifndef WORD_H
#define WORD_H

#include <stdint.h>
#include <ostream>
#include <assert.h>

typedef uint8_t  Word;
typedef uint16_t Word_16;

static_assert(sizeof(Word) == 1, "Word must be 1 byte");
static_assert(sizeof(Word_16) == 2, "Word_16 must be 2 byte");

template<class num_type>
bool get_bit(num_type w, char bit) {
  assert(bit >= 0 && bit <= (sizeof(num_type) * 8));
  return value_ & (1 << bit);
}

int to_int(Word w);
int to_int(Word_16 w);
char* get_char_ptr(Word &w);

#endif