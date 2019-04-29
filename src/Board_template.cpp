#include "Main.hpp"
#include "Board_template.hpp"
#include "Tblock.hpp"
bool TBoard::check(int a, int b)
{
    if(a>x || a<0 || b<0 || b>y)
        return false;
    if(Board[a][b]=='0'){
        return true;  
    }
return false;
}
bool TBoard::place_on_board(int squares, char sign)
{
    if(squares>left_space){
        std::cout<<"This block is to big to be placed on this board!"<<std::endl;
        return false;
    }
    int a = choose_place(x);
    int b = choose_place(y);
    if(place_square(a,b,squares,sign)){
    left_space-=squares;
    return true;   
    }
    std::cout<<"Unable to place a block"<<std::endl;
    return false;
}
bool TBoard::place_square(int a, int b, int number, char sign)
{
    std::cout<<"Hi! This is my sign -- "<<sign<<std::endl;
    if(check(a,b)){
        Board[a][b]=sign;
        for(int i =0; i<number-1;i++){
            if(check(a,b+1)){
                Board[a][b+1]=sign;
                b++;
                continue;
            }else if(check(a+1,b)){
                Board[a+1][b]=sign;
                a++;
                continue;
            }else if(check(a,b-1)){
                Board[a][b-1]=sign;
                b--;
                continue;
            }else if(check(a-1,b)){
                Board[a-1][b]=sign;
                a--;
                continue;
            } else 
                return false;
        }
    }else {
        a=choose_place(x);
        b=choose_place(y);
        place_square(a,b,number,sign);
    }
    return true;
}

void TBoard::show_me()
{
    for(int i=0;i<x+2;i++){
        for(int j=0; j<y+2;j++){
            std::cout<<Board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
TBoard::~TBoard()
{
}
int TBoard::choose_place(int z)
{ 
    int a =rand();
    int b=rand();
    long long int coordinate = std::rand();
    coordinate+=a*b+a+b;
    coordinate%=z;
    return coordinate;
}
int TBoard::how_much_space_left()
{
    return left_space;
}

void TBoard::make_frame()
{
    for(int i=0; i<y+2;i++)
        Board[0][i]='~';
    for(int i=0; i<y+2; i++)
        Board[x+1][i]='~';
    for(int i=0; i<x+2; i++)
        Board[i][0]='|';
    for(int i=0; i<x+2; i++)
        Board[i][y+1]='|';
}

