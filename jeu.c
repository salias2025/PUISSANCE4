#include <stdio.h>

#include "puissance.h"

 void afficherRegles(void){
      printf("\n==================================================\n");
    printf("         BIENVENUE AU JEU DU PUISSANCE 4          \n");
    printf("==================================================\n\n");

    printf("LE MATERIEL :\n");
    printf(" - Une grille de 7 colonnes et 6 lignes.\n");
    printf(" - Des jetons Rouges (X) et Jaunes (O).\n\n");

    printf("DEROULEMENT DE LA PARTIE :\n");
    printf(" 1. Les joueurs jouent a tour de role.\n");
    printf(" 2. A votre tour, choisissez une colonne (1 a 7).\n");
    printf(" 3. Votre jeton tombe automatiquement au bas de la colonne.\n\n");

    printf("COMMENT GAGNER ?\n");
    printf(" Vous devez etre le premier a aligner 4 jetons de votre couleur :\n");
    printf("  - Horizontalement (sur une ligne)\n");
    printf("  - Verticalement (dans une colonne)\n");
    printf("  - En diagonale\n\n");

    printf("FIN DE PARTIE :\n");
    printf(" Le jeu s'arrete des qu'un joueur a aligne 4 jetons.\n");
    printf(" Si la grille est pleine sans alignement, c'est un match nul.\n");
    printf("==================================================\n\n");
 };
 int colonneValide(int colonne){
     if (colonne >7 || colonne <1){
      return 0;
     }else {
      return 1;
     }
 };
 int demanderColonne(void){
         int colonne;
        printf("entrez le numero de la colonne :");
        scanf("%d",&colonne);
        return colonne;
 };
 int changerJoueur(int *joueur){
    if (*joueur==1){
        *joueur=2;
    }else{
        *joueur=1;
    }

 };
 void jouerPrototype(void){
    int joueur=1;
    int colonne ;
      printf("cest le role du joueur %d \n" ,joueur);
  for (int i=0;i<6;i++){
     
    do{   
      
        colonne=demanderColonne();
        
        if (!colonneValide(colonne)){
            printf("numero invalide ,veuillez entrer un autre numero !!!\n");
        }
    }while (!colonneValide(colonne));
    changerJoueur(&joueur);
    printf("cest le role du joueur %d \n" ,joueur);
  }
 };