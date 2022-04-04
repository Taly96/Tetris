#include "Menu.h"



void Menu::run()
{
	int choice;
	bool exit = false;
	while (!exit)
	{
		printMenu();
		std::cin >> choice;
		switch (choice)
		{
		case (NEWGAME):
			newGame();
			break;
		case (CONTINUE):
			continueGame();
			break;
		case(SETTINGS):
			setSettings();
			break;
		case (INSTRUCTIONS):
			showInstructions();
			break;
		case(EXIT):
			exit = true;
		default:
			break;
		}
	}
	std::cout << "Goodbye!";
}

void Menu::newGame() {

	IO::clrscr();
	if (game)
		delete game;
	game = new Game;
	inProgress = true;
	continueGame();

}

void Menu::continueGame()
{
	if (game->play())
	{
		inProgress = false;
		delete game;
		game = nullptr;
	}
}

void Menu::printMenu()
{
	IO::clrscr();
	std::cout << " Welcome to our Tetris Game\n press:\n";
	std::cout << "(1) Start a new game\n";

	if (inProgress) //paused game
		std::cout << "(2) Continue a paused game\n";

	std::cout << "(7) present & change settings\n";
	std::cout << "(8) Present instructions and keys\n";
	std::cout << "(9) EXIT\n";
}

void Menu::showInstructions() {

	IO::clrscr();
	IO::colorizeText(MAGNETA);
	std::cout << "Goal:\n";
	IO::colorizeText(WHITE);
	std::cout << "You have to make full horizontal lines with the different shaped blocks that fall into the game area.\n";
	std::cout << "Full lines will then disappear and provide points.\n";
	std::cout << "The more lines you make at the same time, the more points you earn.\n";
	IO::colorizeText(MAGNETA);
	std::cout << "\nPlayer's keys: \n";
	IO::colorizeText(WHITE);
	std::cout << "  ________________________________________________________________________________________\n";
	std::cout << " |   Shape Action         |      Left Player         |         Right Player               |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n";
	std::cout << " |       LEFT             |    a or A                |            j or J                  |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n";
	std::cout << " |       RIGHT            |    d or D                |          l (small L) or L          |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n";
	std::cout << " |    ROTATE clockwise    |    s or S                |            k or K                  |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n";
	std::cout << " |ROTATE counterclockwise |    w or W                |          i or I (uppercase i)      |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n";
	std::cout << " |        DROP            |    x or X                |             m or M                 |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n\n";

	std::cout << "Press any key to continue";
	_getch();
	if (_kbhit())
		return;
}


void Menu::setSettings()
{

	int choice;
	bool exit = false;
	while (!exit)
	{
		printSettings();
		std::cin >> choice;
		switch (choice)
		{
		case (MUSIC):
			Settings::setMusic(!Settings::getMusic());
			break;

		case (COLOR):
			Settings::setColors(!Settings::getColors());
			break;

		case(SCORE):
			Settings::setScore(!Settings::getScore());
			break;

		case(EXIT):
			exit = true;
		}
	}
	return;
}

void Menu::printSettings()
{
	bool music = Settings::getMusic();
	bool colors = Settings::getColors();
	bool scores = Settings::getScore();
	IO::clrscr();
	std::cout << "Your Settings Are:\n\n";
	std::cout << "* Game Music is currently " << (music ? "on " : "off ") << "\n";
	std::cout << "* Game Colors are currently " << (colors ? "on " : "off ") << "\n";
	std::cout << "* Game Scores are currently " << (scores ? "on " : "off ") << "\n";
	std::cout << "\n";
	std::cout << "press (1) to turn the Game Music " << (music ? "off " : "on ") << "\n";
	std::cout << "press (2) to turn the Game Colors " << (colors ? "off " : "on ") << "\n";
	std::cout << "press (3) to turn the Game Scores " << (scores ? "off " : "on ") << "\n";
	std::cout << "press (9) to go back to the main menu \n";

}

Menu::~Menu()
{
	if (inProgress)
		delete game;
}