#ifndef KEY_H_
#define KEY_H_

#include "objGraph.hpp"

using namespace std;

class Key : public ObjGraph
{
  private :
    sf::RectangleShape touche;
    sf::Color color;
    sf::RenderWindow *window;
    sf::SoundBuffer buff;
    sf::Sound sound;

  public :
    Key(const int&, const int&, const sf::RectangleShape&,
                                const sf::Color&,
                                sf::RenderWindow*);

    void set_sound(const string&);

    void draw();
    void play();
    void realease();

    ~Key();
};
#endif
