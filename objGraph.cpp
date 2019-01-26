#include "objGraph.hpp"

/**************************** Constructors ****************************/

ObjGraph::ObjGraph(const int& x, const int& y) : posX(x), posY(y)
{}
ObjGraph::ObjGraph(const ObjGraph& obj) : posX(obj.posX), posY(obj.posY)
{}

/**************************** Destructor ****************************/
ObjGraph::~ObjGraph()
{}
