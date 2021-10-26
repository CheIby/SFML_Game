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
public:
	Entername();
	virtual ~Entername();
	inline std::string getPlayerName() { return this->playerName; }
	void enterName(std::vector<sf::Event> events);
	void render(sf::RenderTarget* target);
};

#endif // !ENTERNAME_H