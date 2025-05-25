#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include"lstxtprim.h"//pour le stockage des phrases du texte
#include"lstpileprim.h"//pour le stockage des piles des clés
#include "lstchiff.h"// pour le stockage des phrases chiffrées
#include <stdlib.h> // for system () for cleqring the screen
#define maxmots 400000

//*********declaration des fonctions**********************************************************************************************
//les fontions de la 1ere question(remplissage du tableau des nbrs premiers):
int lireFichierEtStockerMots(char mots[600][26],int n);

int nb_phrases (void);
int est_premier (int n,int i);
void generer_premier(int* prem , int m);
//les fonctions de la 2eme question (stockage des phrases):
void txtremplir (txt l,int n);
//les fonctions de la 3eme question (creation des piles):
int nb_alea (int*prem , int m);
void supp_nb (int*prem ,int *m ,int nbr);
int exposant (int m);
int euclide_etendu (int a ,int b ,int *u ,int *v);
int inverse_modulo (int a ,int b ,int x , int y);
void pilesremplir (pile p1, pile p2,int m, int*prem);
//les fonctions de la 4eme question (chiffrement desphrase):
int conv_codeascii(char c);
long long chiffrement (long long m ,long long n ,long long e);
car chiffrer(ph elt,int m,int e);
void texte_chiffre (txtchiff lr, txt l,pile );
//les fonctions de la 5eme question (dechiffrement des phrases):
void texte_dechiffre (txtchiff lr ,pile);



int main(int argc,char*argv[])
{
    int n,m,max;
//travail++++++++++++++++++++++++++++++++++++++///dictionqire/////////////////////////*************************
      static char mots[maxmots][30];
int stop=0,nbmots=0,i,j;
//utiliser static pour reserver de lespace RAM pour l execution du prog //
char line[30];
char t[50];



    FILE*f=fopen("dictionnaire.txt","r");

if (f==NULL){
    printf("impossible d'ouvrir le fichier ");
}
else{
   //  printf("succes \n");
    while(fgets(line,sizeof line,f)){
       // printf("line %s \n",line);
        char*token=strtok(line," \t \n ");
        while((token !=NULL)&& (!stop)){
            if(nbmots<maxmots){
                strncpy(mots[nbmots],token,30);
                nbmots++;
            }
            else{
               printf(" espace insufisant") ;
               stop=1;
            }
       // printf("nbmots=%i",nbmots);
       //printf("token:%s \n",token);
        token=strtok(NULL,"  \t  \n");
        }

    }
}
fclose(f);


////////////////////////////////////////////////////////////////////////////////////////////////////////////
    setlocale(LC_CTYPE,"");
    printf("************************************* ALGORITHME RSA *****************************************************\n");
    //controle de saisie sur le nb des phrases:
    max=nb_phrases();
    do{
    printf("\nVeuillez saisir le nombre de phrases que vous voulez coder (ce nombre ne doit pas depasser %i)",max);
    scanf("%i",&n);
    }while (max<n);

//travail++++++//////////////////////////////////////////////////////////////autocorrection/////////////////////////////////////////

  //// /********/ouverture de fichier texte pour l autocorrection///////
      char words[1000][26];

    // Appeler la fonction pour lire le fichier texte et stocker les mots
    int nbwords = lireFichierEtStockerMots(words,n);

    // Afficher les mots stockés dans le tableau
 /*  printf("Mots lus depuis le fichier :\n");
    for (int i = 0; i < nbwords; i++) {
        printf("%s\n", words[i]);
    }*/

    int reponse;
    printf("do u want us  to suggest for you an autocorrection for  your phrases before encrypting them?(0 if no)(1 if yes)\n" );
    scanf("%i",&reponse);
    if (reponse==1){
        for (int i = 0; i < nbwords; i++){
         printf("word =%s\n", words[i]);
         int rep=autocorrectParagraph(mots, words[i], nbmots);
         if(rep==1){
             printf("Corrected word: %s\n", words[i]);
         }
         else if(rep==2){
            clearScreen();
            break;

         }

    }

    }


    ///////////////////////////////////////////////














    //////////
    m=2*n;
    int *prem =malloc(m*sizeof(int));//la taille du tableau est 2*n pour que chaque pharse ait ses propres clés avec des nbrs qui ne
    //se repetent pas pour une meilleure securite du systeme RSA
    printf ("le tableau des nombres premiers generés:\n");
    generer_premier(prem,m);
    srand(time(NULL));
    printf("LE TEXTE:\n");
    txt l=txtcreer();
    txtremplir(l,n);
    txtafficher(l);
    printf("\n");
    printf("\n");
    pile ppub=pilecreer();
    pile pprv=pilecreer();
    pilesremplir(ppub,pprv,n,prem);
    txtchiff lr;
    lr=txtchiffcreer();
    texte_chiffre(lr,l,pprv);
    printf("\nLE TEXTE CHIFFRE:");
    txtchiffafficher(lr);
    printf ("\nLE TEXTE DECHIFFRE:\n");
    texte_dechiffre(lr,ppub);
    printf("\n");
    txtdetruire(l);
    free(prem);
    piledetruire(ppub);
    piledetruire(pprv);
    //txtchiffdetruire(lr);
 return 0;
}
//les fontions de la 1ere question(remplissage du tableau des nbrs premiers):
    int nb_phrases(void){
    ph elt;
      FILE*file=fopen("texte.txt","r ");
       if (file==NULL)
        printf("echec");
    else
        printf("succes");
    char c= fgetc(file);
    int i=0;
    while ((c!=EOF)){
        if (c!='.'){
            c=fgetc(file);
       }
        else  {// chaque fois on trouve un point i incremente et ça marque le nbr total des phrases dans le texte.
            i++;
            c=fgetc(file);
        }
    }
    return i;}
     int est_premier (int n,int i){
    if (n<2)
        return 0;
    else{
        if (n%i==0 && i!=n)
            return 0;
        else if (n%i==0 && i==n)
            return 1;
        else
            return (est_premier(n,i+1));
           }
    }

   void generer_premier(int* prem, int m){
       int i,max=200 , min =17; //le min 17 car 17*19 =323 pour que n contiendra tous les codes ascii
        for (i=0;i<m;i++){
                int insertion=0;
                while (insertion==0){
                   int nb = rand()%(RAND_MAX - min +1)+ min;//genrer un nbr entre 17 et RAND_MAX
                  // int nb = rand()%(max - min +1)+ min;// si on veut limiter les nbrs premiers mais puls qu'on a des phrases à crypter
                  //on a besoin de plus grand nbrs
                   int j=0, trouve=0;
                    if (est_premier(nb,2)==1){//verifier s'il est premier
                        while (j<i && !trouve){
                                if(prem[j]==nb)
                                    trouve=1;//verifier si le nb a ete deja choisi avant
                                else
                                 j++;
                            }
                    if (trouve==0){//si oui on regenre un autre nbr sinon on l'insere dans le tableau
                   prem[i]=nb;
                   insertion =1;
                    }
                    }
                }
                printf("prem[%i]=%i\n",i,prem[i]);
        }
   }
//les fonctions de la 2eme question (stockage des phrases):
 void txtremplir (txt l , int n){
    ph elt;
      FILE*file=fopen("texte.txt","r ");
    char c= fgetc(file);
    elt=phcreer();
    int i=0;
    while ((c!=EOF) && (l->lg <n) && !(txtsature(l))){
        if (c!='.'){
           elt->chaine[i]=c; //on rempli la chaine caractere par caractere
            i++;
            c=fgetc(file);
       }
        else  {
            elt->chaine[i]='\0'; //si on trouve un point cad la fin de la phrase
            txtinserer(l,elt,txttaille(l)+1);
            elt=phcreer();
            i=0;
            c=fgetc(file);
        }
    }
    if (txtsature(l))
        printf("texte sature");
    fclose(file);
    }
//les fonctions de la 3eme question (creation des piles):
    int nb_alea (int*prem,int m){ //generer un nbr aleatoirement du tableau prem
        int nb=rand()%m;
        return(prem[nb]);
    }
    void supp_nb (int*prem ,int *m ,int nbr){//supprimer un nbr donné s'il existe deja dans le tableau
        int i=0,j;
    while ((i<(*m)) &&(prem[i]!=nbr)){
        i++;
    }
    if (prem[i]==nbr){
        for (j=i;j<(*m);j++)
            prem[j]=prem[j+1];
    }
    (*m)--;
     }
    int exposant (int n){
    int e, x=1,y=0;
    e=rand()%(((n-1)+1)+1); //generer un nbr aleatoire 1<e<phi
    while (euclide_etendu(e,n,&x,&y)!=1)// if aut que le pgcd (e,phi)=1;
         e=rand()%(((n-1)+1)+1);
    return e;
    }
    int euclide_etendu (int a ,int b ,int *u ,int *v){
     if (b == 0) {
        *u = 1;
        *v = 0;
        return a;
    }
    int u1, v1;
    int c = euclide_etendu(b, a % b, &u1, &v1);
    *u = v1;
    *v = u1 - (a / b) * v1;
    return c;
}

    int inverse_modulo (int a ,int b ,int x , int y){
    euclide_etendu(a,b,&x,&y);
    if ((a*x)+(b*y)==1){ //d c'est l'inverse modulo de e mod phi et d'apres la regle d'ecludi si ax+by=1 alors x est l'inverse
            //modulo de a modulo phi
    //printf("%i inverse de %i modulo %i",x,a,b);
     if (x<0){
        while (x<0){
            x=x+b;
        }
        if (x>b)
            x=x-b;
            }

        return x;
        }
    else return 0;
    }
    void pilesremplir (pile p1, pile p2,int m, int*prem){
        int i,n1,n2,phi;
        pp e1, e2;
        int taille=2*m;
       for (i=1;i<=m;i++){
        phi=1;
        e1=clecreer();
        e2=clecreer();
        n1=nb_alea(prem,taille);//choix du 1er nbr
        supp_nb(prem,&taille,n1);//puis on le supprime du tableau
        n2=nb_alea(prem,taille);
        supp_nb(prem,&taille,n2);
        phi=(n1-1)*(n2-1);
        e1->n=n1*n2 ;
        e1->e=exposant(phi);
        empiler(p1,e1);//ajout de la cle a la pile
        e2->n=e1->n; //on rempli simulatanement la 2eme pile
        e2->e=inverse_modulo(e1->e,phi,1,0);
        empiler(p2,e2);
    }
    printf("PILE PUBLIQUE\n");
    pilepubafficher(p1);
    printf("\n");
    printf("PILE PRIVEE:\n");
    pileprvafficher(p2);
    }
//les fonctions de la 4eme question (chiffrement desphrase):
    int conv_codeascii (char c){//pour les caracteres speciaux par exp : le code ascii du 'é'=-23 on peut pas le code car c'est <0
        //et il faut qu'on retrouve son correct code ascii pour pouvoir l'afficher aprés
        int nv_ascii;
        for (int i=-63 ;i<=0;i++){
            if ((int)c==i){
                nv_ascii=256+i;
        }
        }
    return (nv_ascii);
    }
    long long  chiffrement (long long  m,long long  n ,long long e){
    long long puiss=1;//on a choisi long long comme type car les nombres peuvent etre trés grands
    m=m%n;
    while (e!=0){
        if (e%2!=0){
            puiss=(puiss*m)%n;
        }
        m=(m*m)%n;
        e=e/2;
    }
    return(puiss);
    }
    car chiffrer(ph elt , int m ,int e){
    car elem=codecreer();
        long long codeascii ,res;
    for (int i=0;i<strlen(elt->chaine);i++) {
        codeascii=(int)(elt->chaine[i]);//convertir chaque caractere de la chaine en son code ascii
        if (codeascii<0)
            codeascii=conv_codeascii(elt->chaine[i]);
        res=chiffrement(codeascii,m,e);//deduire le code chiffre du caractere
        elem->taille++;
        elem->tab[i]=res;//on le stocke dans un tableau qui va contenir tous les codes de chaque caractere de la phrase
    }
    return elem;
    }
    void texte_chiffre (txtchiff lr,txt l,pile ppub){
    for (int i=1;i<=l->lg;i++){
        printf("here");
        ph elt;
        car elem;
        pp cle_pub=depiler(ppub);//recuperer une cle pub pour chaque phrase
        elt=phcreer();
        elt=txtrecuperer(l,i);
        elem=chiffrer(elt,cle_pub->n,cle_pub->e);
        txtchiffinserer(lr,elem,i);
    }
    printf("\n");
    }
//les fonctions de la 5eme question (dechiffrement des phrases):
    void texte_dechiffre (txtchiff lr ,pile pprv){
        long long res;
        for(int i=1;i<=lr->lg;i++){
            car elt;
            elt=codecreer();
            elt=txtrecuperer(lr,i);
            pp cle_prv=depiler(pprv);//recuperer une cle prv pour chaque phrase
            for (int j=0;j<elt->taille;j++){
            res=chiffrement(elt->tab[j],cle_prv->n,cle_prv->e);//on retrouve chaque phrase au texte chiffré
            printf("%c",res);
            }
            printf(".");
        }
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


//***************  ////travail de plus////////////////***************************************************
// Fonction pour lire un fichier texte et stocker chaque mot dans un tableau

int lireFichierEtStockerMots(char mots[600][26], int n) {
    FILE* fichier = fopen("texte.txt", "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s.\n", "texte.txt");
        return -1; // Échec de l'ouverture du fichier
    }

    int nbMots = 0;
    int linesRead =0 ; // Counter to track the number of lines read
    char ligne[1000];

    // Lire le fichier ligne par ligne jusqu'à ce que le nombre requis de lignes soit lu
    while (linesRead <= n && fgets(ligne, sizeof(ligne), fichier)) {
        char *token = strtok(ligne, " \t\n"); // Séparer la ligne en mots en utilisant des espaces et des tabulations comme délimiteurs
        while (token != NULL) {
            // Copier le mot dans le tableau de mots
            strncpy(mots[nbMots], token, 26);
            mots[nbMots][25] = '\0'; // Assurer la terminaison de la chaîne
            nbMots++;

            // Vérifier si le nombre maximum de mots a été atteint
            if (nbMots >= 600) {
                printf("Le nombre maximum de mots (60) a été atteint.\n");
                fclose(fichier);
                return nbMots;
            }

            // Lire le prochain mot de la ligne
            token = strtok(NULL, " \t\n");
        }

        // Increment linesRead
        linesRead++;
    }

    fclose(fichier);
    return nbMots;
}













////////////////fontion qui trouve le minimum de trois entiers///////////////////
int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

/////////////////fonction qui verifie si le mot se trouve dans le dictionnaire ou non/////////////////////////////////
int isInDictionary(char *word, char dictionary[maxmots][30], int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found in the dictionary
        }
    }
    return 0; // Word not found in the dictionary
}

////////////////fonction qui calcule la levenshteindistance entre 2 chaines////////////////////////////////////////////
 int levenshteinDistance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create a 2D array to store the distances
    int dp[len1 + 1][len2 + 1];

    // Initialize the first row and column of the array
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }

    // Fill in the rest of the array
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = minimum(dp[i - 1][j] + 1,         // deletion
                               dp[i][j - 1] + 1,         // insertion
                               dp[i - 1][j - 1] + cost); // substitution
        }
    }

    // Return the distance between the two strings
    return dp[len1][len2];
}




// Fonction qui trouve le mot le plus proche
char *findClosestMatch(char *word, char dictionary[maxmots][26], int numWords) {
    int minDistance = 26; // Initialiser la distance minimale
    char *closestMatch = NULL; // Pointeur vers le mot le plus proche

    // Parcourir le dictionnaire pour trouver le mot le plus proche
    for (int i = 0; i < numWords; i++) {
        int distance = levenshteinDistance(word, dictionary[i]); // Calculer la distance de Levenshtein
        if (distance < minDistance) {
            minDistance = distance;
            closestMatch = dictionary[i];
        }
    }

    return closestMatch;
}





//fonction d autocorrection
int autocorrectParagraph(char mots[maxmots][30], char *word, int nbmots) {
    int rep = 0;
    if (!isInDictionary(word, mots, nbmots)) {
        char *closestMatch = findClosestMatch(word, mots, nbmots);
        if (closestMatch != NULL) {
            printf("Are you sure you want to correct it? (1 for yes, 0 for no,2 for stop): ");
            scanf("%i", &rep);
            if (rep == 1) {
                strcpy(word, closestMatch);
            }
        }
    }
return rep;
}

void clearScreen() {
    #ifdef _WIN32 // Check if running on Windows
        system("cls");
    #else
        system("clear");
    #endif
}


