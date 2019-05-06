#include "Main.hpp"
#include "TBoard.hpp"
#include "Tblock.hpp"
#include "TBoard_template.hpp"

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
int TBoard::choose_place(int z)
{
    long long int coordinate = std::rand();
    return coordinate%z+1;
}
