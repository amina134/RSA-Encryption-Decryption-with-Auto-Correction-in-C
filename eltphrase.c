#include<string.h>
#include"eltphprim.h"
#include<malloc.h>
#include <stdio.h>
#include <stdlib.h>
ph phcreer(void){
ph l;
l=(ph)malloc(sizeof(phrase));
strcpy(l->chaine,"\0");
return l;
}
void phdetruire (ph elt){
free (elt);
}
void phafficher(ph elt){
printf("%s.",elt->chaine);
}
void phaffecter (ph*e1 , ph e2){
//memcpy(*e1,e2,sizeof(phrase));
*e1=e2;
}
void phcopier(ph*e1,ph e2){
strcpy((*e1)->chaine,e2->chaine);
}
int phcomparer(ph e1 , ph e2){
return strcmp(e1->chaine,e2->chaine);
}
