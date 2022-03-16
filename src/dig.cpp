#include "engine.h"

void engine::dig() {
    srand(time(NULL));
    int num = rand()%100 + 1;
    int item = -1;
    int numXP = -1;

    if(num <= 60 ) {
        srand(time(NULL));
        item = rand()%5;
        xp += 10;
        numXP = 10;
    }
    else if(num > 60 && num < 95) {
        srand(time(NULL));
        item = rand()%3+5;
        xp += 20;
        numXP = 20;
    }
    else if(num >= 95) {
        srand(time(NULL));
        item = rand()%2+8;
        xp += 50;
        numXP = 50;
    }

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

    system("clear");
    for(int i=0; i<6; i++) {
        printf("%s\n", shovel[i].c_str());
        usleep(dig_time);
        system("clear");
    }

    printf("%s\nYou found a %s\n", shovel[6].c_str(), rewards[item].name.c_str());
    printf("+%d XP\n", numXP);

    if(xp >= 100) {
        xp = (100-xp);
        level += 1;
        printf("Level Up!\n");
    }


    bag.push_back(rewards[item]);

    usleep(1000000);
}
