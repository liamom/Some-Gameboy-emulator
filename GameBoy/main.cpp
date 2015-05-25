#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "cartridge.h"
#include "cpu.h"

using namespace std;

int main()
{
	string cartrage_path = "../roms/alleyway (jua).gb";
	cartridge test(cartrage_path);
    test.dump_header_data();

	cpu processorTest(test);

	//Keep the console open after run.
	char a;
	cin >> a;
}
