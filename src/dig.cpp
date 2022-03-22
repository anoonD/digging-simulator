#include "engine.h"
#include "fmt/color.h"

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
    engine::clear();
    for(int i=0; i<6; i++) {
        fmt::print(COL_BOLD_RED, "{}\n", shovel[i]);
        usleep(dig_time-(int)(dig_time*((float)shovel_item.modifier/100.0)) );
        engine::clear();
    }

    /* Render last shovel and notify player of found reward */
    fmt::print(COL_BOLD_RED, "{}\n", shovel[6]);
    fmt::print(COL_BOLD_YELLOW, "You found a {}\n",  item.name);
    fmt::print(COL_BOLD_YELLOW, "+{} XP\n", item.modifier);

    if(xp >= 100) {
        xp = (xp - 100);
        level += 1;
        fmt::print(COL_BOLD_YELLOW, "Level Up!\n");
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
        xp += item.modifier;
    }
    else if(rarity > 60 && rarity < 95) {
        item = rewards[1][rand()%4];
        xp += item.modifier;
    }
    else if(rarity >= 95) {
        item = rewards[2][rand()%4];
        xp += item.modifier;
    }

    return item;
}