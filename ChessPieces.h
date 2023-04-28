/*!
 * @file ChessPieces.h
 * @brief Declaration of the ChessPiece class for Assignments 7/8.
 *
 * @author Andrew House <andrew.w.h.house@mun.ca>
 * @copyright (c) 2018 Andrew House. All rights reserved.
 * @license Apache License, Version 2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

// The following lines are "header guards": they prevent us from redefining the
// ChessPieces classes if we include this file more than once. They effectively
// tell the pre-processor, "only pay attention to the contents of this file if
// you haven't seen them before".
#if !defined(CHESSPIECES_H)
#define CHESSPIECES_H

#include "ChessUtils.h"
#include "ChessBoard.h"
#include <string>
#include <memory>

class ChessPiece
{
    public:
    /**
     * Parameterized constructor for ChessPiece.
     *
     * @params name: piece name
     *         t: Team piece belongs to
     *         start: starting location of piece
     *                @pre Location is a valid chess location
     *         b: shared pointer to ChessBoard object
     *
     * @modifies pieceName, myTeam, currentLocation, board to
     *           hold values passed in, captured to be false.
     */
    ChessPiece(std::string name, Team t, Location start,
               std::shared_ptr<ChessBoard> b);

    //! Accessor to return piece's team
    Team getTeam() const;
    //! Accessor to return piece's name
    std::string getName() const;

    //! Accessor to return piece's location
    Location getLocation() const;

    //! Accessor to see if piece has been captured
    bool isCaptured() const;

    //! Sets captured flag to true.
    void setCaptured();

    /**
     * Virtual move method for piece to make
     * a move in a chess game.
     * @pre piece is not captured
     *
     * @params n: destination location on board
     *            @pre location given in chess notation
     *
     * @modifies currentLocation (if move is valid)
     *
     * @returns true if the move to n is a valid move
     *          for this piece to make AND the board
     *          object allows the move, else false
     */
    virtual bool move(Location n);

    protected:
    const std::string pieceName; // name of piece
    const Team myTeam;           // black or white
    Location currentLocation;    // location on board
    std::shared_ptr<ChessBoard> board;  // pointer to board
    bool captured; // true if captured (and not in play)
};

enum class PromotionTarget {Rook, Bishop, Knight, Queen};

class Pawn : public ChessPiece
{
    public:
    //! Constructor for Pawn piece, same as ChessPiece constructor
    // Must initialize firstMove to true
    Pawn(std::string name, Team t, Location start,
               std::shared_ptr<ChessBoard> b);

    /**
     * If a Pawn is in the last row on the opponent's side
     * of the board, it can be promoted to a higher piece
     * (other than King)
     *
     * @params convertTo : piece type to promote to
     *
     * @modifies Pawn is replaced with a different object in game
     *
     * @returns pointer to newly created piece in same location
     *          as the promoted pawn.
     */
    
    std::shared_ptr<ChessPiece> promote(PromotionTarget convertTo);

    /**
     * Move method for pawn.  Allows it to move forward
     * 2 on first move, one thereafter.  Can move 1
     * forward diagonally to capture.
     *
     * @params n: destination location on board
     *            @pre location given in chess notation
     *
     * @modifies currentLocation (if move is valid)
     *
     * @returns true if the move to n is a valid move
     *          for this piece to make AND the board
     *          object allows the move, else false
     */

    bool move(Location n) override;


    private:
    // Flag is true if pawn hasn't made its first move yet,
    // false after making a move.
    bool firstMove;
};

class Knight : public ChessPiece
{
    public:
    Knight(std::string name, Team t, Location start,
               std::shared_ptr<ChessBoard> b);

    /**
     * Move method for Knight.  Can move in L-shape
     * (2 spaces up/down/left/right, then one space
     * left/right/up/down).
     *
     * @params n: destination location on board
     *            @pre location given in chess notation
     *
     * @modifies currentLocation (if move is valid)
     *
     * @returns true if the move to n is a valid move
     *          for this piece to make AND the board
     *          object allows the move, else false
     */

    bool move(Location n) override;

};

class Bishop : public ChessPiece
{
    public:
    Bishop(std::string name, Team t, Location start,
               std::shared_ptr<ChessBoard> b);

    /**
     * Move method for Bishop.  Allows it to move
     * any number of spaces diagonally.
     *
     * @params n: destination location on board
     *            @pre location given in chess notation
     *
     * @modifies currentLocation (if move is valid)
     *
     * @returns true if the move to n is a valid move
     *          for this piece to make AND the board
     *          object allows the move, else false
     */

    bool move(Location n) override;

};

class Rook : public ChessPiece
{
    public:
    Rook(std::string name, Team t, Location start,
               std::shared_ptr<ChessBoard> b);

    /**
     * Move method for Rook.  Allows it to any number
     * of spaces either left/right or up/down.
     *
     * @params n: destination location on board
     *            @pre location given in chess notation
     *
     * @modifies currentLocation (if move is valid)
     *
     * @returns true if the move to n is a valid move
     *          for this piece to make AND the board
     *          object allows the move, else false
     */

    bool move(Location n) override;


    private:
    bool inStartingPosition;
};

class Queen : public ChessPiece
{
    public:
    Queen(std::string name, Team t, Location start,
               std::shared_ptr<ChessBoard> b);

    /**
     * Move method for Queen.  Move any number of
     * spaces in any direction.
     *
     * @params n: destination location on board
     *            @pre location given in chess notation
     *
     * @modifies currentLocation (if move is valid)
     *
     * @returns true if the move to n is a valid move
     *          for this piece to make AND the board
     *          object allows the move, else false
     */

    bool move(Location n) override;


};

class King : public ChessPiece
{
    public:
    King(std::string name, Team t, Location start,
               std::shared_ptr<ChessBoard> b);

    /**
     * Move method for King.  Allows it to move 1 space
     * in any direction.
     *
     * @params n: destination location on board
     *            @pre location given in chess notation
     *
     * @modifies currentLocation (if move is valid)
     *
     * @returns true if the move to n is a valid move
     *          for this piece to make AND the board
     *          object allows the move, else false
     */
    bool move(Location n) override;

    /**
     * Special move for King.  Allows it to move 2 spaces
     * left/right toward a Rook, and the Rook it moves toward
     * jumps into the space the King crossed over.
     * 
     * @pre King, Rook involved are in starting locations
     * (In actual chess there are other requirements, but we'll
     * ignore them for this assignment.)
     *
     * @params n: destination location on board
     *            @pre location given in chess notation
     *
     * @modifies currentLocation of King and a Rook (if move is valid)
     *
     * @returns true if the move to n is a valid move
     *          for this piece to make AND the board
     *          object allows the move, else false
     */
    bool castle(Location n);

    private:
    bool inStartingPosition;
};
#endif // the end of the CHESSPIECES_H header guard
