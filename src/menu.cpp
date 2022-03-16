#include "engine.h"

void engine::menu() {
    system("clear");
    printf(
            "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            "| D I G G I N G - S I M U L A T O R |\n"
            "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
    );
    printf("Balance: $%d\n", bal);
    printf("XP: %d\n", xp);
    printf("Level: %d\n", level);
    printf("Bag: %ld/%d\n\n", bag.size(), max_inv);

    printf("1: Dig\n");
    printf("2: Sell\n");
    printf("\nq: Quit\n");

    printf("\n>> ");
}