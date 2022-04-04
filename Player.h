#pragma once
#include "Board.h"

/*This header file contains the Player class*/
enum class MOVES { NONE, RIGHT, LEFT, CLOCK, COUNTER, DROP };//enum of moves

class Player {
	Board* players_Board;
	Shape* current_Shape;
	int id;

public:
	/*This function is a player ctor that gets 3 integers*/
	Player(int x, int y, int id);

	/*This function gets a move enum and returns a boolean value that indicates wheather the player lost in this turn*/
	int takeTurn(MOVES& move);

	/*This function prints the shape out*/
	void printShape() { (*current_Shape).print();}

	/*This function print the players board out*/
	void printBoard();

	/*This function gets a move enum and moves the players' shape accordingly*/
	void makeMove(MOVES& m);

	/*This function checks wheather a player lost the game*/
	bool checkLost();

	/*This function drops the players' shape to the bottomn of the board*/
	void dropShape();

	/*This function returns an integer that represents the players' current score*/
	int getScore() { return this->players_Board->getScore(); }

	/* This is the distructor of the class Player; it deletes all the memory that was allocated for using this class  */
	~Player() { delete players_Board; delete current_Shape;}
};