#include <iostream>
#include <cstdlib>
#include "functions.h"

int main() {

    std::array<char,9> grid ={
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '};

    draw_grid(grid);

    return EXIT_SUCCESS;
}