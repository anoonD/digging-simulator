#include "engine.h"

void engine::menu() {
    engine::clear();
    
    fmt::print("{}",
            fmt::styled(
            "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            "| D I G G I N G - S I M U L A T O R |\n"
            "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            , fmt::fg(fmt::color::green) | fmt::bg(fmt::color::blue))
    );

    fmt::print("Balance: ${}\n", bal);
    fmt::print("XP: {}\n", xp);
    fmt::print("Level: {}\n", level);
    fmt::print("Bag: {}/{}\n\n", bag.size(), max_inv);

    fmt::print("1: Dig\n");
    fmt::print("2: Sell\n");
    fmt::print("q: Quit\n");

    fmt::print("\n>> ");
}