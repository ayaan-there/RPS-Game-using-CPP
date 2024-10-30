#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

char getcomputermove(){
    int move;
    srand(time(NULL));
    move=rand()%3;
    if (move==0){
        return 'r';
    }
    else if (move==1){
        return 's';
    }
    return 'p';
}

string result(char player, char comp){
    if(player == comp){
        string d="AWWW HELL NAH IT'S A DRAW";
        return d;
    }
    if((player == 's' && comp == 'p') || (player == 'r' && comp == 's') || (player == 'p' && comp == 'r')){
        string w="CONGRATULATIONS! YOU WON";
        return w;
    }
    string l="TRY AGAIN! YOU LOST";
    return l;
}

int main(){
    char player,comp;
    cout<<"Enter your move: ";
    cin>>player;
    if(player!='r' && player!='s' && player!='p'){
        cout<<"Invalid move";
        return 0;
    }
    comp=getcomputermove();
    cout<<"Computer's move: "<<comp<<endl;
    cout<<result(player,comp);
    return 0;
}