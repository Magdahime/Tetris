#include "Board_template.hpp"
#include "Tblock.hpp"
#include "Main.hpp"
#include "Interface.hpp"
void TInterface::user_interface()
{
    TBoard *Board1=NULL;
    std::string frame(MAX_LINE,'*');
while(true){
    std::cout.width(MAX_LINE);
    std::cout<<frame<<std::endl;
    std::cout<<"ROBCO INDUSTRIES (TM) TERMLINK PROTOCOL"<<std::endl;
    std::cout<<"What would you like to do today?"<<std::endl;
    std::cout<<"[1] Enter data about board."<<std::endl;
    std::cout<<"[2] Enter data about blocks."<<std::endl;
    std::cout<<"[3] Place on board your blocks"<<std::endl;
    std::cout<<"[4] Show me the board"<<std::endl;
    std::cout<<"[5] Exit"<<std::endl;
    std::cout<<frame<<std::endl;
    std::cout<<"Your answer?"<<std::endl;
    std::cout<<"______";
    int ans;
    std::cin>>ans;
        std::cin.clear();
        std::cin.ignore(TRASH_MAX,'\n');
    switch(ans){
        case(1):{
            clrscrs();
            if(Board1==NULL){
            make_new_board(&Board1);
            }else{
                std::cout<<"You already have one board! Do you want to create another one?[Y/N]"<<std::endl;
                if(get_ans())
                    make_new_board(&Board1);
            }
           break; 
        }
        case(2):{
            clrscrs();
            while(true){
                std::vector<int> additional_vect;
                std::cout<<"How much squares you want your block to have?"<<std::endl;
                long long int liczba1 = get_int();
                additional_vect.push_back(liczba1);
                std::cout<<"How much of this blocks you want to have?"<<std::endl;
                long long int liczba2 = get_int();
                additional_vect.push_back(liczba2);
                manual.push_back(additional_vect);
                std::cout<<"Do you want to continue? Y/N"<<std::endl;
                std::cout<<"___";
                if(!get_ans()) break;
            }
            break;
        }
        case(3):{
            clrscrs();
            if(Board1==NULL){
                std::cout<<"There is no board!"<<std::endl<<"HINT: Enter the data about the board first."<<std::endl;
            }else
            place_on_board(Board1);
            break;
        }
        case(4):{
            clrscrs();
            if(Board1==NULL){
                std::cout<<"There is no board!"<<std::endl<<"HINT: Enter the data about the board first."<<std::endl;
            }else{
            Board1->show_me();
            std::cout<<"Please press any key to continue..."<<std::endl;
            getchar();
            }
            break;
        }
        case(5):{
            clrscrs();
            delete Board1;
            std::cout<<"Goodbye."<<std::endl;
            exit(1);
        }
        default:{
            std::cout<<"I'm sorry you cannot choose option "<<ans<<std::endl;
            std::cout<<"Please, try once again."<<std::endl;
        }
    }
}
}
void TInterface::make_new_board(TBoard** board_pointer)
{            
    std::cout<<"You will now enter the data about the board."<<std::endl;
    std::cout<<"Choose the width, then choose the length."<<std::endl;
    std::cout<<"Width: "<<std::endl;
    long long int dim1=get_dimension();
    std::cout<<"Length: "<<std::endl;
    long long int dim2=get_dimension();
    set_dimension(dim1,dim2);
    *board_pointer = new TBoard(width,length);
}

bool TInterface::get_ans()
{
char c;
(std::cin>>c).get();
if(c=='Y'|| c=='y'){
    return true;
}else if(c=='N' || c=='n')
    return false;
else 
    std::cout<<"Error, please try once again."<<std::endl;
return get_ans();
}

int TInterface::get_dimension()
{
    long long int dimension=0;
    std::cin>>dimension;
    std::cin.ignore(TRASH_MAX,'\n');
    while(!std::cin){
    std::cin.clear();
    std::cin.ignore(TRASH_MAX,'\n');
    std::cout << "Woah bad data, try again"<<std::endl;
    std::cin>>dimension;
    }
    return dimension;
}
void TInterface::set_dimension(long long wid, long long len)
{
    width = wid;
    length=len;
}

void TInterface::clrscrs()
{
        system("@cls||clear");
}
int TInterface::get_int()
{
    long long int liczba1;
    char c;
    std::cin>>c;
    if(!std::cin) return 1;
    if(!isdigit(c)) return 1;
    std::cin.unget();
    std::cin>>liczba1;
    if(liczba1>0)
        return liczba1;
    return 1;
        
}
void TInterface::place_on_board(TBoard* board_pointer)
{
    char signs[] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','W','X','Y','Z'};
    int i=0;
    if(board_pointer->place_on_board(Blocks[i],signs[i])){
        i++;
        board_pointer->place_on_board(Blocks[i],signs[i]);
    }else{
        board_pointer->clean_board(signs[i]);
        i--;
        if(i<0){
            std::cout<<"Unable to place the blocks."<<std::endl;
        }else
        board_pointer->place_on_board(Blocks[i],signs[i]);
    }
}
