#include "Player.h"


Player::Player(int x, int y, int id)
{
	srand((unsigned)time(0));
	players_Board = new Board(x, y);
	int rando = (rand() % 7) + 1;
	SHAPES shape = (SHAPES)rando;
	SIDE side = SIDE::UP;
	current_Shape = new Shape(shape,side);
	(*current_Shape) += (*players_Board).getStart();
	(*current_Shape)++;
	(*current_Shape).randomizePos();
	players_Board->printBoard();
	this->id = id;
}

int Player::takeTurn(MOVES& move)
{
	int i = 0;
	(*current_Shape).clear();
	makeMove(move);
	bool stop = !(this->players_Board->checkHit(*current_Shape));
	
	if (stop)
	{
		if (checkLost())
			return 1;
		players_Board->fillBoard(current_Shape);
		players_Board->didTetris();
		players_Board->addScore(10);
		printBoard();
		delete current_Shape;
		int rando = (rand() % 7) + 1;
		SHAPES shape = (SHAPES)rando;
		SIDE side = SIDE::UP;
		current_Shape = new Shape(shape, side);
		(*current_Shape) += (*players_Board).getStart();
		(*current_Shape)++;
		(*current_Shape).randomizePos();
		i++;
	}

	return 0; //return 1 if lost
}

void Player::printBoard()
{
	int xstart = this->players_Board->getStart().getX();
	int ystart = this->players_Board->getStart().getY();
	IO::gotoxy(xstart + 3, ystart - 3);
	std::cout << "Player " << this->id;
	this->players_Board->printBoard();
	if (Settings::getScore())
	{
		IO::gotoxy(xstart + 3, ystart + 20);
		std::cout << "Score: " << this->players_Board->getScore();
	}

}

void Player::makeMove(MOVES& m)
{
	Block b(-1, 0);
	Shape old = *(this->current_Shape);
	switch (m)
	{
	case MOVES::COUNTER:
		this->current_Shape->turnLeft();
		break;
	case MOVES::CLOCK:
		this->current_Shape->turnRight();
		break;
	case MOVES::LEFT:
		(*(this->current_Shape)) += b;
		break;
	case MOVES::RIGHT:
		b.setX(1);
		(*(this->current_Shape)) += b;
		break;
	case MOVES::DROP:
		dropShape();
		(*this->current_Shape)--;
		break;
	default:
		break;
	}
	if (!(this->players_Board->checkHit(*(this->current_Shape))))
	{
		*(this->current_Shape) = old;
	}

	(*this->current_Shape)++;
}

bool Player::checkLost()
{
	int boundry = this->players_Board->getStart().getY();
	boundry++;
	for (int i = 0; i < SIZE; i++)
	{
		if ((*this->current_Shape)[i].getY() <= boundry)
			return true;
	}
	return false;
}

void Player::dropShape()
{
	bool stop = false;
	while (!stop)
	{
		(*current_Shape)++;
		stop = !(this->players_Board->checkHit(*current_Shape));
	}
}
