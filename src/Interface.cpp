#include "Board_template.hpp"
#include "Tblock.hpp"
#include "Main.hpp"
#include "Interface.hpp"
void TInterface::user_interface()
{
    TBoard Board1;
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
            std::cout<<"You will now enter the data about the board."<<std::endl;
            std::cout<<"Choose the width, then choose the length."<<std::endl;
            set_dimension(get_dimension(),get_dimension());
            Board1 = TBoard(width,length);
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
            break;
        }
        case(4):{
            clrscrs();
            Board1.show_me();
            std::cout<<"Please press any key to continue..."<<std::endl;
            getchar();
            break;
        }
        case(5):{
            clrscrs();
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
    while(!std::cin>>dimension){
    std::cin.clear();
    std::cin.ignore(TRASH_MAX,'\n');
    std::cout << "Woah bad data, try again";
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
