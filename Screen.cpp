#include "Screen.hpp"

/**************************** Constructors ****************************/
Screen::Screen(const int& x,
               const int& y,
               const sf::RectangleShape& r,
               const sf::Color& c,
               Accord* a,
               sf::RenderWindow* w) : ObjGraph(x, y),
                                    ecran(r),
                                    color(c),
                                    acc(a),
                                    window(w),
                                    on(true)
{
  // gestion de l'affichade de l'écran
  this->ecran.setFillColor(this->color);
  this->ecran.setPosition(this->posX, this->posY);
  this->ecran.setOutlineThickness(3.f);
  this->ecran.setOutlineColor(sf::Color::Black);

  this->font.loadFromFile("arial_narrow_7.ttf");
  this->nomAcc.setFillColor(sf::Color::Red);
  this->nomAcc.setCharacterSize(200);
  this->nomAcc.setFont(font);
  this->nomAcc.setPosition(this->posX+55, this->posY+20);
}

/**************************** Méthodes ****************************/
void Screen::draw()
{
  if(this->on)  // un accord ne s'affiche que si l'écran est allumé
    this->nomAcc.setString(this->acc->get_nom());
  else          // sinon rien ne s'affiche
    this->nomAcc.setString(" ");

  this->window->draw(this->ecran);
  this->window->draw(this->nomAcc);
}

/**************************** Setters ****************************/

void Screen::set_accord(Accord* a)
{
  this->acc = a;
}
