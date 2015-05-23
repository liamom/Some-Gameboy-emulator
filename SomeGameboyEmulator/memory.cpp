#include "memory.h"


memory::memory(cartridge cart_rom): PC(0x100),
                                   SP(0xFFFE)
{
    switch(cart_rom[cartridge::key_mem_locations::type]){
    case cartridge::cart_type::ROM_ONLY:
        break;
    }

}
memory::~memory()
{
    //dtor
}
