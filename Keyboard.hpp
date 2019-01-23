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
    sf::RectangleShape clavier;
    sf::Color color;
    sf::RenderWindow *window;

  public :
    vector<Key> Keys;
    // map<sf::Keyboard, int> noteClavier;

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
