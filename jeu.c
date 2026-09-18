#include <stdio.h>

#include "puissance4.h"

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
     if (colonne >NB_COLONNES-1 || colonne <0){
      return 0;
     }else {
      return 1;
     }
 };
 int demanderColonne(void){
         int colonne;
         
        printf("entrez le numero de la colonne :");
        do{
        scanf("%d",&colonne);
        if (!colonneValide(colonne-1)){
            printf("numero invalide ,veuillez entrer un autre numero !!!\n");
        }
       }while (!colonneValide(colonne-1));
        return colonne-1;
 };
 int changerJoueur(int *joueur){
    if (*joueur==1){
        *joueur=2;
    }else{
        *joueur=1;
    }

 }
 void jouerTour(int *joueurCourant, int *nombreCoups){


        changerJoueur(joueurCourant);
        (*nombreCoups)++;
    }
 void jouerPrototype(void){
    int joueur=1;
    int colonne ;
    int nbcoups=0;
    // int res;
    int grille[NB_LIGNES][NB_COLONNES];

     initialiserGrille(grille);
     afficherGrille(grille);
    //  placerJeton(grille, 0, 1); 
    // placerJeton(grille, 0, 2); 
    // placerJeton(grille, 0, 1); 
    // afficherGrille(grille);
    // placerJeton(grille, 0, 2);
    // placerJeton(grille, 0, 1);
    // placerJeton(grille, 0, 2);

    // afficherGrille(grille);
    // res = placerJeton(grille, 0, 1);

    // if (res == 0) {
    //     printf("-> ECHEC : Le placement a ete REFUSE (placerJeton a renvoye 0).\n");
    // } else {
    //     printf("-> SUCCES : Le placement a ete accepte alors que la colonne est pleine !\n");
    // }
  while(nbcoups<6){
     printf("cest le role du joueur %d \n" ,joueur); 
       
        colonne=demanderColonne();
        if (colonneLibre(grille,colonne)==1){
            printf("la colonne %d est libre \n",colonne+1);
        }else if (colonneLibre(grille,colonne)==-1){
            printf("la colonne %d est pleine \n",colonne+1);
        }
        // for (int i=0;i<NB_LIGNES;i++){
        //     grille[i][colonne]=1;
        // }
        // afficherGrille(grille);
         jouerTour(&joueur, &nbcoups);
    
  }
  printf("le nombre de coups est %d \n",nbcoups);
 }

