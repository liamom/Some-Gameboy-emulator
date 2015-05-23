#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "cartridge.h"

using namespace std;

int main()
{
    cartridge test("roms/alleyway (jua).gb");
    test.dump_header_data();

	//Keep the console open after run.
	char a;
	cin >> a;
}
