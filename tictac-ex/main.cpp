#include <iostream>
#include "tic.h"
using namespace std;
int player = 1;
int status[SIZE][SIZE];
void Initial(){  //初始化状态
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            status[i][j] = 0;
        }
    }
}
char Pic(int x){//输入判断
    if(x == 0){
        return ' ';
    }else if(x == 1){
        return 'o';
    }else{
        return 'x';
    }
}
void Draw(){   //画出当前状态
    cout << line << endl;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << "|" << Pic(status[i][j]);
        }
        cout << "|" << endl;
        cout << line << endl;
    }
}
int main(){
    Initial();
    Draw();
    while(1){
        int chess;
        if(player == 1){
            cout << "Please input:" << endl;
            cin >> chess;//？
            chess--;//？
            if(status[chess/SIZE][chess%SIZE] == 0){
                Result(chess, player);//放下棋子
            }else{
                cout << "The location is occupied" << endl;
                Draw();//为什么要在这画
                continue;//？
            }
        }
        else{//另一个棋手
            chess = Minimax_Decision(player);//决定在哪下棋
            Result(chess, player);
        }
        Draw();//下完才画
        int re = Check(chess);//下了一个就判断
        if(re == 2){
            SwitchPlayer();//还有地方下棋
            continue;
        }
        if(re == 1){
            cout << player << "player win!" << endl;
            break;
        }
        if(re == 0){
            cout << "No space." << endl;
            break;
        }
    }
}
