#include "engine.h"

engine::engine() {
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
        fmt::print("{}{}{}",COL_RED, rocket, COL_RESET);
        usleep(200000);
        system("clear");
    }
    fmt::print("You have arrived.\n");
    usleep(read_speed);
}