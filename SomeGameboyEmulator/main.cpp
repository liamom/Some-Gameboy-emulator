#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "../GameBoy/cpu.h"

using namespace std;

int main()
{
	string cartridge_path = "../roms/alleyway (jua).gb";
	cartridge test(cartridge_path);
    test.dump_header_data();

	cpu processorTest(test);

	//Keep the console open after run.
	char a;
	cin >> a;
}
