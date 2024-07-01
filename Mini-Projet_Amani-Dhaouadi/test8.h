#ifndef TEST8_H_INCLUDED
#define TEST8_H_INCLUDED

typedef struct {
    char Nombre;
} Joueur;

char Plateau[10][10];

void InitialiserPlateau(Plateau);
void InitialiseJoueur(Plateau);
void AfficherPlateau(Plateau);
int Tirage();
int ResultatTirage();
int VerifierDeplacement(Plateau, x, y);
void DeplacerSoldat(Plateau, x, y, x1, y1);
void play();



#endif // TEST8_H_INCLUDED
