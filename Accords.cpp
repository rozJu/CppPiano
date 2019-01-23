#include "Accords.hpp"

/**************************** Constructors ****************************/

// Accord
Accord::Accord()
{}
Accord::Accord(Note& fond) : fondamentale(fond), nom(fond.toString())
{}
Accord::Accord(const Accord& a) : fondamentale(a.fondamentale), nom(a.nom)
{}

// PowerChord
PowerChord::PowerChord()
{}
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
PowerChord::PowerChord(Note& fond, Note& q) : Accord(fond), quinte(q)
{
  if(q-fond == 6)     // si il y a 6 demi-tons entre la fondamentale et la quinte (quinte diminuée)
    nom += "5dim";    // on ajoute au nom que la quinte est diminuée
  else if (q-fond == 7)
    nom += "5";
}

// TroisSons
TroisSons::TroisSons()
{}
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
TroisSons::TroisSons(Note& fond, Note& t, Note& q) : PowerChord(fond, q), tierce(t)
{
  if(t-fond == 3)   // si il y a trois demi-tons entre la fondamentale et la tierce (tièrce mineure)
    nom += "m";     // alors on ajoute un "m" au nom de l'accord
}

// QuatreSons
QuatreSons::QuatreSons()
{}
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
QuatreSons::QuatreSons(Note& fond, Note& t, Note& q, Note& s) : TroisSons(fond, t, q), septieme(s)
{
  if(s-fond == 10)
    nom += "7";
  else if (s-fond == 11)
    nom += "M7";
}
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
