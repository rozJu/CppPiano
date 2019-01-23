#ifndef SCREEN_H_
#define SCREEN_H_

#include "objGraph.hpp"
#include "Accords.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Screen : ObjGraph
{
  private :
    sf::RectangleShape ecran;
    sf::Color color;
    sf::RenderWindow *window;
    sf::Text nomAcc;
    sf::Font font;
    Accord *acc;

  public :
    Screen(const int& x, const int& y,
                         const sf::RectangleShape& r,
                         const sf::Color& c,
                         Accord*,
                         sf::RenderWindow*);
    Screen(const Screen&);

    void draw();

    void set_accord(Accord* a);
    // string get_accord()const;

    // ~Screen();
};

#endif
