#include "Note.hpp"

/**************************** enum ****************************/
namespace
{
  const string NOMS[] =
  {
    "Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "Sol", "Sol#", "La", "La#", "Si"
  };
}

/**************************** Getters ****************************/

string Note::toString()
{
  return ::NOMS[static_cast<int>(this->nom)];
}

/**************************** Constructors ****************************/

Note::Note(const noteName& n): nom(n)
{}
Note::Note(const Note& note)
{
  this->nom = note.nom;
}

/**************************** Operators ****************************/

bool Note::operator==(const Note& n) const
{
  return (this->nom == n.nom);
}
bool Note::operator!=(const Note& n) const
{
  return (this->nom != n.nom);
}
// permet de changer la hauteur d'une note en lui ajoutant n demis-tons :
void Note::operator+=(const int& n)
{
  int val = (int) this->nom;
  val += (n % 12);
  this->nom = static_cast<noteName>(val);
}

ostream& operator<<(ostream& out, const Note& note)
{
  return out << ::NOMS[static_cast<int>(note.nom)];
}
