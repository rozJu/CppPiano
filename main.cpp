#include <iostream>
#include "Keyboard.hpp"
#include "Key.hpp"
#include "Screen.hpp"
#include "Accords.hpp"

#define X_WIN_SIZE 1500
#define Y_WIN_SIZE 1000
#define X_KEYBOARD_SIZE 1500.f
#define Y_KEYBOARD_SIZE 500.f
#define X_KEYBOARD_POS 0
#define Y_KEYBOARD_POS 500

#define X_WTILE_C_SIZE 150.f
#define Y_WTILE_C_SIZE 350.f
#define X_WTILE_C_POS 150
#define Y_WTILE_C_POS 650

#define X_BTILE_CD_SIZE 100.f
#define Y_BTILE_CD_SIZE 220.f
#define X_BTILE_CD_POS 250
#define Y_BTILE_CD_POS 650

using namespace std;

int main(){

  sf::RenderWindow window(sf::VideoMode(X_WIN_SIZE,Y_WIN_SIZE), "Yellow");
  window.setKeyRepeatEnabled(false);

  Keyboard clavier(0, 500,
                  sf::RectangleShape(sf::Vector2f(X_KEYBOARD_SIZE, Y_KEYBOARD_SIZE)),
                  sf::Color(255, 255, 0),
                  &window);

  clavier.set_Keys_sounds("pianoSounds/Piano.mf.C3.wav",
                          "pianoSounds/Piano.mf.D3.wav",
                          "pianoSounds/Piano.mf.E3.wav",
                          "pianoSounds/Piano.mf.F3.wav",
                          "pianoSounds/Piano.mf.G3.wav",
                          "pianoSounds/Piano.mf.A3.wav",
                          "pianoSounds/Piano.mf.B3.wav",
                          "pianoSounds/Piano.mf.C4.wav",
                          "pianoSounds/Piano.mf.Db3.wav",
                          "pianoSounds/Piano.mf.Eb3.wav",
                          "pianoSounds/Piano.mf.Gb3.wav",
                          "pianoSounds/Piano.mf.Ab3.wav",
                          "pianoSounds/Piano.mf.Bb3.wav");

  Note C(Do);
  TroisSons acc(C, false, false);
  Screen ecran(100, 100,
                sf::RectangleShape(sf::Vector2f(400.f, 300.f)),
                sf::Color::White,
                &acc,
                &window);

  while(window.isOpen())
  {
    window.clear(sf::Color(80, 80, 80, 0));
    clavier.draw();
    ecran.draw();

    sf::Event event;
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case(sf::Event::KeyPressed):
          if(event.key.code == sf::Keyboard::Q) clavier.Keys[0].play();
          if(event.key.code == sf::Keyboard::S) clavier.Keys[1].play();
          if(event.key.code == sf::Keyboard::D) clavier.Keys[2].play();
          if(event.key.code == sf::Keyboard::F) clavier.Keys[3].play();
          if(event.key.code == sf::Keyboard::G) clavier.Keys[4].play();
          if(event.key.code == sf::Keyboard::H) clavier.Keys[5].play();
          if(event.key.code == sf::Keyboard::J) clavier.Keys[6].play();
          if(event.key.code == sf::Keyboard::K) clavier.Keys[7].play();
          if(event.key.code == sf::Keyboard::Z) clavier.Keys[8].play();
          if(event.key.code == sf::Keyboard::E) clavier.Keys[9].play();
          if(event.key.code == sf::Keyboard::T) clavier.Keys[10].play();
          if(event.key.code == sf::Keyboard::Y) clavier.Keys[11].play();
          if(event.key.code == sf::Keyboard::U) clavier.Keys[12].play();
        break;
        case(sf::Event::KeyReleased):
          if(event.key.code == sf::Keyboard::Q) clavier.Keys[0].realease();
          if(event.key.code == sf::Keyboard::S) clavier.Keys[1].realease();
          if(event.key.code == sf::Keyboard::D) clavier.Keys[2].realease();
          if(event.key.code == sf::Keyboard::F) clavier.Keys[3].realease();
          if(event.key.code == sf::Keyboard::G) clavier.Keys[4].realease();
          if(event.key.code == sf::Keyboard::H) clavier.Keys[5].realease();
          if(event.key.code == sf::Keyboard::J) clavier.Keys[6].realease();
          if(event.key.code == sf::Keyboard::K) clavier.Keys[7].realease();
          if(event.key.code == sf::Keyboard::Z) clavier.Keys[8].realease();
          if(event.key.code == sf::Keyboard::E) clavier.Keys[9].realease();
          if(event.key.code == sf::Keyboard::T) clavier.Keys[10].realease();
          if(event.key.code == sf::Keyboard::Y) clavier.Keys[11].realease();
          if(event.key.code == sf::Keyboard::U) clavier.Keys[12].realease();
        break;
        case sf::Event::Closed :
          window.close();
        break;
      }
    }
    window.display();
  }
  return 0;
}
