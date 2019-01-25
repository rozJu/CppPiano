/*****************************************************************************/
//  Dans ce fichier est définie la classe Accord ainsi que les classes qui en
//  héritent : PowerChord (c'est un accord à deux notes), TroisSons (un accord
//  à trois notes) et QuatreSons (inutile de préciser que celui-ci comporte
//  quatre notes).
/*****************************************************************************/
#ifndef ACCORDS_H_
#define ACCORDS_H_

#include <iostream>
#include "Note.hpp"
using namespace std;

/* ======================================================================= */

class Accord
{
  protected :
    Note fondamentale;  // Première note de l'accord (elle lui donne son nom)
    string nom;         // nom de l'accord
  public :
    int nbNote;
    // Constructeurs
    Accord();
    Accord(Note&);
    Accord(const Accord&);
    // Getters
    string get_nom();
    Note get_fondamentale();
    // Surcharges d'opérateurs : si certaines sont virtuelles c'est car
    // dans le main nous utilisons un tableau de type Accord contenant
    // les trois différents types d'accord. Lors de l'appel de ces fonctions
    // il faut que les méthode de la bone clkasse soient appelées.
    friend ostream& operator<<(ostream&, const Accord&);
    virtual bool operator==(const Accord&)const;
    virtual bool operator!=(const Accord&)const;
};

/* ======================================================================= */
// Un PowerChord est un accord à deux sons. Il se compose exclusivent de deux
// notes : la fondamentale (présente dans tous les types d'accord) et la quinte
// La quinte peut être de deux types : soit juste, soit diminuée. Cela se
// détermine en fonction de l'interval séparant la fondamentale et la quinte.

class PowerChord : public Accord
{
  protected :
    Note quinte;
  public :
    // Constructeurs
    PowerChord();
    PowerChord(Note&, const bool&); // paramètre 1 : note fondamentale
                                    // paramètre 2 : caractère diminué ou non de la quinte
    PowerChord(const PowerChord&);  // constructeur par copie
    PowerChord(Note&, Note&);       // Constructeur qui demande toutes les notes de l'accord

    // Getteur
    Note get_quinte();
    // Surcharges d'opérateurs
    virtual bool operator==(const PowerChord&)const;
    virtual bool operator!=(const PowerChord&)const;
};

/* ======================================================================= */
//  Un accord à trois est composé de trois notes : la fondamentale, la quinte
//  et la tièrce. Cette tièrce est comprise entre la fondamentale et la quinte
//  et peut, elle aussi être de deux types : mineure ou majeure. Ce qui est à
// nouveau déterminé par l'intervale avec la fondamentale.

class TroisSons : public PowerChord
{
  protected :
    Note tierce;
  public :
    TroisSons();
    TroisSons(Note&, const bool&, const bool&); // paramètre 1 : note fondamentale
                                                // paramètre 2 : caractère mineure ou non de la quinte
                                                // paramètre 3 : caractère diminué ou non de la quinte
    TroisSons(const TroisSons&);
    TroisSons(Note&, Note&, Note&);
    // Getteur
    Note get_tierce();
    // Surcharges d'opérateur
    virtual bool operator==(const TroisSons&)const;
    virtual bool operator!=(const TroisSons&)const;
};

/* ======================================================================= */
//  Un accord à quatre sons contient 4 notes : une fondamentale, une tierce,
//  une quinte et une septieme. La sptième peut être soit mineure soit majeure

class QuatreSons : public TroisSons
{
  protected :
    Note septieme;
  public :
    // Constructeurs
    QuatreSons();
    QuatreSons(Note&, const bool&, const bool&, const bool&); // paramètre 1 : note fondamentale
                                                              // paramètre 2 : caractère mineure ou non de la quinte
                                                              // paramètre 3 : caractère diminué ou non de la quinte
                                                              // paramètre 4 : caractère diminué ou non de la septième
    QuatreSons(const QuatreSons&);
    QuatreSons(Note&, Note&, Note&, Note&);
    // Getteurs
    Note get_septieme();
    // Surcharges d'opérateur
    virtual bool operator==(const QuatreSons&)const;
    virtual bool operator!=(const QuatreSons&)const;
};

/* ======================================================================= */

Accord tirageAleatoire();

#endif
