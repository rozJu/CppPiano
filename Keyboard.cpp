#include "Keyboard.hpp"

Keyboard::Keyboard( const int& x,
                    const int& y,
                    // const size_t& tx,
                    // const size_t& ty,
                    const sf::RectangleShape& r,
                    const sf::Color& c,
                    sf::RenderWindow* w): ObjGraph(x, y),
                                          // sizeX(tx),
                                          // sizeY(ty),
                                          clavier(r),
                                          color(c),
                                          window(w)
{
  // sf::RectangleShape c(sf::Vector2f(this->sizeX, this->sizeY));
  this->clavier.setFillColor(this->color);
  this->clavier.setPosition(this->posX, this->posY);
  this->clavier.setOutlineThickness(1.f);
  this->clavier.setOutlineColor(sf::Color::Black);

  for(int i=1; i<=8; i++)
    this->Keys.push_back(Key(i*150, 650, sf::RectangleShape(sf::Vector2f(150.f, 400.f)), sf::Color::White, window));

  for(int i=2; i<=7; i++)
  {
      if(i != 4)
        this->Keys.push_back(Key(i*150-45, 650, sf::RectangleShape(sf::Vector2f(90.f, 200.f)), sf::Color::Black, window));
  }
}
Keyboard::Keyboard(const Keyboard& kb) : ObjGraph(kb)
{}

Key Keyboard::get_Keys(const int& i)
{
  return this->Keys[i];
}

void Keyboard::set_Keys_sounds(const string& c, const string& d, const string& e, const string& f,
                                const string& g, const string& a, const string& b, const string& coct,
                                const string& cd, const string& dd, const string& fd, const string& gd,
                                const string& ad)
{
  this->Keys[0].set_sound(c);
  this->Keys[1].set_sound(d);
  this->Keys[2].set_sound(e);
  this->Keys[3].set_sound(f);
  this->Keys[4].set_sound(g);
  this->Keys[5].set_sound(a);
  this->Keys[6].set_sound(b);
  this->Keys[7].set_sound(coct);
  this->Keys[8].set_sound(cd);
  this->Keys[9].set_sound(dd);
  this->Keys[10].set_sound(fd);
  this->Keys[11].set_sound(gd);
  this->Keys[12].set_sound(ad);

}

void Keyboard::draw()
{
  this->window->draw(this->clavier);
  for(auto it : this->Keys)
    it.draw();
}

Keyboard::~Keyboard()
{}
