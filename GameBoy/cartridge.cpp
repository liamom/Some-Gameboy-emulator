#include "cartridge.h"

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


cartridge::cartridge(string filename){
    load_cart(filename);
}


void cartridge::load_cart(string filename){
     streampos size;

    ifstream file (filename, ios::in|ios::binary|ios::ate);
    if (file.is_open()){
        size = file.tellg();
        resize(size);
        file.seekg (0, ios::beg);
        file.read (data(), size);
        file.close();
    }
    else cout << "Unable to open file";
}

void cartridge::dump_header_data(){
    cout << "Game Title: " << get_name() << endl;
    cout << "GBC: " << (int) (*this)[is_gbc] << endl;
	cout << "Cart Type: " << (int)(*this)[type] << endl;
	cout << "Rom Size: " << (int)(*this)[rom_size] << endl;
	cout << "Ram Size: " << (int)(*this)[ram_size] << endl;
}

void cartridge::dump_nintendo_grapic(){
    for(int i = 0x0104; i <0x0134;i++){

        if (i-0x104 % 16 == 0){
            cout << '\n';
        }
		cout << hex << setw(4) << (unsigned int)(*this)[i] << ' ';
    }
}
string cartridge::get_name(){
    string output;

    for (int i =  game_title; i < game_title + 16 ; i++){
		output += (*this)[i];
    }

    return output;
}

cartridge::~cartridge()
{
    //dtor
}