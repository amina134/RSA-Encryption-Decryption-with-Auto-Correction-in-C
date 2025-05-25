#ifndef LSTPILE_H_INCLUDED
#define LSTPILE_H_INCLUDED
#include "eltpileprim.h"
#define LongMax 100
typedef struct structnoeud_1 {
pp info;
struct structnoeud_1 * suivant;
} structnoeud_1, * noeud_1;

typedef struct {
noeud_1 tete;
} pile_cle,*pile;


#endif // LSTPILE_H_INCLUDED
