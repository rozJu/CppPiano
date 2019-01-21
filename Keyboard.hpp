#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "objGraph.hpp"
#include "Key.hpp"

using namespace std;

class Keyboard : public ObjGraph
{
  private :
    sf::RectangleShape clavier;
    sf::Color color;
    sf::RenderWindow *window;
    // Faire une map qui associe une touche de clavier

  public :
    vector<Key> Keys;
    Keyboard(const int&, const int&,
                         const sf::RectangleShape&,
                         const sf::Color&,
                         sf::RenderWindow*);

    Keyboard(const Keyboard&);

    Key get_Keys(const int&);

    void set_Keys_sounds(const string&, const string&, const string&, const string&,
                         const string&, const string&, const string&, const string&,
                         const string&, const string&, const string&, const string&,
                         const string&);

    void draw();

    ~Keyboard();
};

#endif
