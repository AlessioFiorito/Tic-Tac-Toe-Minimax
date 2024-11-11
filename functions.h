#ifndef FUNCTIONS.H
#define  FUNCTIONS.H
#include <array>

void draw_grid(const std::array<char,9>& grid);
bool is_position_ok(int player_position, const std::array<char,9>& grid);
int get_player_position();
bool has_someone_won(const std::array<char,9>& grid);
bool is_draw(const std::array<char,9>& grid);
void ai_turn(std::array<char,9>& grid);
int evaluating_grid(const std::array<char,9>& grid);
int minimax(std::array<char, 9>& grid, int profondeur, bool isMax, int alpha, int beta);



#endif FUNCTIONS.H



