/*****************************************************************************/
//  La classe Keyboard, gère l'affichage complet du piano en bas de l'interface
//  graphique, ainsi que le son qui va être émis par chaque touche
/*****************************************************************************/
#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <vector>
#include <list>
#include "objGraph.hpp"
#include "Key.hpp"

using namespace std;

class Keyboard : public ObjGraph
{
  private :
    sf::RectangleShape clavier; // rectangle représentant la base du clavier
    sf::Color color; // couleur du fond du clavier
    sf::RenderWindow *window; // pointeur sur la fenêtre dans laquelle le clavier doit s'afficher

  public :
    vector<Key> Keys; // vecteur de touche de piano définies dans la classe Key
    // Constructeurs
    Keyboard(const int&, const int&,
                         const sf::RectangleShape&,
                         const sf::Color&,
                         sf::RenderWindow*);
    Keyboard(const Keyboard&);
    // Getters
    Key get_Keys(const int&); // permet de récupérer une touches en fonction de son indice
    // Setter
    void set_Keys_sounds(const string&, const string&, const string&, const string&,
                         const string&, const string&, const string&, const string&,
                         const string&, const string&, const string&, const string&,
                         const string&); // permet de configurer les sons associés à chaque touce
    void draw();

    ~Keyboard();
};

#endif
