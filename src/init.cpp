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

        printf("You Settle On The Journey To The Digging Planet, Earth...");
        for(int i=0; i<x; i++) printf("\n");
        printf("%s", rocket.c_str());
        usleep(200000);
        system("clear");
    }
    printf("You have arrived.\n");
    usleep(2000000);
}