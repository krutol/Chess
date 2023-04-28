//
//  ChessPlayer.cpp
//  A8
//
//  Created by 李子扬 on 2018-11-29.
//  Copyright © 2018 Ziyang Li. All rights reserved.
//

#include "ChessPlayer.h"
#include "ChessUtils.h"
#include "ChessPieces.h"

ChessPlayer::ChessPlayer(Team t)
{
    myTeam = t;
}

void ChessPlayer::addPiece(std::shared_ptr<ChessPiece> p)
{
    if (myTeam == p->getTeam())
        myPieces[myPieces.size() + 1] = p;//add a new element to the vector
}

std::vector< std::shared_ptr<ChessPiece> > ChessPlayer::getPieces()
{
    std::vector< std::shared_ptr<ChessPiece> > list = *new std::vector< std::shared_ptr<ChessPiece> >();
    for (int i = 0; i < myPieces.size(); i++)
    {
        list[i] = myPieces[i];
    }
    return list;
}

