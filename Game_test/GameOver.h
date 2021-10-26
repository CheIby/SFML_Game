#ifndef  GAMEOVER_H
#define GAMEOVER_H

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

class GameOver
{
private:
	float windowX = 1366;
	sf::Texture backgroundTexture;
	sf::Sprite background;

	FILE* fq;
	sf::Font font;
	sf::Text GameOverText;
	sf::Text yourScore;

	char temp[255];
	int score[6];
	std::string name[6];
	std::vector <std::pair<int, std::string>> userScore;
	unsigned int finalScore;

	void initBackground();
	void initText();	
public:
	GameOver();
	virtual ~GameOver();
	void getScore(unsigned int score);
	void updateHigh(std::string name, unsigned int score);
	void render(sf::RenderTarget* target);
};

#endif // ! GAMEOVER_H