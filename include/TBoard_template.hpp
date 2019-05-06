#ifndef BOARD_TEMPLATE
#define BOARD_TEMPLATE
#include "Main.hpp"
template <typename T>
class Boardtemp
{
protected:
    int left_space;
    int x;
    int y;
    std::vector<std::vector<T>> Board;
public:
void make_frame();
void clean_board(T sign);
void show_me();
Boardtemp(int a=10,int b=10): left_space(a*b), x(a), y(b){
        Board.resize(x+2);
        for(int rz=0;rz<x+SPACE_FOR_FRAME;rz++){
            Board[rz].resize(y+SPACE_FOR_FRAME,static_cast<T>(0));
        }
        make_frame();

    }
int how_much_space_left(){
    return left_space;
}
int tell_width(){
    return x;
}
int tell_length(){
    return y;
}
}; 
template <typename T>
void Boardtemp<T>::clean_board(T sign)
{
        int add=0;
        for(int i=0; i<tell_width()+1;i++){
        for(int j=0;j<tell_length()+1;j++){
            if(Board[i][j]==sign){
               Board[i][j]=static_cast<T>(0);
                add++;
            }
        }
    }
        left_space+=add;
}
template<typename T>
void Boardtemp<T>::show_me()
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
template<typename T> 
void Boardtemp<T>::make_frame()
{
    for(int i=0; i<y+2;i++)
        Board[0][i]=static_cast<T>(0);
    for(int i=0; i<y+2; i++)
        Board[x+1][i]=static_cast<T>(0);
    for(int i=0; i<x+2; i++)
        Board[i][0]=static_cast<T>(0);
    for(int i=0; i<x+2; i++)
        Board[i][y+1]=static_cast<T>(0);
}

#endif
