#include "Key.hpp"

Key::Key(const int& x, const int& y, const sf::RectangleShape& r,
                                     const sf::Color& c,
                                     sf::RenderWindow* w): ObjGraph(x,y),
                                                           touche(r),
                                                           color(c),
                                                           window(w)
{
  this->touche.setFillColor(this->color);
  this->touche.setPosition(this->posX, this->posY);
  this->touche.setOutlineThickness(1.f);
  this->touche.setOutlineColor(sf::Color::Black);
}

void Key::set_sound(const string& file)
{
  if (!this->buff.loadFromFile(file)) cout << "error SoundBuffer" << endl;
  this->sound.setBuffer(buff);
}

void Key::draw()
{
  this->window->draw(this->touche);
}

void Key::play()
{
  this->touche.setFillColor(sf::Color::Yellow);
  sound.play();
}

void Key::realease()
{
  this->touche.setFillColor(this->color);
}

Key::~Key()
{}
