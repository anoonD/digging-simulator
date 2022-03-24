#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include "fmt/color.h"

/* Initial dig speed and read speed */
#define dig_time 1000
#define read_speed 500

/* Macros */
#define vec std::vector
#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

#define COL_BOLD_BROWN fg(fmt::rgb(161, 136, 127)) | fmt::emphasis::bold
#define COL_BOLD_BLUE fg(fmt::rgb(164, 186, 220)) | fmt::emphasis::bold 
#define COL_BOLD_YELLOW fg(fmt::rgb(237, 184, 98)) | fmt::emphasis::bold 
#define COL_BOLD_RED fg(fmt::rgb(239, 83, 80)) | fmt::emphasis::bold

class engine {
/* Instance Variables */
private:
    int bal,    // Balance
        xp,     // Experience
        level,  // Level
        max_inv; // Max Inventory Space

    // Struct used to hold name and sell cost
    struct Item {
        std::string name;
        int cost;
        int modifier; // XP in case of reward items, DIG SPEED in case of shovel items
        std::string description;
    };

    Item shovel_item;
    vec<Item> bag; // User inventory

    vec<vec<Item>> rewards; // 2d Vector containing digging rewards
    vec<vec<Item>> shop;    // 2d Vector containing shop items
/* Public Functions */
public:
    engine();
    ~engine();

    static void init(); // Rocket animation
    void menu(); // Main menu
    void dig();
    void sell();
    void buy();

    /* Getters and setters */
    int getBagSize() { return bag.size(); }
    int getMaxInv() { return max_inv; }
    void setBalance(int b) { bal=b; } 

/* Private Functions */
private:
    Item randomPicker(); // Used for picking random reward when digging

    void printShopItem(int index);  // Prints shop items
    static void clear(); // Clears the screen
    static void pad(int sizeOfWord, int totalSpaces); // Used to add format shop items
};