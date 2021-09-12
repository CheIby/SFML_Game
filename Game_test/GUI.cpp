#include "GUI.h"

void GUI::initGUI()
{
	this->score = 0;
	this->check[0] = 0;
	this->check[1] = 0;
	this->font.loadFromFile("font/COOPBL.ttf");

	this->num[0].setPosition(1050, 40);
	this->num[0].setFont(this->font);
	this->num[0].setCharacterSize(30);
	this->num[0].setFillColor(sf::Color::White);
	this->num[1].setPosition(1250, 40);
	this->num[1].setFont(this->font);
	this->num[1].setCharacterSize(30);
	this->num[1].setFillColor(sf::Color::White);

	this->textPoint.setPosition(25, 10);
	this->textPoint.setFont(this->font);
	this->textPoint.setCharacterSize(30);
	this->textPoint.setFillColor(sf::Color::White);

	this->playerHpBar.setSize(sf::Vector2f(500.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setOutlineColor(sf::Color::White);
	this->playerHpBar.setPosition(sf::Vector2f(25, 50));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
	
	this->enmeyTexture[0].loadFromFile("image/enemy1.png");
	this->enmeyTexture[1].loadFromFile("image/enemy2.png");
	this->enemySprite[0].setTexture(this->enmeyTexture[0]);
	this->enemySprite[1].setTexture(this->enmeyTexture[1]);
	this->enemySprite[0].setPosition(sf::Vector2f(950, 30));
	this->enemySprite[1].setPosition(sf::Vector2f(1150, 30));
	this->enemySprite[0].setScale(0.4, 0.4);
	this->enemySprite[1].setScale(0.4, 0.4);
}

GUI::GUI()
{
	this->initGUI();
}

GUI::~GUI()
{

}

void GUI::updatePoint(int points)
{
	this->score += points;
}

void GUI::updatPlayerHpBar(float percent)
{
	this->playerHpBar.setSize(sf::Vector2f(500.f * percent, this->playerHpBar.getSize().y));
}

void GUI::currentPoint()
{
	std::stringstream ss;
	ss << "Points : " << this->score;
	this->textPoint.setString(ss.str());
}

void GUI::updatetype(int type)
{
	this->type = type;
	if (this->type == 0)
	{
		check[0] += 1;
	}
	else if (this->type==1)
	{
		check[1] += 1;
	}
}

void GUI::currentType()
{
	std::stringstream s1;
	s1 << "X " << this->check[0];
	this->num[0].setString(s1.str());
	std::stringstream s2;
	s2 << "X " << this->check[1];
	this->num[1].setString(s2.str());
}

void GUI::renderGui(sf::RenderTarget* target)
{
	target->draw(this->textPoint);
	target->draw(this->playerHpBarBack);
	target->draw(this->playerHpBar);
	target->draw(this->num[0]);
	target->draw(this->num[1]);
	target->draw(this->enemySprite[0]);
	target->draw(this->enemySprite[1]);
}


