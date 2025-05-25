#include<string.h>
#include<malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include"eltpileprim.h"
pp clecreer (void){
pp l;
l=(pp)malloc(sizeof(cle));
l->e=0;
l->n=0;
return l;
}
void cledetruire (pp elt){
free (elt);
}
void clepubafficher(pp elt){
printf("(n=%i,e=%i)\n",elt->n ,elt->e);
}
void clepriveafficher(pp elt){
printf("(n=%i,d=%i)\n",elt->n ,elt->e);
}

void cleaffecter (pp *e1 , pp e2){
*e1=e2;
}
void clecopier(pp*e1,pp e2){
memcpy(*e1,e2,sizeof(cle));
}
int clecomparer(pp e1 , pp e2){
return (e1->n == e2->n);
}

