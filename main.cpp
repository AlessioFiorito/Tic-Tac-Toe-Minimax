#include <iostream>
#include <cstdlib>

#include "functions.h"

int main() {

    std::array<char,9> grid ={
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '};

    //game loop
    bool is_running = true;
    while(is_running) {
        int player_position;
        do {
            player_position = get_player_position();
        }while (!is_position_ok(player_position,grid));
        grid[player_position] = 'X';
        draw_grid(grid);
        if(has_someone_won(grid)) {
            is_running = false;
            break;
        }
        if (is_draw(grid)) {
            std::cout << "It's a draw!" << std::endl;
            is_running = false;
            break;
        }
        ai_turn(grid);
        draw_grid(grid);
        if(has_someone_won(grid)) {
            is_running = false;
            break;
        }
        if (is_draw(grid)) {
            std::cout << "It's a draw!" << std::endl;
            is_running = false;
            break;
        }
    }

    return EXIT_SUCCESS;
}