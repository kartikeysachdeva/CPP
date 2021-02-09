//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

void playMove(GameState& game_state) {
    
	int row = game_state.get_selectedRow();
    int col = game_state.get_selectedColumn();
    bool cur_Turn = game_state.get_turn();
    
    if (game_state.get_gameBoard(row, col) == Empty) {
    	game_state.set_gameBoard(row, col, (cur_Turn ? 1 : -1));
    	game_state.set_moveValid(true);
    }
    else {
    	game_state.set_moveValid(false);
    	game_state.set_gameOver(false);
    	game_state.set_winCode(0);
    	return;
    }
    
    // check if the game is over and update accordingly
    int ii;
    // 1 - Row 0 of the grid, cell (0,0) to cell (0,2)
    for (ii = 0; ii < boardSize; ++ii) {
    	int value = game_state.get_gameBoard(0, ii);
    	if (value != cur_Turn || value == Empty) {
    		game_state.set_winCode(0);
    		break;
		}
	}
	if (ii == boardSize) {
		game_state.set_winCode(1);
		game_state.set_gameOver(true);
		return;
	}
    
    // 2 - Row 1 of the grid, cell (1,0) to cell (1,2)
    for (ii = 0; ii < boardSize; ++ii) {
    	int value = game_state.get_gameBoard(1, ii);
    	if (value != cur_Turn || value == Empty) {
    		game_state.set_winCode(0);
    		break;
		}
	}
	if (ii == boardSize) {
		game_state.set_winCode(2);
		game_state.set_gameOver(true);
		return;
	}
    
    // 3 - Row 2 of the grid, cell (2,0) to cell (2,2)
	for (ii = 0; ii < boardSize; ++ii) {
		int value = game_state.get_gameBoard(2, ii);
    	if (value != cur_Turn || value == Empty) {
    		game_state.set_winCode(0);
    		break;
		}
	}
	if (ii == boardSize) {
		game_state.set_winCode(3);
		game_state.set_gameOver(true);
		return;
	}
	
	// 4 - Column 0 of the grid, cell (0,0) to cell (2,0)
	for (ii = 0; ii < boardSize; ++ii) {
		int value = game_state.get_gameBoard(ii, 0);
    	if (value != cur_Turn || value == Empty) {
    		game_state.set_winCode(0);
    		break;
		}
	}
	if (ii == boardSize) {
		game_state.set_winCode(4);
		game_state.set_gameOver(true);
		return;
	}
    
    // 5 - Column 1 of the grid, cell (0,1) to cell (2,1)
	for (ii = 0; ii < boardSize; ++ii) {
		int value = game_state.get_gameBoard(ii, 1);
    	if (value != cur_Turn || value == Empty) {
    		game_state.set_winCode(0);
    		break;
		}
	}
	if (ii == boardSize) {
		game_state.set_winCode(5);
		game_state.set_gameOver(true);
		return;
	}
    
    // 6 - Column 2 of the grid, cell (0,2) to cell (2,2)
	for (ii = 0; ii < boardSize; ++ii) {
		int value = game_state.get_gameBoard(ii, 2);
    	if (value != cur_Turn || value == Empty) {
    		game_state.set_winCode(0);
    		break;
		}
	}
	if (ii == boardSize) {
		game_state.set_winCode(6);
		game_state.set_gameOver(true);
		return;
	}
	
	// 7 - Left to right diagonal, cell (0,0) to cell (2,2)
	for (ii = 0; ii < boardSize; ++ii) {
    	int value = game_state.get_gameBoard(ii, ii);
    	if (value != cur_Turn || value == Empty) {
			game_state.set_winCode(0);
			break;
		}
	}
	if (ii == boardSize) {
		game_state.set_winCode(7);
		game_state.set_gameOver(true);
		return;
	}
	
	// 8 - Right to left diagonal, cell (2,0) to cell (0,2)
	for (ii = 0; ii < boardSize; --ii) {
		int value = game_state.get_gameBoard(2-ii, ii);
    	if (value != cur_Turn || value == Empty) {
    		game_state.set_winCode(0);
    		break;
		}
	}
	if (ii == boardSize) {
		game_state.set_winCode(8);
		game_state.set_gameOver(true);
		return;
	}
	
    // update the turn
	game_state.set_turn(!cur_Turn);
}

