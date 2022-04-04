#include "Game.h"


bool Game::play()
{
	IO::hidecursor(false);
	if (Settings::getMusic())
		PlaySound(TEXT("TetrisAudio.wav"), NULL, SND_FILENAME | SND_ASYNC);
	IO::clrscr();
	p1.printBoard();
	p2.printBoard();
	MOVES p1Move, p2Move;
	int c=1;
	bool run = true, p1lose = false, p2lose = false;
	while (run && c!= ESC)
	{
		p1Move = p2Move = MOVES::NONE;
		p1.printShape();
		p2.printShape();
		Sleep(350);
		if (getPress(p1Move, p2Move))
			break;
		c = p1.takeTurn(p1Move);
		p1lose = (c == 1);
		c = p2.takeTurn(p2Move);
		p2lose = (c == 1);
		
		if(p1lose || p2lose)
			run = false;
	}
	if(!run)
		printResult(p1lose, p2lose);
	IO::hidecursor(true);
	PlaySound(NULL, NULL, SND_ASYNC);
	return !run;
}


bool Game::getPress(MOVES& p1, MOVES& p2) 
{
	char c = 0;
	if (_kbhit())
		c = _getch();
	switch (c){
	case 'w':
	case 'W':
		p1 = MOVES::COUNTER;
		break;	
	case 's':
	case 'S':
		p1 = MOVES::CLOCK;
		break;
	case 'a':
	case 'A':
		p1 = MOVES::LEFT;
		break;
	case 'd':
	case 'D':
		p1 = MOVES::RIGHT;
		break;
	case 'x':
	case 'X':
		p1 = MOVES::DROP;
		break;
	case 'i':
	case 'I':
		p2 = MOVES::COUNTER;
		break;
	case 'k':
	case 'K':
		p2 = MOVES::CLOCK;
		break;
	case 'j':
	case 'J':
		p2 = MOVES::LEFT;
		break;
	case 'l':
	case 'L':
		p2 = MOVES::RIGHT;
		break;
	case 'm':
	case 'M':
		p2 = MOVES::DROP;
		break;
	case ESCAPE:
		return true;
		break;
	default:
		break;
	}
	return false;
}


void Game::printResult(bool p1lose, bool p2lose)
{
	bool tie = false;
	if (p1lose)
	{
		if (p2lose) //tie
		{
			if (Settings::getScore())
			{
				if (p1.getScore() > p2.getScore())
					p1lose = false;
				else if (p2.getScore() > p1.getScore())
					p2lose = false;
				else
					tie = true;
			}
			else
				tie = true;
		}
	}
	
	IO::printResultHelper(p1lose,p2lose,tie);
	
}
