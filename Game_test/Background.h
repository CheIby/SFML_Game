#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"

class Background
{
private:
	//function
	sf::RectangleShape object[2];
	sf::Vector2f windowSize;
	sf::Vector2f position;

	float speed;

public:
	Background(sf::Texture* texture, float speed);
	virtual ~Background();

	//function
	void updateBackground(float deltatime);
	void render(sf::RenderWindow& render);
};

#endif // !BACKGROUND_H