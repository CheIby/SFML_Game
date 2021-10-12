#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, float posX, float posY,int speed, int hp, int dmg, int score, int rand)
{
    this->movementSpeed = speed;
    this->enemytexture = texture;
    this->enemy.setTexture(*this->enemytexture);
    this->enemy.setScale(0.5f, 0.5f);
    this->enemy.setPosition(posX, posY);
    this->hpMax = hp;
    this->hp = hp;
    this->dmg = dmg;
    this->points = score;
    this->type = rand;
    this->imageCount = sf::Vector2u (3, 1);
    this->switchTime = 0.2f;
    this->currentImage.x = 0;

    this->hpbar.setSize(sf::Vector2f(this->enemy.getGlobalBounds().width / 3, 7));
    this->hpbar.setFillColor(sf::Color::Red);
    this->hpbarBack = this->hpbar;
    this->hpbarBack.setFillColor(sf::Color(25, 25, 25, 200));

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

Enemy::~Enemy()
{

}

const sf::FloatRect Enemy::getBounds() const
{
    return this->enemy.getGlobalBounds();
}

void Enemy::updateEnemy(sf::Vector2f playerPos)
{
    this->playerPos = playerPos;

    if (this->type == 0)
    {
        if (this->enemy.getPosition().x < this->playerPos.x)
        {
            this->enemy.move(this->movementSpeed, 0);
            this->enemy.setTextureRect(uvRect);
        }
        if (this->playerPos.y > this->enemy.getPosition().y)
        {
            check = true;
        }
        else if (this->playerPos.y < this->enemy.getPosition().y)
        {
            check = false;
        }
        if (check)
        {
            this->enemy.move(this->movementSpeed, 1);
            this->enemy.setTextureRect(uvRect);
        }
        else
        {
            this->enemy.move(this->movementSpeed, -1);
            this->enemy.setTextureRect(uvRect);
        }
    }
    else
    {
        this->enemy.move(this->movementSpeed, 0);
        this->enemy.setTextureRect(uvRect);
    }
    
}

void Enemy::loseHp(int var)
{
    this->hp -= var;
    if (this->hp <= 0)
        this->hp = 0;
}

void Enemy::updateAnimation(int row, float deltatime)
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

    this->hpPercent = static_cast<float>(this->hp) / this->hpMax;
    this->hpbar.setSize(sf::Vector2f(this->enemy.getGlobalBounds().width * this->hpPercent, this->hpbar.getSize().y));
    this->hpbar.setPosition(sf::Vector2f(this->enemy.getPosition().x, this->enemy.getPosition().y - 15));
    this->hpbarBack.setPosition(sf::Vector2f(this->enemy.getPosition().x, this->enemy.getPosition().y - 15));
}

void Enemy::render(sf::RenderTarget* target)
{
    target->draw(this->hpbarBack);
    target->draw(this->hpbar);
    target->draw(this->enemy);
}
