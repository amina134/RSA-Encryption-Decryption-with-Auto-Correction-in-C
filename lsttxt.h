#ifndef LSTTXT_H_INCLUDED
#define LSTTXT_H_INCLUDED
#include "eltphprim.h"
typedef struct structnoeud{
ph info;
struct structnoeud*suivant;
}structnoeud,*noeud;
typedef struct{
noeud tete;
int lg;
}texte,*txt;


#endif // LSTTXT_H_INCLUDED
