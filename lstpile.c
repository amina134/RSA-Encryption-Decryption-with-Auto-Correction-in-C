#include <stdlib.h>
#include <stdio.h>
#include "lstpileprim.h"
noeud_1 noeudcreer_1 (pp e) {
noeud n;
n = (noeud_1) malloc(sizeof(structnoeud_1));
if(!n)
printf ("\n Plus d'espace");
else {
cleaffecter(&n->info, e);
n->suivant = NULL;
}
return n;
}
void noeuddetruire_1(noeud_1 n){
cledetruire(n->info);
free(n);
}
pile pilecreer(void) {
pile p;
p = (pile) malloc(sizeof(pile_cle));
if(!p) {
printf(" \nProblème de mémoire") ;
}
else p->tete=NULL;
return(p);
}
void piledetruire(pile p){
noeud_1 n=p->tete;
while(n!=NULL){
    p->tete=n->suivant;
    noeuddetruire(n);
    n=p->tete;
    }
free(p);
}
void pilepubafficher(pile p) {
noeud_1 n;
n= p->tete;
while (n != NULL)
{clepubafficher(n->info);
n = n->suivant; }
}
void pileprvafficher(pile p) {
noeud_1 n;
n= p->tete;
while (n != NULL)
{clepriveafficher(n->info);
n = n->suivant; }
}
int empiler (pile p, pp e) {
int succes=1;
noeud_1 n;
if (pilesaturee(p)){
printf ("\n Pile saturée");
succes=0;}
else
{
n=noeudcreer_1(e);
n->suivant = p->tete;
p->tete = n;
}
return(succes);
}
pp depiler (pile p ) {
pp elt;
noeud_1 n;
if (pilevide(p)) {
printf ("\n Pile vide");
elt = clecreer();
}
else {
n = p->tete;
clecopier(&elt, n ->info);
p->tete= n->suivant;
noeuddetruire_1(n);
}
return (elt);
}

int pilesaturee(pile p) {
noeud_1 temp;
int saturee = 1;
temp = (noeud_1) malloc ( sizeof (structnoeud_1) );
if(temp!= NULL) {
saturee = 0;
free(temp);
}
return saturee;
}
int piletaille(pile p) {
int taille = 0;
noeud_1 n;
n = p->tete;
while (n != NULL)
{ taille++;
n = n->suivant ;}
return(taille);
}
int pilevide(pile p){
return p->tete==NULL;}
