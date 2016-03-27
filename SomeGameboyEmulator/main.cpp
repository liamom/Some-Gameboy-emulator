#include <iostream>
#include <fstream>
#include <memory>

#include <cpu.h>


using namespace std;

int main()
{
  string cartridge_path = "../roms/alleyway (jua).gb";
  Cartridge test;
  if (!test.load_cart(cartridge_path))
  {
    cout << "Unable to open file";
  }
  else
  {
    test.dump_header_data(cout);
    test.dump_nintendo_grapic(cout);
    Cpu processorTest(test);
  }

	//Keep the console open after run.
	char a;
	cin >> a;
}
