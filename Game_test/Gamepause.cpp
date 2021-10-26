#include "Gamepause.h"

Gamepause::Gamepause()
{
	this->window.x = 1366;
	this->window.y = 768;
	this->shape.setSize(sf::Vector2f(window.x, 300));
	this->shape.setFillColor(sf::Color(10, 10, 10, 50));
	this->shape.setPosition(0, (this->window.y / 2) - (this->shape.getGlobalBounds().height / 2));

	this->font.loadFromFile("font/COOPBL.ttf");
	this->gamePause.setFont(this->font);
	this->gamePause.setCharacterSize(40);
	this->gamePause.setFillColor(sf::Color::White);
	this->gamePause.setString("GAME PAUSE");
	/*this->gamePause.setPosition((this->window.x/2)-(this->gamePause.getGlobalBounds().width/2),(this->window.y/2)- (this->shape.getGlobalBounds().height / 2)+20);*/
	this->gamePause.setPosition(100, 100);
}

Gamepause::~Gamepause()
{
}

void Gamepause::render(sf::RenderTarget* target)
{
	/*target->draw(this->shape);*/
	target->draw(this->gamePause);
}
