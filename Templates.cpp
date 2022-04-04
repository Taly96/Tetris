#include "Templates.h"

/*Every function in this cpp file sets a Block with the coords according to wanted shape whilst coord[0]
is the pivot coord and returns it*/
Block* Templates::getT(SIDE& side)
{
	Block* blocks = new Block[SIZE];
	switch (side)
	{
	case SIDE::UP:
		blocks[1].setY(1);
		blocks[2].setX(-1);
		blocks[3].setX(1);
		break;

	case SIDE::RIGHT:
		blocks[1].setY(-1);
		blocks[2].setY(1);
		blocks[3].setX(1);
		break;

	case SIDE::DOWN:
		blocks[1].setX(-1);
		blocks[2].setY(-1);
		blocks[3].setX(1);
		break;

	case SIDE::LEFT:
		blocks[1].setY(-1);
		blocks[2].setY(1);
		blocks[3].setX(-1);
		break;

	default:
		break;
	}
	return blocks;
}

Block* Templates::getI(SIDE& side)
{
	Block* blocks = new Block[SIZE];
	switch (side)
	{
	case SIDE::UP:
		blocks[1].setY(-1);
		blocks[2].setY(1);
		blocks[3].setY(2);
		break;

	case SIDE::RIGHT:
		blocks[1].setX(1);
		blocks[2].setX(2);
		blocks[3].setX(-1);
		break;

	case SIDE::DOWN:
		blocks[1].setY(-1);
		blocks[2].setY(1);
		blocks[3].setY(2);
		break;

	case SIDE::LEFT:
		blocks[1].setX(1);
		blocks[2].setX(2);
		blocks[3].setX(-1);
		break;

	default:
		break;
	}
	return blocks;
}


Block* Templates::getJ(SIDE& side)
{
	Block* blocks = new Block[SIZE];
	switch (side)
	{
	case SIDE::UP:
		blocks[1].setY(-1);
		blocks[2].setY(1);
		blocks[3].setY(1);
		blocks[3].setX(-1);
		break;

	case SIDE::RIGHT:
		blocks[1].setX(1);
		blocks[2].setX(-1);
		blocks[3].setX(-1);
		blocks[3].setY(-1);
		break;

	case SIDE::DOWN:
		blocks[1].setY(-1);
		blocks[2].setY(1);
		blocks[3].setY(-1);
		blocks[3].setX(1);
		break;

	case SIDE::LEFT:
		blocks[1].setX(-1);
		blocks[2].setX(1);
		blocks[3].setX(1);
		blocks[3].setY(1);
		break;

	default:
		break;
	}
	return blocks;
}

Block* Templates::getL(SIDE& side)
{
	Block* blocks = new Block[SIZE];
	switch (side)
	{
	case SIDE::UP:
		blocks[1].setY(-1);
		blocks[2].setY(1);
		blocks[3].setY(1);
		blocks[3].setX(1);
		break;

	case SIDE::RIGHT:
		blocks[1].setX(1);
		blocks[2].setX(-1);
		blocks[3].setX(-1);
		blocks[3].setY(1);
		break;

	case SIDE::DOWN:
		blocks[1].setY(-1);
		blocks[2].setY(1);
		blocks[3].setY(-1);
		blocks[3].setX(-1);
		break;

	case SIDE::LEFT:
		blocks[1].setX(-1);
		blocks[2].setX(1);
		blocks[3].setX(1);
		blocks[3].setY(-1);
		break;

	default:
		break;
	}
	return blocks;
}

Block* Templates::getO(SIDE& side)
{
	Block* blocks = new Block[SIZE];
	switch (side)
	{
	case SIDE::UP:
		blocks[1].setY(-1);
		blocks[2].setX(-1);
		blocks[3].setY(-1);
		blocks[3].setX(-1);
		break;

	case SIDE::RIGHT:
		blocks[1].setY(-1);
		blocks[2].setX(-1);
		blocks[3].setY(-1);
		blocks[3].setX(-1);
		break;

	case SIDE::DOWN:
		blocks[1].setY(-1);
		blocks[2].setX(-1);
		blocks[3].setY(-1);
		blocks[3].setX(-1);
		break;

	case SIDE::LEFT:
		blocks[1].setY(-1);
		blocks[2].setX(-1);
		blocks[3].setY(-1);
		blocks[3].setX(-1);
		break;

	default:
		break;
	}
	return blocks;
}


Block* Templates::getS(SIDE& side)
{
	Block* blocks = new Block[SIZE];
	switch (side)
	{
	case SIDE::UP:
		blocks[1].setY(-1);
		blocks[2].setX(-1);
		blocks[3].setY(-1);
		blocks[3].setX(1);
		break;

	case SIDE::RIGHT:
		blocks[1].setY(1);
		blocks[2].setX(-1);
		blocks[3].setY(-1);
		blocks[3].setX(-1);
		break;

	case SIDE::DOWN:
		blocks[1].setY(-1);
		blocks[2].setX(-1);
		blocks[3].setY(-1);
		blocks[3].setX(1);
		break;

	case SIDE::LEFT:
		blocks[1].setY(1);
		blocks[2].setX(-1);
		blocks[3].setY(-1);
		blocks[3].setX(-1);
		break;

	default:
		break;
	}
	return blocks;
}

Block* Templates::getZ(SIDE& side)
{
	Block* blocks = new Block[SIZE];
	switch (side)
	{
	case SIDE::UP:
		blocks[1].setY(1);
		blocks[2].setX(-1);
		blocks[3].setY(1);
		blocks[3].setX(1);
		break;

	case SIDE::RIGHT:
		blocks[1].setY(-1);
		blocks[2].setX(-1);
		blocks[3].setY(1);
		blocks[3].setX(-1);
		break;

	case SIDE::DOWN:
		blocks[1].setY(1);
		blocks[2].setX(-1);
		blocks[3].setY(1);
		blocks[3].setX(1);
		break;

	case SIDE::LEFT:
		blocks[1].setY(-1);
		blocks[2].setX(-1);
		blocks[3].setY(1);
		blocks[3].setX(-1);
		break;

	default:
		break;
	}
	return blocks;
}