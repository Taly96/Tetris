#pragma once
#include "Game.h"
#include "Settings.h"
#define NEWGAME 1
#define CONTINUE 2
#define INSTRUCTIONS 8
#define SETTINGS 7
#define EXIT 9

/*This header file contains the Menu class*/
class Menu {
	Game* game;
	bool inProgress = false;
public:
	/*This function is a Menu ctor*/
	Menu() { game = nullptr; }

	/*This function runs the game*/
	void run();

	/*This function prints the menu out*/
	void printMenu();

	/*This functions sets a new game*/
	void newGame();

	/*This function continues a paused game*/
	void continueGame();

	/*This function shows the games' instructions on the screen*/
	void showInstructions();

	/*This function sets the games' settings according to the players' requests*/
	void setSettings();

	/*This function prints out the games' settings to the screen*/
	void printSettings();

	/* This is the distructor of the class Menu; it deletes all the memory that was allocated for using this class  */
	~Menu();

};