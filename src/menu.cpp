#include "engine.h"
#include "fmt/color.h"

void engine::menu() {
    engine::clear();
    
    fmt::print("{}",
            fmt::styled(
            "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            "| D I G G I N G - S I M U L A T O R |\n"
            "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            , COL_BOLD_BROWN)
    );

    fmt::print("{} ${}\n", fmt::styled("Balance:", COL_BOLD_BROWN), bal);
    fmt::print("{} {}\n", fmt::styled("XP:", COL_BOLD_BROWN), xp);
    fmt::print("{} {}\n", fmt::styled("Level:", COL_BOLD_BROWN), level);
    fmt::print("{} {}/{}\n\n", fmt::styled("Bag:", COL_BOLD_BROWN), bag.size(), max_inv);

    fmt::print(COL_BOLD_BLUE, "1: Dig\n");
    fmt::print(COL_BOLD_BLUE, "2: Sell\n");
    fmt::print(COL_BOLD_BLUE, "q: Quit\n");

    fmt::print("\n>> ");
}