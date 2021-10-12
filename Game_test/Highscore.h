#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <utility>
#include <algorithm>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"

class Highscore
{
private:
	float windowX=1366;
	sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Font font;
	sf::Text scoreBoardText;

	FILE* high;
	char temp[255];
	int score[6];
	std::string name[6];
	sf::Text playerName[6];
	sf::Text playerScore[6];
	std::vector <std::pair<int, std::string>> userScore;

	void initHighscore();
	void initText();
	void initBackground();
public:
	Highscore();
	virtual ~Highscore();
	void render(sf::RenderTarget* target);
};

#endif // !HIGHSCORE_H