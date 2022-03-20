#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>

#include "../include/fmt/include/fmt/color.h"

#define dig_time   200000
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
        int sell_cost;
        int xp_item;
    };

    std::vector<Item> bag; // User inventory

    int bal{0}, // Balance
        xp{0}, // Experience
        level{0}, // Level
        max_inv{4}; // Max Inventory Space

    Item rewards[3][4] = {
        {   {"Bottle Cap", 5, 10},        // 0  Common 60%
            {"Shoe", 10, 10},             // 1
            {"Can", 10, 10},              // 2
            {"Candy Wraper", 10, 10},     // 3
        },
        {
            {"Animal Skull", 20, 20},     // 0 Uncommon 35%
            {"Car Tire", 50, 30},         // 1 
            {"Metal Scraps", 100, 20},    // 2
            {"Trident", 150, 20},         // 3
        },
        {
            {"Engine Parts", 200, 30},      // 0 Rare 5%
            {"Machine Gun Scraps", 250, 30},// 1
            {"Dinosaur Bone", 500, 30},     // 2
            {"Diamond", 1000, 30},          // 3
        }
    };

public:
    engine();
    ~engine();

    static void init();
    void menu();
    void dig();
    void sell();

    int getBagSize() { return bag.size(); }
    int getMaxInv() { return max_inv; }

    static inline void clear();
private:
    Item randomPicker();
};

inline void engine::clear() {
    int x = system("clear");
    if(x != 0) {
        fmt::print("An error occured with the clear function.\n");
        exit(1);
    }
}