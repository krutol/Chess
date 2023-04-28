//
//  ChessGame.cpp
//  A8
//
//  Created by 李子扬 on 2018-11-29.
//  Copyright © 2018 Ziyang Li. All rights reserved.
//

#include "ChessUtils.h"
#include "ChessGame.h"
#include "ChessPieces.h"
#include "ChessBoard.h"
#include "ChessPlayer.h"
#include <iostream>
#include <fstream>
using namespace std;

ChessGame::ChessGame(shared_ptr<ChessPlayer> w,
                     shared_ptr<ChessPlayer> b,
                     shared_ptr<ChessBoard> brd) :white(w), black(b), board(brd)
{
    
}

ChessGame* ChessGame::Create()
{
    try
    {
        shared_ptr<ChessBoard> brd(new ChessBoard());
        shared_ptr<ChessPlayer> w(new ChessPlayer(Team::White));
        shared_ptr<ChessPlayer> b(new ChessPlayer(Team::Black));
        
        shared_ptr<Pawn> whitePawn1(new Pawn("White Pawn 1", Team::White, (struct Location) {'a', 2 }, brd));
        w->addPiece(whitePawn1);
        shared_ptr<Pawn> whitePawn2(new Pawn("White Pawn 2", Team::White, (struct Location) { 'b', 2 }, brd));
        w->addPiece(whitePawn2);
        shared_ptr<Pawn> whitePawn3(new Pawn("White Pawn 3", Team::White, (struct Location) { 'c', 2 }, brd));
        w->addPiece(whitePawn3);
        shared_ptr<Pawn> whitePawn4(new Pawn("White Pawn 4", Team::White, (struct Location) { 'd', 2 }, brd));
        w->addPiece(whitePawn4);
        shared_ptr<Pawn> whitePawn5(new Pawn("White Pawn 5", Team::White, (struct Location) { 'e', 2 }, brd));
        w->addPiece(whitePawn5);
        shared_ptr<Pawn> whitePawn6(new Pawn("White Pawn 6", Team::White, (struct Location) { 'f', 2 }, brd));
        w->addPiece(whitePawn6);
        shared_ptr<Pawn> whitePawn7(new Pawn("White Pawn 7", Team::White, (struct Location) { 'g', 2 }, brd));
        w->addPiece(whitePawn7);
        shared_ptr<Pawn> whitePawn8(new Pawn("White Pawn 8", Team::White, (struct Location) { 'h', 2 }, brd));
        w->addPiece(whitePawn8);
        shared_ptr<Rook> whiteRook1(new Rook("White Rook 1", Team::White, (struct Location) { 'a', 1 }, brd));
        w->addPiece(whiteRook1);
        shared_ptr<Rook> whiteRook2(new Rook("White Rook 2", Team::White, (struct Location) { 'h', 1 }, brd));
        w->addPiece(whiteRook2);
        shared_ptr<Knight> whiteKnight1(new Knight("White Kight 1", Team::White, (struct Location) { 'b', 1 }, brd));
        w->addPiece(whiteKnight1);
        shared_ptr<Knight> whiteKnight2(new Knight("White Kight 2", Team::White, (struct Location) { 'g', 1 }, brd));
        w->addPiece(whiteKnight2);
        shared_ptr<Bishop> whiteBishop1(new Bishop("White Bishop 1", Team::White, (struct Location) { 'c', 1 }, brd));
        w->addPiece(whiteBishop1);
        shared_ptr<Bishop> whiteBishop2(new Bishop("White Bishop 2", Team::White, (struct Location) { 'f', 1 }, brd));
        w->addPiece(whiteBishop2);
        shared_ptr<King> whiteKing(new King("White King", Team::White, (struct Location) { 'e', 1 }, brd));
        w->addPiece(whiteKing);
        shared_ptr<Queen> whiteQueen(new Queen("White Queen", Team::White, (struct Location) { 'd', 1 }, brd));
        w->addPiece(whiteQueen);
        shared_ptr<Pawn> blackPawn1(new Pawn("Black Pawn 1", Team::Black, (struct Location) { 'a', 7 }, brd));
        b->addPiece(blackPawn1);
        shared_ptr<Pawn> blackPawn2(new Pawn("Black Pawn 2", Team::Black, (struct Location) { 'b', 7 }, brd));
        b->addPiece(blackPawn2);
        shared_ptr<Pawn> blackPawn3(new Pawn("Black Pawn 3", Team::Black, (struct Location) { 'c', 7 }, brd));
        b->addPiece(blackPawn3);
        shared_ptr<Pawn> blackPawn4(new Pawn("Black Pawn 4", Team::Black, (struct Location) { 'd', 7 }, brd));
        b->addPiece(blackPawn4);
        shared_ptr<Pawn> blackPawn5(new Pawn("Black Pawn 5", Team::Black, (struct Location) { 'e', 7 }, brd));
        b->addPiece(blackPawn5);
        shared_ptr<Pawn> blackPawn6(new Pawn("Black Pawn 6", Team::Black, (struct Location) { 'f', 7 }, brd));
        b->addPiece(blackPawn6);
        shared_ptr<Pawn> blackPawn7(new Pawn("Black Pawn 7", Team::Black, (struct Location) { 'g', 7 }, brd));
        b->addPiece(blackPawn7);
        shared_ptr<Pawn> blackPawn8(new Pawn("Black Pawn 8", Team::Black, (struct Location) { 'h', 7 }, brd));
        b->addPiece(blackPawn8);
        shared_ptr<Rook> blackRook1(new Rook("Black Rook 1", Team::Black, (struct Location) { 'a', 8 }, brd));
        b->addPiece(blackRook1);
        shared_ptr<Rook> blackRook2(new Rook("Black Rook 2", Team::Black, (struct Location) { 'h', 8 }, brd));
        b->addPiece(blackRook2);
        shared_ptr<Knight> blackKnight1(new Knight("Black Kight 1", Team::Black, (struct Location) { 'b', 8 }, brd));
        b->addPiece(blackKnight1);
        shared_ptr<Knight> blackKnight2(new Knight("Black Kight 2", Team::Black, (struct Location) { 'g', 8 }, brd));
        b->addPiece(blackKnight2);
        shared_ptr<Bishop> blackBishop1(new Bishop("Black Bishop 1", Team::Black, (struct Location) { 'c', 8 }, brd));
        b->addPiece(blackBishop1);
        shared_ptr<Bishop> blackBishop2(new Bishop("Black Bishop 2", Team::Black, (struct Location ){ 'f', 8 }, brd));
        b->addPiece(blackBishop2);
        shared_ptr<King> blackKing(new King("Black King", Team::Black, (struct Location) { 'e', 8 }, brd));
        b->addPiece(blackKing);
        shared_ptr<Queen> blackQueen(new Queen("Black Queen", Team::Black, (struct Location) { 'd', 8 }, brd));
        b->addPiece(blackQueen);
        brd->setPiece(whitePawn1, whitePawn1->getLocation());
        brd->setPiece(whitePawn2, whitePawn2->getLocation());
        brd->setPiece(whitePawn3, whitePawn3->getLocation());
        brd->setPiece(whitePawn4, whitePawn4->getLocation());
        brd->setPiece(whitePawn5, whitePawn5->getLocation());
        brd->setPiece(whitePawn6, whitePawn6->getLocation());
        brd->setPiece(whitePawn7, whitePawn7->getLocation());
        brd->setPiece(whitePawn8, whitePawn8->getLocation());
        brd->setPiece(blackPawn1, blackPawn1->getLocation());
        brd->setPiece(blackPawn2, blackPawn2->getLocation());
        brd->setPiece(blackPawn3, blackPawn3->getLocation());
        brd->setPiece(blackPawn4, blackPawn4->getLocation());
        brd->setPiece(blackPawn5, blackPawn5->getLocation());
        brd->setPiece(blackPawn6, blackPawn6->getLocation());
        brd->setPiece(blackPawn7, blackPawn7->getLocation());
        brd->setPiece(blackPawn8, blackPawn8->getLocation());
        brd->setPiece(whiteBishop1, whiteBishop1->getLocation());
        brd->setPiece(whiteBishop2, whiteBishop2->getLocation());
        brd->setPiece(whiteKnight1, whiteKnight1->getLocation());
        brd->setPiece(whiteKnight2, whiteKnight2->getLocation());
        brd->setPiece(whiteRook1, whiteRook1->getLocation());
        brd->setPiece(whiteRook2, whiteRook2->getLocation());
        brd->setPiece(whiteKing, whiteKing->getLocation());
        brd->setPiece(whiteQueen, whiteQueen->getLocation());
        ChessGame* chessGame(new ChessGame(w, b, brd));
        return chessGame;
    }
    catch (exception e)
    {
        return nullptr;
    }
}

ChessGame* ChessGame::CreateFromFile(string filename)
{
    try
    {
        ChessGame* chessGame(Create());
        constexpr size_t Length = sizeof(ChessGame);
        char buffer[Length];
        fstream file;
//        file(filename, ios::in | ios::binary);
        file.read(buffer, Length);
        file.close();
        chessGame = reinterpret_cast<ChessGame*> (buffer);
        return chessGame;
    }
    catch (exception e)
    {
        return nullptr;
    }
}

std::shared_ptr<ChessPlayer> ChessGame::getWhitePlayer()
{
    return white;
}

std::shared_ptr<ChessPlayer> ChessGame::getBlackPlayer()
{
    return black;
}

std::shared_ptr<ChessBoard> ChessGame::getBoard()
{
    return board;
}
