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
        }
        if(is_draw(grid)) {
            is_running = false;
        }
        ai_turn(grid);
        draw_grid(grid);
        if(has_someone_won(grid)) {
            is_running = false;
        }
        if(is_draw(grid)) {
            is_running = false;
        }
    }

    return EXIT_SUCCESS;
}