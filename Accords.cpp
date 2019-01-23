#include "Accords.hpp"

/**************************** Constructors ****************************/

// Accord
Accord::Accord(Note& fond) : fondamentale(fond), nom(fond.toString())
{}
Accord::Accord(const Accord& a) : fondamentale(a.fondamentale), nom(a.nom)
{}

// PowerChord
PowerChord::PowerChord(Note& fond, const bool& dim) : Accord(fond), quinte(fond)
{
  if(dim){
    this->quinte += 6;
    nom += "5dim";
  } else {
    this->quinte += 7;
    nom += "5";
  }
}
PowerChord::PowerChord(const PowerChord& pwc) : Accord(pwc), quinte(pwc.quinte)
{}

// TroisSons
TroisSons::TroisSons(Note& fond, const bool& min, const bool& dim) : PowerChord(fond, dim), tierce(fond)
{
  if(min){ // l'accord est mineur
    this->tierce += 3;
    nom += "m";
  } else { // l'accord est majeur
    this->tierce += 4;
  }
}
TroisSons::TroisSons(const TroisSons& acc) : PowerChord(acc), tierce(acc.tierce)
{}

// QuatreSons
QuatreSons::QuatreSons(Note& fond, const bool& tmin, const bool& smin, const bool& dim) : TroisSons(fond, tmin, dim), septieme(fond)
{
  if(smin){
    this->septieme += 10;
    nom += "7";
  } else {
    this->septieme += 11;
    nom += "M7";
  }
}
QuatreSons::QuatreSons(const QuatreSons& acc) : TroisSons(acc), septieme(acc.septieme)
{}

/**************************** Getters ****************************/

// Accord
string Accord::get_nom()
{
  return this->nom;
}
Note Accord::get_fondamentale()
{
  return this->fondamentale;
}

// PowerChord
Note PowerChord::get_quinte()
{
  return this->quinte;
}

// TroisSons
Note TroisSons::get_tierce()
{
  return this->tierce;
}

// QuatreSons
Note QuatreSons::get_septieme()
{
  return this->septieme;
}

/**************************** Operators ****************************/

// Accord
ostream& operator<<(ostream& out, const Accord& a)
{
  return out << a.nom;
}
bool Accord::operator==(const Accord& a) const
{
  return (this->fondamentale == a.fondamentale);
}
bool Accord::operator!=(const Accord& a) const
{
  return (this->fondamentale != a.fondamentale);
}

// PowerChord
bool PowerChord::operator==(const PowerChord& pwc) const
{
  return ((this->fondamentale == pwc.fondamentale)
          && (this->quinte == pwc.quinte));
}
bool PowerChord::operator!=(const PowerChord& pwc) const
{
  return ((this->fondamentale != pwc.fondamentale)
          || (this->quinte != pwc.quinte));
}

// TroisSons
bool TroisSons::operator==(const TroisSons& acc) const
{
  return ((this->fondamentale == acc.fondamentale)
          && (this->quinte == acc.quinte) && (this->tierce == acc.tierce));
}
bool TroisSons::operator!=(const TroisSons& acc) const
{
  return  ((this->fondamentale != acc.fondamentale)
          || (this->quinte != acc.quinte) || (this->tierce != acc.tierce));
}

// TroisSons
bool QuatreSons::operator==(const QuatreSons& acc)const
{
  return ((this->fondamentale == acc.fondamentale)
                        && (this->quinte == acc.quinte)
                        && (this->tierce == acc.tierce)
                        && (this->septieme == acc.septieme));
}
bool QuatreSons::operator!=(const QuatreSons& acc)const
{
  return ((this->fondamentale != acc.fondamentale)
                        || (this->quinte != acc.quinte)
                        || (this->tierce != acc.tierce)
                        || (this->septieme != acc.septieme));
}
