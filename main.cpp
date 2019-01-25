#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include <time.h>
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

  srand(time(NULL));
  int mae=0, i=0, score=0;
  Note C(Do); Note D(Re); Note E(Mi); Note F(Fa); Note G(Sol); Note A(La); Note B(Si);
  Note Cd(Dod); Note Dd(Red); Note Fd(Fad); Note Gd(Sold); Note Ad(Lad);

  Accord accTab[10];
  for(int i = 0; i<10; i++){
    accTab[i] = tirageAleatoire();
    cout << accTab[i].get_nom() << " ";
  }
  cout << endl;

  vector<Note> chordNotes;

  sf::RenderWindow window(sf::VideoMode(X_WIN_SIZE,Y_WIN_SIZE), "Yellow");
  window.setKeyRepeatEnabled(false);

  // Construction du clavier
  Keyboard clavier(0, 500,
                  sf::RectangleShape(sf::Vector2f(X_KEYBOARD_SIZE, Y_KEYBOARD_SIZE)),
                  sf::Color(255, 255, 0),
                  &window);
  // Création des sons associées aux touches du clavier
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

  // Construction de l'écran d'affichage des accords
  Screen ecran(100, 100,
                sf::RectangleShape(sf::Vector2f(900.f, 300.f)),
                sf::Color::White,
                &accTab[i],
                &window);

  // Création et configuration des éléments de texte pour l'affichage du score
  sf::Text affScore;
  sf::Font font;
  font.loadFromFile("arial_narrow_7.ttf");
  affScore.setFillColor(sf::Color::White);
  affScore.setCharacterSize(80);
  affScore.setFont(font);
  affScore.setPosition(1100, 100);

  // Boucle de Jeu
  while(window.isOpen())
  {
    // màj de la fenêtre
    window.clear(sf::Color(80, 80, 80, 0));
    clavier.draw();
    ecran.set_accord(&accTab[i]);
    ecran.draw();
    affScore.setString("Score : " + to_string(score));
    window.draw(affScore);

    // Gestion des événements d'intéraction utilisateur
    sf::Event event;
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        // cas où l'utilisateur presse une touche simulant une touche de piano
        case(sf::Event::KeyPressed):
          if(event.key.code == sf::Keyboard::Q){
            clavier.Keys[0].play();     // La note est jouée (voir fonction play() dans Key.cpp)
            chordNotes.push_back(C);    // La note est placée dans le vecteur de construction d'accord
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
            chordNotes.push_back(Ad);
          }
        break;
        // Cas où l'utilisateur relache une touche
        case(sf::Event::KeyReleased):
          if(event.key.code == sf::Keyboard::Q) clavier.Keys[0].realease(); // La note est relachée (voir fonction realease() dans Key.cpp)
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
        // Cas où l'utilisateur ferme la fenêtre
        case sf::Event::Closed :
          window.close();
        break;
      }
    }

    // Ici on utilise une machine à état pour gérer le différentes phases de jeu
    // Phase 1 : remplissage de l'accord réponse
    if(mae == 0)
    { // L'utilisateur presse successivement les touches correspondant aux notes de l'accord demandé
        if(chordNotes.size() == accTab[i].nbNote){ // Si le bon nombre de notes a été joué
          mae = 1;              // l'état suivant sera l'état 1
          chordNotes.clear();   // on vide le vecteur des notes saisies pour récuoérer l'accord suivant
        }
    }
    // Phase 2 : résultat
    else if (mae == 1)
    {
      if(accTab[i].nbNote == 2){
        PowerChord reponse(chordNotes[0], chordNotes[1]); // construction de l'accord saisi par l'utilisateur
        if(accTab[i] == reponse) score++;   // comparaison de cet accord avec celui demandé
        i++;                                // On incrémente i pour passer à l'accord suivant
      }
      if(accTab[i].nbNote == 3){
        TroisSons reponse(chordNotes[0], chordNotes[1], chordNotes[2]);
        if(accTab[i] == reponse) score++;
        i++;
        cout << score << endl;
      }
      if(accTab[i].nbNote == 4){
        QuatreSons reponse(chordNotes[0], chordNotes[1], chordNotes[2], chordNotes[3]);
        if(accTab[i] == reponse) score++;
        i++;
        cout << score << endl;
      }

      if(i < 10){
        mae = 0;
        cout << "mae=0" << endl;
      }
      else {
        mae = 2;
        ecran.on = false; // extinction de l'écran
      }
    }

    // Affichage de la fenêtre
    window.display();
  }
  return 0;
}
