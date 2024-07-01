void InitialiserPlateau(char Plateau[10][10]) {
    for (int i = 0; i < Taille; i++) {
        for (int j = 0; j < Taille; j++) {
            Plateau[i][j] = '-';
        }
    }
}

void InitialiseJoueur1(char Plateau[10][10]){
    for (int j = 0; j < 4; j++) {
        Plateau[0][j] = 'X';
    }

    for (int j = 0; j < 3; j++) {
        Plateau[1][j] = 'X';
    }

    for (int j = 0; j < 2; j++) {
        Plateau[2][j] = 'X';
    }

    Plateau[3][0] = 'X';
}

void InitialiseJoueur2(char Plateau[10][10]){
    for (int j = 9; j > 5; j--) {
        Plateau[9][j] = 'Y';
    }
    for (int j = 9; j > 6; j--) {
        Plateau[8][j] = 'Y';
    }

    for (int j = 9; j > 7; j--) {
        Plateau[7][j] = 'Y';
    }

    Plateau[6][9] = 'Y';
}


void AfficherPlateau(char Plateau[10][10]) {
    printf("\n");
    for (int i = 0; i < Taille; i++) {
        for (int j = 0; j < Taille; j++) {
            printf("%c ", Plateau[i][j]);
        }
        printf("\n");
    }
}

int Tirage() {
    srand(time(NULL));
    int tour = rand() % 2 + 1;
    return tour;
}

int ResultatTirage(){
    if (Tirage() == 1){
        printf("Tour du joueur1 : \n");
        return 3;
    }
    else if (Tirage() == 2){
        printf("Tour du joueur2 : \n");
        return 4;
    }
}

int VerifierDeplacement(char Plateau[10][10], int x, int y) {
    int x1,y1;
    if(Plateau[x][y] == "-")
    {
        printf("case vide");
        return 0;
    }

    if (!((abs(x1 - x) == 1 || abs(x1 - x) == 0) && (abs(y1 - y) == 1 || abs(y1 - y) == 0)) || (x1 == x && y1 == y)) {
      printf("Déplacement invalide.\n");
      return 0;
    }

    if (x < 0 || y < 0 || x >= 10 || y >= 10) {
        printf("Position invalide. \n");
        return 0;
    }
    if ( (Plateau[x1][y1] == "X") || (Plateau[x1][y1] == "Y") ) {
        printf("Deplacement invalide. \n");
        return 0;
    }

//    if (x1 < 0 || y1 < 0 || x1 >= 10 || y1 >= 10) {
  //      printf("Déplacement invalide.\n");  //vous avez depacé les limites du plateau
    //    return 0;
//    }
    return 1;
}

void DeplacerSoldat(char Plateau[10][10],int x,int y,int x1,int y1){
    if( (Plateau[x1][y1] == "X") || (Plateau[x1][y1] == "Y") ){
        if(Plateau[x1][y1+1] == "-"){
            printf("Contourner un soldat");
            Plateau[x1][y1+1] = Plateau[x][y];
            Plateau[x][y] = "-";
        }
        else if(Plateau[x1+1][y1] == "-"){
            printf("Contourner un soldat");
            Plateau[x1+1][y1] = Plateau[x][y];
            Plateau[x][y] = "-";
        }
        else if(Plateau[x1+1][y1+1] == "-"){
            printf("Contourner un soldat");
            Plateau[x1+1][y1+1] = Plateau[x][y];
            Plateau[x][y] = "-";
        }
        else if(Plateau[x1][y1-1] == "-"){
            printf("Contourner un soldat");
            Plateau[x1][y1-1] = Plateau[x][y];
            Plateau[x][y] = "-";
        }
        else if(Plateau[x1-1][y1] == "-"){
            printf("Contourner un soldat");
            Plateau[x1-1][y1] = Plateau[x][y];
            Plateau[x][y] = "-";
        }
        else if(Plateau[x1-1][y1-1] == "-"){
            printf("Contourner un soldat");
            Plateau[x1-1][y1-1] = Plateau[x][y];
            Plateau[x][y] = "-";
        }
    }
    else{
        printf("Deplacement simple");
        Plateau[x1][y1] = Plateau[x][y];
        Plateau[x][y] = "-";;
    }

}

void Play() {
    int JoueurActuel = 0;

    while (1) {
        AfficherPlateau(&Plateau);
        printf("Tour de Joueur %d.\n", JoueurActuel+1 );

        int x, y , x1, y1 ;
        printf("soldat a deplacer (x,y) : ");
        scanf("%d %d", &x, &y);
        printf("nouvelle position du soldat (x1 y1) : ");
        scanf("%d %d", &x1, &y1);

        if (VerifierDeplacement(Plateau, x, y) == 1) {
           DeplacerSoldat(Plateau,x,y,x1,y1);
           JoueurActuel = (JoueurActuel + 1) % 2;
        }
    }
}
