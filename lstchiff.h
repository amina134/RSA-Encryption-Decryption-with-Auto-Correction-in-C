#ifndef LSTCHIFF_H_INCLUDED
#define LSTCHIFF_H_INCLUDED
#include"eltchiffprim.h"
typedef struct structnoeud_2{
car info;
struct structnoeud_2*suivant;
}structnoeud_2,*noeud_2;
typedef struct{
noeud_2 tete;
int lg;
}textechiff,*txtchiff;


#endif // LSTCHIFF_H_INCLUDED
