#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "TBoard.hpp"
#include "Main.hpp"
#include "Tblock.hpp"
class TInterface {
private:
    int width;
    int length;
    std::vector<std::vector<int>> manual;
    std::vector<TBlock> Blocks;
    void set_dimension(long long int wid, long long int len);
public:
    void clrscrs(void);
    void make_new_board(TBoard** board_pointer);
    void make_new_manual();
    void create_all_blocks();
    void place_on_board(TBoard* board_pointer,long unsigned int i);
    int get_dimension();
    void user_interface();
    int get_int();
    bool get_ans();
};
#endif
