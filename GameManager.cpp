#include "GameManager.hpp"

using namespace std;
using namespace sf;

GameManager::GameManager()
{
    //On veut que le menu principal soit ouvert au d�marrage
    string toDo = "OPEN_MENU";

    //On ouvre la fen�tre pour qu'elle puisse exister
    myApp.create(VideoMode(0, 0, 32), "Tetris");

    //On instancie les diff�rentes parties du programme
    myMenu = new Menu();
    //myGame = new Game();
    //myOptions = new Options();
    //myCredits = new Credits();

    /*La boucle permettant de naviguer dans tout le programme
    Tant qu'on a pas quitt� un membre du programme en disant
    que l'on veut quitter le programme entier, on continue �
    afficher ce qu'on demande */
    while(toDo != "EXIT")
    {
        if(toDo == "OPEN_MENU")
            toDo = myMenu->Open(myApp);
    }
}

GameManager::~GameManager()
{
    delete myMenu;
    //delete myGame;
    //delete myOptions;
    //Delete myCredits;
}
