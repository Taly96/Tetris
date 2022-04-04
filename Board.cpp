#include "Board.h"


Board::Board(int x, int y) :start(x, y, false) {

	this->score = 0;
	int i,j;
	int currx, curry;
	board = new Block * [HEIGHT+1];
	for (i = 0,curry=start.getY(); i < HEIGHT+1; i++)
	{
		board[i] = new Block[WIDTH+2];
		for (j = 0,currx = start.getX(); j < WIDTH+2; j++)
		{
			board[i][j].setX(currx + j);
			board[i][j].setY(curry + i);
		}
	}

	for (i = 0; i < HEIGHT+1; i++)
	{
		board[i][0].setFilled(true);
	}

	for (i = 0; i < WIDTH+2; i++)
	{
		board[HEIGHT][i].setFilled(true);
	}

	for (i = 0; i < HEIGHT+1; i++)
	{
		board[i][WIDTH+1].setFilled(true);
	}

}

void Board::printBoard()
{
	for (int i = 0; i < HEIGHT + 1; i++)
	{
		for (int j = 0; j < WIDTH + 2; j++)
		{
			board[i][j].printBlock();
		}
	}
}


void Board::initBoard()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 1; j < WIDTH+1; j++)
		{
			board[i][j].setFilled(false);
		}
	}
}


void Board::fillBoard(Shape*& shape)
{
	int bx, by, x, y;
	for (int i = 0; i < SIZE; i++)
	{
		x = (*shape)[i].getX();
		y = (*shape)[i].getY();
		bx = x - this->start.getX();
		by = y - this->start.getY();
		board[by-1][bx].setFilled(true);
	}
}

bool Board::checkHit(Shape& s)
{
	for (int i = 0; i < SIZE; i++)
	{
		int xoffset = (s)[i].getX() - this->start.getX();
		int yoffset = (s)[i].getY() - this->start.getY();
		if (board[yoffset][xoffset].getFilled())
			return false;
	}
	return true;
}


void Board::didTetris()
{
	bool flag = true;
	int amount = 0;
	for (int i = HEIGHT-1; i >= 0; i--,flag=true)
	{
		for (int j = 0; j < WIDTH + 1; j++)
		{
			if (!(this->board[i][j].getFilled()))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			lowerBlocks(i);
			i--;
			amount++;
		}
	}
	if(amount != 0) //had a tetris
		addScore(100 * pow(2, amount-1));
}


void Board::lowerBlocks(int row)
{
	for (int i = row; i >= 1; i--)
	{
		for (int j = 1; j < WIDTH + 1; j++)
		{
			this->board[i][j].setFilled(this->board[i - 1][j].getFilled());
		}
	}

	for (int i = 1; i < WIDTH + 1; i++)//clear top row
	{
		this->board[0][i].setFilled(false);
	}
}

Board::~Board()
{
	for(int i=0;i<HEIGHT+1;i++)
		delete[] board[i];

	delete[] board;
}