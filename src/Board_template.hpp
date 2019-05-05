#ifndef BOARD_TEMPLATE
#define BOARD_TEMPLATE
#include "Main.hpp"
#include "Tblock.hpp"
class TBlock;
constexpr int SPACE_FOR_FRAME={2};
constexpr int ERROR_SPAWN={1};
constexpr int OK={0};
constexpr int ERROR_PLACEMENT={2};
class TBoard{
private: 
void make_frame();
int left_space;
int x;
int y;
std::vector<std::vector<unsigned int>> Board;
public:
    TBoard(int a=10,int b=10): left_space(a*b), x(a), y(b){
        Board.resize(x+2);
        for(int rz=0;rz<x+SPACE_FOR_FRAME;rz++){
            Board[rz].resize(y+SPACE_FOR_FRAME,0);
        }
        make_frame();

    }
    ~TBoard();
    bool check(int a, int b);
    int tell_width();
    int tell_length();
    void clean_board(unsigned int sign);
    bool place_on_board(TBlock& block1, int sign);
    void show_me();
    int choose_place(int z);
    int place_square(int a, int b, int number, char sign,int number_of_attempts);
    int how_much_space_left();
    bool check_around(int a, int b);
};
#endif
