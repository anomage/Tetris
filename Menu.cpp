#include <iostream>
#include "Menu.hpp"

using namespace std;
using namespace sf;

Menu::Menu()
{
    /* Laborieux, on donne le chemin de la feuille de sprites,
    la position des 3 états possibles de chaque bouton sur la feuille,
    ainsi que leur position sur la fenêtre */
    myPlayButton = new Button(string("Ressources/Feuille_Sprites_Menus.png"),
                              IntRect(0,0,600,104), IntRect(0,0,600,104), IntRect(0,0,600,104),
                              Vector2f(200, 47));
    myOptionsButton = new Button(string("Ressources/Feuille_Sprites_Menus.png"),
                                 IntRect(0,104,600,104), IntRect(0,104,600,104), IntRect(0,104,600,104),
                                 Vector2f(200, 198));
    myCreditsButton = new Button(string("Ressources/Feuille_Sprites_Menus.png"),
                                 IntRect(0,208,600,104), IntRect(0,208,600,104), IntRect(0,208,600,104),
                                 Vector2f(200, 349));

    /* On fixe la texture à "RELEASED" au départ,
    correspondant au bouton qui n'est pas sous le
    curseur (peut être supprimé quand la détection de la
    position du curseur sera implémentée) */
    myPlayButton->switchTexture("RELEASED");
    myOptionsButton->switchTexture("RELEASED");
    myCreditsButton->switchTexture("RELEASED");

    //On charge le bakground du menu, on l'assigne au Sprite
    if(!myBackgroundTexture.loadFromFile("Ressources/Background.png"))
        cerr << "Erreur de chargement." << endl;
    else
        myBackgroundSprite.setTexture(myBackgroundTexture);
}

string Menu::Open(RenderWindow &app) //Le RenderWindow en référence permet de modifier l'app de GameManager directement
{
    //On assigne la taille correspodnant au menu à l'appli
    app.setSize(Vector2u(1000, 500));

    // Boucle principale
    while (app.isOpen())
    {
        Event event;

        while (app.pollEvent(event)) //Tant qu'un event est capté...
        {
            switch(event.type)
            {
                //Si on clique sur la croix, on demande au GameManager d'arrêter le programme
                case Event::Closed :
                    return "EXIT";

                case Event::KeyPressed : //Si on appuie sur une touche...
                    switch(event.key.code)
                    {
                        //Si on presse sur Echap dans le menu, même chose que Event::Closed.
                        case Keyboard::Escape :
                            return "EXIT";
                        /*
                        //Si on presse J, on demande au GameManager de lancer le jeu
                        case Keyboard::J :
                            return "OPEN_GAME";
                        //Si on presse O, on demande au GameManager de d'ouvrir les options
                        case Keyboard::O :
                            return "OPEN_OPTIONS";
                        //Si on presse C, on demande au GameManager de montrer les crédits
                        case Keyboard::C :
                            return "OPEN_CREDITS";
                        */
                    }
            }

        }

        // Affichages
        app.clear();

        //On affiche le background
        app.draw(myBackgroundSprite);
        //On affiche les 3 boutons grâce à la méthode Button::getSprite()
        app.draw(myPlayButton->getSprite());
        app.draw(myOptionsButton->getSprite());
        app.draw(myCreditsButton->getSprite());

        app.display();
    }

    //Ne sert théoriquement pas à grand chose, mais ça ne coûte rien.
    return "EXIT";
}

Menu::~Menu()
{
    delete myPlayButton;
    delete myOptionsButton;
    delete myCreditsButton;
}
