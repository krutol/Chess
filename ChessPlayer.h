/*!
 * @file ChessPlayer.h
 * @brief Declaration of the ChessPlayer class for Assignments 7/8.
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
// ChessPlayer class if we include this file more than once. They effectively
// tell the pre-processor, "only pay attention to the contents of this file if
// you haven't seen them before".
#if !defined(CHESSPLAYER_H)
#define CHESSPLAYER_H

#include "ChessUtils.h"
#include <memory>
#include <vector>

class ChessPiece;
class ChessBoard;

class ChessPlayer
{
    public:
    //! Constructor
    ChessPlayer(Team t);

    /**
     * Adds appropriate chess piece to player's control.
     *
     * @params p: pointer to piece to add to player
     *         @pre p's team is same as player's
     *
     * @modifies myPieces to contain p
     */
    void addPiece(std::shared_ptr<ChessPiece> p);

    /**
     * Gets list of player's pieces
     *
     * @returns copy of myPieces
     */
    std::vector< std::shared_ptr<ChessPiece> > getPieces();
    
    //! Accessor to get team
    Team getTeam() { return myTeam; };

    private:
    Team myTeam;
    std::vector< std::shared_ptr<ChessPiece> > myPieces;
};

#endif // the end of the CHESSPLAYER_H header guard
