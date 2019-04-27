#ifndef BOARD_TEMPLATE
#define BOARD_TEMPLATE
#include "Main.hpp"
#include "Tblock.hpp"
class TBoard{
private: 
    unsigned int left_space;
    unsigned int x;
    unsigned int y;
std::vector<std::vector<char>> Board;
public:
    TBoard(unsigned int a, unsigned int b): left_space(a*b), x(a), y(b){
        for(int i=0; i<x;i++){
            Board[i].resize(b,'0');
        }
    }
    ~TBoard();
    bool check(int a, int b);
    bool place_on_board(TBlock block, char sign);
    void show_me();
    int choose_place(int z);

};
#endif
