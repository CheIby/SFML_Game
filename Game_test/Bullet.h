#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"

class Bullet
{
private:
	sf::Sprite bullet;
	sf::Vector2f direction;

	float bulletSpeed;

public:
	Bullet(sf::Texture* bullet, float posX, float posY, float dirX, float dirY, float bulletSpeed);
	virtual ~Bullet();

	const sf::FloatRect getBounds() const;
	inline sf::Vector2f getPos() { return this->bullet.getPosition(); }

	void updateBullet();
	void render(sf::RenderTarget* target);
};

#endif // !BULLET_H