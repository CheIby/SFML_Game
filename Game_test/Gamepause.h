#ifndef GAMEPAUSE_H
#define GAMEPAUSE_H

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


class Gamepause
{
private:
	sf::Vector2f window;
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text gamePause;
public:
	Gamepause();
	virtual ~Gamepause();
	void render(sf::RenderTarget* target);
};

#endif // !GAMEPAUSE_H