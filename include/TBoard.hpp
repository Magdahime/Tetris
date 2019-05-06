#ifndef TBOARD
#define TBOARD
#include "Main.hpp"
#include "Tblock.hpp"
#include "TBoard_template.hpp"
class TBlock;
class TBoard : public Boardtemp<int>{
public:
    TBoard(int a=10, int b=10){
        Boardtemp(a,b);
    }
    bool check(int a, int b);
    bool place_on_board(TBlock& block1, int sign);
    int choose_place(int z);
    int place_square(int a, int b, int number, char sign,int number_of_attempts);
    bool check_around(int a, int b);
};
#endif
