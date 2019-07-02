#include "tic.h"
#include<iostream>
using namespace std;
int Check(int chess){ //判断棋局是否结束
    int row = chess/SIZE;//为什么要这么写，这个为什么不是%，为什么不能直接以棋子的位置替代chess为棋子数量
    int col = chess%SIZE;//为什么要这么写
    if(status[row][0] == status[row][1] && status[row][0] == status[row][2]){
        return 1;
    }//同一行相等
    if(status[0][col] == status[1][col] && status[0][col]== status[2][col]){
        return 1;
    }//同一列
    if(row == col && status[(row+2)%SIZE][(col+2)%SIZE] == status[row][col] && status[row][col] == status[(row+1)%SIZE][(col+1)%SIZE]){
        return 1;
    }//对角线
    if(row+col == (SIZE-1) && status[(row+2)%SIZE][(col+1)%SIZE] == status[row][col] && status[row][col] == status[(row+1)%SIZE][(col+2)%SIZE]){
        return 1;
    }//判断赢了
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(status[i][j] == 0){
                return 2;//没有棋子
            }
        }
    }
    return 0;
}
void SwitchPlayer(){
    player = -player;//交换棋手
}
void Result(int chess, int player){
    status[chess/SIZE][chess%SIZE] = player;//棋手代表棋子不同
}
int Minimax_Decision(int player){//把棋手传进来-1,如果可能出现两个棋子就堵住它
    int max = -INF;//？
    int flag = -1;//？
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(status[i][j] == 0){
                status[i][j] = player;//在这里放下棋子
                int temp = Min_Value(i*SIZE+j, -player);//用了min_value，对手最弱
                if(max < temp){//好好回头看，要最小的
                    max = temp;//最小
                    flag = i*SIZE+j;//棋子位置
                }
                status[i][j] = 0;
            }
        }
    }
    return flag;
}
int Max_Value(int chess, int player){
    int max=-INF;
    if(Check(chess)==1)return -1;//
    if(Check(chess)==0)return 0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(status[i][j]==0){
                status[i][j]=player;
                int temp=Min_Value(i*SIZE+j,-player);
                if(max<temp){
                    max=temp;
                }
                status[i][j]=0;
            }
        }
    }
    return max;
}

/*最终结果：
 * max赢（1）：返回1；
 * min赢（-1）：返回-1；
 * 平局：返回0；
*/
int Min_Value(int chess, int player){
    int min=INF;
    if(Check(chess)==1)return 1;//要ai赢应该返回一个高的分值
    if(Check(chess)==0)return 0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(status[i][j]==0){
                status[i][j]=player;
                int temp=Max_Value(i*SIZE+j,-player);
                status[i][j]=0;
                if(min>temp){
                    min=temp;
                }
            }
        }
    }
    return min;
}


