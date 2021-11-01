#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "Game.h"
#include "Player.h"
#include "Background.h"
#include "mainMenu.h"
#include "Botton.h"


int main()
{
    srand(time(0));
    Game game;
    game.run();
    return 0;
}