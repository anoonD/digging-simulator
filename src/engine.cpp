#include "engine.h"
#include "fmt/color.h"

engine::engine() {
    bal = 0; // Balance
    xp = 0; // Experience
    level = 0; // Level
    max_inv = 4; // Max Inventory Space

    shovel_item = {"Dirt Shovel", 0, 0, "How does this even work?"};

    // In this case, the third field, modifier, is used for storing the XP of each reward
    rewards = {
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

    // In here, the third field, modifier, is used for storing the digging speed percentage
    // The reason for using a 2D vector is to be able to make menus based on the categories of the items
    shop = {
        {
            {"Backpack", 500, 0, "Adds +1 inventory slot to your backpack"},
        },
    {
            {"Copper Shovel",   500,    5,  "5% Speed Boost"},
            {"Iron Shovel",     1000,   20, "20% Speed Boost"},
            {"Diamond Shovel",  10000,  30, "30% Speed Boost"},
            {"Uranium Shovel",  20000,  70, "70% Speed Boost"},
            {"Dragon Shovel",   30000,  90, "90% Speed Boost"},
        }
    };
}

engine::~engine() {
}

void engine::pad(int sizeOfWord, int totalSpaces) {
    for(int x=0; x<abs(totalSpaces-sizeOfWord); x++) {  // This adds a padding to the costs so that they appear in a 
        fmt::print(" ");                                // table-like fashon, the totalSpaces is the number of spaces used for padding                            
    }
}

void engine::clear() {
    int x = system("clear");

    if(x != 0) { // Exits is for some reason the clear command fails
        fmt::print("An error occured with the clear function.\n");
        exit(1); 
    }
}

void engine::init() {
    int x = 15; // Number of newlines
    // Prints rocket animation
    while(true) {
        x -= 1;
        if(x < 1) break;

        fmt::print("You Settle On The Journey To The Digging Planet, Earth...");        
        for(int i=0; i<x; i++) fmt::print("\n");                                        
        fmt::print(fg(fmt::rgb(106, 123, 131)) | fmt::emphasis::bold, "{}",
            "   /‾‾\\   \n"
            "   |  |    \n"
            "   |  |    \n"
            "  /|  |\\  \n"
            " / |  | \\ \n"
            "/__|__|__\\\n"
            "  /----\\  \n"
            "  ------   \n");
        
        sleep(200);
        engine::clear();
    }
    fmt::print("You have arrived.\n");
    sleep(1000);
}