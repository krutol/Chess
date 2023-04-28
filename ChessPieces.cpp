//
//  ChessPieces.cpp
//  A7
//
//  Created by 李子扬 on 2018-11-20.
//  Copyright © 2018 Ziyang Li. All rights reserved.
//

#include <stdlib.h>
#include "ChessPieces.h"
#include"ChessBoard.h"
#include"ChessUtils.h"
using namespace std;

ChessPiece::ChessPiece(string name, Team t, Location start,shared_ptr<ChessBoard> b):pieceName(name),myTeam(t),currentLocation(start),board(b)
{
    captured=false;
}

Team ChessPiece::getTeam() const
{
    return myTeam;
}

string ChessPiece::getName() const
{
    return pieceName;
}

Location ChessPiece::getLocation() const
{
    return currentLocation;
}

bool ChessPiece::isCaptured() const
{
    return captured;
}

void ChessPiece::setCaptured() {
    captured = true;
}

//virtual
bool ChessPiece::move(Location n)
{
    currentLocation = n;
    return true;
}

//Pawn

Pawn::Pawn(std::string name, Team t, Location start,std::shared_ptr<ChessBoard> b):ChessPiece(name,t,start,b)
{
    firstMove=true;
}

shared_ptr<ChessPiece> Pawn::promote(PromotionTarget convertTo)
{
    if (currentLocation.row == 7)
    {
        
        
        if (PromotionTarget::Rook == convertTo)
        {
            std::shared_ptr<ChessPiece> pro(new Rook("pro Rook ", myTeam, currentLocation, board));
            return pro;
        }
        else if(PromotionTarget::Bishop == convertTo)
        {
            std::shared_ptr<ChessPiece> pro(new Bishop("pro Bishop ", myTeam, currentLocation, board));
            return pro;
        }
        
        else if (PromotionTarget::Knight == convertTo)
        {
            std::shared_ptr<ChessPiece> pro(new Knight("pro Knight ", myTeam, currentLocation, board));
            return pro;
        }
        else if (PromotionTarget::Queen == convertTo)
        {
            std::shared_ptr<ChessPiece> pro(new Queen("pro Queen ", myTeam, currentLocation, board));
            return pro;
        }
    }
    return nullptr;
}

bool Pawn::move(Location n)
{
    bool col_v = false;
    bool row_v = false;
    
    //check if location is valid
    char col[] = { 'a','b','c','d','e','f','h','g' };
    int row[] = { 1,2,3,4,5,6,7,8 };//standard array
    for (int i = 0; i < 8; i++)
    {
        if (n.col == col[i])
            col_v = true;
        if (n.row == row[i])
            row_v = true;
    }
    if (col_v && row_v)
    {
        if (firstMove)
        {
            if (myTeam == Team::White)
            {
                if (((n.row == currentLocation.row + 1) || (n.row == currentLocation.row + 2)) && n.col == currentLocation.col)
                {
                    if (board->movePiece(currentLocation, n))
                    {
                        currentLocation = n;
                        firstMove = false;
                        return true;
                    }
                }
            }
            else
            {
                if (((n.row == currentLocation.row -1) || (n.row == currentLocation.row - 2)) && n.col == currentLocation.col)
                {
                    if (board->movePiece(currentLocation, n))
                    {
                        currentLocation = n;
                        firstMove = false;
                        return true;
                    }
                }
            }
        }
        else
        {
            if (myTeam == Team::White)
            {
                if ((n.row == currentLocation.row + 1))
                {
                    if (board->movePiece(currentLocation, n))
                    {
                        currentLocation = n;
                        firstMove = false;
                        return true;
                    }
                }
            }
            else
            {
                if ((n.row == currentLocation.row - 1))
                {
                    if (board->movePiece(currentLocation, n))
                    {
                        currentLocation = n;
                        firstMove = false;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//knight
Knight::Knight(std::string name, Team t, Location start,std::shared_ptr<ChessBoard> b):ChessPiece(name,t,start,b)
{
    
}

bool Knight::move(Location n)
{
    bool col_v = false;
    bool row_v = false;
    
    //check if location is valid
    char col[] = { 'a','b','c','d','e','f','h','g' };
    int row[] = { 1,2,3,4,5,6,7,8 };//standard array
    for (int i = 0; i < 8; i++)
    {
        if (n.col == col[i])
            col_v = true;
        if (n.row == row[i])
            row_v = true;
    }
    if (col_v && row_v) {
        int col1 = 0, col2 = 0;
        int row1 = 0, row2 = 0;
        switch (n.col)
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
        row1 = n.row - 1;
        switch (currentLocation.col)
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
        row2 = currentLocation.row - 1;
        if ((row1 == row2 + 2)||(row1 == row2 - 2))
        {
            if ((col1 == col2 + 1) || (col1 == col2 - 1))
            {
                if(board->movePiece(currentLocation,n))
                {
                    currentLocation = n;
                    return true;
                }
                
            }
        }
        else if((row1 == row2 + 1) || (row1 == row2 -1 ))
        {
            if ((col1 == col2 + 2) || (col1 == col2 - 2) )
            {
                if(board->movePiece(currentLocation,n))
                {
                    currentLocation = n;
                    return true;
                }
                
            }
        }
        
    }
    return false;
}

//Bishop
Bishop::Bishop(std::string name, Team t, Location start,std::shared_ptr<ChessBoard> b):ChessPiece(name,t,start,b)
{
    
}

bool Bishop::move(Location n)
{
    bool col_v = false;
    bool row_v = false;
    
    //check if location is valid
    char col[] = { 'a','b','c','d','e','f','h','g' };
    int row[] = { 1,2,3,4,5,6,7,8 };//standard array
    for (int i = 0; i < 8; i++)
    {
        if (n.col == col[i])
            col_v = true;
        if (n.row == row[i])
            row_v = true;
    }
    if (col_v && row_v)
    {
        int col1 = 0, col2 = 0;
        int row1 = 0, row2 = 0;
        switch (n.col)
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
        row1 = n.row - 1;
        switch (currentLocation.col)
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
        row2 = currentLocation.row - 1;
        if (abs(row1-row2)==abs(col1-col2))
        {
            if(board->movePiece(currentLocation,n))
            {
                currentLocation = n;
                return true;
            }
        }
    }
    return false; 
}

//Rook
Rook::Rook(std::string name, Team t, Location start,std::shared_ptr<ChessBoard> b):ChessPiece(name,t,start,b)
{
    inStartingPosition=true;
}

bool Rook::move(Location n)
{
    bool col_v = false;
    bool row_v = false;
    
    //check if location is valid
    char col[] = { 'a','b','c','d','e','f','h','g' };
    int row[] = { 1,2,3,4,5,6,7,8 };//standard array
    for (int i = 0; i < 8; i++)
    {
        if (n.col == col[i])
            col_v = true;
        if (n.row == row[i])
            row_v = true;
    }
    if (col_v && row_v) {
        int col1 = 0, col2 = 0;
        int row1 = 0, row2 = 0;
        switch (n.col)
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
        row1 = n.row - 1;
        switch (currentLocation.col)
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
        row2 = currentLocation.row - 1;
        if ((row1 == row2 || col1 == col2))
        {
            if(board->movePiece(currentLocation,n))
            {
                currentLocation = n;
                return true;
                
            }
        }
    }
    return false;
}

//Queen
Queen::Queen(std::string name, Team t, Location start,std::shared_ptr<ChessBoard> b):ChessPiece(name,t,start,b)
{
    
}

bool Queen::move(Location n)
{
    bool col_v = false;
    bool row_v = false;
    
    //check if location is valid
    char col[] = { 'a','b','c','d','e','f','h','g' };
    int row[] = { 1,2,3,4,5,6,7,8 };//standard array
    for(int i = 0; i < 8; i++)
    {
        if (n.col == col[i])
            col_v = true;
        if (n.row == row[i])
            row_v = true;
    }
    if (col_v && row_v)
    {
        int col1 = 0, col2 = 0;
        int row1 = 0, row2 = 0;
        switch (n.col)
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
        row1 = n.row - 1;
        switch (currentLocation.col)
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
        row2 = currentLocation.row - 1;
        if (abs(row1 - row2) == abs(col1 - col2)|| row1 == row2 || col1 == col2)
        {
            if(board->movePiece(currentLocation,n))
            {
                currentLocation = n;
                return true;
            }
            
        }
    }
    return false;
}

//King
King::King(std::string name, Team t, Location start,std::shared_ptr<ChessBoard> b):ChessPiece(name,t,start,b)
{
    inStartingPosition=true;
}

bool King::move(Location n)
{
    bool col_v = false;
    bool row_v = false;
    
    //check if location is valid
    char col[] = { 'a','b','c','d','e','f','h','g' };
    int row[] = { 1,2,3,4,5,6,7,8 };//standard array
    for (int i = 0; i < 8; i++)
    {
        if (n.col == col[i])
            col_v = true;
        if (n.row == row[i])
            row_v = true;
    }
    if (col_v && row_v)
    {
        int col1 = 0, col2 = 0;
        int row1 = 0, row2 = 0;
        switch (n.col)
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
        row1 = n.row - 1;
        switch (currentLocation.col)
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
        row2 = currentLocation.row - 1;
        if (abs(row1 - row2) == abs(col1 - col2) && abs(row1 - row2) == 1)
        {
            if(board->movePiece(currentLocation,n))
            {
                currentLocation = n;
                inStartingPosition = false;
                
                return true;
                
            }
        }
        else if (row1 == row2)
        {
            if (abs(col1 - col2) == 1)
            {
                if(board->movePiece(currentLocation,n))
                {
                    currentLocation = n;
                    inStartingPosition = false;
                    return true;
                }
                
            }
        }
        else if (col1 == col2)
        {
            if (abs(row1 - row2) == 1)
            {
                if(board->movePiece(currentLocation,n))
                {
                    currentLocation = n;
                    inStartingPosition = false;
                    return true;
                }
                
            }
        }
    }
    return false;
}

bool King::castle(Location n)
{
    bool col_v = false;
    bool row_v = false;
    int col1 = 0, col2 = 0;
    int row1 = 0, row2 = 0;
    //check if location is valid
    char col[] = { 'a','b','c','d','e','f','h','g' };
    int row[] = { 1,2,3,4,5,6,7,8 };//standard array
    for (int i = 0; i < 8; i++)
    {
        if (n.col == col[i])
            col_v = true;
        if (n.row == row[i])
            row_v = true;
    }
    if (col_v && row_v)
    {
        
        switch (n.col)
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
        row1 = n.row - 1;
        switch (currentLocation.col)
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
        row2 = currentLocation.row - 1;
        
    }
    std::shared_ptr<ChessPiece>r1 = board->checkBoard((struct Location) { 'a', currentLocation.row });
    std::shared_ptr<ChessPiece>r2 = board->checkBoard((struct Location) { 'h', currentLocation.row });
    
    if (inStartingPosition)
    {
        if (col1 == col2 + 2)
        {
            currentLocation = n;
            r2->move((struct Location) { 'f', currentLocation.row });
            inStartingPosition = false;
            return true;
        }
        
        else if  (col1 == col2 - 2)
        {
            currentLocation = n;
            r1->move(( struct Location ){ 'd', currentLocation.row });
            inStartingPosition = false;
            return true;
        }
    }
    else return false;
    return 0;
}




