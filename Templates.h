#pragma once
#include "Block.h"
#define SIZE 4
enum class SIDE { UP, RIGHT, DOWN, LEFT }; //enum of sides

/*This header file contains the templates class*/
class Templates {

public:
	/*This function gets a SIDE enum and returns a Block that represent the cubic shape in the game*/
	static Block* getO(SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the S shape in the game*/
	static Block* getS(SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the Z shape in the game*/
	static Block* getZ(SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the T shape in the game*/
	static Block* getT(SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the J shape in the game*/
	static Block* getJ(SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the L shape in the game*/
	static Block* getL(SIDE& side);

	/*This function gets a SIDE enum and returns a Block that represent the | shape in the game*/
	static Block* getI(SIDE& side);
};