#include <iostream>
#include <cstdlib>
#include <array>

void display(const std::array<char, 9> &boxes);
void refresh();

int main(){
std::array<char, 9> boxes {'1','2','3','4','5','6','7','8','9'};
bool playerNumber{false};
bool nextRound{true};
int number;
int movesCounter = 0;
do{
refresh();
display(boxes);
std::cout<<"\n\nPlayer "<<static_cast<int>(playerNumber)+1<<" enters a number: ";
std::cin>>number;
if(number!=1 && number!=2 && number!=3 && number!=4 && number!=5 && number!=6 && number!=7 && number!=8 && number!=9){
    refresh();
    std::cout<<"*********Invalid command. Please try again**********\n\n";
    }
else if (boxes.at(number-1)=='o' || boxes.at(number-1)=='x'){
    refresh();
    std::cout<<"*********Already taken! Try again*********\n\n";
    }
else{
    movesCounter++;
    if(playerNumber)
        boxes.at(number-1)='o';
    else
        boxes.at(number-1)='x';

    if((boxes.at(0)==boxes.at(1)&&boxes.at(0)==boxes.at(2)) || (boxes.at(3)==boxes.at(4)&&boxes.at(3)==boxes.at(5)) ||
        (boxes.at(6)==boxes.at(7)&& boxes.at(6)==boxes.at(8)) || (boxes.at(0)==boxes.at(3)&&boxes.at(0)==boxes.at(6)) ||
        (boxes.at(1)==boxes.at(4)&&boxes.at(1)==boxes.at(7)) || (boxes.at(2)==boxes.at(5)&&boxes.at(2)==boxes[8]) ||
        (boxes.at(0)==boxes.at(4)&&boxes.at(0)==boxes.at(8)) || (boxes.at(2)==boxes.at(4)&&boxes.at(2)==boxes.at(6))){
        refresh();
        std::cout<<"*********Player "<<static_cast<int>(playerNumber)+1<<" wins!*********\n\n";
        nextRound = !nextRound;
        }
    playerNumber = !playerNumber;
}
if(movesCounter==9 && nextRound==true){
refresh();
std::cout<<"*********It's a draw!*********\n\n";
nextRound = !nextRound;
}
}
while(nextRound);
display(boxes);
return 0;
}

void display(const std::array<char, 9> &boxes){
std::cout<<"\n\tTic Tac Toe\n\n";
std::cout<<"Player 1 <"<<"x"<<">\tPlayer 2 <"<<"o"<<">\n\n";
std::cout<<"     |     |     "<<std::endl;
std::cout<<"  "<<boxes.at(0)<<"  |  "<<boxes.at(1)<<"  |  "<<boxes.at(2)<<"  "<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"-----|-----|-----"<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"  "<<boxes.at(3)<<"  |  "<<boxes.at(4)<<"  |  "<<boxes.at(5)<<"  "<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"-----|-----|-----"<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"  "<<boxes.at(6)<<"  |  "<<boxes.at(7)<<"  |  "<<boxes.at(8)<<"  "<<std::endl;
std::cout<<"     |     |     "<<std::endl;
}

void refresh(){
#ifdef __unix__
system("clear"); //linux
#endif
#ifdef _WIN32
system("cls"); //windows
#endif
}
