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
    noteName nom;
  public :
    Note(const noteName&);
    Note(const Note&);

    string toString();

    bool operator==(const Note&) const;
    bool operator!=(const Note&) const;
    void operator+=(const int&);

    friend ostream& operator<<(ostream&, const Note&);
};

#endif
