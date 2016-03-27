#include <gtest\gtest.h>
#include <cpu.h>



TEST(register_test, getters_and_setters){
  //Cpu cpu;
  //reg.set(Registers::A, 5);
  //char a = reg.get(Registers::A);
  //ASSERT_EQ(a, 5);
  //
  //short af = reg.get(Registers::AF);
  //
  //ASSERT_EQ(af, 1280);
}

TEST(memory_test, 16_bit_data) {
  Memory m;
  m.write_byte(0x0, 0);
  m.write_byte(0x1, 0);
  ASSERT_EQ(m.read_byte(0), 0);
  ASSERT_EQ(m.read_byte(1), 0);
  ASSERT_EQ(m.read_word_16(0), 0);

  m.write(0x0, 0xFFF);
  ASSERT_EQ(m.read_byte(0x0), 0xFF);
  ASSERT_EQ(m.read_byte(0x1), 0xF);
  ASSERT_EQ(m.read_word_16(0x0), 0xFFF);

  m.write_byte(2, 0xF);
  ASSERT_EQ(m.read_word_16(0x1), 0xF0F);
}

TEST(union_test, test_register_system) {
  union {
    struct {
      //In oposite order because the least significant byte is first
      Word F;
      Word A;
      
      Word C;
      Word B;
      
      Word E;
      Word D;
      
      Word L;
      Word H;
    };
    struct {
      Word_16 AF;
      Word_16 BC;
      Word_16 DE;
      Word_16 HL;
    } size_16;
  } r;

  r.B = 243;
  r.C = 758;
  ASSERT_EQ(r.size_16.BC, (r.B << 8) | r.C);
}