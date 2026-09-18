#include <stdio.h>
#include "puissance4.h"


void initialiserGrille(int grille[][NB_COLONNES]){
    for (int i=0;i<NB_LIGNES;i++){
        for (int j=0;j<NB_COLONNES;j++){
            grille[i][j]=0;
        }
    }
}
void afficherGrille(int grille[][NB_COLONNES]){
    for (int i=0;i<NB_LIGNES;i++){
        printf("|");
        for (int j=0;j<NB_COLONNES;j++){
            if (grille[i][j]==0){
                printf(" . ");
            }else if (grille[i][j]==1){
                printf(" X ");
            }else if (grille[i][j]==2){
                printf(" O ");
            }
        }
        printf("|\n");
    }
    printf("+---------------------+\n");
    printf("  1  2  3  4  5  6  7 \n");
}
int colonneLibre(int grille[][NB_COLONNES], int colonne){
    
        if (grille[0][colonne]==0){
             return 1;
            }else {
                return -1;
            }
    }
    int placerJeton(int grille[][NB_COLONNES], int colonne, int joueur){
        for (int i=5;i>=0;i--){
            if (grille[i][colonne]==0){
                grille[i][colonne]=joueur;
              
                return 1;
                  
            }
        }
        return 0;
    }
  
