/* This file includes the class which represents a board object */
#pragma once
#include "Shape.h"

/* This class represents a board (it's x,y starting coordinate, a matrix of block object and a player's score)*/
class Board {

	Block** board;
	Block start;
	int score;

public:

	/* this is a board's ctor that recieves the start block x and y coordinates (blocks that represents the starting block of the board)
	and sets them to be the current board stating point. 
	the function creates a board accordingly */
	Board(int x, int y);

	/* this function returns a reference to the board start point (represented by a BLOCK object) */
	Block& getStart() { return start; }

	/* This function prints the player's board , with it's filled/ not filled blocks */
	void printBoard();

	/* This function initializes the board ( sets all it's inner blocks (inside the boards frame) to be unfilled  */
	void initBoard();

	/* This function recieves a pointer to shape and sets the board to be filled with that shape, at the right location  */
	void fillBoard(Shape*& shape);

	/*  this function recieves a pointer to a shape and presents it on the right position in the board
	the function returns true if the shape was able to settle and false otherwise */
	bool checkHit(Shape& s);

	/* this function handles the case of the player's tetris (full line completed) */
	void didTetris();

	/* this function recieves an integer representing a row number and clears this row and lowers the blocks above it*/
	void lowerBlocks(int row);

	/* this function returns the score of the player's on the cuurent board */
	int getScore() { return score; }

	/* this function recieves a number and updates the score as a sum of the old score and the new number recieved */
	void addScore(int sum) { score += sum; }

	/* This is the distructor of the class Board; it deletes all the memory that was allocated for using this class  */
	~Board();
};