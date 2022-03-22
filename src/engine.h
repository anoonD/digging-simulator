#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>

#include "../include/fmt/include/fmt/color.h"

#define dig_time 1000000
#define read_speed 500000

#define COL_BOLD_BROWN fg(fmt::rgb(161, 136, 127)) | fmt::emphasis::bold
#define COL_BOLD_BLUE fg(fmt::rgb(164, 186, 220)) | fmt::emphasis::bold 
#define COL_BOLD_YELLOW fg(fmt::rgb(237, 184, 98)) | fmt::emphasis::bold 
#define COL_BOLD_RED fg(fmt::rgb(239, 83, 80)) | fmt::emphasis::bold

class engine
{
private:
    // Struct to hold name and sell cost
    struct Item {
        std::string name;
        int cost;
        int modifier; // XP in case of reward items, DIG SPEED in case of shovel items
        std::string description;
    };

    Item shovel_item = {"Dirt Shovel", 0, 0, "How does this even work?"};

    std::vector<Item> bag; // User inventory

    int bal{0}, // Balance
        xp{0}, // Experience
        level{0}, // Level
        max_inv{4}; // Max Inventory Space

    Item rewards[3][4] = {
        {   {"Bottle Cap", 5, 10, ""},        // 0  Common 60%
            {"Shoe", 10, 10, ""},             // 1
            {"Can", 10, 10, ""},              // 2
            {"Candy Wraper", 10, 10, ""},     // 3
        },
        {
            {"Animal Skull", 20, 20, ""},     // 0 Uncommon 35%
            {"Car Tire", 50, 30, ""},         // 1 
            {"Metal Scraps", 100, 20, ""},    // 2
            {"Trident", 150, 20, ""},         // 3
        },
        {
            {"Engine Parts", 200, 30, ""},      // 0 Rare 5%
            {"Machine Gun Scraps", 250, 30, ""},// 1
            {"Dinosaur Bone", 500, 30, ""},     // 2
            {"Diamond", 1000, 30, ""},          // 3
        }
    };

    std::vector<std::vector<Item>> shop{
    {
        {"Backpack", 500, 0, "Adds +1 inventory slot to your backpack"},
    },
    {
        {"Copper Shovel", 500, 5,       "5% Speed Boost"},
        {"Iron Shovel", 1000, 20,       "20% Speed Boost"},
        {"Diamond Shovel", 10000, 30,   "30% Speed Boost"},
        {"Uranium Shovel", 20000, 70,   "70% Speed Boost"},
        {"Dragon Shovel", 30000, 90,    "90% Speed Boost"},
    }
    };

public:
    engine();
    ~engine();

    static void init();
    void menu();
    void dig();
    void sell();
    void buy();

    int getBagSize() { return bag.size(); }
    int getMaxInv() { return max_inv; }

    static inline void clear();

    /* Getters and setters */
    void setBalance(int b) { bal=b; } 

private: // Private Functions
    Item randomPicker();
    static inline void pad(int sizeOfWord, int totalSpaces);
    void printShopItem(int index);
};

inline void engine::pad(int sizeOfWord, int totalSpaces) {
    for(int x=0; x<abs(totalSpaces-sizeOfWord); x++) { // This adds a padding to the costs so that they appear in a 
        fmt::print(" ");                        // table-like fashon, the 20 is the number of spaces used for padding                            
    }
}

inline void engine::clear() {
    int x = system("clear");
    if(x != 0) {
        fmt::print("An error occured with the clear function.\n");
        exit(1);
    }
}