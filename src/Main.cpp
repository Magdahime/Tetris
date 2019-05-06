#include "Main.hpp"
#include "TBoard.hpp"
#include "Tblock.hpp"
#include "Interface.hpp"
#include "TBoard_template.hpp"
#ifndef user
int TBlock::Impl::number=0;
void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
int main(){
        srand(time(NULL));
    test1();
    test2();
    test3();
    test4();
    //test5();
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
  std::cout<<"How many squares block2: (should be 10) "<<block2s<<std::endl;
  std::cout<<"End of the test."<<std::endl<<stars;
}
void test2()
{
    std::string stars(30, '*');
    std::cout<<stars<<std::endl<<"Start test 2: Testing Board and placing on board algorithm."<<std::endl;
    TBoard Board2(20,20);
    TBoard Board1;
    TBlock block1(35);
    TBlock block2(20);
    ////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout<<"That's how Board1 looks like before placing an object : "<<std::endl;
    Board1.show_me();
    std::cout<<"How much space has Board1 before placing an object: "<<Board1.how_much_space_left()<<std::endl;
    Board1.place_on_board(block1,1);
    std::cout<<"How much space has Board1 after placing an object1: "<<Board1.how_much_space_left()<<std::endl;
    std::cout<<"That's how Board1 looks like after placing object1 : "<<std::endl;
    Board1.show_me();
    Board1.place_on_board(block2,2);
    std::cout<<"How much space has Board1 after placing an object2: "<<Board1.how_much_space_left()<<std::endl;
    std::cout<<"That's how Board1 looks like after placing object2 : "<<std::endl;
    Board1.show_me();
    ////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout<<"That's how Board2 looks like before placing an object : "<<std::endl;
    Board2.show_me();
    std::cout<<"How much space has Board2 before placing an object: "<<Board2.how_much_space_left()<<std::endl;
    Board2.place_on_board(block1,1);
    std::cout<<"How much space has Board2 after placing an object1: "<<Board2.how_much_space_left()<<std::endl;
    std::cout<<"That's how Board2 looks like after placing object1 : "<<std::endl;
    Board2.show_me();
    Board2.place_on_board(block2,2);
    std::cout<<"How much space has Board1 after placing an object2: "<<Board2.how_much_space_left()<<std::endl;
    std::cout<<"That's how Board2 looks like after placing object2 : "<<std::endl;
    Board2.show_me();
    std::cout<<"End of the test."<<std::endl<<stars;
}
void test3()
{
    std::string stars(30, '*');
    std::cout<<stars<<std::endl<<"Start test 3: Testing place algorithm - real test."<<std::endl;
    TBoard test_board(10,20);
    TBlock block1(10);
    TBlock block2(78);
    TBlock block3(13);
    TBlock block4(39);
    TBlock block5(60);
    std::cout<<"Start placing blocks. "<<std::endl;
    test_board.place_on_board(block1,1);
    test_board.show_me();
    test_board.place_on_board(block2,2);
    test_board.show_me();
    test_board.place_on_board(block3,3);
    test_board.show_me();
    test_board.place_on_board(block4,4);
    test_board.show_me();
    test_board.place_on_board(block5,5);
    test_board.show_me();
    std::cout<<"End of the test. Expecting solution: Possible."<<std::endl<<stars;
    
}

void test4()
{
    std::string stars(30, '*');
    std::cout<<stars<<std::endl<<"Start test 4: Testing place algorithm."<<std::endl;
    TBoard* board1;
    board1=new TBoard(10,10);
    TInterface interface;
    interface.make_new_manual();
    interface.create_all_blocks();
    interface.place_on_board(board1,1);
    board1->show_me();
    delete board1;
    std::cout<<"End of the test."<<std::endl<<stars;
}
void test5()
{
    std::string stars(30, '*');
    std::cout<<stars<<std::endl<<"Start test 4: Testing board template."<<std::endl;
    Boardtemp<int> board;
    board.show_me();
    Boardtemp<double> boarddouble;
    boarddouble.show_me();
    std::cout<<"End of the test."<<std::endl<<stars;
}

#else
int TBlock::Impl::number=0;
int main(){
    TInterface interface;
    interface.user_interface();
    return 0;
};
#endif
