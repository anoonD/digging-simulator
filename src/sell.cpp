#include "engine.h"

void engine::sell() {
    std::string input;
    engine::clear();
    fmt::print( COL_BOLD_BROWN,
            "~~~~~~~~~~~\n"
            "| S E L L | Type \"a\" to sell all items\n"
            "~~~~~~~~~~~\n"
    );
    fmt::print("{} ${}\n\n", fmt::styled("Balance:", COL_BOLD_BROWN), bal);

    if(bag.size() == 0) {
        fmt::print(COL_BOLD_YELLOW, "You have no items!\n");
        usleep(read_speed);
    }
    else {
        fmt::print(COL_BOLD_BLUE, "Pick Item to Sell\n\n");
        for(int i=0; i<bag.size(); i++) {
            fmt::print(COL_BOLD_BLUE, "{}: {}", i+1, bag[i].name);
            for(int x=bag[i].name.size(); x<20; x++) { // This adds a padding to the costs so that they appear in a table-like fashon, the 20 is the number of spaces used for padding
                fmt::print(" ");
            }
            fmt::print(COL_BOLD_BLUE, "${}\n", bag[i].cost);
        }
        fmt::print(COL_BOLD_BLUE, "q: go back\n");
        
        fmt::print(">> ");
        std::cin >> input;
        int input_num = atoi(input.c_str());

        if(input == "q") return;
        else if(input == "a") {
            int total = 0;
            for(int i=0; i<bag.size(); i++) {
                total += bag[i].cost;
            }
            fmt::print(COL_BOLD_YELLOW, "\n+${}\n", total);
            bal += total;
            bag.clear();
            usleep(read_speed);
        }
        else if(input_num > 0 && input_num <= bag.size()) {
            fmt::print(COL_BOLD_YELLOW, "\n+{}\n", bag[input_num - 1].cost);

            bal += bag[input_num -1 ].cost;
            bag.erase(bag.begin() + input_num - 1 );
            usleep(read_speed);
        }
        else {
            fmt::print(COL_BOLD_YELLOW, "Invalid Input\n");
            usleep(read_speed);
        }
    }
}