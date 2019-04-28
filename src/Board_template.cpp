#include "Main.hpp"
#include "Board_template.hpp"
#include "Tblock.hpp"
bool TBoard::check(int a, int b)
{
    if(a>x || b>y)
        return false;
    if(Board[a][b]==0)
        return true;
return false;
}
bool TBoard::place_on_board(TBlock block, char sign)
{
    int how_many = block.how_many_squares();
    if(how_many>left_space){
        std::cout<<"This block is to big to be placed on this board!"<<std::endl;
        return false;
    }
    int a = choose_place(x);
    int b = choose_place(y);
    if(check(a,b)){
        Board[a][b]=sign;
        
    }
    return true;
}
void TBoard::show_me()
{
    for(int i=0;i<x;i++){
        for(int j=0; j<y;j++){
            std::cout<<Board[i][j]<<" ";
        }
    }
}
TBoard::~TBoard()
{
}
int TBoard::choose_place(int z)
{
    srand(time(NULL));
    return std::rand()%z;
}


