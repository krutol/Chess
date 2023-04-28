/*!
 * @file ChessGame.h
 * @brief Declaration of the ChessGame class for Assignments 7/8.
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
// ChessGame class if we include this file more than once. They effectively
// tell the pre-processor, "only pay attention to the contents of this file if
// you haven't seen them before".
#if !defined(CHESSGAME_H)
#define CHESSGAME_H

#include "ChessUtils.h"
#include <memory>
#include <string>

// Forward declaration of other classes
class ChessPiece;
class ChessBoard;
class ChessPlayer;

class ChessGame
{
    public:

    /** Create ******************************************
    *
    * Static method to create a ChessGame object by 
    * creating two ChessPlayer objects, all the appropriate
    * kinds of pieces (in starting locations), a ChessBoard,
    * and passing them all to the constructor of ChessGame.
    *
    *
    * @returns pointer to newly-created ChessGame object,
    *          or nullptr if error
    */
    static ChessGame* Create();

    /** CreateFromFile **********************************
    *
    * Static method to create a ChessGame object and read
    * a PGN file and execute each move to leave the game
    * in a state as dictated by the file.
    *
    *
    * @params filename - name of file to use
    *
    * @returns pointer to newly-created ChessGame in state
    *          as read from supplied file, or nullptr if error
    */
    static ChessGame* CreateFromFile(std::string filename);

    //! Gets pointer to white player
    std::shared_ptr<ChessPlayer> getWhitePlayer();

    //! Gets pointer to black player
    std::shared_ptr<ChessPlayer> getBlackPlayer();

    //! Gets pointer to board
    std::shared_ptr<ChessBoard> getBoard();

    private:
    ChessGame(std::shared_ptr<ChessPlayer> w,
              std::shared_ptr<ChessPlayer> b,
              std::shared_ptr<ChessBoard> brd);

    std::shared_ptr<ChessPlayer> white, black;
    std::shared_ptr<ChessBoard> board;
};

#endif // the end of the CHESSGAME_H header guard
