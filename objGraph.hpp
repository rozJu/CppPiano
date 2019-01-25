/*****************************************************************************/
//  ObjGraph est la classe mère de toutes les classes gérant de l'affichage
//  avec la SFML. En effet toutes ces classes auront besoint d'une position
//  (x et y) et d'une fonction qui la déssinera sur la fenêtre (draw()).
//  Cette classe est virtuelle.
/*****************************************************************************/
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
