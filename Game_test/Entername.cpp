#include "Entername.h"

Entername::Entername()
{
	this->font.loadFromFile("font/COOPBL.ttf");
	this->player.setFont(this->font);
	this->player.setCharacterSize(50);
	this->player.setFillColor(sf::Color::White);
	this->player.setPosition((1366/2)-(474/2), 115);
	this->player.setLetterSpacing(1.5);
	this->player.setString(this->playerName);
	this->player.setString("Enter Your Name");

	this->backgoundTex.loadFromFile("image/mainmenu4.png");
	this->backgoundSprite.setTexture(this->backgoundTex);

	this->playerTexture.loadFromFile("image/moveplane2.png");
	this->playerSprite.setTexture(this->playerTexture);
	this->playerSprite.setScale(0.7f, 0.7f);
	this->playerSprite.setPosition(sf::Vector2f(260,345));

	this->enemyTexture[0].loadFromFile("image/moveEnemy1.png");
	this->enemyTexture[1].loadFromFile("image/moveEnemy2.png");
	this->enemySprite[0].setTexture(this->enemyTexture[0]);
	this->enemySprite[1].setTexture(this->enemyTexture[1]);
	this->enemySprite[0].setScale(0.7f, 0.7f);
	this->enemySprite[1].setScale(0.7f, 0.7f);
	this->enemySprite[0].setPosition(sf::Vector2f(700, 360));
	this->enemySprite[1].setPosition(sf::Vector2f(705, 520));

	this->currentImage.x = 0;
	this->switchTime = 0.2f;
	this->imageCount = sf::Vector2u(3, 1);
	this->imageCountPlay = sf::Vector2u(3, 1);
	uvRect.width = this->enemyTexture[0].getSize().x / float(imageCount.x);
	uvRect.height = this->enemyTexture[0].getSize().y / float(imageCount.y);
	uvRectPlayer.width = this->playerTexture.getSize().x / float(imageCountPlay.x);
	uvRectPlayer.height = this->playerTexture.getSize().y / float(imageCountPlay.y);
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

void Entername::Animation(float deltatime)
{
	this->totalTime += deltatime;
	currentImage.y = 0;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		
		if (currentImage.x >= 3)
		{
			currentImage.x = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
	uvRectPlayer.left = currentImage.x * uvRectPlayer.width;
	uvRectPlayer.top = currentImage.y * uvRectPlayer.height;

	this->playerSprite.setTextureRect(uvRectPlayer);
	for (int i = 0; i < 2; i++)
	{
		this->enemySprite[i].setTextureRect(uvRect);
	}
}

void Entername::render(sf::RenderTarget* target)
{
	target->draw(this->backgoundSprite);
	target->draw(this->player);
	for (int i = 0; i < 2; i++)
	{
		target->draw(this->enemySprite[i]);
	}
	target->draw(this->playerSprite);
}
