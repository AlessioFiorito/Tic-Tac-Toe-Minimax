#include "functions.h"
#include <iostream>
#include <iomanip>

void draw_grid(const std::array<char, 9>& grid) {
    for (int i = 0; i < 9; i += 3) {
        std::cout << " " << std::setw(2) << grid[i] << " | "
        << std::setw(2) << grid[i + 1] << " | "
        << std::setw(2) << grid[i + 2] << " " << std::endl;
        if (i < 6) {
            std::cout << "----|----|----" << std::endl;
        }
    }
}


