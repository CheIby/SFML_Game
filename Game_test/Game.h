#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Background.h"
#include "Bullet.h"
#include "Enemy.h"
#include "GUI.h"
#include "Item.h"

class Game
{
private:
	sf::Event ev;
	sf::RenderWindow* window;
	sf::Clock clock;
	float deltaTime;

	//background
	sf::Texture backgroundTexture[2];
	sf::RectangleShape background2;
	sf::Texture background2Texture;
	std::vector<Background> backgrounds;

	//Item
	std::vector<Item*> items;
	float itemSpawnTimer;
	float itemSpawnTimerMax;
	float setScale[3];
	int randomItem;
	sf::Texture itemTexture[3];
	sf::Sprite itemSprite;
	
	//bullet
	std::map<std::string, sf::Texture*> bulletTexture;
	std::vector<Bullet*> bullets;
	sf::Texture bulletX2;
	int bulletFlag;
	float flagcooldown;
	float flagcooldownMax;

	//enemy
	std::vector<Enemy*> enemies;
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
	
	//explosion
	sf::Texture expoTexture;
	sf::Sprite expoSprite;

	//con
	void initWindow();
	void initBackground();
	void initItem();
	void initVar();
	void initPlayer();
	void initBullet();
	void initEnemy();

	//player
	Player* player;

public:
	Game();
	virtual ~Game();

	void updatePullEvent();
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
	void render();
	void run ();
};

#endif // !GAME_H