#pragma once

#include <stdio.h>

class Board
{
public:
    int board[10][10];
    int turn;
    int WCP[65];
    int IPDWT[100][8];

    Board();
    void ClearBoard();
    void PrintBoard();
    void CheckBoard();
    void PutPiece();
    void PutPiece(int putx, int puty);
};