#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unistd.h>

#define dig_time 1000000
#define read_speed 2000000

class engine
{
private:
    // Struct to hold name and sell cost
    struct Item {
        std::string name;
        int sell_cost;
    };

    std::vector<Item> bag; // User inventory

    int bal{0}, // Balance
        xp{0}, // Experience
        level{0}, // Level
        max_inv{4}; // Max Inventory Space

    Item rewards[10] = {
            {"Bottle Cap", 5},        // 0  Common 60%
            {"Shoe", 10},             // 1
            {"Can", 10},              // 2
            {"Candy Wraper", 10},     // 3
            {"Animal Skull", 20},     // 4
            {"Car Tire", 50},         // 5  Uncommon 35%
            {"Metal Scraps", 100},    // 6
            {"Trident", 200},         // 7
            {"Dinosaur Bone", 500},   // 8  Rare 5%
            {"Diamond", 1000},        // 9
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
};