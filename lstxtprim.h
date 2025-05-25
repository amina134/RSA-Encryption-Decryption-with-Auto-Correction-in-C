#ifndef LSTXTPRIM_H_INCLUDED
#define LSTXTPRIM_H_INCLUDED
#include"eltphprim.h"
#include "lstsdd.h"
noeud noeudcreer(ph e);
void noeuddetruire(noeud n);
txt txtcreer (void);
void txtafficher (txt l);
void txtdetruire (txt l);
void txtinserer (txt l,ph e ,int pos);
int txtsupprimer (txt l ,int pos);
ph txtrecuperer (txt l ,int pos);
int txtsature(txt l);
int txtvide(txt l);
int txttaille (txt l);
txt txtcopier(txt l);
int txtcomparer (txt l ,txt lr);


#endif // LSTXTPRIM_H_INCLUDED
