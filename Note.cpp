#include "Note.hpp"

/**************************** enum ****************************/
namespace
{
  // Les strings contenues dans ce tableau sont dans le même ordre que les notes
  // cela est utilisé dans la fonction toString() ci-dessous.
  const string NOMS[] =
  {
    "Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "Sol", "Sol#", "La", "La#", "Si"
  };
}

/**************************** Getters ****************************/

// Cette fonction retourne la chaine de caractère associée au nom de type noteName
string Note::toString()
{
  return ::NOMS[static_cast<int>(this->nom)]; // retourne le nom de l'accord sous forme de string
                                              // en utilisant l'indice par défaut du enum pour récupérer
                                              // le nom de la note dans le tableau NOMS[]
}

/**************************** Constructors ****************************/
Note::Note()
{}
Note::Note(const noteName& n): nom(n)
{}
Note::Note(const Note& note)
{
  this->nom = note.nom;
}

/**************************** Operators ****************************/

// Les notes sont comparées par leur noms puisque c'est essentiellement ce qui les différencie
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

// La soustraction de deux notes renvoie l'intérval en demis-tons qui les séparent
int operator-(const Note& f, const Note& s)
{
  int val1 = (int) f.nom;
  int val2 = (int) s.nom;
  return val1-val2;
}

ostream& operator<<(ostream& out, const Note& note)
{
  return out << ::NOMS[static_cast<int>(note.nom)];
}
