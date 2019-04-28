#include "Main.hpp"
#include "Board_template.hpp"
#include "Tblock.hpp"
#ifndef user
int TBlock::Impl::number=0;
void test1(void);
void test2(void);
void test3(void);
void test4(void);
int main(){
    test1();
    return 0;
};
void test1(){
    std::string stars(30, '*');
  std::cout<<stars<<std::endl<<"Start test 1: Testing pImpl and TBlock class"<<std::endl;
  TBlock block1;
  int block1b = block1.how_many_blocks();
  int block1s = block1.how_many_squares();
  TBlock block2(10);
  int block2b =block2.how_many_blocks();
  int block2s = block2.how_many_squares();
  std::cout<<"How many blocks block1: "<<block1b<<std::endl;
  std::cout<<"How many squares block1: (should be 4) " <<block1s<<std::endl;
  std::cout<<"How many blocks block2: "<<block2b<<std::endl;
  std::cout<<"How many squares block2: (should be 10) "<<block2s<<std::endl<<stars;
}

#else
int main(){
    return 0;
};
#endif
