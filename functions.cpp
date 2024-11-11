#include "functions.h"
#include <iostream>
#include <iomanip>
#include <random>

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
bool is_position_ok(int player_position, const std::array<char,9>& grid) {
    if(player_position < 0 || player_position > 8) {
        return false;
    }
    if(grid[player_position] == ' ') {
        return true;
    }
    return false;
}
int get_player_position() {
    int player_position;
    std::cout << "Place an X on the grid\npositions:\n0 / 1 / 2\n" <<  "3 / 4 / 5\n" << "6 / 7 / 8" << std::endl;
    std::cin >> player_position;
    return player_position;
}
bool has_someone_won(const std::array<char, 9>& grid) {
    // Win conditions
    if ((grid[0] + grid[1] + grid[2] == 88 * 3) ||
        (grid[6] + grid[7] + grid[8] == 88 * 3) ||
        (grid[0] + grid[3] + grid[6] == 88 * 3) ||
        (grid[1] + grid[4] + grid[7] == 88 * 3) ||
        (grid[2] + grid[5] + grid[8] == 88 * 3) ||
        (grid[0] + grid[4] + grid[8] == 88 * 3) ||
        (grid[2] + grid[4] + grid[6] == 88 * 3)) {
        std::cout << "You Won!" << std::endl;
        return true;
        }
    if ((grid[0] + grid[1] + grid[2] == 79 * 3) ||
        (grid[6] + grid[7] + grid[8] == 79 * 3) ||
        (grid[0] + grid[3] + grid[6] == 79 * 3) ||
        (grid[1] + grid[4] + grid[7] == 79 * 3) ||
        (grid[2] + grid[5] + grid[8] == 79 * 3) ||
        (grid[0] + grid[4] + grid[8] == 79 * 3) ||
        (grid[2] + grid[4] + grid[6] == 79 * 3)) {
        std::cout << "Computer Won !" << std::endl;
        return true;
    }
    return false;
}
bool is_draw(const std::array<char, 9> &grid) {
    for(char c : grid) {
        if(c == ' ') {
            return false;
        }
    }
    std::cout << "It's a draw !" << std::endl;
    return true;
}
void ai_turn(std::array<char, 9>& grid) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 8);

    int ai_position;
    do {
        ai_position = dis(gen);
    } while (grid[ai_position] != ' ');

    grid[ai_position] = 'O';
}
int evaluating_grid(const std::array<char, 9> &grid) {
    //evaluating rows
    for(int i = 0; i < 9; i+=3) {
        if(grid[i] == grid[i+1] && grid[i+1] == grid[i+2]) {
            if(grid[i] == 'O') return 10;
            if(grid[i] == 'X') return -10;
        }
    }
    //evaluating columns
    for(int i = 0; i < 3; ++i) {
        if(grid[i] == grid[i+3] && grid[i+3] == grid[i+6]) {
            if(grid[i] == 'O') return 10;
            if(grid[i] == 'X') return -10;
        }
    }
    //evaluating diags
    if (grid[0] == grid[4] && grid[4] == grid[8]) {
        if (grid[0] == 'O') return 10;
        if (grid[0] == 'X') return -10;
    }
    if (grid[2] == grid[4] && grid[4] == grid[6]) {
        if (grid[2] == 'O') return 10;
        if (grid[2] == 'X') return -10;
    }

    //if no winner
    return 0;
}


