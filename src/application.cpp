#include "engine.h"

int main(int argc, char **argv) {
    engine x;
    std::string choice;

     engine::init();
    while(true) {
        x.menu();
        std::cin >> choice;

        if(choice == "1") {
            if(x.getBagSize() < x.getMaxInv()) {
                x.dig();
            }
            else {
                printf("Inventory Full.  Sell some items to free up space.\n");
                usleep(read_speed);
            }
        }
        else if(choice == "2") x.sell();
        else if (choice == "q") break;
        else {
            printf("Invalid Input\n");
            usleep(read_speed);
        }
    }
}
