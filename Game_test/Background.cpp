#include "Background.h"

Background::Background(sf::Texture* texture, float speed)
{
	this->speed = speed;
	this->windowSize = sf::Vector2f(1366.f, 768.f);

	for (int i = 0; i < 2; i++)
	{
		this->object[i].setSize(windowSize);
		this->object[i].setTexture(texture);
	}

	if (speed < 0)
	{
		this->object[1].setPosition(windowSize.x-2.f , 0.f);
	}
	else
	{
		this->object[1].setPosition(-windowSize.x+2.f, 0.f);
	}
}

Background::~Background()
{
	
}

void Background::updateBackground(float deltatime)
{
	
	for (int j = 0; j < 2; j++)
	{
		this->position = object[j].getPosition();
		this->object[j].move(this->speed * deltatime, 0);
		
		if (this->position.x <= -windowSize.x && this->speed < 0)
		{
			this->object[j].setPosition(windowSize.x-2.f , this->position.y);
		}
		else if (this->position.x >= this->windowSize.x && this->speed > 0)
		{
			this->object[j].setPosition(-windowSize.x+2.f, this->position.y);
		}
		
	}
	
}

void Background::render(sf::RenderWindow& render)
{
	render.draw(object[1]);
	render.draw(object[0]);
}
