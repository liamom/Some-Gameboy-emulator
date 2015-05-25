#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\GameBoy\cpu.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace gameboy_test
{
	TEST_CLASS(memory_test)
	{
	public:
		
		TEST_METHOD(memory_test_1)
		{
			cartridge cart("../roms/alleyway (jua).gb");
			memory mem(cart);

			Assert::IsTrue(true);
		}

	};
}