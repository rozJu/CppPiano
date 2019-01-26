#include "Accords.hpp"

/**************************** Constructors ****************************/

// Accord //
Accord::Accord()
{}
Accord::Accord(Note& fond) : fondamentale(fond), nom(fond.toString()), nbNote(1)
{}
Accord::Accord(const Accord& a) : fondamentale(a.fondamentale), nom(a.nom), nbNote(a.nbNote)
{}

// PowerChord //
PowerChord::PowerChord()
{this->nbNote = 2;}
PowerChord::PowerChord(Note& fond, const bool& dim) : Accord(fond), quinte(fond)
{
  if(dim){                 // la quinte est diminuée
    this->quinte += 6;
    nom += "5dim";
  } else {                 // la quinte est juste
    this->quinte += 7;
    nom += "5";
  }
  this->nbNote = 2;
}
PowerChord::PowerChord(const PowerChord& pwc) : Accord(pwc), quinte(pwc.quinte)
{}
PowerChord::PowerChord(Note& fond, Note& q) : Accord(fond), quinte(q)
{
  if(q-fond == 6)          // si il y a 6 demi-tons entre la fondamentale et la quinte (quinte diminuée)
    nom += "5dim";         // on ajoute au nom que la quinte est diminuée
  else if (q-fond == 7)
    nom += "5";
  this->nbNote = 2;
}

// TroisSons //
TroisSons::TroisSons()
{this->nbNote = 3;}
TroisSons::TroisSons(Note& fond, const bool& min, const bool& dim) : PowerChord(fond, dim), tierce(fond)
{
  nom = fond.toString();
  // gestion de la tierce
  if(min){                 // l'accord est mineur
    this->tierce += 3;
    nom += "m";
  } else {                 // l'accord est majeur
    this->tierce += 4;
  }
  // gestion de la quinte
  if(dim){
    this->quinte += 6;
    nom += "b5";
  } else {
    this->quinte += 7;
  }
  this->nbNote = 3;
}
TroisSons::TroisSons(const TroisSons& acc) : PowerChord(acc), tierce(acc.tierce)
{}
TroisSons::TroisSons(Note& fond, Note& t, Note& q) : PowerChord(fond, q), tierce(t)
{
  nom = fond.toString();
  if(t-fond == 3){         // si il y a trois demi-tons entre la fondamentale et la tierce (tièrce mineure)
    nom += "m";            // alors on ajoute un "m" au nom de l'accord
  }
  if(q-fond == 6){
    nom += "b5";
  }
  this->nbNote = 3;
}

// QuatreSons //
QuatreSons::QuatreSons()
{this->nbNote = 4;}
QuatreSons::QuatreSons(Note& fond, const bool& tmin, const bool& smin, const bool& dim) : TroisSons(fond, tmin, dim), septieme(fond)
{
  nom = fond.toString();
  // gestion de la get_tierce
  if(tmin){                 // l'accord est mineur
    this->tierce += 3;
    nom += "m";
  } else {                 // l'accord est majeur
    this->tierce += 4;
  }
  // gestion de la septième
  if(smin){                 // la septième est mineure
    this->septieme += 10;
    nom += "7";
  } else {                  // la septième est majeure
    this->septieme += 11;
    nom += "M7";
  }
  // gestion de la quinte
  if(dim){
    this->quinte += 6;
    nom += "b5";
  } else {
    this->quinte += 7;
  }

  this->nbNote = 4;
}
QuatreSons::QuatreSons(const QuatreSons& acc) : TroisSons(acc), septieme(acc.septieme)
{}
QuatreSons::QuatreSons(Note& fond, Note& t, Note& q, Note& s) : TroisSons(fond, t, q), septieme(s)
{
  nom = fond.toString();
  if(t-fond == 3){
    nom += "m";
  }
  if(s-fond == 10){
    nom += "7";
  }
  else if (s-fond == 11){
    nom += "M7";
  }
  if(q-fond == 6){
    nom += "b5";
  }
  this->nbNote = 4;
}
/**************************** Getters ****************************/

// Accord //
string Accord::get_nom()
{
  return this->nom;
}
Note Accord::get_fondamentale()
{
  return this->fondamentale;
}

// PowerChord //
Note PowerChord::get_quinte()
{
  return this->quinte;
}

// TroisSons //
Note TroisSons::get_tierce()
{
  return this->tierce;
}

// QuatreSons //
Note QuatreSons::get_septieme()
{
  return this->septieme;
}

/**************************** Operators ****************************/

// Accord //
ostream& operator<<(ostream& out, const Accord& a)
{
  return out << a.nom;
}
bool Accord::operator==(const Accord& a) const // retourne vrai si toutes les notes qui compose l'accord sont les mêmes
{
  return (this->fondamentale == a.fondamentale);
}
bool Accord::operator!=(const Accord& a) const // retourne vrai si toutes les notes qui compose l'accord ne sont pas les mêmes
{
  return (this->fondamentale != a.fondamentale);
}

// PowerChord //
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

// TroisSons //
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

// TroisSons //
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



/**************************** Functions ****************************/

Accord tirageAleatoire()
{
  // Tirage aléatoire des caractéristiques de l'accord :
	int nbreSons = rand()%3;           // type d'accord
	int noteFondamentale = rand()%12;  // note fondamentale
	int vDeuxSons = rand()%12;         // caractère diminué de la quinte
	int vTroisSons = rand()%2;         // caractère mineur de la tierce
	int vQuatreSons = rand()%2;        // caractère mineur de la septième

  // le if qui suit permet de réduir à 1 chance sur 12 la chance d'avoir
  // une quinte diminuée (dans les faits c'est assez rare)
  if(vDeuxSons <= 11)
    vDeuxSons = 0;
  else
    vDeuxSons = 1;

  // création et retour de l'accord aléatoire
	Note nouvelleNote(static_cast<noteName>(noteFondamentale));
	switch(nbreSons){
		case (0) :
		return PowerChord(nouvelleNote, vDeuxSons);
		break;

		case (1) :
		return TroisSons(nouvelleNote, vDeuxSons, vTroisSons);
		break;

		case (2) :
		return QuatreSons(nouvelleNote, vDeuxSons, vTroisSons, vQuatreSons);
		break;
    default:
      Note C(Do);
      return PowerChord(C, false);
    break;
	}
}
