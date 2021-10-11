#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"


class Enemy
{
private:
	sf::Sprite enemy;
	sf::Texture* enemytexture;

	//animation
	float switchTime;
	float totalTime;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	int hpMax;
	int hp;
	int points;
	int dmg;
	int movementSpeed;
	int type;

	sf::Vector2f playerPos;
	sf::Vector2f center;
	sf::FloatRect playerBounds;
	bool check;
	
public:
	Enemy(sf::Texture* texture, float posX, float posY, int speed,int hp,int dmg,int score,int rand);
	virtual ~Enemy();

	sf::IntRect uvRect;

	const sf::FloatRect getBounds() const;
	inline sf::Vector2f getPos() { return this->enemy.getPosition(); }
	inline int currentHP() { return this->hp; }
	inline int Point() { return this->points; }
	inline int Dmg() { return this->dmg; }
	inline int getType() { return this->type; }

	void updateEnemy(sf::Vector2f playerPos, sf::Vector2f center, sf::FloatRect playerBounds);
	void loseHp(int var);
	void updateAnimation(int row, float deltatime);
	void render(sf::RenderTarget* target);
};
#endif // !ENEMY_H
