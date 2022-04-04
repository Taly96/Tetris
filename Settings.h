#pragma once
#include "IO.h"
#define COLOR 2
#define MUSIC 1
#define SCORE 3
/*This header file contains the settings functions of the game*/
class Settings {
	static bool colors;
	static bool music;
	static bool score;

public:
	/*This function returns a boolean value that indicates wheather the colors are on or off*/
	static bool getColors() { return colors; }

	/*This function returns a boolean value that indicates wheather the music is on or off*/
	static bool getMusic() { return music; }

	/*This function returns a boolean value that indicates wheather the score is shown or not*/
	static bool getScore() { return score; }

	/*This function gets a boolean value and sets the colors to on or off */
	static void setColors(bool _colors) { colors = _colors; }

	/*This function gets a boolean value and sets the music to on or off */
	static void setMusic(bool _music) { music = _music; }

	/*This function gets a boolean value and sets the score to on or off */
	static void setScore(bool _score) { score = _score; }
};