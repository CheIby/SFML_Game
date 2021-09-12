#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"


class Player
{
public:
	sf::Texture playerTexture;
	sf::Vector2u playerTextureSize;
	sf::Sprite playerSprite;
	sf::RectangleShape* player;

	sf::Texture sahaTexture;
	sf::Sprite sahaSprite;

	//status
	int hpMax;
	int hp;
	int damage;
	float movementSpeed;
	float cooldown;
	float cooldownMax;

	int flag;
	float itemCooldown;
	float itemCooldownMax;

	int fireRateflag;
	float itemCooldown2;
	float itemCooldownMax2;

	//collision
	int collision;
	float colCooldown;
	float colCooldownMax;
	sf::Texture playerColTexture;
	sf::Sprite playerColSprite;

	//Animation
	float totalTime;
	float switchTime;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	//con
	void initStatus();
	void initPlayer();

public:
	Player();
	virtual ~Player();

	sf::IntRect uvRect;

	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	//update
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);

	//function
	void move(const float dirX, const float dirY);
	void Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	void updateAnmation(int row,float deltatime);
	void updateHp(int dmg);
	void collisionPlayer();
	void plusHp(int hp);
	void getDmg();
	void getFireRate();
	const bool canAttack();
	inline int getHpMax() { return this->hpMax; }
	inline int getHp() { return this->hp; }

	void updateAttack();
	void updatePlayer();
	void render(sf::RenderTarget& target);
};

#endif // !PLAYER_H