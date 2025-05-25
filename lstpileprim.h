#ifndef LSTPILEPRIM_H_INCLUDED
#define LSTPILEPRIM_H_INCLUDED
#include "eltpileprim.h"
#include "lstsdd.h"
noeud_1 noeudcreer_1(pp e);
void noeuddetruire_1(noeud_1 n);
pile pilecreer(void);
void piledetruire(pile);
int pilevide(pile);
int pilesaturee(pile);
int piletaille(pile);
pp sommet(pile);
int empiler(pile, pp);
pp depiler(pile);
void pileprvafficher(pile);
void pilepubafficher(pile);
pile pilecopier(pile);
int pilecomparer(pile, pile);


#endif // LSTPILEPRIM_H_INCLUDED
