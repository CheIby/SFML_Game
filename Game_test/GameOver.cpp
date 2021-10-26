#define _CRT_SECURE_NO_WARNINGS 1
#include "GameOver.h"

void GameOver::initBackground()
{
	this->backgroundTexture.loadFromFile("image/gameOver.jpg");
	this->background.setTexture(this->backgroundTexture);
}

void GameOver::initText()
{
	this->font.loadFromFile("font/COOPBL.ttf");
	this->GameOverText.setFont(this->font);
	this->GameOverText.setCharacterSize(60);
	this->GameOverText.setFillColor(sf::Color::White);
	this->GameOverText.setString("GAME OVER");
	this->GameOverText.setPosition((this->windowX / 2) - (this->GameOverText.getGlobalBounds().width / 2), 100);

	this->yourScore.setFont(this->font);
	this->yourScore.setCharacterSize(40);
	this->yourScore.setFillColor(sf::Color::White);
	std::stringstream ss;
	ss << "YOUR SCORE : " << this->finalScore;
	this->yourScore.setString(ss.str());
}

GameOver::GameOver()
{
	this->initBackground();
	this->initText();
}

GameOver::~GameOver()
{
	this->backgroundTexture;
	this->background;
}

void GameOver::getScore(unsigned int score)
{
	this->finalScore = score;
	this->yourScore.setFont(this->font);
	this->yourScore.setCharacterSize(40);
	this->yourScore.setFillColor(sf::Color::White);
	std::stringstream ss;
	ss << "YOUR SCORE : " << this->finalScore;
	this->yourScore.setString(ss.str());
}

void GameOver::updateHigh(std::string name, unsigned int score)
{
	this->fq = fopen("BackEn/highscore.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(fq, "%s", &temp);
		this->name[i] = temp;
		fscanf(fq, "%d", &this->score[i]);
		this->userScore.push_back(std::make_pair(this->score[i], this->name[i]));
	}
	this->name[5] = name;
	this->score[5] = score;
	this->userScore.push_back(std::make_pair(this->score[5], this->name[5]));
	std::sort(this->userScore.begin(), this->userScore.end());
	fclose(this->fq);
	for (int i = 1; i < 6; i++)
	{
		std::cout << this->userScore[i].second + "\t" << this->userScore[i].first << "\n";
	}
	this->fq = fopen("BackEn/highscore.txt", "w");
	for (int i = 5; i >= 1; i--)
	{
		strcpy(temp, userScore[i].second.c_str());
		fprintf(fq, "%s %d\n", temp, userScore[i].first);
	}
	fclose(this->fq);
}

void GameOver::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	target->draw(this->GameOverText);
	target->draw(this->yourScore);
}
