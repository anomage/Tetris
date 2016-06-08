#include "Button.hpp"

using namespace std;
using namespace sf;

//Morceau indigeste, on demande le path
Button::Button(string spritesSheetPath,
               IntRect releasedTextureRect, IntRect hoveredTextureRect, IntRect pressedTextureRect,
               Vector2f position)
{
    setReleasedButtonTexture(spritesSheetPath, releasedTextureRect);
    setHoveredButtonTexture(spritesSheetPath, hoveredTextureRect);
    setPressedButtonTexture(spritesSheetPath, pressedTextureRect);
    setPosition(position);
}

void Button::setPressedButtonTexture(string path, IntRect rect)
{
    if(!myPressedTexture.loadFromFile(path, rect))
        cerr << "Erreur de chargement." << endl;
}

void Button::setHoveredButtonTexture(string path, IntRect rect)
{
    if(!myHoveredTexture.loadFromFile(path, rect))
        cerr << "Erreur de chargement." << endl;
}

void Button::setReleasedButtonTexture(string path, IntRect rect)
{
    if(!myReleasedTexture.loadFromFile(path, rect))
        cerr << "Erreur de chargement." << endl;
}

void Button::setPosition(Vector2f position)
{
    mySprite.setPosition(position);
}

Sprite Button::getSprite()
{
    return mySprite;
}

void Button::switchTexture(string texture)
{
    if(texture == "RELEASED")
        mySprite.setTexture(myReleasedTexture);
    else if(texture == "HOVERED")
        mySprite.setTexture(myHoveredTexture);
    else if(texture == "PRESSED")
        mySprite.setTexture(myPressedTexture);
}
