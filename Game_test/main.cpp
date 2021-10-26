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
    /*sf::Font font;
    Botton* Back;
    font.loadFromFile("font/COOPBL.ttf");
    Back = new Botton(25, 25, 150, 50, &font, "BACK", 40,
        sf::Color(1, 1, 1, 255), sf::Color(1, 1, 1, 122), sf::Color(1, 1, 1, 0));*/
    srand(time(0));
    Game game;
    game.run();
    return 0;
}