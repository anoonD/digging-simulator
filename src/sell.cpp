#include "engine.h"

void engine::sell() {
    std::string input;
    system("clear");
    printf(
            "~~~~~~~~~~~\n"
            "| S E L L | Type \"a\" to sell all items\n"
            "~~~~~~~~~~~\n\n"
    );


    if(bag.size() == 0) {
        printf("You have no items!\n");
        usleep(read_speed);
    }
    else {
        printf("Pick Item to Sell\n\n");
        for(int i=0; i<bag.size(); i++) {
            printf("%d: %s\t\t%d\n", i+1, bag[i].name.c_str(), bag[i].sell_cost);
        }
        printf(">> ");
        std::cin >> input;
        int input_num = atoi(input.c_str());


        if(input == "a") {
            int total = 0;
            for(int i=0; i<bag.size(); i++) {
                total += bag[i].sell_cost;
            }
            printf("\n+$%d\n", total);
            bal += total;
            bag.clear();
            usleep(read_speed);
        }
        else if(input_num > 0 && input_num <= bag.size()) {
            printf("\n+$%d\n", bag[input_num - 1].sell_cost);

            bal += bag[input_num -1 ].sell_cost;
            bag.erase(bag.begin() + input_num - 1 );
            usleep(read_speed);
        }
        else {
            printf("Invalid Input\n");
            usleep(read_speed);
        }
    }
}