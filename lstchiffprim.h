#ifndef LSTCHIFFPRIM_H_INCLUDED
#define LSTCHIFFPRIM_H_INCLUDED
#include"eltchiffprim.h"
#include "lstsdd.h"
noeud_2 noeudcreer_2 (car e);
void noeuddetruire_2 (noeud_2 n);
int txtchiffvide(txtchiff l);
int txtchiffsature (txtchiff l);
void txtchiffinserer(txtchiff l,car e ,int pos);
int txtchiffsupprimer (txtchiff l , int pos);
car txtchiffrecuperer (txtchiff l ,int pos);
txtchiff txtchiffcreer(void);
void txtchiffdetruire (txtchiff l);
void txtchiffafficher (txtchiff l);
txtchiff txtchiffcopier (txtchiff l);
int txtchiffcomparer (txtchiff l,txtchiff lr);
int txtchifftaille(txtchiff l);


#endif // LSTCHIFFPRIM_H_INCLUDED
