#include"eltchiffprim.h"
#include<malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
car codecreer(void){
car l;
l=(car)malloc(sizeof(caractere));
(*l).tab=(long long *)malloc(1000*sizeof(long long));
for (int i=0;i<1000;i++)
    (*l).tab[i]=0;
l->taille=0;
return l;
}
void codedetruire (car elt){
free (elt);
}
void codeafficher(car elt){
    for (int i=0;i<elt->taille;i++)
printf("%llu ",(*elt).tab[i]);
}
void codeaffecter(car *e1,car e2){
    *e1=e2;
}
void codecopier (car *e1,car e2){
for (int i=0;i<(*e1)->taille;i++)
    (*e1)->tab[i]=e2->tab[i];
}
void codeinserer(car *e1,long long entier ,int pos){
    if (pos>=0 && pos<(*e1)->taille)
    (*e1)->tab[pos]=entier;
}
