#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#define N 8
#define M 16

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/

/*Structure qui represente la tablette du jeu*/
typedef struct tablette {
    int tchoco[N][M];
} Tablette;

/*Fonction qui permet d'initialiser la tablette*/
Tablette creer_tablette(void){
    int i,j;
    Tablette t;
    for (i = 0 ; i < N ; i++)
        for (j = 0 ; j < M ; j++)
            t.tchoco[i][j] = 1;
    return t;
}

/*Structure booléene qui représente les 2 joueurs*/
typedef enum {
    JOUEUR_1,
    JOUEUR_2
} Joueur;

/*Structure qui represente une position de jeu */
typedef struct position{
    Tablette t;
    Joueur joueur;
} Position;

/*Structure qui represente un coup joué avec une coordonnée x et y */
typedef struct coup{
    int x;
    int y;
} Coup;

/*fonction qui renvoie l'adversaire du joueur joueur*/
Joueur adversaire(Joueur joueur){
    Joueur rand;

    if (joueur== JOUEUR_1)
        rand = JOUEUR_2;
    else 
        rand = JOUEUR_1;
    return rand;
}

/*fonction qui permet de manger la tablette selon les regles*/
void manger(Tablette *tab, int x, int y){
    int i,j;
    assert(x < M && x >= 0);
    assert(y < N && y >= 0);
    for (i = x ; i < N ; i++)
        for (j = y ; j < M ; j++)
            tab->tchoco[i][j] = 0;
}

/*fonction qui verifie si un coup est légal*/
int est_legal(Position pos, Coup coup){
    int x_temp, y_temp;

    x_temp= coup.x;
    y_temp= coup.y;
    if ((x_temp < 0) || ((x_temp) >= M) || ((y_temp) < 0) || ((y_temp) >= N)) /*Si le carré est en dehors de la tablette*/
        return 0;
    
    if (pos.t.tchoco[coup.x][coup.y] == 1){  /*Si le carré de chocolat existe*/
        return 1;
    }
    else{
        return 0;
    }
}

/*fonction qui verifie si le jeu est termine*/
int est_jeu_termine(Position pos, Joueur *joueur_gagnant){
    assert(joueur_gagnant != NULL);
    if (pos.t.tchoco[0][0] == 0){
        *joueur_gagnant = pos.joueur;
        return 1;
    }
    else{
        return 0;
    }
    
}

/*fonction qui joue le coup coup dans la position pos en paramètre */
void jouer_coup(Position *pos, Coup coup){
    int x_temp, y_temp;
    
    x_temp= coup.x;
    y_temp= coup.y;
    manger(&(pos->t), x_temp, y_temp);
    pos->joueur = adversaire(pos->joueur);
}

/*
void afficher_position(Position pos){
    
}




Coup lire_coup(Position pos){
    
}
    
*/  

int main(void){
    /*Position pos;
    while(est_jeu_termine(Position pos, Joueur *joueur_gagnant)==0){
        afficher_position(pos);
        lire_coup(pos);
        jouer_coup(pos);
    }
    
    
    if(pos.joueur == JOUEUR_1){
        mvprintw(0,0,"le gagnant est le joueur 1");   
    }
    else{
        mvprintw(0,0,"le gagnant est le joueur 2");
    }

*/
    return 0;
}
