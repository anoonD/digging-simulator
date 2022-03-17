#include "engine.h"

void engine::sell() {
    std::string input;
    system("clear");
    fmt::print(
            "~~~~~~~~~~~\n"
            "| S E L L | Type \"a\" to sell all items\n"
            "~~~~~~~~~~~\n\n"
    );


    if(bag.size() == 0) {
        fmt::print("You have no items!\n");
        usleep(read_speed);
    }
    else {
        fmt::print("Pick Item to Sell\n\n");
        for(int i=0; i<bag.size(); i++) {
            fmt::print("{}: {}\t\t{}\n", i+1, bag[i].name, bag[i].sell_cost);
        }
        fmt::print(">> ");
        std::cin >> input;
        int input_num = atoi(input.c_str());


        if(input == "a") {
            int total = 0;
            for(int i=0; i<bag.size(); i++) {
                total += bag[i].sell_cost;
            }
            fmt::print("\n+${}\n", total);
            bal += total;
            bag.clear();
            usleep(read_speed);
        }
        else if(input_num > 0 && input_num <= bag.size()) {
            fmt::print("\n+{}\n", bag[input_num - 1].sell_cost);

            bal += bag[input_num -1 ].sell_cost;
            bag.erase(bag.begin() + input_num - 1 );
            usleep(read_speed);
        }
        else {
            fmt::print("Invalid Input\n");
            usleep(read_speed);
        }
    }
}