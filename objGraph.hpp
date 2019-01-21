#ifndef OBJGRAPH_H_
#define OBJGRAPH_H_

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/InputSoundFile.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace std;

class ObjGraph
{
  protected :
    int posX;
    int posY;

  public :
    ObjGraph(const int&, const int&);
    ObjGraph(const ObjGraph&);

    virtual void draw() = 0;

    virtual ~ObjGraph();
};

#endif
