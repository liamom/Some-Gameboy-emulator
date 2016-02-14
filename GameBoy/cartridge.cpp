#include "Cartridge.h"

#include <vector>
#include <ostream>
#include <fstream>

Cartridge::Cartridge(std::string filename){
  load_cart(filename);
}

bool Cartridge::load_cart(std::string filename){
  std::ifstream file (filename, std::ios::in| std::ios::binary| std::ios::ate);
  if (file.is_open())
  {
    std::streampos size   = file.tellg();
    int64_t int_size = size.seekpos();
    data_.resize(int_size);
    file.seekg (0, std::ios::beg);
    file.read (reinterpret_cast<char*>(data_.data()), size);
    file.close();

    return true;
  }
  else
  {
    return false;
  }
}

void Cartridge::dump_header_data(std::ostream& stream){
  stream << "Game Title: " << get_name()                       << std::endl
         << "GBC: "        << (unsigned int)get(key_mem_locations::is_gbc)   << std::endl
	       << "Cart Type: "  << (unsigned int)get(key_mem_locations::type)     << std::endl
	       << "Rom Size: "   << (unsigned int)get(key_mem_locations::rom_size) << std::endl
	       << "Ram Size: "   << (unsigned int)get(key_mem_locations::ram_size) << std::endl;
}

void Cartridge::dump_nintendo_grapic(std::ostream& stream){
  for(int i = 0x0104; i <0x0134;i++){

    if (i - 0x104 % 16 == 0){
      stream << '\n';
    }
    stream << std::hex << std::setw(4) << (unsigned int)data_[i] << ' ';
  }
}
std::string Cartridge::get_name(){
  size_t index = static_cast<size_t>(key_mem_locations::game_title);
  char *char_pointer = reinterpret_cast<char*>(&data_[index]);
  std::string output(char_pointer, 16);
  return output;
}