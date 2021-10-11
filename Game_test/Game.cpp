#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1366,768 ), "The Adventure In Space");
	this->window->setFramerateLimit(75);
}

void Game::innitMainMenu()
{
	this->font.loadFromFile("font/COOPBL.ttf");
	this->menu = new mainMenu();
	this->Newgame = new Botton(533, 300, 300, 50, &font, "NEW GAME", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
	this->HighScore = new Botton(533, 400, 300, 50, &font, "HIGH SCORE", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
	this->Exit = new Botton(533, 500, 300, 50, &font, "EXIT", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
	this->Back = new Botton(25, 25, 150, 50, &font, "BACK", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
}

//void Game::initHighScore()
//{
//	this->highscoreTex.loadFromFile("image/mainmenu.jpg");
//	this->highScoreSpirte.setTexture(this->highscoreTex);
//	file = fopen("./highscore.txt", "r");
//	for (int i = 0; i < 5; i++)
//	{
//		fscanf(file, "%s", temp);
//		playerName[i] = temp;
//		fscanf(file, "%d", scoreArr[i]);
//		highScore.push_back(std::make_pair(scoreArr[i], playerName[i]));
//	}
//}

void Game::initBackground()
{
	this->backgroundTexture[0].loadFromFile("image/sky.png");
	this->backgroundTexture[1].loadFromFile("image/mountain.png");
	this->backgrounds.push_back(Background(&this->backgroundTexture[0], -50.f));
	this->backgrounds.push_back(Background(&this->backgroundTexture[1], -200.f));
	this->background2Texture.loadFromFile("image/sky2.png");
	this->background2.setSize(sf::Vector2f(1366, 768));
	this->background2.setTexture(&background2Texture);
}

void Game::initItem()
{
	this->itemTexture[0].loadFromFile("image/item1.png");
	this->itemTexture[1].loadFromFile("image/item2.png");
	this->itemTexture[2].loadFromFile("image/item3.png");
	this->setScale[0] = 0.4f;
	this->setScale[1] = 0.4f;
	this->setScale[2] = 0.4f;
}

void Game::initVar()
{
	this->gui = new GUI();
	this->itemSpawnTimerMax = 15.f; 
	this->spawnEnemyTimerMax = 20.f;
	this->updateSpawmTimer = 10000;
}

void Game::initPlayer()
{
	this->player = new Player();
	this->player->Animation(&this->player->playerTexture, sf::Vector2u(3, 1), 0.2f);
	this->player->setPosition(20, this->window->getSize().y / 2 - (this->player->getBounds().height / 2));
}

void Game::initBullet()
{
	this->bulletFlag = 0;
	this->bulletTexture["BULLET"] = new sf::Texture();
	this->bulletTexture["BULLET"]->loadFromFile("image/bullet.png");
	this->flagcooldownMax = 50.f;
}

void Game::initEnemy()
{
	this->Enemies[0].loadFromFile("image/moveEnemy1.png");
	this->Enemies[1].loadFromFile("image/moveEnemy2.png");
	this->enemySpeed[0] =-(rand() % 5 + 2);
	this->enemySpeed[1] =-(rand() % 5 + 4);
	this->enemyHP[0] = 150;
	this->enemyHP[1] = 50;
	this->enemyScore[0] = 100;
	this->enemyScore[1] = 200;
	this->enemyDmg[0] = 50;
}

Game::Game()
{
	this->initVar();
	this->innitMainMenu();
	/*this->initHighScore();*/
	this->initBackground();
	this->initItem();
	this->initBullet();
	this->initEnemy();
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->player;
	delete this->menu;
	delete this->Newgame;
	delete this->HighScore;
	delete this->Exit;
	for (auto& i : this->bulletTexture)
	{
		delete i.second;
	}
	//delete bullet
	for (auto* i : this->bullets)
	{
		delete i;
	}

	for (auto* i : this->enemies)
	{
		delete i;
	}

	for (auto* i : this->items)
	{
		delete i;
	}
	
}

void Game::updatePullEvent()
{
	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::updateMenu()
{
	
	this->Newgame->update(this->mousePos);
	this->Exit->update(this->mousePos);
	this->HighScore->update(this->mousePos);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		this->gameOn = 1;
		this->menuOn = 0;
		this->scoreOn = 0;
		this->gamOverOn = 0;
	}
	if (this->Newgame->isPressed())
	{
		this->gameOn = 1;
		this->menuOn = 0;
		this->scoreOn = 0;
		this->gamOverOn = 0;
	}
	if (this->HighScore->isPressed())
	{
		this->gameOn = 0;
		this->menuOn = 0;
		this->scoreOn = 1;
		this->gamOverOn = 0;
	}
	if (this->Exit->isPressed())
	{
		this->window->close();
	}
}

//void Game::updateHighScore()
//{
//	highScore.erase(highScore.begin(), highScore.end());
//	file = fopen("./highsocore.txt", "r");
//	for (int i = 0; i < 5; i++)
//	{
//		fscanf_s(file, "%s", temp);
//		playerName[i] = temp;
//		fscanf_s(file, "%d", scoreArr[i]);
//		highScore.push_back(std::make_pair(scoreArr[i], playerName[i]));
//	}
//
//	this->Back->update(this->mousePos);
//	if (this->Back->isPressed())
//	{
//		this->gameOn = 0;
//		this->menuOn = 1;
//		this->scoreOn = 0;
//		this->gamOverOn = 0;
//	}
//
//}

void Game::updateInput()
{
	//moveplayer
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->bulletTexture["BULLET"],
			this->player->getPos().x + this->player->getBounds().width/2, 
			this->player->getPos().y + this->player->getBounds().height/2, 
			1.f, 0.f, 10.f));
	}
}

void Game::updateCollisionWorld()
{
	//left world collision
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	//right world collison
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}
	//top world collision
	if (this->player->getBounds().top < 90.f)
	{
		this->player->setPosition(this->player->getBounds().left, 90.f);
	}
	//Bottom world collison
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}
}

void Game::updateSpawnTimer()
{
	
	if (this->timer >= this->updateSpawmTimer)
	{
		this->timer = 0;
		this->spawnEnemyTimerMax -= 10;
		if (this->spawnEnemyTimerMax <= 10)
			this->spawnEnemyTimerMax = 10;
	}
	this->timer += 5;
}

void Game::updateAnimation()
{
	
	//player
	this->player->updateAnmation(0,this->deltaTime);
	this->player->playerSprite.setTextureRect(player->uvRect);
	//background
	for (Background& background : backgrounds)
		background.updateBackground(deltaTime);
}

void Game::updateEnemy()
{
	this->spawnEnemyTimer += 0.5f;
	if (this->spawnEnemyTimer >= this->spawnEnemyTimerMax)
	{
		this->enemyDmg[1] = rand() % 150 + 101;
		this->random = rand() % 2;
		this->PosX = this->window->getSize().x + 100.f;
		this->PosY = this->window->getSize().y - ((rand() % this->window->getSize().y-200) +100.f);
		this->enemies.push_back(new Enemy(&this->Enemies[random], this->PosX, this->PosY, this->enemySpeed[random], this->enemyHP[random], this->enemyDmg[random], this->enemyScore[random],this->random));
		this->spawnEnemyTimer = 0.f;
	}
	
	for (int i = 0; i < enemies.size(); i++)
	{
		this->enemies[i]->updateEnemy(this->player->getPos(),this->player->getCenter(),this->player->getBounds());
		this->enemies[i]->updateAnimation(0,this->deltaTime);
		
		if (this->enemies[i]->getPos().x < 0 - this->enemies[i]->getBounds().width)
		{
			this->enemies.erase(this->enemies.begin() + i);
		}
		else if (enemies[i]->getBounds().intersects(this->player->getBounds()))
		{

			if (this->player->getSaha())
			{
				this->gui->updatePoint(this->enemies[i]->Point());
				this->gui->updatetype(this->enemies[i]->getType());
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);
			}
			else
			{
				this->player->updateHp(this->enemies[i]->Dmg());
				this->player->collisionPlayer();
				if (this->player->getHp() == 0)
				{
					this->gameOn = 0;
					this->menuOn = 0;
					this->scoreOn = 0;
					this->gamOverOn = 1;
				}
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);
			}
		}
	}
	
}

void Game::updateItem()
{
	this->itemSpawnTimer += this->deltaTime;
	if (this->itemSpawnTimer >= this->itemSpawnTimerMax)
	{
		this->itemSpawnTimer -= this->itemSpawnTimerMax;
		this->randomItem = rand() % 3;
		this->items.push_back(new Item(&this->itemTexture[randomItem],this->window->getSize().x+100, this->window->getSize().y - ((rand() % this->window->getSize().y - 200) + 100.f), this->setScale[randomItem],this->randomItem));
	}

	for (int i = 0; i < items.size(); i++)
	{
		this->items[i]->updateItem();
		if (this->items[i]->getBounds().intersects(this->player->getBounds()))
		{
			if (this->items[i]->itemType() == 0)
			{
				this->player->plusHp(rand()%100+101);
				delete this->items[i];
				this->items.erase(this->items.begin() + i);
			}
			else if (this->items[i]->itemType() == 1)
			{
				this->player->getDmg();
				delete this->items[i];
				this->items.erase(this->items.begin() + i);
			}
			else if (this->items[i]->itemType() == 2)
			{
				this->player->getFireRate();
				delete this->items[i];
				this->items.erase(this->items.begin() + i);
			}
		}
		else if (this->items[i]->deleteItem())
		{
			delete this->items[i];
			this->items.erase(this->items.begin() + i);
		}
	}
}

void Game::updateBullet()
{
	this->player->updateAttack();
	for (int i = 0; i < bullets.size(); i++)
	{
		this->bullets[i]->updateBullet();
		if (this->bullets[i]->getPos().x > this->window->getSize().x)
		{
			this->bullets.erase(this->bullets.begin() + i);
		}
	}
}

void Game::updateCombat()
{
	for (int j = 0; j < this->enemies.size(); ++j)
	{
		bool enemy_deleted = false;
		for (int k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[j]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				this->enemies[j]->loseHp(this->player->damage);
				if (this->enemies[j]->currentHP() == 0)
				{
					this->gui->updatePoint(this->enemies[j]->Point());
					this->gui->updatetype(this->enemies[j]->getType());
					delete this->enemies[j];
					this->enemies.erase(this->enemies.begin() + j);
					enemy_deleted = true;
				}
			}
		}
	}
}

void Game::updateGui()
{
	this->gui->currentPoint();
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->gui->updatPlayerHpBar(hpPercent);
	this->gui->currentType();
}

void Game::update()
{	
	this->deltaTime = this->clock.restart().asSeconds();
	this->updateSpawnTimer();
	this->updateAnimation();
	this->updateInput();
	this->updateEnemy();
	this->updateItem();
	this->updateBullet();
	this->updateCombat();
	this->updateGui();
	this->updateCollisionWorld();
}

void Game::renderMenu()
{
	this->window->clear();
	this->menu->render(*this->window);
	this->Newgame->render(this->window);
	this->Exit->render(this->window);
	this->HighScore->render(this->window);
	/*showText(sf::Vector2f(660.0f, 950.0f), "63010952 Soravee Rattanaapha", &font, 40, *window);*/
	this->window->display();
}

//void Game::renderHigh()
//{
//	this->window->clear();
//	this->window->draw(this->highScoreSpirte);
//	this->Back->render(this->window);
//	this->window->display();
//}

void Game::render()
{
	this->window->clear();
	//background
	this->window->draw(this->background2);
	for (Background& background : backgrounds)
		background.render(*this->window);
	//enemy
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}
	//buullet
	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}
	for (auto* item : this->items)
	{
		item->render(this->window);
	}
	//player
	this->player->render(*this->window);
	this->gui->renderGui(this->window);
	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->mouse = sf::Mouse::getPosition(*this->window);
		this->mousePos = sf::Vector2f(static_cast<float>(mouse.x), static_cast<float>(mouse.y));
		this->updatePullEvent();
		if (menuOn)
		{
			this->updateMenu();
			this->renderMenu();
		}
		/*if (scoreOn)
		{
			this->updateHighScore();
			this->renderHigh();
		}*/
		if (gameOn)
		{
			this->update();
			this->render();
		}
		if (gamOverOn)
		{
			this->window->close();
		}
	}
}
