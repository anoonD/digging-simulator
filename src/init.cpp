#include "engine.h"
#include "fmt/color.h"

engine::engine() {
    bal = 0; // Balance
    xp = 0; // Experience
    level = 0; // Level
    max_inv = 4; // Max Inventory Space

    shovel_item = {"Dirt Shovel", 0, 0, "How does this even work?"};

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

    shop = {
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
}

engine::~engine() {
}

void engine::init() {
    int x = 15; // Number of newlines
    std::string rocket =
            "   /‾‾\\   \n"
            "   |  |    \n"
            "   |  |    \n"
            "  /|  |\\  \n"
            " / |  | \\ \n"
            "/__|__|__\\\n"
            "  /----\\  \n"
            "  ------   \n";

    while(true) {
        x -= 1;
        if(x < 1) break;

        fmt::print("You Settle On The Journey To The Digging Planet, Earth...");
        for(int i=0; i<x; i++) fmt::print("\n");
        fmt::print(fg(fmt::rgb(106, 123, 131)) | fmt::emphasis::bold, "{}", rocket);
        usleep(200000);
        engine::clear();
    }
    fmt::print("You have arrived.\n");
    usleep(1000000);
}