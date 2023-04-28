//
//  ChessBoard.cpp
//  A7
//
//  Created by 李子扬 on 2018-11-20.
//  Copyright © 2018 Ziyang Li. All rights reserved.
//

#include <stdio.h>
#include "ChessBoard.h"
#include "ChessPieces.h"
#include"ChessUtils.h"
using namespace std;

void ChessBoard::setPiece(shared_ptr<ChessPiece> p, Location loc)
{
    bool col_v = false;
    bool row_v= false;
    
    //check if location is valid
    char col[] = { 'a','b','c','d','e','f','h','g' };
    int row[] = { 1,2,3,4,5,6,7,8 };
    for (int i = 0; i < 8; i++)
    {
        if (loc.col == col[i])
            col_v = true;
        if (loc.row == row[i])
            row_v = true;
    }
    if (col_v&&row_v)
    {
        int col = 0, row = 0;
        switch (loc.col)
        {
            case 'a':col = 0; break;
            case 'b':col = 1; break;
            case 'c':col = 2; break;
            case 'd':col = 3; break;
            case 'e':col = 4; break;
            case 'f':col = 5; break;
            case 'g':col = 6; break;
            case 'h':col = 7; break;
        }
        row = loc.row - 1;//transfer the location into the array board
        board[col][row] = p;
    }
}


bool ChessBoard::movePiece(Location source, Location dest)
{
    int col1 = 0, col2 = 0;
    int row1 = 0, row2 = 0;
    bool col1_v = false, col2_v = false;
    bool row1_v = false, row2_v = false;
    
    //check if location is valid
    char col[] = { 'a','b','c','d','e','f','h','g' };
    int row[] = { 1,2,3,4,5,6,7,8 };//standard array
    for (int i = 0; i < 8; i++)
    {
        if (source.col == col[i])
            col1_v = true;
        if (source.row == row[i])
            row1_v = true;
        if (dest.col == col[i])
            col2_v = true;
        if (dest.row == row[i])
            row2_v = true;
    }
    if ((col1_v && col2_v && row1_v && row2_v && (source.col != dest.col)) || (source.row != dest.row))
    {//the piece must be moved, source!=dest
        switch (source.col)
        {
            case 'a':col1 = 0; break;
            case 'b':col1 = 1; break;
            case 'c':col1 = 2; break;
            case 'd':col1 = 3; break;
            case 'e':col1 = 4; break;
            case 'f':col1 = 5; break;
            case 'g':col1 = 6; break;
            case 'h':col1 = 7; break;
        }
        row1 = source.row - 1;
        switch (dest.col)
        {
            case 'a':col2 = 0; break;
            case 'b':col2 = 1; break;
            case 'c':col2 = 2; break;
            case 'd':col2 = 3; break;
            case 'e':col2 = 4; break;
            case 'f':col2 = 5; break;
            case 'g':col2 = 6; break;
            case 'h':col2 = 7; break;
        }
        row2 = dest.row - 1;//transfer location
        if (board[col1][row1] != nullptr)
        {
            if(board[col2][row2]==nullptr)
            {
                board[col2][row2] = board[col1][row1];
                board[col1][row1] = nullptr;
                return true;
            }
            else{
                if(board[col2][row2]->getTeam()!=board[col1][row1]->getTeam())
                {
                    
                    board[col2][row2]->setCaptured();
                    board[col2][row2] = board[col1][row1];
                    board[col1][row1] = nullptr;
                    return true;
                }
                
            }
        }
    }
    return false;
}

shared_ptr<ChessPiece> ChessBoard::checkBoard(Location toCheck)
{
    bool col_v = false;
    bool row_v = false;
    
    //check if location is valid
    char col[] = { 'a','b','c','d','e','f','h','g' };
    int row[] = { 1,2,3,4,5,6,7,8 };//standard array
    for (int i = 0; i < 8; i++)
    {
        if (toCheck.col == col[i])
            col_v = true;
        if (toCheck.row == row[i])
            row_v = true;
    }
    if (col_v && row_v)
    {
        int col = 0, row = 0;
        switch (toCheck.col)
        {
            case 'a':col = 0; break;
            case 'b':col = 1; break;
            case 'c':col = 2; break;
            case 'd':col = 3; break;
            case 'e':col = 4; break;
            case 'f':col = 5; break;
            case 'g':col = 6; break;
            case 'h':col = 7; break;
        }
        row = toCheck.row - 1;//transfer the location into the array board
        return board[col][row];
    }
    return nullptr;
}





