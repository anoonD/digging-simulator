#include "engine.h"

void engine::dig() {
    Item item = randomPicker();  // Get random item

    std::string frame1 =
        "    \\                      \n"
        "     \\                     \n"
        "      \\                    \n"
        "       \\_____              \n"
        "       |    |              \n"
        "       |____|              \n"
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
        "###########################\n"
        "###########################\n"
        "###########################\n";

    std::string frame2 =
        "                           \n"
        "                     *     \n"
        "            /‾\\         *  \n"
        "   ________/   \\      *    \n"
        "           \\   /           \n"
        "            \\_/            \n"
        "~~~~      ~~~~~~~~~~~~~~~~~\n"
        "####      #################\n"
        "######   ##################\n"
        "###########################\n";

    std::string frame3 =
        "    \\                      \n"
        "     \\                     \n"
        "      \\                    \n"
        "       \\_____              \n"
        "       |    |         ###  \n"
        "       |____|        ######\n"
        "~~~~      ~~~~~~~~~~~~~~~~~\n"
        "####      #################\n"
        "######   ##################\n"
        "###########################\n";

    std::string frame4 =
        "                       *   \n"
        "                        *  \n"
        "            /‾\\      *     \n"
        "   ________/   \\           \n"
        "           \\   /      ###  \n"
        "            \\_/      ######\n"
        "~~~~        ~~~~~~~~~~~~~~~\n"
        "####        ###############\n"
        "###           #############\n"
        "###########################\n";

    std::string frame5 =
        "    \\                      \n"
        "     \\                     \n"
        "      \\                    \n"
        "       \\_____          #   \n"
        "       |    |       #####  \n"
        "       |____|      ########\n"
        "~~~~        ~~~~~~~~~~~~~~~\n"
        "####        ###############\n"
        "###           #############\n"
        "###########################\n";

    std::string frame6 =
        "                        *  \n"
        "                   *  *    \n"
        "            /‾\\          * \n"
        "   ________/   \\       #   \n"
        "           \\   /    #####  \n"
        "            \\_/    ########\n"
        "~~~~          ~~~~~~~~~~~~~\n"
        "####           ############\n"
        "###               #########\n"
        "###########################\n";

    std::string frame7 =
        "    \\                      \n"
        "     \\                     \n"
        "      \\                #   \n"
        "       \\_____        ###   \n"
        "       |    |       ###### \n"
        "       |____|    ##########\n"
        "~~~~          ~~~~~~~~~~~~~\n"
        "####           ############\n"
        "###               #########\n"
        "###########################\n";

    std::string shovel[7] = {frame1, frame2, frame3, frame4, frame5, frame6, frame7};

    /* Render Shovel Animation */
    system("clear");
    for(int i=0; i<6; i++) {
        printf("%s\n", shovel[i].c_str());
        usleep(dig_time);
        system("clear");
    }

    /* Render last shovel and notify player of found reward */
    printf("%s\nYou found a %s\n", shovel[6].c_str(), item.name.c_str());
    printf("+%d XP\n", item.xp_item);

    if(xp >= 100) {
        xp = (xp - 100);
        level += 1;
        printf("Level Up!\n");
    }

    bag.push_back(item);
    usleep(1000000);
}

engine::Item engine::randomPicker() {
    srand(time(NULL)); // Seed random generator
    int rarity = rand()%100 + 1; // Generate random number between 1-100
    Item item; // Create empty Item object

    /* Pick Rarity based on rarity and then
    * shuffle again to pick a random 
    * item from that rarity
    */
    if(rarity <= 60 ) {
        srand(time(NULL));
        item = rewards[0][rand()%4];
        xp += item.xp_item;
    }
    else if(rarity > 60 && rarity < 95) {
        item = rewards[1][rand()%4];
        xp += item.xp_item;
    }
    else if(rarity >= 95) {
        item = rewards[2][rand()%4];
        xp += item.xp_item;
    }

    return item;
}