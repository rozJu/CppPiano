/*****************************************************************************/
//  La classe Key permet de gérer l'affichage et l'utilisation d'une touche de
//  piano (toujours avec la SFML), c'est uniquement la classe Keyboard qui
//  l'utilisera. En effet cettedernière gère l'affichage et l'utilisation,
//  d'un clavier complet.
/*****************************************************************************/
#ifndef KEY_H_
#define KEY_H_

#include "objGraph.hpp"

using namespace std;

class Key : public ObjGraph
{
  private :
    sf::RectangleShape touche;  // recctangle représentant la touche
    sf::Color color;            // couleur de la touche
    sf::RenderWindow *window;   // pointeur sur la pfenêtre dans laquelles s'affiche la touche
    sf::SoundBuffer buff;       // buffer nécessaire à la génération d'un son
    sf::Sound sound;            // son de la touche

  public :
    // Constructeur
    Key(const int&, const int&, const sf::RectangleShape&,
                                const sf::Color&,
                                sf::RenderWindow*);
    // Setter
    void set_sound(const string&);
    // Méthodes
    void draw();
    void play();      // gère l'enfoncement d'une touche. Sur le plan sonore et graphique
    void realease();  // gère le relachement d'une touche.

    ~Key();
};
#endif
