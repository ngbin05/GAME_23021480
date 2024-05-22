#ifndef LOGIC_H
#define LOGIC_H
#include"defs.h"
#define BoardSize 3
#define CELL_EPTY 0
#define CELL_O -1
#define CELL_X 1
struct Tictactoe {

int board[BoardSize][BoardSize];
int nextMove=CELL_X;

    void init(){
        nextMove=CELL_X;
        for(int i=0;i<BoardSize;i++){
            for(int j=0;j<BoardSize;j++){
            board[i][j]=CELL_EPTY;
            }
        }
    }
    void move(int row,int col){
        if(board[row][col]==0)
    board[row][col]=nextMove;
     nextMove = (nextMove == CELL_O) ? CELL_X : CELL_O;

    }
};

#endif // LOGIC_H
