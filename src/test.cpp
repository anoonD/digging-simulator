#include <fmt/color.h>

int main() {
    fmt::color color2 = {
    };

    fmt::print("{}",
        fmt::styled("Normal", fg(fmt::rgb(200, 200, 200)) | fmt::emphasis::bold )
    );
}