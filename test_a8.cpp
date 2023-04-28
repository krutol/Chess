#include <string>
#include <iostream>
#include <vector>
#include "ChessUtils.h"
#include "ChessPieces.h"
#include "ChessBoard.h"
#include "ChessPlayer.h"
#include "ChessGame.h"
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

ostream& operator<< (ostream& o, Location loc)
{
    o << loc.col << loc.row;
    return o;    
}

int main()
{
    cout << "Starting tests of A8 ChessPlayer and ChessGame." << endl;
    unique_ptr<ChessGame> g(ChessGame::Create());
    if (g == nullptr)
    {
        cout << "Static Create() method failed, cannot test Player." << endl;
    }
    else
    {
        cout << "Static Create() returned a non-nullptr value." << endl;
        cout << "Let's start checking players and whatnot." << endl;
        shared_ptr<ChessPlayer> whitePlayer = g->getWhitePlayer();
        shared_ptr<ChessPlayer> blackPlayer = g->getBlackPlayer();
        shared_ptr<ChessBoard> theBoard = g->getBoard();

        if (whitePlayer->getTeam() == Team::White)
        {
            cout << "White Player has right team colour." << endl;
        }
        else
        {
            cout << "White Player has wrong colour!" << endl;
        }

        if (blackPlayer->getTeam() == Team::Black)
        {
            cout << "Black Player has right team colour." << endl;
        }
        else
        {
            cout << "Black Player has wrong colour!" << endl;
        }

        cout << "White Player has the following pieces:" << endl;
        for (auto p : whitePlayer->getPieces())
        {
            cout << "  " << p->getName() << " at location " << p->getLocation() << endl;
        }
        cout << "Black Player has the following pieces:" << endl;
        for (auto p : blackPlayer->getPieces())
        {
            cout << "  " << p->getName() << " at location " << p->getLocation() << endl;
        }
        cout << "Board sees the following pieces at the given locations:" << endl;
        char cols[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        for (int row = 1; row <= 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                Location bloc = {cols[col], row};
                cout << "  At location " << bloc << " board has ";
                shared_ptr<ChessPiece> temp = theBoard->checkBoard(bloc);
                if (temp == nullptr)
                {
                    cout << "nothing." << endl;
                }
                else
                {
                    cout << temp->getName() << " on team ";
                    if (temp->getTeam() == Team::White)
                    {
                        cout << "White." << endl;
                    }
                    else
                    {
                        cout << "Black." << endl;
                    }
                }
            }
        }
    }
    cout << "Basic Testing Done." << endl;
    cout << "Starting test of CreateFromFile()." << endl;
    unique_ptr<ChessGame> g2(ChessGame::CreateFromFile("chessmatch.pgn"));
    if (g2 == nullptr)
    {
        cout << "CreateFromFile() returned nullptr!" << endl;
    }
    else
    {
        cout << "CreateFromFile() produced a non-null game! Exploring state." << endl;
        cout << "Pieces/board should match the game described in the file after the step marked 12." << endl;
        shared_ptr<ChessPlayer> whitePlayer = g2->getWhitePlayer();
        shared_ptr<ChessPlayer> blackPlayer = g2->getBlackPlayer();
        shared_ptr<ChessBoard> theBoard = g2->getBoard();

        if (whitePlayer->getTeam() == Team::White)
        {
            cout << "White Player has right team colour." << endl;
        }
        else
        {
            cout << "White Player has wrong colour!" << endl;
        }

        if (blackPlayer->getTeam() == Team::Black)
        {
            cout << "Black Player has right team colour." << endl;
        }
        else
        {
            cout << "Black Player has wrong colour!" << endl;
        }

        cout << "White Player has the following pieces:" << endl;
        for (auto p : whitePlayer->getPieces())
        {
            cout << "  " << p->getName();
            if (p->isCaptured())
            {
                cout << "(captured)" << endl;
            }
            else
            {
                cout << " at location " << p->getLocation() << endl;
            }
        }
        cout << "Black Player has the following pieces:" << endl;
        for (auto p : blackPlayer->getPieces())
        {
            cout << "  " << p->getName();
            if (p->isCaptured())
            {
                cout << "(captured)" << endl;
            }
            else
            {
                cout << " at location " << p->getLocation() << endl;
            }
        }
        cout << "Board sees the following pieces at the given locations:" << endl;
        char cols[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        for (int row = 1; row <= 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                Location bloc = {cols[col], row};
                cout << "  At location " << bloc << " board has ";
                shared_ptr<ChessPiece> temp = theBoard->checkBoard(bloc);
                if (temp == nullptr)
                {
                    cout << "nothing." << endl;
                }
                else
                {
                    cout << temp->getName() << " on team ";
                    if (temp->getTeam() == Team::White)
                    {
                        cout << "White." << endl;
                    }
                    else
                    {
                        cout << "Black." << endl;
                    }
                }
            }
        }
    }
    cout << "Done testing of CreateFromFile()." << endl;
    return 0;
}
