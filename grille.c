#include <stdio.h>
#include "puissance4.h"


void initialiserGrille(Partie *partie){
    for (int i=0;i<NB_LIGNES;i++){
        for (int j=0;j<NB_COLONNES;j++){
            (*partie).grille[i][j]=0;
        }
    }
}
void afficherGrille(Partie *partie){
    for (int i=0;i<NB_LIGNES;i++){
        printf("|");
        for (int j=0;j<NB_COLONNES;j++){
            if ((*partie).grille[i][j]==0){
                printf(" . ");
            }else if ((*partie).grille[i][j]==1){
                printf(" X ");
            }else if ((*partie).grille[i][j]==2){
                printf(" O ");
            }
        }
        printf("|\n");
    }
    printf("+---------------------+\n");
    printf("  1  2  3  4  5  6  7 \n");
}
int colonneLibre(Partie *partie, int colonne){
    
        if ((*partie).grille[0][colonne]==0){
             return 1;
            }else {
                return -1;
            }
    }
    int placerJeton(Partie *partie, int colonne, int joueur){
        for (int i=5;i>=0;i--){
            if ((*partie).grille[i][colonne]==0){
                (*partie).grille[i][colonne]=joueur;
              
                return 1;
                  
            }
        }
        return 0;
    }
  

    int alignementHorizental(Partie *partie){
    for (int i=0;i<NB_COLONNES;i++){
        for (int j=0;j<NB_COLONNES-3;j++){
            if ((*partie).grille[i][j]==(*partie).joueurCourant &&  (*partie).grille[i][j+1]==(*partie).joueurCourant &&
            (*partie).grille[i][j+2]==(*partie).joueurCourant && (*partie).grille[i][j+3]==(*partie).joueurCourant ){
                return 1;
            }
        }
    }
    return 0;
}
int alignementVertical(Partie *partie){
    for (int i=0;i<NB_LIGNES-3;i++){
        for (int j=0;j<NB_COLONNES;j++){
            if ((*partie).grille[i][j] == (*partie).joueurCourant &&
             (*partie).grille[i + 1][j] == (*partie).joueurCourant &&
                (*partie).grille[i + 2][j] == (*partie).joueurCourant &&
                (*partie).grille[i + 3][j] == (*partie).joueurCourant)
            {
                return 1;
            }
        }
    }
    return 0;
}

int alignementDiagonal(Partie * partie){

    // diagonale vers le bas et la droite 

    for (int i=0;i<NB_LIGNES-3;i++){
        for (int j=0;j<NB_COLONNES-3;j++){
            if ((*partie).grille[i][j]== (*partie).joueurCourant && 
               (*partie).grille[i+1][j+1]==(*partie).joueurCourant &&
                (*partie).grille[i+2][j+2]==(*partie).joueurCourant &&
                (*partie).grille[i+3][j+3]){
                      return 1;
               }
        }
    }

    // diagonale vers le bas et la gauche 
     for (int i=0;i<NB_LIGNES-3;i++){
        for (int j=0;j<NB_COLONNES-3;j++){
            if ((*partie).grille[i][j]== (*partie).joueurCourant && 
               (*partie).grille[i+1][j-1]==(*partie).joueurCourant &&
                (*partie).grille[i+2][j-2]==(*partie).joueurCourant &&
                (*partie).grille[i+3][j-3]){
                      return 1;
               }
        }
    }
  return 0;
}

int joueurAGagne(Partie* partie,int joueur){
    if (alignementDiagonal((*partie).grille,joueur) ||
       alignementHorizental((*partie).grille,joueur)|| 
       alignementVertical((*partie).grille,joueur)){

        return 1;

    }else {
        return 0;
    }

}

int grillePleine(int grille[][NB_COLONNES]){
      
        for (int j=0;j<NB_COLONNES;j++){
            if (grille[0][j]==0){
                return 0;
            }
        
    }
    return 1;
};

