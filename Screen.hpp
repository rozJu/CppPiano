/*****************************************************************************/
//  La classe Screen représente l'écran en haut à gauche de l'interface
//  graphique. Cet écrant est utilisable pour afficher le nom d'un accord.
//  Il gère toutes les parties de la SFML nécessaires à l'affichage dans une
//  fenêtre.
/*****************************************************************************/
#ifndef SCREEN_H_
#define SCREEN_H_

#include "objGraph.hpp"
#include "Accords.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Screen : ObjGraph
{
  private :
    sf::RectangleShape ecran; // rectangle représentant le fond de l'écran
    sf::Color color;          // couleur de l'écran
    sf::RenderWindow *window; // pointeur sur la fenêtre dans laquelle devra être affichée l'écran
    sf::Text nomAcc;          // Texte affiché qui correspond au nom d'un accord
    sf::Font font;            // police utilisée pour le texte
    Accord *acc;              // accord à afficher

  public :
    //  Constructeurs
    Screen(const int& x, const int& y,
                         const sf::RectangleShape& r,
                         const sf::Color& c,
                         Accord*,
                         sf::RenderWindow*);
    Screen(const Screen&);
    // Setter
    void set_accord(Accord* a);
    // Méthode permettant de dessiner l'écran sur la fenêtre
    void draw();
    // Booléen permettant d'allumer ou éteindre l'écran
    bool on;
    // string get_accord()const;
};

#endif
