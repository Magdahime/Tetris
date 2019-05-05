#include "Main.hpp"
#include "Board_template.hpp"
#include "Tblock.hpp"
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
    if(a>x || a<0 || b<0 || b>y)
        return false;
    if(Board[a][b]=='0'){
        return true;  
    }
return false;
}
bool TBoard::check_around(int a, int b)
{
    if(check(a+1,b)&& check(a-1,b) && check(a,b+1) &&check(a,b-1))
        return true;
    return false;
}

bool TBoard::place_on_board(TBlock& block1, char sign)
{
    if(block1.how_many_squares()>left_space){
        std::cout<<"This block is to big to be placed on this board!"<<std::endl;
        return false;
    }
    int a = choose_place(x);
    int b = choose_place(y);
    int i=1;
    if(place_square(a,b,block1.how_many_squares(),sign,i)){
    left_space-=block1.how_many_squares();
    return true;   
    }else
    std::cout<<"Unable to place a block"<<std::endl;
    return false;
}
bool TBoard::place_square(int a, int b, int number, char sign,int number_of_attempts)
{
    std::cout<<"This is my "<<number_of_attempts<<" try."<<std::endl;
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
            } else 
                return false;
        }
    }else {
        a=choose_place(x);
        b=choose_place(y);
        number_of_attempts++;
        place_square(a,b,number,sign,number_of_attempts);
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
    coordinate-=a*b+a+b;
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
void TBoard::clean_board(char sign)
{
    for(int i=0; i<tell_width();i++){
        for(int j=0;j<tell_length();j++){
            if(Board[i][j]==sign)
               Board[i][j]='0';
        }
    }
}
