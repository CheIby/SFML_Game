#ifndef GUI_H
#define GUI_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"

class GUI
{
private:
	sf::Font font;
	sf::Text textPoint;
	sf::Text num[2];
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::Texture enmeyTexture[2];
	sf::Sprite enemySprite[2];
	int score;
	int type;
	int check[2];

	void initGUI();

public:
	GUI();
	virtual ~GUI();
	void updatPlayerHpBar(float percent);
	void updatePoint(int points);
	void currentPoint();
	void updatetype(int type);
	void currentType();
	void renderGui(sf::RenderTarget* target);
};

#endif // !GUI_H