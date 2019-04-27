#ifndef TBLOCK
#define TBLOCK
#include "Main.hpp"
#include "Board_template.hpp"
class TBlock{
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
public:
int how_many_squares();
int how_many_blocks();
TBlock(int i);
};
#endif
