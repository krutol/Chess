/*!
 * @file ChessBoard.h
 * @brief Declaration of the ChessBoard class for Assignments 7/8.
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
// ChessBoard class if we include this file more than once. They effectively
// tell the pre-processor, "only pay attention to the contents of this file if
// you haven't seen them before".
#if !defined(CHESSBOARD_H)
#define CHESSBOARD_H

#include "ChessUtils.h"
#include <memory>

class ChessPiece;

class ChessBoard
{
    public:
    // No constructor needed since board will initially be empty
    
    /**
     * Sets a ChessPiece into a particular location on the board.
     *
     * @params p: shared pointer to ChessPiece to be placed
     *         loc: location where piece is to be set
     *         @pre Location is a valid chess location
     *
     * @modifies board to have pointer to piece in given location
     */
    void setPiece(std::shared_ptr<ChessPiece> p, Location loc);

    /**
     * Requests the move of a piece from source to dest,
     * and executes it (including captures) if allowed.
     *
     * @params source - location of piece to be moved
     *         dest - place to be moved to
     *         @pre source/dest is a valid chess location
     *
     * @modifies if valid move, modifies board so source
     *           is nullptr, dest contains piece that was
     *           at source, and the piece that was at dest
     *           (if any) is set to captured
     *
     * @returns true if move is valid and made, false
     *          if move is invalid
     */
    bool movePiece(Location source, Location dest);

    /**
     * Gets ChessPiece at a particular location
     *
     * @params toCheck - space on board to be checked
     *         @pre toCheck is a valid chess location
     *
     * @modifies nothing
     * 
     * @returns pointer to whatever piece is in toCheck
     *          (nullptr if none)
     */
    std::shared_ptr<ChessPiece> checkBoard(Location toCheck);

    private:
    // Representation of board
    std::shared_ptr<ChessPiece> board[8][8];
};

#endif // the end of the CHESSBOARD_H header guard
