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
#include "decodeur/utilitaire.h"

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
static void test_afficher_heure();
static void test_decimale_a_octale();

int main(void)
{
    afficher_entete_test();
    test_afficher_heure();
    test_decimale_a_octale();

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

static void test_afficher_heure()
{
    printf("\nTest fonction afficher heure:\n");
    printf("Jeu d'essais\n");

    printf("Entree: %-5d, Sortie attendu: 00h00m00s, Sortie:", 0);
    afficher_heure(0);

    printf("Entree: %-5d, Sortie attendu: 00h00m59s, Sortie:", 59);
    afficher_heure(59);

    printf("Entree: %-5d, Sortie attendu: 00h01m01s, Sortie:", 61);
    afficher_heure(61);

    printf("Entree: %-5d, Sortie attendu: 01h01m01s, Sortie:", 3661);
    afficher_heure(3661);

    printf("Entree: %-5d, Sortie attendu: 09h09m09s, Sortie:", 32949);
    afficher_heure(32949);

    printf("Entree: %-5d, Sortie attendu: 23h59m59s, Sortie:", 86399);
    afficher_heure(86399);


}

static void test_decimale_a_octale()
{
    printf("\n\nTest fonction decimale a octale:\n");
    printf("Jeu d'essais\n");

    unsigned int valeur_a_afficher;

    valeur_a_afficher = decimale_a_octale(1);
    printf("Entree: %-3d, Sortie attendu: %-3d, Sortie: %i", 1,1,valeur_a_afficher);

    valeur_a_afficher =decimale_a_octale(8);
    printf("\nEntree: %-3d, Sortie attendu: %-3d, Sortie:%i", 8,10,valeur_a_afficher);


    valeur_a_afficher =decimale_a_octale(15);
    printf("\nEntree: %-3d, Sortie attendu: %-3d, Sortie:%i", 15,17,valeur_a_afficher);


    valeur_a_afficher =decimale_a_octale(64);
    printf("\nEntree: %-3d, Sortie attendu: %-3d, Sortie:%i", 64,100,valeur_a_afficher);


    valeur_a_afficher =decimale_a_octale(104);
    printf("\nEntree: %-3d, Sortie attendu: %-3d, Sortie:%i", 104,150,valeur_a_afficher);


    valeur_a_afficher =decimale_a_octale(209);
    printf("\nEntree: %-3d, Sortie attendu: %-3d, Sortie:%i", 209,321,valeur_a_afficher);

}

static void test_calculer_nb_bits_actifs()
{

}

static void test_afficher_bits()
{

}

static void test_afficher_entete_encodeur()
{

}

static void test_decoder_mot_a429()
{



}


#endif
