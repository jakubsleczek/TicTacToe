#include <iostream>
#include <cstdlib>
const void display(char boxes[9]);


int main(){

char boxes[9] {'1','2','3','4','5','6','7','8','9'};
bool playerNumber{0};
bool nextRound{1};
int number;
int i = 0;

do{
system("clear");
display(boxes);
std::cout<<"\n\nPlayer "<<static_cast<int>(playerNumber)+1<<" enters a number:";
std::cin>>number;
if(number!=1 && number!=2 && number!=3 && number!=4 && number!=5 && number!=6 && number!=7 && number!=8 && number!=9){
    system("clear");
    std::cout<<"*********Invalid command. Please try again**********\n\n";
    }
else if (boxes[number-1]=='o' || boxes[number-1]=='x'){
    system("clear");
    std::cout<<"*********Already taken! Try again*********\n\n";
    }
else{
    i++;
    if(playerNumber)
        boxes[number-1]='o';
    else
        boxes[number-1]='x';

    if((boxes[0]==boxes[1]&&boxes[0]==boxes[2]) || (boxes[3]==boxes[4]&&boxes[3]==boxes[5]) ||
        (boxes[6]==boxes[7]&& boxes[6]==boxes[8]) || (boxes[0]==boxes[3]&&boxes[0]==boxes[6]) ||
        (boxes[1]==boxes[4]&&boxes[1]==boxes[7]) || (boxes[2]==boxes[5]&&boxes[2]==boxes[8]) ||
        (boxes[0]==boxes[4]&&boxes[0]==boxes[8]) || (boxes[2]==boxes[4]&&boxes[2]==boxes[6])){
        system("clear");
        std::cout<<"*********Player "<<static_cast<int>(playerNumber)+1<<" wins!*********\n\n";
        nextRound = !nextRound;
        }
    playerNumber = !playerNumber;

}
if(i==9 && nextRound==1){
system("clear");
std::cout<<"*********It's a draw!*********\n\n";
nextRound = !nextRound;
}

}
while(nextRound);
display(boxes);

return 0;
}

const void display(char boxes[9]){
std::cout<<"\n\tTic Tac Toe\n\n";
std::cout<<"Player 1 <"<<"x"<<">\tPlayer 2 <"<<"o"<<">\n\n";
std::cout<<"     |     |     "<<std::endl;
std::cout<<"  "<<boxes[0]<<"  |  "<<boxes[1]<<"  |  "<<boxes[2]<<"  "<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"-----|-----|-----"<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"  "<<boxes[3]<<"  |  "<<boxes[4]<<"  |  "<<boxes[5]<<"  "<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"-----|-----|-----"<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"  "<<boxes[6]<<"  |  "<<boxes[7]<<"  |  "<<boxes[8]<<"  "<<std::endl;
std::cout<<"     |     |     "<<std::endl;

}
