/*****************************************************************************/
//  Dans ce fichier est définie la classe Note et l'enum noteName, cet enum
//  permet de limiter les noms de notes possibles à ceux existants.
/*****************************************************************************/
#ifndef NOTE_H_
#define NOTE_H_

#include <iostream>
using namespace std;

enum noteName
{
  Do, Dod, Re, Red, Mi, Fa, Fad, Sol, Sold, La, Lad, Si
};

class Note {
  private :
    noteName nom; // Nom de la note
  public :
    // Constructeurs
    Note();
    Note(const noteName&);
    Note(const Note&);
    // Getteur
    string toString();
    // Surcharges d'opérateur
    bool operator==(const Note&) const;
    bool operator!=(const Note&) const;
    void operator+=(const int&);

    friend int operator-(const Note&, const Note&);
    friend ostream& operator<<(ostream&, const Note&);
};

#endif
