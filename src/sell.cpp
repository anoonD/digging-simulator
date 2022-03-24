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


    // Exits function if user has not items
    if(bag.size() == 0) {
        fmt::print(COL_BOLD_YELLOW, "You have no items!\n");
        sleep(read_speed);
        return;
    }
    else {
        // Prints user item inventory
        fmt::print(COL_BOLD_BLUE, "Pick Item to Sell\n\n");
        for(int i=0; i<bag.size(); i++) {
            fmt::print(COL_BOLD_BLUE, "{}: {}", i+1, bag[i].name);
            engine::pad(bag[i].name.size(), 20);
            fmt::print(COL_BOLD_BLUE, "${}\n", bag[i].cost);
        }
        fmt::print(COL_BOLD_BLUE, "q: go back\n");
        
        fmt::print(">> ");
        std::cin >> input;
        int input_num = atoi(input.c_str()); // "Casting" user number to integer

        if(input == "q") return;
        else if(input == "a") { // Adds cost of all items and displays them
            int total = 0;
            for(int i=0; i<bag.size(); i++) {
                total += bag[i].cost;
            }
            fmt::print(COL_BOLD_YELLOW, "\n+${}\n", total);
            bal += total;
            bag.clear();
            sleep(read_speed);
        }
        else if(input_num > 0 && input_num <= bag.size()) { // Checks if user input is valid
            fmt::print(COL_BOLD_YELLOW, "\n+{}\n", bag[input_num - 1].cost);

            bal += bag[input_num -1 ].cost;
            bag.erase(bag.begin() + input_num - 1 );
            sleep(read_speed);
        }
        else {
            fmt::print(COL_BOLD_YELLOW, "Invalid Input\n");
            sleep(read_speed);
        }
    }
}