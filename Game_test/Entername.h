#ifndef ENTERNAME_H
#define ENTERNAME_H

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

class Entername
{
private:
	sf::Font font;
	std::string playerName;
	sf::Text player;
	sf::Texture playerTexture;
	sf::Texture enemyTexture[2];
	sf::Sprite playerSprite;
	sf::Sprite enemySprite[2];

	sf::Texture* shapeTex;
	sf::Sprite shapeSprite;
	float totalTime;
	float switchTime;
	sf::Vector2u imageCount;
	sf::Vector2u imageCountPlay;
	sf::Vector2u currentImage;
public:
	Entername();
	virtual ~Entername();

	sf::IntRect uvRect;
	sf::IntRect uvRectPlayer;

	inline std::string getPlayerName() { return this->playerName; }
	void enterName(std::vector<sf::Event> events);
	void Animation(float deltatime);
	/*void getDeltatime(float deltatime);*/
	void render(sf::RenderTarget* target);
};

#endif // !ENTERNAME_H