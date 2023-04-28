/*!
 * @file ChessUtils.h
 * @brief Declarations of utility enums and classes for Assignments 7/8.
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
// ChessUtils header if we include this file more than once. They effectively
// tell the pre-processor, "only pay attention to the contents of this file if
// you haven't seen them before".
#if !defined(CHESSUTILS_H)
#define CHESSUTILS_H

enum class Team {Black, White};

// https://en.wikipedia.org/wiki/Algebraic_notation_(chess)
struct Location
{
    char col;
    int row;
};



#endif // the end of the CHESSUTILS_H header guard



