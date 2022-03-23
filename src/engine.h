#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>

#include "fmt/color.h"

#define dig_time 1000000
#define read_speed 500000

#define vec std::vector

#define COL_BOLD_BROWN fg(fmt::rgb(161, 136, 127)) | fmt::emphasis::bold
#define COL_BOLD_BLUE fg(fmt::rgb(164, 186, 220)) | fmt::emphasis::bold 
#define COL_BOLD_YELLOW fg(fmt::rgb(237, 184, 98)) | fmt::emphasis::bold 
#define COL_BOLD_RED fg(fmt::rgb(239, 83, 80)) | fmt::emphasis::bold

class engine
{
private: // Private Variables

    int bal, // Balance
        xp, // Experience
        level, // Level
        max_inv; // Max Inventory Space

    // Struct to hold name and sell cost
    struct Item {
        std::string name;
        int cost;
        int modifier; // XP in case of reward items, DIG SPEED in case of shovel items
        std::string description;
    };

    Item shovel_item;
    vec<Item> bag; // User inventory

    vec<vec<Item>> rewards,
        shop;

public: // Public Functions
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