#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class cartridge
{
    public:
        vector<char> cart_data_;
        cartridge(string filename);
        string get_name();
        void dump_header_data();
        //string cart_title();
        virtual ~cartridge();
        void load_cart(string filename);
        char inline operator[](int location){return cart_data_[location];}
        void dump_nintendo_grapic();
        enum cart_type {
            ROM_ONLY = 0X0,
            ROM_MBC1 = 0X1,
            ROM_MBC1_RAM = 0X2,
            ROM_MBC1_RAM_BATT = 0X3,
            ROM_MBC2 = 0X5,
            ROM_MBC2_BATTERY = 0X6,
            ROM_RAM = 0X8,
            ROM_RAM_BATTERY = 0X9,
            ROM_MBC3_RAM = 0X12,
            ROM_MBC3_RAM_BATT = 0X13,
            ROM_MBC5 = 0X19,
            ROM_MBC5_RAM = 0X1A,
            ROM_MBC5_RAM_BATT = 0X1B,
            ROM_MBC5_RUMBLE = 0X1C,
            ROM_MBC5_RUMBLE_SRAM = 0X1D,
            ROM_MBC5_RUMBLE_SRAM_BATT = 0X1E,
            ROM_MMM01 = 0XB,
            Pocket_Camera = 0X1F,
            ROM_MMM01_SRAM = 0XC,
            Bandai_TAMA5 = 0XFD,
            ROM_MMM01_SRAM_BATT = 0XD,
            Hudson_HuC_3 = 0XFE
        };
        enum key_mem_locations{
            game_title = 0x0134,
            is_gbc     = 0x0143,
            type = 0x0147,
            rom_size   = 0x0148,
            ram_size   = 0x0149
        };

    protected:
    private:
};

#endif // CARTRIDGE_H
