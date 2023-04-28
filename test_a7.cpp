#include <iostream>
#include "ChessUtils.h"
#include "ChessPieces.h"
#include "ChessBoard.h"
#include <memory>
using namespace std;

bool operator==(Location a, Location b)
{
    if ((a.col == b.col) and (a.row == b.row))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << "Starting tests of ChessPiece subclasses and ChessBoard." << endl;
    // Create a ChessBoard
    shared_ptr<ChessBoard> theBoard(new ChessBoard());

    // Create white pawn, rook, bishop, knight, queen, and king
    shared_ptr<Pawn> whitePawn(new Pawn("White Pawn", Team::White, (struct Location){'e', 2}, theBoard));
    shared_ptr<Rook> whiteRook(new Rook("White Rook", Team::White, (struct Location){'a', 1}, theBoard));
    shared_ptr<Bishop> whiteBishop(new Bishop("White Bishop", Team::White, (struct Location){'c', 1}, theBoard));
    shared_ptr<Knight> whiteKnight(new Knight("White Knight", Team::White, (struct Location){'f', 3}, theBoard));
    shared_ptr<Queen> whiteQueen(new Queen("White Queen", Team::White, (struct Location){'d', 1}, theBoard));
    shared_ptr<King> whiteKing(new King("White King", Team::White, (struct Location){'e', 1}, theBoard));

    // Create black pawns, Queen, and King, bishop, knight, rook
    shared_ptr<Pawn> blackPawn1(new Pawn("Black Pawn 1", Team::Black, (struct Location){'h', 1}, theBoard));
    shared_ptr<Pawn> blackPawn2(new Pawn("Black Pawn 2", Team::Black, (struct Location){'g', 7}, theBoard));
    shared_ptr<Queen> blackQueen(new Queen("Black Queen", Team::Black, (struct Location){'d', 8}, theBoard));
    shared_ptr<King> blackKing(new King("Black King", Team::Black, (struct Location){'e', 8}, theBoard));
    shared_ptr<Rook> blackRook(new Rook("Black Rook", Team::Black, (struct Location){'h', 8}, theBoard));
    shared_ptr<Bishop> blackBishop(new Bishop("Black Bishop", Team::Black, (struct Location){'c', 8}, theBoard));
    shared_ptr<Knight> blackKnight(new Knight("Black Knight", Team::Black, (struct Location){'b', 8}, theBoard));

    // Add pieces to board
    cout << "Adding to board" << endl;
    theBoard->setPiece(whitePawn, whitePawn->getLocation());
    theBoard->setPiece(whiteRook, whiteRook->getLocation());
    theBoard->setPiece(whiteKnight, whiteKnight->getLocation());
    theBoard->setPiece(whiteBishop, whiteBishop->getLocation());
    theBoard->setPiece(whiteKing, whiteKing->getLocation());
    theBoard->setPiece(whiteQueen, whiteQueen->getLocation());
    theBoard->setPiece(blackKing, blackKing->getLocation());
    theBoard->setPiece(blackQueen, blackQueen->getLocation());
    theBoard->setPiece(blackPawn1, blackPawn1->getLocation());
    theBoard->setPiece(blackPawn2, blackPawn2->getLocation());
    theBoard->setPiece(blackBishop, blackBishop->getLocation());
    theBoard->setPiece(blackRook, blackRook->getLocation());
    theBoard->setPiece(blackKnight, blackKnight->getLocation());
    
    cout << "Setup complete.  Starting testing of invalid moves." << endl;

    // Invalid move for Pawn
    Location startLoc = whitePawn->getLocation();
    Location destLoc = {'g', 4};
    if ((whitePawn->move(destLoc) == false) and
        (whitePawn->getLocation() == startLoc))
    {
        cout << "Pawn rejects move as it should." << endl;
    }
    else
    {
        cout << "Pawn moved when it shouldn't!" << endl;
    }

    // Invalid move for Bishop
    startLoc = whiteBishop->getLocation();
    destLoc = {'b', 1};
    if ((whiteBishop->move(destLoc) == false) and
        (whiteBishop->getLocation() == startLoc))
    {
        cout << "Bishop rejects move as it should." << endl;
    }
    else
    {
        cout << "Bishop moved when it shouldn't!" << endl;
    }

    // Invalid move for Rook
    startLoc = whiteRook->getLocation();
    destLoc = {'b', 2};
    if ((whiteRook->move(destLoc) == false) and
        (whiteRook->getLocation() == startLoc))
    {
        cout << "Rook rejects move as it should." << endl;
    }
    else
    {
        cout << "Rook moved when it shouldn't!" << endl;
    }

    // Invalid move for Knight
    startLoc = whiteKnight->getLocation();
    destLoc = {'f', 4};
    if ((whiteKnight->move(destLoc) == false) and
        (whiteKnight->getLocation() == startLoc))
    {
        cout << "Knight rejects move as it should." << endl;
    }
    else
    {
        cout << "Knight moved when it shouldn't!" << endl;
    }

    // Invalid move for King (would capture its queen)
    startLoc = whiteKing->getLocation();
    destLoc = {'d', 1};
    if ((whiteKing->move(destLoc) == false) and
        (whiteKing->getLocation() == startLoc))
    {
        cout << "King rejects move as it should." << endl;
    }
    else
    {
        cout << "King moved when it shouldn't!" << endl;
    }

    // Invalid move for Queen
    startLoc = blackQueen->getLocation();
    destLoc = {'c', 4};
    if ((blackQueen->move(destLoc) == false) and
        (blackQueen->getLocation() == startLoc))
    {
        cout << "Queen rejects move as it should." << endl;
    }
    else
    {
        cout << "Queen moved when it shouldn't!" << endl;
    }
    
    // Reset board for testing successful moves
    shared_ptr<ChessBoard> cleanSlate(new ChessBoard());
    theBoard = cleanSlate;

// Create white pawn, rook, bishop, knight, queen, and king
    shared_ptr<Pawn> nwhitePawn(new Pawn("White Pawn", Team::White, (struct Location){'e', 2}, theBoard));
    shared_ptr<Pawn> whitePawn2(new Pawn("White Pawn 2", Team::White, (struct Location){'h', 6}, theBoard));
    shared_ptr<Rook> nwhiteRook(new Rook("White Rook", Team::White, (struct Location){'a', 1}, theBoard));
    shared_ptr<Bishop> nwhiteBishop(new Bishop("White Bishop", Team::White, (struct Location){'c', 1}, theBoard));
    shared_ptr<Knight> nwhiteKnight(new Knight("White Knight", Team::White, (struct Location){'f', 3}, theBoard));
    shared_ptr<Queen> nwhiteQueen(new Queen("White Queen", Team::White, (struct Location){'d', 1}, theBoard));
    shared_ptr<King> nwhiteKing(new King("White King", Team::White, (struct Location){'e', 1}, theBoard));

    // Create black pawns, Queen, and King, bishop, knight, rook
    shared_ptr<Pawn> nblackPawn1(new Pawn("Black Pawn 1", Team::Black, (struct Location){'h', 1}, theBoard));
    shared_ptr<Pawn> nblackPawn2(new Pawn("Black Pawn 2", Team::Black, (struct Location){'g', 7}, theBoard));
    shared_ptr<Pawn> blackPawn3(new Pawn("Black Pawn 3", Team::Black, (struct Location){'a', 7}, theBoard));
    shared_ptr<Queen> nblackQueen(new Queen("Black Queen", Team::Black, (struct Location){'d', 8}, theBoard));
    shared_ptr<King> nblackKing(new King("Black King", Team::Black, (struct Location){'e', 8}, theBoard));
    shared_ptr<Rook> nblackRook(new Rook("Black Rook", Team::Black, (struct Location){'h', 8}, theBoard));
    shared_ptr<Bishop> nblackBishop(new Bishop("Black Bishop", Team::Black, (struct Location){'c', 8}, theBoard));
    shared_ptr<Knight> nblackKnight(new Knight("Black Knight", Team::Black, (struct Location){'b', 8}, theBoard));

    // Overwrite old piece pointers
    whitePawn = nwhitePawn;
    whiteRook = nwhiteRook;
    whiteKnight = nwhiteKnight;
    whiteBishop = nwhiteBishop;
    whiteKing = nwhiteKing;
    whiteQueen = nwhiteQueen;
    blackKing = nblackKing;
    blackQueen = nblackQueen;
    blackPawn1 = nblackPawn1;
    blackPawn2 = nblackPawn2;
    blackBishop = nblackBishop;
    blackRook = nblackRook;
    blackKnight = nblackKnight;

    // Add pieces to board
    cout << "Adding to board" << endl;
    theBoard->setPiece(whitePawn, whitePawn->getLocation());
    theBoard->setPiece(whitePawn2, whitePawn2->getLocation());
    theBoard->setPiece(whiteRook, whiteRook->getLocation());
    theBoard->setPiece(whiteKnight, whiteKnight->getLocation());
    theBoard->setPiece(whiteBishop, whiteBishop->getLocation());
    theBoard->setPiece(whiteKing, whiteKing->getLocation());
    theBoard->setPiece(whiteQueen, whiteQueen->getLocation());
    theBoard->setPiece(blackKing, blackKing->getLocation());
    theBoard->setPiece(blackQueen, blackQueen->getLocation());
    theBoard->setPiece(blackPawn1, blackPawn1->getLocation());
    theBoard->setPiece(blackPawn2, blackPawn2->getLocation());
    theBoard->setPiece(blackPawn3, blackPawn3->getLocation());
    theBoard->setPiece(blackBishop, blackBishop->getLocation());
    theBoard->setPiece(blackRook, blackRook->getLocation());
    theBoard->setPiece(blackKnight, blackKnight->getLocation());

    cout << "Resetting board and starting testing of valid moves." << endl;

    // Valid move for Pawns
    startLoc = whitePawn->getLocation();
    destLoc = {'e', 4};
    if ((whitePawn->move(destLoc) == true) and
        (whitePawn->getLocation() == destLoc) and
        (theBoard->checkBoard(destLoc) == whitePawn))
    {
        cout << "White Pawn move success!" << endl;
    }
    else
    {
        cout << "White Pawn move failed!" << endl;
    }

    startLoc = blackPawn3->getLocation();
    destLoc = {'a', 6};
    if ((blackPawn3->move(destLoc) == true) and
        (blackPawn3->getLocation() == destLoc) and
        (theBoard->checkBoard(destLoc) == blackPawn3))
    {
        cout << "Black Pawn 3 move success!" << endl;
    }
    else
    {
        cout << "Black Pawn 3 move failed!" << endl;
    }

    // Move black pawn 2 diagonally to capture white pawn 2
    startLoc = blackPawn2->getLocation();
    destLoc = {'h', 6};
    if ((blackPawn2->move(destLoc) == true) and
        (blackPawn2->getLocation() == destLoc) and
        (theBoard->checkBoard(destLoc) == blackPawn2))
    {
        cout << "Black Pawn 2 move success!" << endl;
    }
    else
    {
        cout << "Black Pawn 2 move failed!" << endl;
    }

    if (whitePawn2->isCaptured())
    {
        cout << "Capture of White Pawn 2 by Black Pawn 2 correctly recorded." << endl;
    }
    else
    {
        cout << "Capture of White Pawn 2 not set properly." << endl;
    }

    // Valid move for Bishop
    startLoc = whiteBishop->getLocation();
    destLoc = {'a', 3};
    if ((whiteBishop->move(destLoc) == true) and
        (whiteBishop->getLocation() == destLoc) and
        (theBoard->checkBoard(destLoc) == whiteBishop))
    {
        cout << "Bishop move success!" << endl;
    }
    else
    {
        cout << "Bishop move failed!" << endl;
    }

    // Valid move for Rook
    startLoc = whiteRook->getLocation();
    destLoc = {'a', 2};
    if ((whiteRook->move(destLoc) == true) and
        (whiteRook->getLocation() == destLoc) and
        (theBoard->checkBoard(destLoc) == whiteRook))
    {
        cout << "Rook move success!" << endl;
    }
    else
    {
        cout << "Rook move failed!" << endl;
    }

    // Valid move for Knight
    startLoc = whiteKnight->getLocation();
    destLoc = {'e', 5};
    if ((whiteKnight->move(destLoc) == true) and
        (whiteKnight->getLocation() == destLoc) and
        (theBoard->checkBoard(destLoc) == whiteKnight))
    {
        cout << "Knight move success!" << endl;
    }
    else
    {
        cout << "Knight move failed!" << endl;
    }

    // Valid move for King
    startLoc = whiteKing->getLocation();
    destLoc = {'f', 1};
    if ((whiteKing->move(destLoc) == true) and
        (whiteKing->getLocation() == destLoc) and
        (theBoard->checkBoard(destLoc) == whiteKing))
    {
        cout << "King move success!" << endl;
    }
    else
    {
        cout << "King move failed!" << endl;
    }

    // Valid move for Queen (with capture!)
    startLoc = whiteQueen->getLocation();
    destLoc = {'d', 8};
    if ((whiteQueen->move(destLoc) == true) and
        (whiteQueen->getLocation() == destLoc) and
        (theBoard->checkBoard(destLoc) == whiteQueen))
    {
        cout << "Queen move success!" << endl;
    }
    else
    {
        cout << "Queen move failed!" << endl;
    }

    if (blackQueen->isCaptured())
    {
        cout << "Other Queen correctly marked as captured after last move." << endl;
    }
    else
    {
        cout << "Error! Other Queen should be captured but isn't." << endl;
    }

    // Test special methods
    cout << "Testing castle() method of Black King." << endl;
    // Valid move for King
    startLoc = blackKing->getLocation();
    destLoc = {'g', 8};
    Location rookLoc = {'h', 8};
    Location rookDest = {'f', 8};
    shared_ptr<ChessPiece> probablyRook = theBoard->checkBoard(rookLoc);
    if ((blackKing->castle(destLoc) == true) and
        (blackKing->getLocation() == destLoc) and
        (theBoard->checkBoard(destLoc) == blackKing) and
        (theBoard->checkBoard(rookDest) == blackRook) ) 
    {
        cout << "Castle move success!" << endl;
    }
    else
    {
        cout << "Castle move failed!" << endl;
    }

    cout << "Testing pawn promotion to Queen." << endl;
    shared_ptr<ChessPiece> retval = blackPawn1->promote(PromotionTarget::Queen);
    startLoc = blackPawn1->getLocation();
    if (retval != nullptr)
    {
        shared_ptr<Queen> queenVal = dynamic_pointer_cast<Queen>(retval);
        if ((queenVal != nullptr) and (queenVal->getLocation() == startLoc) and (queenVal->getTeam() == blackPawn1->getTeam()))
        {
            cout << "Promotion of Black Pawn 1 to a Black Queen worked!" << endl;
        }
        else    
        {
            cout << "Error! Pawn promotion didn't return a Queen." << endl;
        }    
    }
    else
    {
        cout << "Promotion returned nullptr :(" << endl;
    }
    cout << "Basic Testing Done." << endl;
    return 0;
}
