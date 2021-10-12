#define _CRT_SECURE_NO_WARNINGS 1
#include "Highscore.h"

void Highscore::initHighscore()
{
	if (!(this->high = fopen("BackEn/highscore.txt", "r")))
	{
		std::cout << "error";
	}
	for (int i = 0; i < 5; i++)
	{
		fscanf(this->high, "%s", &this->temp);
		this->name[i] = this->temp;
		this->playerName[i].setString(this->name[i]);
		fscanf(this->high, "%d", &this->score[i]);
		this->playerScore[i].setString(std::to_string(this->score[i]));
		this->userScore.push_back(std::make_pair(this->score[i], this->name[i]));
	}
}

void Highscore::initText()
{
	this->font.loadFromFile("font/COOPBL.ttf");
	this->scoreBoardText.setFont(this->font);
	this->scoreBoardText.setCharacterSize(60.f);
	this->scoreBoardText.setFillColor(sf::Color::White);
	this->scoreBoardText.setString("Leader Board");
	this->scoreBoardText.setPosition((this->windowX/2)-(this->scoreBoardText.getGlobalBounds().width/2),50);
	for (int i = 0; i < 5; i++)
	{
		this->playerName[i].setFont(this->font);
		this->playerName[i].setCharacterSize(30.f);
		this->playerName[i].setFillColor(sf::Color::White);
		this->playerName[i].setPosition((this->windowX/2)-(this->scoreBoardText.getGlobalBounds().width/2),200+100*i);
		this->playerScore[i].setFont(this->font);
		this->playerScore[i].setCharacterSize(30.f);
		this->playerScore[i].setFillColor(sf::Color::White);
		this->playerScore[i].setPosition((this->windowX / 2) + (this->scoreBoardText.getGlobalBounds().width / 2), 200+ 100 * i);
	}
}

void Highscore::initBackground()
{
	this->backgroundTexture.loadFromFile("image/sky.png");
	this->background.setTexture(this->backgroundTexture);
}

Highscore::Highscore()
{
	this->initHighscore();
	this->initText();
	this->initBackground();
}

Highscore::~Highscore()
{

}

void Highscore::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	target->draw(this->scoreBoardText);

	for (int i = 0; i < 5; i++)
	{
		target->draw(this->playerName[i]);
		target->draw(this->playerScore[i]);
	}
}
