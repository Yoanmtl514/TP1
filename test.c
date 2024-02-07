
/****************************************************************************************
/*                                      TEST                                           *
/****************************************************************************************
Auteur : Yoan Sapet & Alexis St-Pierre
Date   : 24 Janvier 2024

Fonction publique:

Ce module permet de lancer tous les tests unitaires de chaque module de l'application
*****************************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#include "configuration.h"


#if TEST

/*
    AFFICHER_ENTETE_TEST

    Cette fonction permet d'afficher une entete quand le mode test est lance

    Paramètres:
        - Aucun

    Retour:
        - Aucun.
*/
static void afficher_entete_test();

int main(void)
{
    afficher_entete_test();
    return EXIT_SUCCESS;
}

//
// On affiche l'entete du mode test
//
static void afficher_entete_test()
{
    printf("Pogramme execute en mode test\n");
    printf("Yoan Sapet & Alexis St-Pierre\n");
    printf("Session: Hiver 2024\n");

}

#endif
