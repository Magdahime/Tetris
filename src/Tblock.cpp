#include "Main.hpp"
#include "Tblock.hpp"
int TBlock::how_many_squares()
{
return pImpl->squares;
}
int TBlock::how_many_blocks()
{
    return pImpl->number;
}
void TBlock::Impl::increase_number()
{
    number++;
}
TBlock::TBlock(int i):pImpl{new Impl{i}}
{pImpl->increase_number();}

