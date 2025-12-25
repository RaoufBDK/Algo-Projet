// Projet Algo 1 
#include <stdio.h>
#include <string.h>

/* ======= VARIABLES GLOBALES ======= */
int choix;  //variable pour le choix du menu
int i; //variable pour les boucles

 /* =================== [1] GERER MATIERES =================== */
    int choixMAT;               // choix dans le sous-menu matières   
    int n;                     // nombre temporaire 
    int nbMAT = 0;            // nombre actuel de matières définies
    char nomsMAT[10][30];    // noms des matières 
    int coeff[5];           // coefficient de chaque matière 

 /* =================== [2] GERER ETUDIANTS =================== */
    int etuMat = 0 ;       // choix dans le sous-menu étudiants
    int nbETU = 0;          // nombre actuel d'étudiants définis
    int N;                  // nombre temporaire
    char nomsETU [50][50];        // noms des étudiants
    int idETU[50];           // identifiants des étudiants
    float note[50][10];        // notes des étudiants pour chaque matière
    int j;             // variable pour les boucles
    int exit;          // variable pour sortir des sous-menus
 /* =================== [3] RECHERCHER ETUDIANT =================== */
    int choixRECH;        // choix du sous-menu recherche
    char nomRecherche[50];         // nom recherché par l'utilisateur
 
 /* =================== [4] CALCULS & STATS =================== */
  int choixCALC;      // choix du sous-menu calculs & stats
  int s;               // variable pour les boucles
  int idRecherche;  // id recherché par l'utilisateur
  int idx;          // index de l'étudiant trouvé
  int trouve;          
 

/* =================== [5] AFFICHER TOUS LES ETUDIANTS =================== */
    int raouf;        
    int existe;      // variable pour vérifier l'existence d'un ID

int main() 
{
    do
    {
        // MENU (un menu qui display toutes les options disponibles du programme avec des numéros pour chaque option)
        printf("\n");
        printf("------------------------------------------------------------------------\n");
        printf("          GESTION AVANCEE DES ETUDIANTS - ING1 (C)\n");    
        printf("------------------------------------------------------------------------");
        printf("\n");
        printf("Matieres definies : %d/10    |    Etudiants : %d/50\n", nbMAT ,nbETU);
        printf("------------------------------------------------------------------------");
        printf("\n");
        printf("  [1] Gerer les matieres \n");
        printf("  [2] Gerer les etudiants \n");
        printf("  [3] Rechercher un etudiant (id / nom)\n");
        printf("  [4] Calculs & statistiques\n");
        printf("  [5] Afficher tous les etudiants\n");
        printf("  [6] Quitter\n");
        printf("------------------------------------------------------------------------");
        printf("\nChoix : ");

        //choix ( une boucle case of/switch pour séléctionner les options du menu)
        
        scanf("%d",&choix);

        switch (choix)
        {
        /* =================== [1] GERER MATIERES =================== */
            case 1:
                do {
                    printf("------------------------------------------------------------------------\n");
                    printf("\n>> Gestion des matieres (en cours...)\n");
                    printf("------------------------------------------------------------------------\n");
                    printf("  [1] Ajouter des matieres\n");
                    printf("  [2] Afficher les matieres\n");
                    printf("  [3] Retour\n");
                    printf("------------------------------------------------------------------------\n");
                    printf("Choix : ");
                    scanf("%d", &choixMAT);

                    //choix ( une boucle case of/switch pour séléctionner les options du gestion des matieres)
                    switch (choixMAT){
                        case 1: {
                            /* =================== [1]  AJOUTER DES MATIERES =================== */
                            // les matieres a ajouter
                            printf("Combien de matieres a ajouter ?");
                            scanf("%d", &n);

                            if (nbMAT + n > 10){ // +n pour ajouter a les matieres existantes
                                printf("Depasement du nombre max mattieres ! \n "); //depasement
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while(exit != 3);
                            } else { //numero de matiere le nom et la coefficient
                                for (int i=0; i<n; i++)
                                {
                                    printf("\nMatiere %d\n", nbMAT + 1);
                                    printf("Nom :");
                                    scanf("%s", nomsMAT[nbMAT]);

                                    int exists = 0;
                                    for (int k = 0; k < nbMAT; k++)
                                    { //verifier l'existence strcmp sert a comparer deux chaines de caracteres
                                        if (strcmp(nomsMAT[nbMAT], nomsMAT[k]) == 0) 
                                        {
                                            printf("Cette matiere existe deja. Veuillez entrer un nom unique.\n");
                                            exists = 1;
                                            break;
                                        }
                                    }

                                    if (exists)
                                    {
                                        i--;
                                        continue;
                                    }
                                    
                                    printf("Coefficient (1-5) : ");
                                    scanf("%d", &coeff[nbMAT]);
                                    nbMAT++;
                                }
                                printf("type 3 to exit this\n");
                                do
                                {
                                    scanf("%d", &exit);
                                }while(exit != 3);
                            }
                            break;
                        }
                        /* =================== [2] AFFICHER LES MATIERES =================== */
                        case 2: {
                            if (nbMAT == 0){ //check pour 0 matieres
                                printf("aucune matiere definie. Utilisez la gestion des matières d'abord.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while(exit != 3);
                            } else { //for loop pour l'affichage
                                printf("\nListe des matieres :\n");
                                for (int i =0; i < nbMAT; i++){
                                    printf("%d. %s Coeff %d \n", i+1, nomsMAT[i], coeff[i]);
                                }
                                printf("type 3 to exit this\n");
                                do
                                {
                                    scanf("%d", &exit);
                                }while(exit != 3);
                            }
                            break;
                        }

                        case 3: 
                        {
                            break;
                        }
                        default:
                            printf("Choix invalide \n");
                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while(exit != 3);
                            break;
                    }
                } while (choixMAT != 3);

                break;
            /* =================== [2] GERER ETUDIANTS =================== */   
            case 2:
                do
                {
                    printf("------------------------------------------------------------------------\n");
                    printf("\n>> Gestion des etudiants (en cours...)\n");
                    printf("------------------------------------------------------------------------\n");
                    printf("  [1] Ajouter un etudiant\n");
                    printf("  [2] Modifier un etudiant\n");
                    printf("  [3] Suprimer un etudiant\n");
                    printf("  [4] retour\n");
                    printf("------------------------------------------------------------------------\n");
                    printf("Choix : ");
                    scanf("%d", &etuMat);
                
                    switch (etuMat)
                    {
                    /* =================== [1] AJOUTER UN ETUDIANT =================== */
                        case 1:
                        printf("Combien d'etudiant a ajouter ?");
                        scanf("%d", &N);
                        if ( nbETU + N > 50)
                            {
                                printf("Depasement du nombre max etudiants ! \n ");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while(exit != 3);

                            } 
                            else
                                {
                                for (int i = 0; i < N ; i++)
                                {
                                    printf("\n Etudiant %d\n", nbETU + 1);
                                    printf("Nom :");
                                    scanf("%s", nomsETU[nbETU]);

                                    do
                                    {
                                        printf("Identifiant (unique) : ");
                                        scanf("%d", &idETU[nbETU]);

                                        existe = 0;
                                        for (int k = 0; k < nbETU; k++)
                                        {
                                            if (idETU[k] == idETU[nbETU])
                                            {
                                                existe = 1;
                                                break;
                                            }
                                        }

                                        if (existe)
                                        {
                                            printf("Cet ID existe deja. Veuillez entrer un ID unique.\n");
                                        }
                                    } while (existe);

                                    for (int m = 0; m < nbMAT ; m++)
                                    {
                                        do
                                        {
                                            printf("La note de %s ", nomsMAT[m]);
                                            scanf("%f", &note[nbETU][m]);
                                        } while (note[nbETU][m]<0 || note[nbETU][m]>20 );
                                        
                                    }

                                    nbETU++;
                                }
                                printf("type 3 to exit this\n");
                                do
                                {
                                    scanf("%d", &exit);
                                }while(exit != 3);
                            }

                    break;
                    /* =================== [2] MODIFIER UN ETUDIANT =================== */
                    case 2:
            
                    if (nbETU == 0) 
                    {
                        printf("Aucun etudiant defini.\n");
                        printf("type 3 to exit this\n");
                        do { scanf("%d", &exit); } while (exit != 3);
                        break;
                    }
                    else
                    {
                        printf("Quel est l'etudiant a modifier (ID) :\n");
                        scanf("%d", &idRecherche);

                        idx = -1;
                        for (i = 0; i < nbETU; i++)
                        {
                            if (idETU[i] == idRecherche)
                            {
                                idx = i;
                                break;
                            }
                        }

                        if (idx == -1)
                        {
                            printf("Etudiant non trouve.\n");
                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                        }

                        printf("Nouveau nom : ");
                        scanf("%49s", nomsETU[idx]);

                        int newId;
                        do
                        {
                            printf("Nouvel identifiant (unique) : ");
                            scanf("%d", &newId);

                            existe = 0;
                            for (int k = 0; k < nbETU; k++)
                            {
                                if (k != idx && idETU[k] == newId)
                                {
                                    existe = 1;
                                    break;
                                }
                            }

                            if (existe)
                            {
                                printf("Cet ID existe deja. Veuillez entrer un ID unique.\n");
                            }
                        } while (existe);

                        idETU[idx] = newId;

                        for (int m = 0; m < nbMAT; m++)
                        {
                            do
                            {
                                printf("La note de %s : ", nomsMAT[m]);
                                scanf("%f", &note[idx][m]);
                            } while (note[idx][m] < 0.0f || note[idx][m] > 20.0f);
                        }

                        printf("Modification terminee.\n");
                    }

                    printf("type 3 to exit this\n");
                    do
                    {
                        scanf("%d", &exit);
                    }while(exit != 3);
                    break;
                    /* =================== [3] SUPPRIMERR UN ETUDIANT =================== */
                    case 3:
                        if (nbETU == 0)
                        {
                            printf("aucun etudiant a supprimer \n");
                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                        }
                        
                        printf("Quel est l'etudiant a supprimer (ID) :\n");
                        scanf("%d",&idRecherche);
                        idx = -1; // tsema makach hna
                        for  (i=0; i< nbETU; i++)
                        {
                            if (idETU[i] == idRecherche)
                            {
                                idx = i;    
                                break;
                            }
                        }

                        if (idx == -1)
                        {
                            printf("Etudiant non trouve.\n");
                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                        }
                        else
                        {
                            /* decaler tous les elements apres idx vers la gauche */
                            for (int k = idx; k < nbETU - 1; k++)
                            { // strcpy sert a copier des chaines de caracteres 
                                strcpy(nomsETU[k], nomsETU[k + 1]);
                                idETU[k] = idETU[k + 1];
                                for (int m = 0; m < nbMAT; m++)
                                {
                                    note[k][m] = note[k + 1][m];
                                }
                            }
                            nbETU--;
                            printf("Etudiant supprime.\n");
                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                        }
                        
                        break;
                        
                    case 4:
                        break;
                    default:
                        printf("Choix invalide \n");
                        printf("type 3 to exit this\n");
                        do { scanf("%d", &exit); } while (exit != 3);
                        break;
                    }
                } while (etuMat != 4);            
                break;
                /* =================== [3] RECHERCHER ETUDIANT =================== */
            case 3: 
                printf("\n>> Recherche d'un etudiant (en cours...)\n");
                if (nbETU == 0) {
                    printf("Aucun etudiant defini.\n");
                    printf("type 3 to exit this\n");
                    do { scanf("%d", &exit); } while (exit != 3);
                    break;
                }
                if (nbMAT == 0) {
                    printf("Aucune matiere definie (donc aucune note a afficher).\n");
                    printf("type 3 to exit this\n");
                    do { scanf("%d", &exit); } while (exit != 3);
                    break;
                }

                do {
                    printf("------------------------------------------------------------------------\n");
                    printf("  [1] Rechercher par ID\n");
                    printf("  [2] Rechercher par NOM\n");
                    printf("  [3] Retour\n");
                    printf("------------------------------------------------------------------------\n");
                    printf("Choix : ");
                    scanf("%d", &choixRECH);

                    switch (choixRECH) {
                        case 1: {
                            printf("ID a rechercher : ");
                            scanf("%d", &idRecherche);

                            idx = -1;
                            for (i = 0; i < nbETU; i++) {
                                if (idETU[i] == idRecherche) {
                                    idx = i;
                                    break;
                                }
                            }

                            if (idx < 0) {
                                printf("Etudiant non trouve.\n");
                            } else {
                                printf("Etudiant : %s (ID %d)\n", nomsETU[idx], idETU[idx]);
                                printf("Notes :\n");
                                for (j = 0; j < nbMAT; j++) {
                                    printf("  - %s : %.2f\n", nomsMAT[j], note[idx][j]);
                                }
                            }

                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                        }

                        case 2: {
                            int found = 0;

                            printf("Nom a rechercher : ");
                            scanf("%49s", nomRecherche);

                            for (i = 0; i < nbETU; i++) {
                                if (strcmp(nomsETU[i], nomRecherche) == 0) {
                                    found = 1;
                                    printf("Etudiant : %s (ID %d)\n", nomsETU[i], idETU[i]);
                                    printf("Notes :\n");
                                    for (j = 0; j < nbMAT; j++) {
                                        printf("  - %s : %.2f\n", nomsMAT[j], note[i][j]);
                                    }
                                }
                            }

                            if (!found) {
                                printf("Etudiant non trouve.\n");
                            }

                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                        }

                        case 3:
                            break;

                        default:
                            printf("Choix invalide\n");
                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                    }
                } while (choixRECH != 3);
                    if (nbETU == 0) {
                        printf("Aucun etudiant defini.\n");
                        printf("type 3 to exit this\n");
                        do { scanf("%d", &exit); } while (exit != 3);
                        break;
                    }

                    do {
                        printf("------------------------------------------------------------------------\n");
                        printf("  [1] Rechercher par ID\n");
                        printf("  [2] Rechercher par NOM\n");
                        printf("  [3] Retour\n");
                        printf("------------------------------------------------------------------------\n");
                        printf("Choix : ");
                        scanf("%d", &choixRECH);

                        switch (choixRECH) {
                            /* =================== [1] RECHERCHER PAR ID =================== */
                            case 1:
                                printf("ID a rechercher : ");
                                scanf("%d", &idRecherche);

                                idx = -1;
                                for (i = 0; i < nbETU; i++) {
                                    if (idETU[i] == idRecherche) {
                                        idx = i;
                                        break;
                                    }
                                }

                                if (idx == -1) {
                                    printf("Etudiant non trouve.\n");
                                } else {
                                    printf("Etudiant trouve : %s (ID %d)\n", nomsETU[idx], idETU[idx]);
                                    for (int j = 0; j < nbMAT; j++)
                                    {
                                        printf("%s : %.2f \n", nomsMAT[j], note[idx][j]);
                                         
                                    }
                                    
                                }

                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                               /* =================== [2] RECHERCHER PAR NOM =================== */
                            case 2: {
                                int trouve = 0;

                                printf("Nom a rechercher : ");
                                scanf("%s", nomRecherche);

                                for (i = 0; i < nbETU; i++) {
                                    if (strcmp(nomsETU[i], nomRecherche) == 0) { //strcmp sert a comparer deux chaines de caracteres
                                        printf("Etudiant trouve : %s (ID %d)\n", nomsETU[i], idETU[i]);
                                        for (int j = 0; j < nbMAT; j++)
                                        {
                                            printf("%s : %.2f \n", nomsMAT[j], note[idx][j]);
                                         
                                        }
                                        trouve = 1;
                                    }
                                }

                                if (!trouve) {
                                    printf("Etudiant non trouve.\n");
                                }
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }

                            case 3:
                                break;

                            default:
                                printf("Choix invalide\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                        }
                    } while (choixRECH != 3);
                
                break;
                

            
            /* =================== [4] CALCULS & STATISTIQUES  =================== */
            case 4:
                do {
                    //choix ( une boucle case of/switch pour séléctionner les options du calculs et statistiques)
                    printf("------------------------------------------------------------------------\n");
                    printf("\n>> Calculs et statistiques (en cours...)\n");
                    printf("------------------------------------------------------------------------\n");
                    printf("  [1] Moyenne ponderee par etudiant\n");
                    printf("  [2] Moyenne generale par matiere\n");
                    printf("  [3] Moyenne generale globale\n");
                    printf("  [4] Meilleur et pire note par etudiant\n");
                    printf("  [5] Meilleur et pire note par matiere\n");
                    printf("  [6] Retour\n");
                    printf("------------------------------------------------------------------------\n");
                    printf("Choix : ");
                    scanf("%d", &choixCALC);

                    switch (choixCALC) {
                        /* =================== [1] MOYENNE PONDEREE PAR ETUDIANT =================== */
                        case 1: {
                            float somme;
                            int sommeCoeff;

                            if (nbETU == 0) {
                                printf("Aucun etudiant defini.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }
                            if (nbMAT == 0) {
                                printf("Aucune matiere definie.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }
                            for (i = 0; i < nbETU; i++) {
                                somme = 0.0f;
                                sommeCoeff = 0;
                                for (j = 0; j < nbMAT; j++) {
                                    somme += note[i][j] * coeff[j];
                                    sommeCoeff += coeff[j];
                                }
                                if (sommeCoeff == 0) {
                                    printf("Moyenne ponderee pour %s (ID %d) :  (coefficients nuls)\n", nomsETU[i], idETU[i]);
                                } else {
                                    printf("Moyenne ponderee pour %s (ID %d) : %.2f\n", nomsETU[i], idETU[i], somme / sommeCoeff);
                                }
                            }
                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                        }

                        /* =================== [2] MOYENNE GENERALE PAR MATIERE =================== */
                        case 2: {
                            if (nbETU == 0) {
                                printf("Aucun etudiant defini.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }
                            if (nbMAT == 0) {
                                printf("Aucune matiere definie.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }
                            for (j = 0; j < nbMAT; j++) {
                                float sommeMatiere = 0.0f;
                                int count = 0;
                                for (i = 0; i < nbETU; i++) {
                                    sommeMatiere += note[i][j];
                                    count++;
                                }
                                if (count == 0) {
                                    printf("Moyenne pour %s : (aucune note)\n", nomsMAT[j]);
                                } else {
                                    printf("Moyenne pour %s : %.2f\n", nomsMAT[j], sommeMatiere / count);
                                }
                            }
                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                        }

                        /* =================== [3] MOYENNE GENERALE GLOBALE  =================== */
                        case 3: {
                            if (nbETU == 0) {
                                printf("Aucun etudiant defini.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }
                            if (nbMAT == 0) {
                                printf("Aucune matiere definie.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }
                            float sommeAll = 0.0f;
                            int sommeCoeffAll = 0;
                            for (j = 0; j < nbMAT; j++) {
                                sommeCoeffAll += coeff[j];
                            }
                            if (sommeCoeffAll == 0) {
                                printf("Moyenne generale globale :  (coefficients nuls)\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }
                            for (i = 0; i < nbETU; i++) {
                                for (j = 0; j < nbMAT; j++) {
                                    sommeAll += note[i][j] * coeff[j];
                                }
                            }
                            printf("Moyenne generale globale  : %.2f\n", sommeAll / (nbETU * sommeCoeffAll));
                            printf("type 3 to exit\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                        }
                        case 4:
                            {
                                if (nbETU == 0) {
                                    printf("Aucun etudiant defini.\n");
                                    printf("type 3 to exit this\n");
                                    do { scanf("%d", &exit); } while (exit != 3);
                                    break;
                                }
                                if (nbMAT == 0) {
                                    printf("Aucune matiere definie.\n");
                                    printf("type 3 to exit this\n");
                                    do { scanf("%d", &exit); } while (exit != 3);
                                    break;
                                }

                                for (i = 0; i < nbETU; i++) {
                                    float best = note[i][0];
                                    float worst = note[i][0];
                                    int bestIdx = 0;
                                    int worstIdx = 0;

                                    for (j = 1; j < nbMAT; j++) {
                                        if (note[i][j] > best) {
                                            best = note[i][j];
                                            bestIdx = j;
                                        }
                                        if (note[i][j] < worst) {
                                            worst = note[i][j];
                                            worstIdx = j;
                                        }
                                    }

                                    printf("\n%s (ID %d)\n", nomsETU[i], idETU[i]);
                                    printf("  Meilleure note : %.2f (%s)\n", best, nomsMAT[bestIdx]);
                                    printf("  Pire note      : %.2f (%s)\n", worst, nomsMAT[worstIdx]);
                                }

                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                            }
                            break;

                          case 5: 
                        {
                            if (nbETU == 0) {
                                printf("Aucun etudiant defini.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }
                            if (nbMAT == 0) {
                                printf("Aucune matiere definie.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }

                            for (j = 0; j < nbMAT; j++) {
                                float best = note[0][j];
                                float worst = note[0][j];
                                int bestEtu = 0;
                                int worstEtu = 0;

                                for (i = 1; i < nbETU; i++) {
                                    if (note[i][j] > best) {
                                        best = note[i][j];
                                        bestEtu = i;
                                    }
                                    if (note[i][j] < worst) {
                                        worst = note[i][j];
                                        worstEtu = i;
                                    }
                                }

                                printf("\n%s\n", nomsMAT[j]);
                                printf("  Meilleure note : %.2f (%s, ID %d)\n", best, nomsETU[bestEtu], idETU[bestEtu]);
                                printf("  Pire note      : %.2f (%s, ID %d)\n", worst, nomsETU[worstEtu], idETU[worstEtu]);
                            }

                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                        }
                        case 6:
                            break;

                        default:
                            printf("Choix invalide\n");
                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                            break;
                    }
                } while (choixCALC != 6);
                break;
            /* =================== [5] AFFICHER TOUS LES ETUDIANTS =================== */
            case 5:
                do
                {
                    if (nbETU == 0) {
                        printf("Aucun etudiant defini.\n");
                        printf("type 3 to exit this\n");
                        do { scanf("%d", &exit); } while (exit != 3);
                        raouf = 4; /* sortir du sous-menu */
                    } 
                    else 
                    {
                        printf("------------------------------------------------------------------------\n");
                        printf("[1]Liste de tous les etudiants par ordre alphabetique :\n");
                        printf("[2]Liste de tous les etudiants par moyenne:\n");
                        printf("[3]Liste des etudiants  qui n'ont pas eu la moyenne:\n");
                        printf("[4]Retour\n");
                        printf("------------------------------------------------------------------------\n");
                        printf("Choix : ");
                        scanf ("%d",&raouf);
                        switch (raouf)
                        {
                            case 1:
                                 {
                                int ordre[50];

                                for (i = 0; i < nbETU; i++) {
                                    ordre[i] = i;
                                }

                                /* tri par nom (puis par id en cas d'egalite) */
                                for (i = 0; i < nbETU - 1; i++) {
                                    for (j = 0; j < nbETU - 1 - i; j++) {
                                        int a = ordre[j];
                                        int b = ordre[j + 1];
                                                //strcmp sert a comparer deux chaines de caracteres
                                        int cmp = strcmp(nomsETU[a], nomsETU[b]);   // compare les noms 
                                        if (cmp > 0 || (cmp == 0 && idETU[a] > idETU[b])) {
                                            int tmp = ordre[j];
                                            ordre[j] = ordre[j + 1];
                                            ordre[j + 1] = tmp;
                                        }
                                    }
                                }

                                printf("\n--- Liste des etudiants (ordre alphabetique) ---\n");
                                for (i = 0; i < nbETU; i++) {
                                    int k = ordre[i];
                                    printf("%2d. %s (ID %d)\n", i + 1, nomsETU[k], idETU[k]);
                                }

                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                            }
                                break;
                            case 2:
                             {
                            if (nbMAT == 0) {
                                printf("Aucune matiere definie.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }

                            int ordre[50];
                            float moy[50];
                            int sommeCoeff = 0;

                            for (j = 0; j < nbMAT; j++) {
                                sommeCoeff += coeff[j];
                            }
                            if (sommeCoeff == 0) {
                                printf("Impossible de calculer les moyennes (coefficients nuls).\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }

                            for (i = 0; i < nbETU; i++) {
                                float somme = 0.0f;
                                for (j = 0; j < nbMAT; j++) {
                                    somme += note[i][j] * coeff[j];
                                }
                                moy[i] = somme / sommeCoeff;
                                ordre[i] = i;
                            }

                            /* tri par moyenne (desc), puis par nom, puis par id */
                            for (i = 0; i < nbETU - 1; i++) {
                                for (j = 0; j < nbETU - 1 - i; j++) {
                                    int a = ordre[j];
                                    int b = ordre[j + 1];

                                    int swap = 0;
                                    if (moy[a] < moy[b]) {
                                        swap = 1;
                                    } else if (moy[a] == moy[b]) {
                                        int cmp = strcmp(nomsETU[a], nomsETU[b]);
                                        if (cmp > 0 || (cmp == 0 && idETU[a] > idETU[b])) {
                                            swap = 1;
                                        }
                                    }

                                    if (swap) {
                                        int tmp = ordre[j];
                                        ordre[j] = ordre[j + 1];
                                        ordre[j + 1] = tmp;
                                    }
                                }
                            }

                            printf("\n--- Liste des etudiants (par moyenne) ---\n");
                            for (i = 0; i < nbETU; i++) {
                                int k = ordre[i];
                                printf("%2d. %s (ID %d) : %.2f\n", i + 1, nomsETU[k], idETU[k], moy[k]);
                            }

                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                        }
                                break;
                            case 3:
                                {
                            if (nbMAT == 0) {
                                printf("Aucune matiere definie.\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }

                            int sommeCoeff = 0;
                            for (j = 0; j < nbMAT; j++) {
                                sommeCoeff += coeff[j];
                            }

                            if (sommeCoeff == 0) {
                                printf("Impossible de calculer les moyennes (coefficients nuls).\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }

                            printf("\n--- Etudiants n'ayant pas eu la moyenne (< 10.00) ---\n");
                            int count = 0;

                            for (i = 0; i < nbETU; i++) {
                                float somme = 0.0f;
                                for (j = 0; j < nbMAT; j++) {
                                    somme += note[i][j] * coeff[j];
                                }
                                float moyenne = somme / sommeCoeff;

                                if (moyenne < 10.0f) {
                                    printf("%2d. %s (ID %d) : %.2f\n", count + 1, nomsETU[i], idETU[i], moyenne);
                                    count++;
                                }
                            }

                            if (count == 0) {
                                printf("Aucun etudiant n'est en dessous de la moyenne.\n");
                            }

                            printf("type 3 to exit this\n");
                            do { scanf("%d", &exit); } while (exit != 3);
                        }
                                
                                break;
                            case 4:
                                break;
                            default:
                                printf ("Choix invalide\n");
                                printf("type 3 to exit this\n");
                                do { scanf("%d", &exit); } while (exit != 3);
                                break;
                            }
                        }
                    } while(raouf != 4);
                break;
                    /* =================== [6] QUITTER  =================== */
            case 6:
                printf("\n au revoir!   Merci de votre attention , \n"
                       "                    fait par Raouf , Islem , Souheil   \n");
                
                return 0;
                break;
            default:
                printf("\nChoix invalide\n");
                printf("type 3 to exit this\n");
                do { scanf("%d", &exit); } while (exit != 3);
                break;
                                       
        }
    } while(choix != 6);

    return 0;
}
