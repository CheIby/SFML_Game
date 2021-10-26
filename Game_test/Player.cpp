#include "Player.h"
#include <iostream>

void Player::initStatus()
{
	this->gameReset = 0;
	if (gameReset=1)
	{
		this->hp = this->hpMax;
		this->gameReset = 0;
	}
	this->damage = 50;
	this->hpMax = 1000;
	this->hp = this->hpMax;
	this->movementSpeed = 5.f;
	this->cooldownMax = 12.f;
	this->cooldown = this->cooldownMax;
	this->flag = 0;
	this->sahaBool = false;
	this->itemCooldownMax = 200.f;
	this->fireRateflag = 0;
	this->itemCooldownMax2 = 200.f;
	this->collision = 0;
	this->colCooldownMax = 10.f;
}

void Player::initPlayer()
{
	
	if (!this->playerTexture.loadFromFile("image/moveplane2.png"))
	{
		std::cout << "error" << "\n";
	}
	this->playerSprite.setTexture(this->playerTexture);
	this->playerSprite.setScale(0.5f, 0.5f);

	this->sahaTexture.loadFromFile("image/saha.png");
	this->sahaSprite.setTexture(this->sahaTexture);
	this->sahaSprite.setScale(0.5f, 0.5f);

	this->playerColTexture.loadFromFile("image/combat.png");
	this->playerColSprite.setTexture(this->playerColTexture);
	this->playerColSprite.setScale(0.5f, 0.5f);
}

Player::Player()
{
	this->initPlayer();
	this->initStatus();
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->playerSprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->playerSprite.getGlobalBounds();
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->playerSprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->playerSprite.setPosition(x, y);
}

void Player::move(const float dirX, const float dirY)
{
	this->playerSprite.move(movementSpeed * dirX, movementSpeed * dirY);
}

void Player::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

void Player::updateAnmation(int row,float deltatime)
{
	currentImage.y = row;
	totalTime += deltatime;

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
}

void Player::updateHp(int dmg)
{
	this->hp -= dmg;
	if (this->hp <= 0)
		this->hp = 0;
}

void Player::collisionPlayer()
{
	this->collision = 1;
}

void Player::plusHp(int hp)
{
	this->hp += hp;
	if (this->hp >= this->hpMax)
		this->hp = this->hpMax;
}

void Player::getDmg()
{
	this->flag = 1;
}

void Player::getFireRate()
{
	this->fireRateflag = 1;
}

const bool Player::canAttack()
{
	if (this->cooldown >= this->cooldownMax)
	{
		this->cooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (this->cooldown < this->cooldownMax)
		this->cooldown += 0.5f;
	if (this->flag == 1)
	{
		if (this->itemCooldown >= this->itemCooldownMax)
		{
			this->flag = 0;
			this->itemCooldown = 0;
		}
		if (this->itemCooldown < this->itemCooldownMax)
			this->itemCooldown += 0.5f;
	}
	if (this->flag == 0)
	{
		this->sahaBool = false;
	}
	else if (this->flag==1)
	{
		this->sahaBool = true;
		this->sahaSprite.setPosition(this->playerSprite.getPosition().x-this->sahaSprite.getGlobalBounds().width/2+50,this->playerSprite.getPosition().y-this->sahaSprite.getGlobalBounds().height/2+45);
	}
	if (this->fireRateflag == 1)
	{
		if (this->itemCooldown2 >= this->itemCooldownMax2)
		{
			this->fireRateflag = 0;
			this->itemCooldown2 = 0;
		}
		if (this->itemCooldown2 < this->itemCooldownMax2)
			this->itemCooldown2 += 0.5f;
	}
	if (this->fireRateflag == 0)
	{
		this->cooldownMax = 12;
		this->movementSpeed = 5.f;
	}
	else if (this->fireRateflag == 1)
	{
		this->cooldownMax =5;
		this->movementSpeed = 8.f;
	}
	if (this->collision == 1)
	{
		if (this->colCooldown >= this->colCooldownMax)
		{
			this->collision = 0;
			this->colCooldown = 0;
		}
		if (this->colCooldown < this->colCooldownMax)
			this->colCooldown += 0.5f;
	}
	if (this->collision == 1)
	{
		this->playerSprite.setTexture(this->playerColTexture);
	}
	else if (this->collision==0)
	{
		this->playerSprite.setTexture(this->playerTexture);
	}
}

void Player::updatePlayer()
{
	updateAttack();
}

void Player::render(sf::RenderTarget& target)
{	
	if (this->flag == 1)
	{
		target.draw(this->sahaSprite);
	}
	target.draw(this->playerSprite);
}
