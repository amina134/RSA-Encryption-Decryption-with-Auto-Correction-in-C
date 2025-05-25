#include "lstxtprim.h"
#include<string.h>
#include<malloc.h>
#include <stdio.h>
#include <stdlib.h>
noeud noeudcreer(ph e){
noeud n;
n=(noeud)malloc(sizeof(structnoeud));
if (!n)
    printf("plus d'espace");
else {
    phaffecter(&n->info,e);
    n->suivant=NULL;
}
return n;
}
void noeuddetruire(noeud n){
phdetruire(n->info);
free(n);
}
int txtvide(txt l){
return (l->lg==0);
}
int txtsature (txt l){
noeud temp;
int saturee =1;
temp=(noeud)malloc(sizeof(structnoeud));
if (temp!=NULL){
    saturee=0;
    free(temp);
}
return saturee;
}
int txttaille (txt l){
return (l->lg);
}
void txtinserer (txt l ,ph  e ,int pos){
int i;
noeud n,p,q;
if (txtsature(l)){
    printf("texte sature");
}
else{
    if (pos<1 || (pos<l->lg +1)){
        printf("position invalide");
    }
    else{
        n=noeudcreer(e);
        if (pos==1){
            n->suivant=l->tete;
            l->tete=n;
        }
        else{
            q=l->tete;
            for (i=1;i<pos;i++){
                p=q;
                q=q->suivant;
            }
            p->suivant=n;
            n->suivant=q;
        }
        (l->lg)++;
    }
}
}
int txtsupprimer (txt l , int pos){
int i;
int succee=1;
noeud p , q;
if (txtvide(l)){
printf("texte vide");
succee=0;
}
else {
    if ((pos<1)||(pos>l->lg)){
        printf("position valide");
        succee=0;
    }
    else {
        q=l->tete;
        if (pos==1)
            l->tete=l->tete->suivant;
        else{
            for (i=1;i<pos;i++){
                p=q;
                q=q->suivant;
            }
            p->suivant=q->suivant;
        }
    noeuddetruire(q);
    (l->lg)--;
    }
}
return succee;
}
ph txtrecuperer (txt l ,int pos){
ph elt=phcreer();
int i;
noeud p;
if (txtvide(l))
    printf("texte vide");
else{
    if ((pos<1)||(pos>l->lg))
        printf("position invalide");
    else{
        p=l->tete;
        for(i=1;i<pos;i++)
            p=p->suivant;
        phaffecter(&elt,p->info);
    }
}
return (elt);
}
txt txtcreer(void){
txt l;
l=(txt)malloc(sizeof(texte));
if(!l)
    printf("probleme de memoire");
else{
    l->lg=0;
    l->tete=NULL;
}
return (l);
}
void txtdetruire (txt l){
int i;
noeud p,q;
q=l->tete;
for(i=1;i<=l->lg;i++){
    p=q;
    q=q->suivant;
    noeuddetruire(p);
}
free(l);
}
void txtafficher(txt l){
int i=1;
noeud p;
p=l->tete;
for (i=1;i<=l->lg;i++){
    phafficher(p->info);
    p=p->suivant;
}
}
txt txtcopier (txt l){
txt lr=txtcreer();
int i;
ph elt;
for(i=1;i<=l->lg;i++){
    elt=phcreer();
    phcopier(&elt,txtrecuperer(l,i));
    txtinserer(lr,elt,i);
}
return lr;
}
int txtcomparer(txt l,txt lr){
int test=1;
int i=1;
if (txttaille(l)!=txttaille(lr))
    test=0;
while ((i<=txttaille(l)) && (test)) {
if
(phcomparer(txtrecuperer(l,i),txtrecuperer(lr,i))!=0)
test=0;
i++;
}
return test;
}

