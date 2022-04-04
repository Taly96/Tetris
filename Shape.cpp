#include "Shape.h"


Shape::Shape(SHAPES& _kind, SIDE& _side)
{

	coords = getShape(_kind, _side);
	kind = _kind;
	side = _side;
}

Shape::Shape(const Shape& other)
{
	if (this != &other)
	{
		this->coords = nullptr;
		(*this) = other;
	}
}
Block* Shape::getShape(SHAPES& _kind, SIDE& _side)
{
	Block* tmp = nullptr;
	switch (_kind)
	{
	case SHAPES::I:
		tmp = Templates::getI(_side);
		break;
	case SHAPES::Z:
		tmp = Templates::getZ(_side);
		break;
	case SHAPES::O:
		tmp = Templates::getO(_side);
		break;
	case SHAPES::L:
		tmp = Templates::getL(_side);
		break;
	case SHAPES::T:
		tmp = Templates::getT(_side);
		break;
	case SHAPES::J:
		tmp = Templates::getJ(_side);
		break;
	case SHAPES::S:
		tmp = Templates::getS(_side);
		break;
	default:
		break;
	}
	return tmp;
}

void Shape::print()
{
	if (Settings::getColors())
		IO::colorize((int)this->kind);
	for (int i = 0; i < SIZE; i++)
	{
		IO::gotoxy(coords[i].getX(), coords[i].getY());
		std::cout << (char)219u;
	}
	IO::colorize(7);

}

void Shape::clear()
{
	for (int i = 0; i < SIZE; i++)
	{
		IO::gotoxy(coords[i].getX(), coords[i].getY());
		std::cout << " ";
	}
}


void Shape::operator+=(Block& other)
{
	for (int i = 0; i < SIZE; i++)
	{
		coords[i] += other;
	}
}

void Shape::randomizePos()
{
	int offset = rand() % (WIDTH - 2);
	offset += 2;
	for (int i = 0; i < SIZE; i++)
	{
		coords[i] += offset;
	}
}

void Shape::operator++(int)
{
	for (int i = 0; i < SIZE; i++)
	{
		(coords[i])++;
	}
}

void Shape::operator--(int)
{
	for (int i = 0; i < SIZE; i++)
	{
		(coords[i])--;
	}
}

bool Shape::operator==(Block& other)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (coords[i].getY() == other.getY())
		{
			return true;
		}
	}
	return false;
}

Shape& Shape::operator=(const Shape& other)
{
	this->kind = other.kind;
	this->side = other.side;
	if (coords)
		delete[] coords;
	coords = new Block[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->coords[i] = other.coords[i];
	}
	return *this;
}


void Shape::turnLeft() {

	int s = (int)this->side;// getting the right SIDE enum to turn the shape
	s = (s - 1) % 4;
	if (s < 0)
		s = 4 + s;
	SIDE side = (SIDE)s;
	rotate(side);
}
void Shape::turnRight() {

	int s = (int)this->side;//getting the right SIDE enum to turn the shape
	s = (s + 1) % 4;
	SIDE side = (SIDE)s;
	rotate(side);
}

void Shape::rotate(SIDE& newSide)
{
	int xcontrol, ycontrol;
	xcontrol = coords[0].getX();//every shape holds a pivot coordinates in coords[0] and the shape rotates according to it
	ycontrol = coords[0].getY();
	delete[] coords;
	coords = getShape(this->kind, newSide);
	xcontrol = xcontrol - coords[0].getX();
	ycontrol = ycontrol - coords[0].getY();
	for (int i = 0; i < SIZE; i++)
	{
		coords[i].setX(coords[i].getX() + xcontrol);
		coords[i].setY(coords[i].getY() + ycontrol);
	}
	this->side = newSide;
}
