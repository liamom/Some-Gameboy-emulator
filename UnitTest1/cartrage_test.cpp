#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\GameBoy\cpu.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace gameboy_test
{		
	TEST_CLASS(cartrage_test)
	{
	public:
		
		TEST_METHOD(cartridge_test)
		{
			cartridge cart("../roms/alleyway (jua).gb");
			Assert::IsTrue(cart.size() > 0);
			string alleyway_name = cart.get_name();
			Assert::IsTrue(cart.get_name() == alleyway_name);
		}
	};
}