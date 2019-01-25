#ifndef ACCORDS_H_
#define ACCORDS_H_

#include <iostream>
#include "Note.hpp"
using namespace std;

/* ======================================================================= */

class Accord
{
  protected :
    Note fondamentale;
    string nom;
  public :
    int nbNote;

    Accord();
    Accord(Note&);
    Accord(const Accord&);

    string get_nom();
    Note get_fondamentale();

    friend ostream& operator<<(ostream&, const Accord&);
    virtual bool operator==(const Accord&)const;
    virtual bool operator!=(const Accord&)const;
};

/* ======================================================================= */

class PowerChord : public Accord
{
  protected :
    Note quinte;
  public :
    PowerChord();
    PowerChord(Note&, const bool&);
    PowerChord(const PowerChord&);
    PowerChord(Note&, Note&);

    Note get_quinte();
    virtual bool operator==(const PowerChord&)const;
    virtual bool operator!=(const PowerChord&)const;
};

/* ======================================================================= */

class TroisSons : public PowerChord
{
  protected :
    Note tierce;
  public :
    TroisSons();
    TroisSons(Note&, const bool&, const bool&);
    TroisSons(const TroisSons&);
    TroisSons(Note&, Note&, Note&);

    Note get_tierce();
    virtual bool operator==(const TroisSons&)const;
    virtual bool operator!=(const TroisSons&)const;
};

/* ======================================================================= */

class QuatreSons : public TroisSons
{
  protected :
    Note septieme;
  public :
    QuatreSons();
    QuatreSons(Note&, const bool&, const bool&, const bool&);
    QuatreSons(const QuatreSons&);
    QuatreSons(Note&, Note&, Note&, Note&);

    Note get_septieme();
    virtual bool operator==(const QuatreSons&)const;
    virtual bool operator!=(const QuatreSons&)const;
};

Accord tirageAleatoire();
Accord* tableauDixAccords();

#endif
