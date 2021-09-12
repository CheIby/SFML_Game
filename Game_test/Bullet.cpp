#include "Bullet.h"

Bullet::Bullet(sf::Texture* bullet, float posX, float posY, float dirX, float dirY, float bulletSpeed)
{
	this->bullet.setTexture(*bullet);
	this->bullet.setPosition(posX, posY);
	this->bullet.setScale(0.5,0.5);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->bulletSpeed = bulletSpeed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return	this->bullet.getGlobalBounds();
}

void Bullet::updateBullet()
{
	this->bullet.move(this->bulletSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->bullet);
}
