class TBlock;
#ifndef BOARD_TEMPLATE
#define BOARD_TEMPLATE
#include "Main.hpp"
#include "Tblock.hpp"
class TBoard{
private: 
void make_frame();
int left_space;
int x;
int y;
std::vector<std::vector<unsigned char>> Board;
public:
    TBoard(int a=10,int b=10): left_space(a*b), x(a), y(b){
        Board.resize(x+2);
        for(int rz=0;rz<x+2;rz++){
            Board[rz].resize(y+2,'0');
        }
        make_frame();

    }
    ~TBoard();
    bool check(int a, int b);
    bool place_on_board(int squares, char sign);
    void show_me();
    int choose_place(int z);
    bool place_square(int a, int b, int number, char sign);
    int how_much_space_left();

};
#endif
