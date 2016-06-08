#ifndef HEADER_MENU
#define HEADER_MENU

#include <iostream>
#include <string>

#include "Button.hpp"

#include "SFML/Graphics.hpp"

class Menu
{
    public:
        Menu();
        ~Menu();
        std::string Open(sf::RenderWindow &app);

    protected:
        Button *myPlayButton, *myOptionsButton, *myCreditsButton;
        sf::Texture myBackgroundTexture;
        sf::Sprite myBackgroundSprite;
};

#endif
