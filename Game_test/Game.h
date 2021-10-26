#define _CRT_SECURE_NO_WARNINGS

#ifndef GAME_H
#define GAME_H
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <utility>
#include <algorithm>

#include "Player.h"
#include "Background.h"
#include "Bullet.h"
#include "Enemy.h"
#include "GUI.h"
#include "Item.h"
#include "mainMenu.h"
#include "Botton.h"
#include "Highscore.h"
#include "GameOver.h"
#include "Gamepause.h"
#include "Entername.h"

//void showText(sf::Vector2f position, std::string word, sf::Font* font, int size, sf::RenderWindow& window);

class Game
{
private:
	sf::Image icon;
	sf::Event ev;
	sf::RenderWindow* window;
	sf::Clock clock;

	float windowX;
	float deltaTime;
	bool menuOn = 1;
	bool inputName = 0;
	bool gameOn = 0;
	bool gameStop = 0;
	bool scoreOn = 0;
	bool gamOverOn = 0;
	
	//mainmenu
	mainMenu *menu;
	sf::SoundBuffer menuBuffer;
	sf::Sound menuSound;

	//highscore
	Highscore *highscore;

	//botton
	sf::Vector2i mouse;
	sf::Vector2f mousePos;
	sf::Font font;
	Botton *Newgame;
	Botton *Exit;
	Botton* HighScore;
	Botton* Back;
	Botton* Play;
	Botton* BackInput;
	Botton* Continuous;
	Botton* ExitGamePause;
	Botton* GoToHighScore;
	Botton* ExtitGame;
	
	Entername* enterName;
	std::vector<sf::Event> textName;

	//background
	sf::Texture highscoreTex;
	sf::Sprite highScoreSpirte;
	sf::Texture backgroundTexture[2];
	sf::RectangleShape background2;
	sf::Texture background2Texture;
	std::vector<Background> backgrounds;

	//Item
	std::vector<Item*> items;
	sf::SoundBuffer itemBuffer;
	sf::Sound itemSound;
	float itemSpawnTimer;
	float itemSpawnTimerMax;
	float setScale[3];
	int randomItem;
	sf::Texture itemTexture[3];
	sf::Sprite itemSprite;
	
	//bullet
	sf::SoundBuffer hitBuffer;
	sf::Sound hitSound;
	std::map<std::string, sf::Texture*> bulletTexture;
	std::vector<Bullet*> bullets;
	int bulletFlag;
	float flagcooldown;
	float flagcooldownMax;

	//enemy
	std::vector<Enemy*> enemies;
	sf::SoundBuffer expoBuffer;
	sf::Sound expoSound;
	float spawnEnemyTimer;
	float spawnEnemyTimerMax;
	sf::Texture Enemies[2];
	int enemySpeed[2];
	int enemyHP[2];
	int enemyScore[2];
	int enemyDmg[2];
	unsigned random;
	float PosY;
	float PosX;
	float updateSpawmTimer;
	float timer;

	//Gui
	GUI* gui;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	
	//con
	void initWindow();
	void innitMainMenu();
	void initHighScore();
	void initEnterName();
	void initGamePause();
	void initGameOver();
	void initGame();
	void initBackground();
	void initItem();
	void initVar();
	void initPlayer();
	void initBullet();
	void initEnemy();

	Gamepause *gamePause;

	//player
	Player* player;
	sf::SoundBuffer oofBuffer;
	sf::Sound oof;

	GameOver* gameOver;
	

public:
	Game();
	virtual ~Game();

	void updatePullEvent();

	void updateMenu();
	void updateHighScore();
	void updateEnterName();
	void updateGamePause();
	void updateGameOver();

	void updateInput();
	void updateCollisionWorld();
	void updateSpawnTimer();
	void updateAnimation();
	void updateEnemy();
	void updateItem();
	void updateBullet();
	void updateCombat();
	void updateGui();
	void update();
	void gameRestart();

	void renderMenu();
	void renderHigh();
	void renderEnterName();
	void renderGamePause();
	void renderGameOver();
	void render();
	void run ();
};

//void showText(sf::Vector2f position, std::string word, sf::Font* font, int size, sf::RenderWindow& window) {
//	sf::Text text;
//	text.setFont(*font);
//	text.setPosition(position);
//	text.setString(word);
//	text.setCharacterSize(size);
//	text.setOutlineColor(sf::Color::Black);
//	text.setOutlineThickness(3);
//	window.draw(text);
//}

#endif // !GAME_H