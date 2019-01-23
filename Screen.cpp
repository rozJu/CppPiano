#include "Screen.hpp"

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

void Screen::draw()
{
  if(this->on)
    this->nomAcc.setString(this->acc->get_nom());
  else
    this->nomAcc.setString(" ");

  this->window->draw(this->ecran);
  this->window->draw(this->nomAcc);
}

void Screen::set_accord(Accord* a)
{
  this->acc = a;
}

// void Screen::set_on(bool& b){
//   this->on = b;
// }
