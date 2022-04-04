#include "Block.h"


void Block::printBlock()
{
	if (filled)
	{
		IO::gotoxy(x, y);
		std::cout << (char)219u;
	}
	else
	{
		IO::gotoxy(x, y);
		std::cout << " ";
	}
}

bool Block::operator==(Block& other)
{
	return ((this->y == other.y) && (this->x == other.x));
}