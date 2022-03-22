#include "engine.h"

void engine::buy() {
    std::string input;
    engine::clear();
    fmt::print( COL_BOLD_BROWN,
            "~~~~~~~~~~~\n"
            "| S H O P |\n"
            "~~~~~~~~~~~\n"
    );
    fmt::print("{} ${}\n\n", fmt::styled("Balance:", COL_BOLD_BROWN), bal);

    fmt::print(COL_BOLD_BLUE,
            "1: Backpack Upgrades\n"
            "2: Shovel Upgrades\n"
            "q: go back\n");
    
    fmt::print("\n>> ");
    std::cin >> input;

    if(input == "1") {
        for(int i=0; i<shop[0].size(); i++) {
            fmt::print(COL_BOLD_BLUE, "{}: {}", i+1, shop[0][i].name);
            engine::pad(shop[0][i].name.size(), 20);
            fmt::print(COL_BOLD_BLUE, "{}", shop[0][i].description);
            engine::pad(shop[0][i].description.size(), 10);
            fmt::print(COL_BOLD_BLUE, "${}\n", shop[0][i].cost);
        }
        fmt::print("\n>> ");
        std::cin >> input;
        int input_num = atoi(input.c_str());

        if (input_num > 0 && input_num <= shop[0].size()) {
            max_inv++;
            fmt::print(COL_BOLD_YELLOW, "Purchased {}\n", shop[0][input_num-1].name);
            usleep(read_speed);
        }
        else {
            fmt::print(COL_BOLD_YELLOW, "Invalid Input\n");
            usleep(read_speed);
        }
    }
    else if(input == "2") {
        for(int i=0; i<shop[1].size(); i++) {
            fmt::print(COL_BOLD_BLUE, "{}: {}", i+1, shop[1][i].name);
            engine::pad(shop[1][i].name.size(), 20);
            fmt::print(COL_BOLD_BLUE, "{}", shop[1][i].description);
            engine::pad(shop[1][i].description.size(), 10);
            fmt::print(COL_BOLD_BLUE, "${}\n", shop[1][i].cost);
        }
        
        fmt::print("\n>> ");
        std::cin >> input;
        int input_num = atoi(input.c_str());
        
        if (input_num > 0 && input_num <= shop[1].size()) {
            shovel_item = shop[1][input_num-1];
            fmt::print(COL_BOLD_YELLOW, "Purchased {}\n", shop[1][input_num-1].name);
            usleep(read_speed);
        }
        else {
            fmt::print(COL_BOLD_YELLOW, "Invalid Input\n");
            usleep(read_speed);
        }
    }
    else if(input == "q") return;
    else {
       fmt::print(COL_BOLD_YELLOW, "Invalid Input\n");
        usleep(read_speed);
    }
}