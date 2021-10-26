#include "Entername.h"

Entername::Entername()
{
	this->font.loadFromFile("font/COOPBL.ttf");
	this->player.setFont(this->font);
	this->player.setCharacterSize(50);
	this->player.setFillColor(sf::Color::White);
	this->player.setPosition(300, 300);
	this->player.setLetterSpacing(1.5);
	this->player.setString(this->playerName);
	this->player.setString("Enter Your Name");
}

Entername::~Entername()
{

}

void Entername::enterName(std::vector<sf::Event> events)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i].text.unicode != 32 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && events[i].text.unicode != 63)
		{
			if (events[i].text.unicode == 8 && this->playerName.length() > 0)
			{
				this->playerName.erase(playerName.length() - 1);
			}
			else if (events[i].text.unicode < 128 && playerName.length() < 10 && events[i].text.unicode != 8)
			{
				this->playerName += static_cast<char>(events[i].text.unicode);
			}
			this->player.setString(playerName);
			this->player.setOrigin(this->player.getLocalBounds().width / 2, this->player.getLocalBounds().height / 2);
		}
	}
}

void Entername::render(sf::RenderTarget* target)
{
	target->draw(this->player);
}
