#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <fmt/color.h>
#include <unistd.h>
#include "color.h"

#define dig_time 1000000
#define read_speed 2000000

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
private:
    Item randomPicker();
};