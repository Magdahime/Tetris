#ifndef TBLOCK
#define TBLOCK
#include "Main.hpp"
#include "TBoard.hpp"
class TBlock{
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
public:
int how_many_squares();
int how_many_blocks();
TBlock(int i=4);
};

struct TBlock::Impl{
    static int number; 
    int squares;
    static void increase_number();
};
#endif
