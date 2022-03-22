#include <fmt/color.h>
#include <chrono>
#include <thread>
#include <iostream>

#define STEP 5
#define TIME 200
#define ROWS 10
#define COLS 10

inline void clear() {
    int x = system("clear");
    if(x != 0) {
        fmt::print("An error occured with the clear function.\n");
        exit(1);
    }
}

void increment(int &color, int &step) {
    if(color+step >= 255) {
        step = -step;
    }
    else if(color-abs(step) <= step) {
        color=2*abs(step);
        step = -step;
    }

    color += step;

}

int main() {
    int r{0}, g{125}, b{255},
    rstep{STEP}, gstep{STEP}, bstep{STEP};
    // std::string symbol = "██";
    std::string symbol = "HH";

    while(true) {
        increment(r, rstep);
        increment(g, gstep);
        increment(b, bstep);

        fmt::print(
            "r: {}\n"
            "g: {}\n"
            "b: {}\n", r, g, b);

        for(int x=0; x<ROWS; x++) {
            for(int y=0; y<COLS; y++) {
                fmt::print(fg(fmt::rgb(r, g, b)), "{}", symbol);
            }
            fmt::print("\n");
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(TIME));

        clear();
    }
}