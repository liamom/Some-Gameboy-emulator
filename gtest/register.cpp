#include <gtest\gtest.h>
#include <registers.h>



TEST(register_test, getters_and_setters)
{
  Registers reg;
  reg.set(Registers::A, 5);
  char a = reg.get(Registers::A);
  ASSERT_EQ(a, 5);

  short af = reg.get(Registers::AF);

  ASSERT_EQ(af, 1280);
}