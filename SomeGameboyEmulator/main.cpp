#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "cartridge.h"

using namespace std;

int main()
{
    cartridge test("alleyway (jua).gb");
    test.dump_header_data();
    test.dump_nintendo_grapic();//

	//Keep the console open after run.
	char a;
	cin >> a;
}
