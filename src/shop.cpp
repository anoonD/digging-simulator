#include "engine.h"

void engine::printShopItem(int index) {
    for(int i=0; i<shop[index].size(); i++) {
        fmt::print(COL_BOLD_BLUE, "{}: {}", i+1, shop[index][i].name);
        engine::pad(shop[index][i].name.size(), 20);
        fmt::print(COL_BOLD_BLUE, "{}", shop[index][i].description);
        engine::pad(shop[index][i].description.size(), 20);
        fmt::print(COL_BOLD_BLUE, "${}\n", shop[index][i].cost);
    }
}

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
        printShopItem(0); // Prints Items

        fmt::print("\n>> ");
        std::cin >> input;
        int input_num = atoi(input.c_str());

        if (input_num > 0 && input_num <= shop[0].size()) {
            if(bal<shop[0][input_num-1].cost) {
                fmt::print(COL_BOLD_YELLOW, "Not enough money\n");
                sleep(read_speed);
                return;
            }

            max_inv++;
            fmt::print(COL_BOLD_YELLOW, "Purchased {}\n", shop[0][input_num-1].name);
            sleep(read_speed);
        }
        else {
            fmt::print(COL_BOLD_YELLOW, "Invalid Input\n");
            sleep(read_speed);
        }
    }
    else if(input == "2") {
        printShopItem(1); // Prints Items

        fmt::print("\n>> ");
        std::cin >> input;
        int input_num = atoi(input.c_str());
        
        if(bal<shop[0][input_num-1].cost) {
                fmt::print(COL_BOLD_YELLOW, "Not enough money\n");
                sleep(read_speed);
                return;
        }

        if (input_num > 0 && input_num <= shop[1].size()) {
            shovel_item = shop[1][input_num-1];
            fmt::print(COL_BOLD_YELLOW, "Purchased {}\n", shop[1][input_num-1].name);
            sleep(read_speed);
        }
        else {
            fmt::print(COL_BOLD_YELLOW, "Invalid Input\n");
            sleep(read_speed);
        }
    }
    else if(input == "q") return;
    else {
       fmt::print(COL_BOLD_YELLOW, "Invalid Input\n");
        sleep(read_speed);
    }
}