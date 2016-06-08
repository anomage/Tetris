#ifndef HEADER_BUTTON
#define HEADER_BUTTON

#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"

class Button
{
    public:
        Button(std::string spritesSheetPath,
               sf::IntRect releasedTextureRect, sf::IntRect hoveredTextureRect, sf::IntRect pressedTextureRect,
               sf::Vector2f position);
        void setReleasedButtonTexture(std::string path, sf::IntRect rect);
        void setHoveredButtonTexture(std::string path, sf::IntRect rect);
        void setPressedButtonTexture(std::string path, sf::IntRect rect);
        void setPosition(sf::Vector2f position);
        sf::Sprite getSprite();
        void switchTexture(std::string texture);

    protected:
        sf::Texture myReleasedTexture, myHoveredTexture, myPressedTexture;
        sf::Sprite mySprite;
};

#endif
