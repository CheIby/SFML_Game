#include "Game.h"
#define _CRT_SECURE_NO_WARNINGS
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1366,768 ), "The Adventure In Space");
	this->window->setFramerateLimit(75);
	this->icon.loadFromFile("image/icon.jpg");
	this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	this->State = 1;
}

void Game::innitMainMenu()
{
	this->menuBuffer.loadFromFile("audio/starwar.wav");
	this->menuSound.setBuffer(this->menuBuffer);
	this->menuSound.setVolume(20);
	this->menuSound.play();
	this->menuSound.setLoop(true);
	this->font.loadFromFile("font/COOPBL.ttf");
	this->menu = new mainMenu();
	this->Newgame = new Botton(533, 300, 300, 50, &font, "NEW GAME", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
	this->HighScore = new Botton(533, 400, 300, 50, &font, "HIGH SCORE", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
	this->Exit = new Botton(533, 500, 300, 50, &font, "EXIT", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
}

void Game::initHighScore()
{
	this->highscore = new Highscore();
	this->Back = new Botton(25, 25, 150, 50, &font, "BACK", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
}

void Game::initEnterName()
{
	this->enterName = new Entername();
	this->BackInput = new Botton(100, 100, 150, 50, &font, "BACK", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
	this->Play = new Botton(500, 200, 150, 50, &font, "PLAY", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
	this->exEnemy[0].loadFromFile("image/moveEnemy1.png");
	this->exEnemy[1].loadFromFile("image/moveEnemy2.png");
}

void Game::initGamePause()
{
	this->gamePause = new Gamepause();
	this->Continuous= new Botton(533, 300, 300, 50, &font, "COUNTINUOUS", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
	this->ExitGamePause = new Botton(533, 400, 300, 50, &font, "EXIT GAME", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
}

void Game::initGameOver()
{
	this->gameOver = new GameOver();
	this->GoToHighScore = new Botton(300, 300, 300, 50, &font, "HIGH SCORE", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
	this->ExtitGame = new Botton(300, 400, 300, 50, &font, "EXIT GAME", 40,
		sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));
}

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
	this->itemBuffer.loadFromFile("audio/item.wav");
	this->itemSound.setBuffer(this->itemBuffer);
	this->itemSound.setVolume(60);
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
	this->buffer.loadFromFile("audio/vader.wav");
	this->sound.setBuffer(buffer);
	this->sound.setVolume(20);
	this->itemSpawnTimerMax = 15.f; 
	this->spawnEnemyTimerMax = 80.f;
	this->updateSpawmTimer = 10000;
}

void Game::initPlayer()
{
	this->player = new Player();
	this->oofBuffer.loadFromFile("audio/oof.wav");
	this->oof.setBuffer(this->oofBuffer);
	this->oof.setVolume(50);
	this->player->Animation(&this->player->playerTexture, sf::Vector2u(3, 1), 0.2f);
	this->player->setPosition(20, this->window->getSize().y / 2 - (this->player->getBounds().height / 2));
}

void Game::initBullet()
{
	this->hitBuffer.loadFromFile("audio/hit.wav");
	this->hitSound.setBuffer(this->hitBuffer);
	this->hitSound.setVolume(50);
	this->bulletFlag = 0;
	this->bulletTexture["BULLET"] = new sf::Texture();
	this->bulletTexture["BULLET"]->loadFromFile("image/bullet.png");
	this->flagcooldownMax = 50.f;
}

void Game::initEnemy()
{
	this->expoBuffer.loadFromFile("audio/expo.wav");
	this->expoSound.setBuffer(this->expoBuffer);
	this->expoSound.setVolume(20);
	this->Enemies[0].loadFromFile("image/moveEnemy1.png");
	this->Enemies[1].loadFromFile("image/moveEnemy2.png");
	this->enemyHP[0] = 150;
	this->enemyHP[1] = 100;
	this->enemyScore[0] = 100;
	this->enemyScore[1] = 200;
	this->enemyDmg[0] = 50;
}

void Game::initGame()
{
	this->menuSound.stop();
	this->initBackground();
	this->initItem();
	this->initVar();
	this->initPlayer();
	this->initBullet();
	this->initEnemy();
	this->sound.play();
	this->sound.setLoop(true);
	clock.restart();
}

Game::Game()
{
	this->initWindow();
	this->innitMainMenu();
	this->initEnterName();
	this->initGamePause();
}

Game::~Game()
{
	delete this->window;
	delete this->gui;
	delete this->player;
	delete this->menu;
	delete this->highscore;
	delete this->Newgame;
	delete this->HighScore;
	delete this->Exit;
	delete this->Back;
	delete this->BackInput;
	delete this->Play;
	delete this->Continuous;
	delete this->ExtitGame;

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
		switch (ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::TextEntered:
			this->textName.push_back(ev);
			break;
		}
	}
}

void Game::updateMenu()
{
	this->Newgame->update(this->mousePos);
	this->Exit->update(this->mousePos);
	this->HighScore->update(this->mousePos);
	if (this->Newgame->isPressed())
	{
		this->State = 3;
	}
	if (this->HighScore->isPressed())
	{
		this->initHighScore();
		this->State = 2;
	}
	if (this->Exit->isPressed())
	{
		this->window->close();
	}
}

void Game::updateHighScore()
{
	this->Back->update(this->mousePos);
	if (this->Back->isPressed())
	{
		this->State = 1;
	}
}

void Game::updateEnterName()
{
	this->enterName->Animation(this->deltaTime);
	this->enterName->enterName(this->textName);
	this->BackInput->update(this->mousePos);
	this->Play->update(this->mousePos);
	if (this->Play->isPressed())
	{
		this->initGame();
		this->State = 4;
	}
	if (this->BackInput->isPressed())
	{
		this->State = 1;
	}
}

void Game::updateGamePause()
{
	this->sound.pause();
	this->Continuous->update(this->mousePos);
	this->ExitGamePause->update(this->mousePos);
	if (this->Continuous->isPressed())
	{
		this->State = 4;
		this->sound.play();
	}
	if (this->ExitGamePause->isPressed())
	{
		this->window->close();
	}
}

void Game::updateGameOver()
{
	this->GoToHighScore->update(this->mousePos);
	this->ExtitGame->update(this->mousePos);
	if (this->GoToHighScore->isPressed())
	{
		this->initHighScore();
		/*this->gameOn = 0;
		this->inputName = 0;
		this->menuOn = 0;
		this->scoreOn = 1;
		this->gameStop = 0;
		this->gamOverOn = 0;*/
	}
	if (this->ExtitGame->isPressed())
	{
		this->window->close();
	}
}

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
		this->hitSound.play();
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
		if (this->spawnEnemyTimerMax <= 20)
			this->spawnEnemyTimerMax = 20;
	}
	this->timer += 5;
}

void Game::updateAnimation()
{
	//player
	this->player->updateAnmation(0, this->deltaTime);
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
		this->random = rand() % 2;
		this->enemySpeed[0] = -(rand() % 5 + 2);
		this->enemySpeed[1] = -(rand() % 5 + 4);
		this->enemyDmg[1] = rand() % 150 + 101;
		this->PosX = this->window->getSize().x + 100.f;
		this->PosY = this->window->getSize().y - ((rand() % this->window->getSize().y-200) +100.f);
		this->enemies.push_back(new Enemy(&this->Enemies[random], this->PosX, this->PosY, this->enemySpeed[random], this->enemyHP[random], this->enemyDmg[random], this->enemyScore[random],this->random));
		this->spawnEnemyTimer = 0.f;
	}
	
	for (int i = 0; i < enemies.size(); i++)
	{
		this->enemies[i]->updateEnemy(this->player->getPos());
		this->enemies[i]->updateAnimation(0,this->deltaTime);
		
		if (this->enemies[i]->getPos().x < 0 - this->enemies[i]->getBounds().width)
		{
			this->enemies.erase(this->enemies.begin() + i);
		}
		else if (enemies[i]->getBounds().intersects(this->player->getBounds()))
		{
			if (this->player->getSaha())
			{
				this->expoSound.play();
				this->gui->updatePoint(this->enemies[i]->Point());
				this->gui->updatetype(this->enemies[i]->getType());
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);
			}
			else
			{
				this->oof.play();
				this->player->updateHp(this->enemies[i]->Dmg());
				this->player->collisionPlayer();
				if (this->player->getHp() == 0)
				{
					this->initGameOver();
					this->sound.stop();
					this->gameOver->getScore(this->gui->getScore());
					this->gameOver->updateHigh(this->enterName->getPlayerName(), this->gui->getScore());
					this->State = 6;
					this->gameRestart();
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
			this->itemSound.play();
			if (this->items[i]->itemType() == 0)
			{
				this->player->plusHp(rand()%101+100);
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
					this->expoSound.play();
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
	this->updateSpawnTimer();
	this->updateInput();
	this->updateEnemy();
	this->updateItem();
	this->updateBullet();
	this->updateCombat();
	this->updateGui();
	this->updateCollisionWorld();
	this->updateAnimation();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->State = 5;
	}
	
}

void Game::gameRestart()
{
	/*for (int i = 0; i < enemies.size(); i++)
	{
		delete this->enemies[i];
		this->enemies.erase(this->enemies.begin() + i);
	}
	for (int i = 0; i < items.size(); i++)
	{
		delete this->items[i];
		this->items.erase(this->items.begin() + i);
	}*/
	this->player->gameReset = 1;
	this->player->setPosition(20, this->window->getSize().y / 2 - (this->player->getBounds().height / 2));
	this->spawnEnemyTimerMax = 80;
	this->gui->gameReset = 1;
	/*this->backgrounds.clear();*/
	/*this->enemies.clear();
	this->items.clear();
	this->gui->score = 0;
	this->backgrounds.push_back(Background(&this->backgroundTexture[0], -50.f));
	this->backgrounds.push_back(Background(&this->backgroundTexture[1], -200.f));*/
}

void Game::renderMenu()
{
	this->window->clear();
	this->menu->render(*this->window);
	this->Newgame->render(this->window);
	this->Exit->render(this->window);
	this->HighScore->render(this->window);
	this->window->display();
}

void Game::renderHigh()
{
	this->window->clear();
	this->highscore->render(this->window);
	this->Back->render(this->window);
	this->window->display();
}

void Game::renderEnterName()
{
	this->window->clear();
	this->enterName->render(this->window);
	this->Play->render(this->window);
	this->BackInput->render(this->window);
	this->window->display();
}

void Game::renderGamePause()
{
	this->window->clear();
	this->gamePause->render(this->window); 
	this->Continuous->render(this->window);
	this->ExitGamePause->render(this->window);
	this->window->display();
}

void Game::renderGameOver()
{
	this->window->clear();
	this->gameOver->render(this->window);
	this->GoToHighScore->render(this->window);
	this->ExtitGame->render(this->window);
	this->window->display();
}

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
		this->deltaTime = this->clock.restart().asSeconds();
		this->mouse = sf::Mouse::getPosition(*this->window);
		this->mousePos = sf::Vector2f(static_cast<float>(mouse.x), static_cast<float>(mouse.y));
		this->updatePullEvent();
		switch (this->State)
		{
		case 1 :
			this->updateMenu();
			this->renderMenu();
			break;
		case 2:
			this->updateHighScore();
			this->renderHigh();
			break;
		case 3:
			this->updateEnterName();
			this->renderEnterName();
			break;
		case 4:
			this->update();
			this->render();
			break;
		case 5:
			this->updateGamePause();
			this->renderGamePause();
			break;
		case 6 :
			this->updateGameOver();
			this->renderGameOver();
		}
	}
}
