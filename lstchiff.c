#include "lstchiffprim.h"
#include<string.h>
#include<malloc.h>
#include <stdio.h>
#include <stdlib.h>
noeud_2 noeudcreer_2 (car e){
noeud_2 n;
n=(noeud_2)malloc(sizeof(structnoeud_2));
if (!n)
    printf("plus d'espace");
else {
    codeaffecter(&n->info,e);
    n->suivant=NULL;
}
return n;
}
void noeuddetruire_2 (noeud_2 n){
codedetruire(n->info);
free(n);
}
int txtchiffvide(txtchiff l){
return (l->lg==0);
}
int txtchiffsature (txtchiff l){
noeud_2 temp;
int saturee =1;
temp=(noeud_2)malloc(sizeof(structnoeud_2));
if (temp!=NULL){
    saturee=0;
    free(temp);
}
return saturee;
}
int txtchifftaille (txtchiff l){
return (l->lg);
}
void txtchiffinserer (txtchiff l,car e ,int pos){
int i;
noeud_2 n,p,q;
if (txtchiffsature(l)){
    printf("texte chiffre sature");
}
else{
    if (pos<1 || (pos<l->lg +1)){
        printf("position invalide");
    }
    else{
        n=noeudcreer_2(e);
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
int txtchiffresupprimer (txtchiff l , int pos){
int i;
int succee=1;
noeud_2 p , q;
if (txtchiffvide(l)){
printf("texte chiffre vide");
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
    noeuddetruire_2(q);
    (l->lg)--;
    }
}
return succee;
}
car txtchiffrecuperer(txtchiff l ,int pos){
car elt=codecreer();
int i;
noeud_2 p;
if (txtchiffvide(l))
    printf("texte chiffre vide");
else{
    if ((pos<1)||(pos>l->lg))
        printf("position invalide");
    else{
        p=l->tete;
        for(i=1;i<pos;i++)
            p=p->suivant;
        codeaffecter(&elt,p->info);
    }
}
return (elt);
}
txtchiff txtchiffcreer(void){
txtchiff l;
l=(txtchiff)malloc(sizeof(textechiff));
if(!l)
    printf("probleme de memoire");
else{
    l->lg=0;
    l->tete=NULL;
}
return (l);
}
void txtchiffdetruire (txtchiff l){
int i;
noeud_2 p,q;
q=l->tete;
for(i=1;i<=l->lg;i++){
    p=q;
    q=q->suivant;
    noeuddetruire_2(p);
}
free(l);
}
void txtchiffafficher(txtchiff l){
int i=1;
noeud_2 p;
p=l->tete;
for (i=1;i<=l->lg;i++){
    printf("\n%i) ",i);
    codeafficher(p->info);
    p=p->suivant;
    printf("\n");
}
}
txtchiff txtchiffcopier(txtchiff l){
txtchiff lr=txtchiffcreer();
int i;
car elt;
for(i=1;i<=l->lg;i++){
    elt=codecreer();
    codecopier(&elt,txtchiffrecuperer(l,i));
    txtchiffinserer(lr,elt,i);
}
return lr;
}
