#ifndef TIC_H
#define TIC_H

#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
const int SIZE = 3;//棋盘大小
const int INF = 10000;
extern int status[SIZE][SIZE];//状态，也是棋盘
const string line = " ----- ";
const int NUM = 9;//这个是什么？
extern int player;
int Check(int chess);//检查棋子
void Result(int chess, int player);
void SwitchPlayer();
int Minimax_Decision(int player);
int Max_Value(int chess, int player);
int Min_Value(int chess, int player);
void Initial();
void Draw();
char Pic(int x);//这个是啥？

#endif // TIC_H
