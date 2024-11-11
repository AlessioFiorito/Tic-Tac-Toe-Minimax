#ifndef FUNCTIONS.H
#define  FUNCTIONS.H
#include <array>

void draw_grid(const std::array<char,9>& grid);
bool is_position_ok(int player_position, const std::array<char,9>& grid);
int get_player_position();
bool has_someone_won(const std::array<char,9>& grid);
bool is_draw(const std::array<char,9>& grid);
void ai_turn(std::array<char,9>& grid);


#endif FUNCTIONS.H



