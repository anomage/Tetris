#ifndef HEADER_GAMEMANAGER
#define HEADER_GAMEMANAGER

#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"

#include "Menu.hpp"

class GameManager
{
    public:
        GameManager();
        ~GameManager();

    protected:
        sf::RenderWindow myApp;
        Menu *myMenu;
        //Game *myGame;
        //Options *myOptions;
        //Credits *myCredits;
};

#endif
