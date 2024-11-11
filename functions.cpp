#include "functions.h"
#include <iostream>
#include <iomanip>
#include <random>

int nombre_coups_explores = 0;

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
bool is_draw(const std::array<char, 9>& grid) {
    for (char c : grid) {
        if (c == ' ') {
            return false;
        }
    }
    return true;
}
void ai_turn(std::array<char, 9>& grid) {
    nombre_coups_explores = 0;
    int meilleurScore = INT_MIN;
    int meilleurCoup = -1;

    for (int i = 0; i < 9; i++) {
        if (grid[i] == ' ') {
            grid[i] = 'O';
            int score = minimax(grid, 0, false, INT_MIN, INT_MAX);
            grid[i] = ' ';

            if (score > meilleurScore) {
                meilleurScore = score;
                meilleurCoup = i;
            }
        }
    }

    if (meilleurCoup != -1) {
        grid[meilleurCoup] = 'O';
    }

    std::cout << "Number of possibilites explored : " << nombre_coups_explores << std::endl;
}
int evaluating_grid(const std::array<char, 9> &grid) {
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
int minimax(std::array<char, 9>& grid, int profondeur, bool isMax, int alpha, int beta) {
    nombre_coups_explores++;

    int score = evaluating_grid(grid);

    if (score == 10) return score - profondeur;
    if (score == -10) return score + profondeur;
    if (is_draw(grid)) return 0;

    if (isMax) {
        int meilleurScore = INT_MIN;
        for (int i = 0; i < 9; i++) {
            if (grid[i] == ' ') {
                grid[i] = 'O';
                int valeur = minimax(grid, profondeur + 1, false, alpha, beta);
                grid[i] = ' ';
                meilleurScore = std::max(meilleurScore, valeur);
                alpha = std::max(alpha, meilleurScore);
                if (beta <= alpha) break;
            }
        }
        return meilleurScore;
    } else {
        int meilleurScore = INT_MAX;
        for (int i = 0; i < 9; i++) {
            if (grid[i] == ' ') {
                grid[i] = 'X';
                int valeur = minimax(grid, profondeur + 1, true, alpha, beta);
                grid[i] = ' ';
                meilleurScore = std::min(meilleurScore, valeur);
                beta = std::min(beta, meilleurScore);
                if (beta <= alpha) break;
            }
        }
        return meilleurScore;
    }
}
