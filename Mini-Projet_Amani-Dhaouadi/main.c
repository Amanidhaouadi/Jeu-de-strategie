#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Taille 10

#include "test8.h"
#include "test8.c"


int main() {

    InitialiserPlateau(&Plateau);

    InitialiseJoueur1(&Plateau);
    InitialiseJoueur2(&Plateau);

    Play();

    return 0;
}
