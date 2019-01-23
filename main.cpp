#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
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

  int mae=0, i=0, score=0;
  Note C(Do); Note D(Re); Note E(Mi); Note F(Fa); Note G(Sol); Note A(La); Note B(Si);
  Note Cd(Dod); Note Dd(Red); Note Fd(Fad); Note Gd(Sold); Note Ad(Lad);

  Accord accTab[10];
  for(int i = 0; i<10; i++){
    accTab[i] = tirageAleatoire();
  }

  vector<Note> chordNotes;

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

  Screen ecran(100, 100,
                sf::RectangleShape(sf::Vector2f(400.f, 300.f)),
                sf::Color::White,
                &accTab[i],
                &window);

  sf::Text affScore;
  sf::Font font;
  font.loadFromFile("arial_narrow_7.ttf");
  affScore.setFillColor(sf::Color::White);
  affScore.setCharacterSize(100);
  affScore.setFont(font);
  affScore.setPosition(600, 100);

  while(window.isOpen())
  {
    // màj de la fenêtre
    window.clear(sf::Color(80, 80, 80, 0));
    clavier.draw();
    ecran.set_accord(&accTab[i]);
    ecran.draw();
    affScore.setString("Score : " + to_string(score));
    window.draw(affScore);

    sf::Event event;
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case(sf::Event::KeyPressed):
          if(event.key.code == sf::Keyboard::Q){
            clavier.Keys[0].play();
            chordNotes.push_back(C);
          }
          if(event.key.code == sf::Keyboard::S){
            clavier.Keys[1].play();
            chordNotes.push_back(D);
          }
          if(event.key.code == sf::Keyboard::D){
            clavier.Keys[2].play();
            chordNotes.push_back(E);
          }
          if(event.key.code == sf::Keyboard::F){
            clavier.Keys[3].play();
            chordNotes.push_back(F);
          }
          if(event.key.code == sf::Keyboard::G){
            clavier.Keys[4].play();
            chordNotes.push_back(G);
          }
          if(event.key.code == sf::Keyboard::H){
            clavier.Keys[5].play();
            chordNotes.push_back(A);
          }
          if(event.key.code == sf::Keyboard::J){
            clavier.Keys[6].play();
            chordNotes.push_back(B);
          }
          if(event.key.code == sf::Keyboard::K){
            clavier.Keys[7].play();
            chordNotes.push_back(C);
          }
          if(event.key.code == sf::Keyboard::Z){
            clavier.Keys[8].play();
            chordNotes.push_back(Cd);
          }
          if(event.key.code == sf::Keyboard::E){
            clavier.Keys[9].play();
            chordNotes.push_back(Dd);
          }
          if(event.key.code == sf::Keyboard::T){
            clavier.Keys[10].play();
            chordNotes.push_back(Fd);
          }
          if(event.key.code == sf::Keyboard::Y){
            clavier.Keys[11].play();
            chordNotes.push_back(Gd);
          }
          if(event.key.code == sf::Keyboard::U){
            clavier.Keys[12].play();
            chordNotes.push_back(Gd);
          }
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

    if(mae == 0){ // rempissage de l'accord réponse
      if(typeid(accTab[i])==typeid(PowerChord)){
        if(chordNotes.size() == 2){
          mae = 1;
          chordNotes.clear();
        }
      }
      if(typeid(accTab[i])==typeid(TroisSons)){
        if(chordNotes.size() == 3){
          mae = 1;
          chordNotes.clear();
        }
      }
      if(typeid(accTab[i])==typeid(QuatreSons)){
        if(chordNotes.size() == 4){
          mae = 1;
          chordNotes.clear();
        }
      }
    } else if (mae == 1){ // résultat
      if(typeid(accTab[i])==typeid(PowerChord)){
        PowerChord reponse(chordNotes[0], chordNotes[1]);
        if(reponse == (PowerChord) accTab[i]) score++;
        i++;
        if(i < 2){
          mae = 0;
        }
        else {
          mae = 2;
          ecran.on = false; // extinction de l'écran
        }
        cout << score << endl;
      }
      if(typeid(accTab[i])==typeid(TroisSons)){
        TroisSons reponse(chordNotes[0], chordNotes[1], chordNotes[2]);
        if(reponse == (TroisSons) accTab[i]) score++;
        i++;
        if(i < 3){
          mae = 0;
        }
        else {
          mae = 2;
          ecran.on = false; // extinction de l'écran
        }
        cout << score << endl;
      }
      if(typeid(accTab[i])==typeid(QuatreSons)){
        QuatreSons reponse(chordNotes[0], chordNotes[1], chordNotes[2], chordNotes[3]);
        if(reponse == (QuatreSons) accTab[i]) score++;
        i++;
        if(i < 4){
          mae = 0;
        }
        else {
          mae = 2;
          ecran.on = false; // extinction de l'écran
        }
        cout << score << endl;
      }
    }

    // Affichage de la fenêtre
    window.display();
  }
  return 0;
}
