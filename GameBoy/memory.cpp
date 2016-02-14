#include "memory.h"


Memory::Memory(Cartridge &cart_rom)
{
    switch(cart_rom[Cartridge::key_mem_locations::type]){
    case Cartridge::cart_type::ROM_ONLY:
        break;
    }

}
Memory::~Memory()
{
    //dtor
}
