#include "Main.hpp"
#include "Board_template.hpp"
#include "Tblock.hpp"
#include <chrono>
int TBoard::tell_length()
{
    return y;
}
int TBoard::tell_width()
{
    return x;
}

bool TBoard::check(int a, int b)
{
    if(a>x || a<=0 || b<=0 || b>y)
        return false;
    if(Board[a][b]==0){
        return true;  
    }
return false;
}
bool TBoard::check_around(int a, int b)
{
    if(check(a,b) && (check(a+1,b)|| check(a-1,b) || check(a,b+1) ||check(a,b-1)))
        return true;
    return false;
}

bool TBoard::place_on_board(TBlock& block1, int sign)
{
    if(block1.how_many_squares()>left_space){
        std::cout<<"This block is to big to be placed on this board!"<<std::endl;
        return false;
    }
    int a =choose_place(x);
    int b =choose_place(y);
    int i=1;
    int result =place_square(a,b,block1.how_many_squares(),sign,i);
    while(result ==ERROR_SPAWN){
    int a = choose_place(x);
    int b = choose_place(y);
    i++;
    result =place_square(a,b,block1.how_many_squares(),sign,i);
    }
    if(result==OK){
        return true;
    }
    return false;
}
int TBoard::place_square(int a, int b, int number, char sign,int number_of_attempts)
{
    std::cout<<"This is my "<<number_of_attempts<<" try."<<std::endl;
    if(number_of_attempts>left_space)
        return ERROR_PLACEMENT;
    if(check_around(a,b)){
        Board[a][b]=sign;
        for(int i =0; i<number-1;i++){
            if(check(a,b+1)){
                Board[a][b+1]=sign;
                b++;
            }else if(check(a+1,b)){
                Board[a+1][b]=sign;
                a++;
            }else if(check(a,b-1)){
                Board[a][b-1]=sign;
                b--;
            }else if(check(a-1,b)){
                Board[a-1][b]=sign;
                a--;
            }else{
                std::cout<<"Nie udało się ułożyć do końca."<<std::endl;
                left_space-=i+1;
            return ERROR_PLACEMENT;
            }
        }
        std::cout<<"Udało się ułożyć."<<std::endl;
        left_space-=number;
        return OK;
    }
    return ERROR_SPAWN;
}

void TBoard::show_me()
{
    for(int i=0;i<x+2;i++){
        for(int j=0; j<y+2;j++){
            std::cout.width(3);
            std::cout<<Board[i][j];
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
    long long int coordinate = std::rand();
    return coordinate%z+1;
}
int TBoard::how_much_space_left()
{
    return left_space;
}

void TBoard::make_frame()
{
    for(int i=0; i<y+2;i++)
        Board[0][i]=0;
    for(int i=0; i<y+2; i++)
        Board[x+1][i]=0;
    for(int i=0; i<x+2; i++)
        Board[i][0]=0;
    for(int i=0; i<x+2; i++)
        Board[i][y+1]=0;
}
void TBoard::clean_board(unsigned int sign)
{
    int add=0;
    for(int i=0; i<tell_width()+1;i++){
        for(int j=0;j<tell_length()+1;j++){
            if(Board[i][j]==sign){
               Board[i][j]=0;
               add++;
            }
        }
    }
    left_space+=add;
}
