#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>

#include "..\GameBoy\cpu.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace gameboy_test
{
	TEST_CLASS(registers_test)
	{
	public:
		registers reg_;

		TEST_CLASS_INITIALIZE(setup){
		}

		TEST_METHOD(registers_test_1){
			bool pc_test = reg_.get_pc() == 0x100;
			bool sp_test = reg_.get_sp() == 0xFFFE;

			Assert::IsTrue(pc_test && sp_test);
		}

		TEST_METHOD(registers_test_set_reg){
			reg_.set(A, 0xfd);
			Assert::AreEqual(reg_.get(A), (unsigned char)0xfd);
		}

		TEST_METHOD(registers_test_set_double_reg){
			reg_.set(HL, 0xfff0);
			auto var = reg_.get(HL);
			Assert::IsTrue(reg_.get(HL) == (unsigned short)0xfff0);
		}

		TEST_METHOD(registers_test_get_double_reg){
			reg_.set(D, 0xff);
			reg_.set(E, 0xaf);
			Assert::IsTrue(reg_.get(DE) == (unsigned short)0xffaf);
		}

	};
}