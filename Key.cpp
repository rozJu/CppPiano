#include "Key.hpp"

/**************************** Constructors ****************************/

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

/**************************** Seter ****************************/

void Key::set_sound(const string& file)           // configuration du sond associé à la touche
{
  if (!this->buff.loadFromFile(file)) cout << "error SoundBuffer" << endl;
  this->sound.setBuffer(buff);
}

/**************************** Méthodes ****************************/

void Key::draw()                                  // Affichage de la touche
{
  this->window->draw(this->touche);
}

void Key::play()                                  // fonction appelée quand l'utilisateur joue une note
{
  this->touche.setFillColor(sf::Color::Yellow);   // La touche change de couleur
  sound.play();                                   // le son du la touche est joué
}

void Key::realease()                              // Fonction appelée quand l'utilisateur relache la touche
{
  this->touche.setFillColor(this->color);         // La touche reprend sa couleur initiale
}

Key::~Key()
{}
