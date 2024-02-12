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
#include "decodeur/a429.h"

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

/*
    test_afficher_heure

    Cette fonction permet de tester la fonction_afficher_heure

    Paramètres:
        - Aucun

    Retour:
        - Aucun.
*/
static void test_afficher_heure();

/*
    test_decimale_a_octale

    Cette fonction permet de tester la fonction decimale_a_octale qui convertit un entier decimal a octal

    Paramètres:
        - Aucun

    Retour:
        - Aucun.
*/
static void test_decimale_a_octale();

/*
    test_calculer_nb_bits_actifs

    Cette fonction permet de tester la fonction calculer_nb_bits_actifs qui comptent le nombre de bits d'entreee
    hexadecimale

    Paramètres:
        - Aucun

    Retour:
        - Aucun.
*/
static void test_calculer_nb_bits_actifs();

/*
    test_afficher_bits

    Cette fonction permet de tester la fonction afficher_bits qui affiche les bits d'un entier par groupe de 4

    Paramètres:
        - Aucun

    Retour:
        - Aucun.
*/
static void test_afficher_bits();

/*
    test_afficher_entete_encodeur

    Cette fonction permet de tester la fonction afficher_entete_encodeur qui affiche une entete lorsque la fonction main
    est lancee


    Paramètres:
        - Aucun

    Retour:
        - Aucun.
*/
static void test_afficher_entete_encodeur();

/*
    test_decoder_mot_a429

    Cette fonction permet de tester la fonction decoder_mot_a429 qui decode un entier Hexadecimal suivant le protocole
    bcd ou bnr


    Paramètres:
        - Aucun

    Retour:
        - Aucun.
*/
static void test_decoder_mot_a429();

/*
    test_fonction_main

    Cette fonction permet de tester la fonction main du programme qui affiche le mot ARINC-429, l'etat de corruption et
    les donnees du mot en utilisant la fonction decoder_mot_a429


    Paramètres:
        - Aucun

    Retour:
        - Aucun.
*/
static void test_fonction_main();

int main(void)
{
    afficher_entete_test();

    int choix = -1;
    while (choix != 0)
    {
        printf("\nChoisissez le test que vous voulez executer: \n1: Test fonction afficher_heure\n2: Test fonction decimale_a_octale\n3: Test fonction calculer_nb_bits_actifs\n4: Test fonction afficher_bits"
               "\n5: Test fonction afficher_entete_encodeur\n6: Test fonction decoder_mot_a429\n7: Test fonction main 0 pour quitter : ");
        scanf("%d", &choix);

        if (choix == 0)
        {
            printf("Fin des tests.\n");
        }
        else if (choix == 1)
        {
            test_afficher_heure();
        }
        else if (choix == 2)
        {
            test_decimale_a_octale();
        }
        else if (choix == 3)
        {
            test_calculer_nb_bits_actifs();
        }
        else if (choix == 4)
        {
            test_afficher_bits();
        }
        else if (choix == 5)
        {
            test_afficher_entete_encodeur();
        }
        else if (choix == 6)
        {
            test_decoder_mot_a429();
        }
        else if (choix ==7)
        {
            test_fonction_main();
        }
        else {
            printf("Choix invalide. Veuillez choisir un nombre entre 1 et 6 ou 0 pour quitter.\n");
        }
    }

    return EXIT_SUCCESS;

}


static void afficher_entete_test()
{
    printf("***************************************************\n\n");
    printf("Pogramme execute en mode test\n");
    printf("Yoan Sapet & Alexis St-Pierre\n");
    printf("Session: Hiver 2024\n");
    printf("***************************************************\n\n");

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
    int nb_bits_actifs;

    printf("\n\nTest fonction calculer_nb_bits_actifs:\n");
    printf("Jeu d'essais\n");

    nb_bits_actifs= calculer_nb_bits_actifs(0x00000000);
    printf("\nEntree: 0x00000000 , Sortie attendu: %-3d, Sortie:%i", 0,nb_bits_actifs);

    nb_bits_actifs= calculer_nb_bits_actifs(0x00000001);
    printf("\nEntree: 0x00000001 , Sortie attendu: %-3d, Sortie:%i", 1,nb_bits_actifs);

    nb_bits_actifs= calculer_nb_bits_actifs(0x80000000);
    printf("\nEntree: 0x80000000 , Sortie attendu: %-3d, Sortie:%i", 1,nb_bits_actifs);

    nb_bits_actifs= calculer_nb_bits_actifs(0x12345678);
    printf("\nEntree: 0x12345678 , Sortie attendu: %-3d, Sortie:%i", 13,nb_bits_actifs);

    nb_bits_actifs= calculer_nb_bits_actifs(0xFFFFFFFF);
    printf("\nEntree: 0xFFFFFFFF , Sortie attendu: %-3d, Sortie:%i", 32,nb_bits_actifs);

}

static void test_afficher_bits()
{

    printf("\n\nTest fonction afficher bits:\n");
    printf("Jeu d'essais\n");

    printf("\nValeur: 0x12345678 ,Bit de depart: %-3d, Bit de fin: %-3d\n",0,31);
    printf("Affichage attendu: (0x12345678) : 0001 0010 0011 0100 0101 0110 0111 1000\n");
    printf("Affichage:         ");
    afficher_bits(0x12345678,0,31);

    printf("\n\nValeur: 0x9ABCDEF0 ,Bit de depart: %-3d, Bit de fin: %-3d\n",0,31);
    printf("Affichage attendu: (0x9ABCDEF0) : 1001 1010 1011 1100 1101 1110 1111 0000\n");
    printf("Affichage:         ");
    afficher_bits(0x9ABCDEF0,0,31);

    printf("\n\nValeur: 0xA3CF8643 ,Bit de depart: %-3d, Bit de fin: %-3d\n",4,15);
    printf("Affichage attendu: (0xA3CF8643) : 1000 0110 0100\n");
    printf("Affichage:         ");
    afficher_bits(0xA3CF8643,4,15);

    printf("\n\nValeur: 0xA3CF8643 ,Bit de depart: %-3d, Bit de fin: %-3d\n",31,31);
    printf("Affichage attendu: (0xA3CF8643) : 1\n");
    printf("Affichage:         ");
    afficher_bits(0xA3CF8643,31,31);

    printf("\n\nValeur: 0xA3CF8643 ,Bit de depart: %-3d, Bit de fin: %-3d\n",0,0);
    printf("Affichage attendu: (0xA3CF8643) : 1\n");
    printf("Affichage:         ");
    afficher_bits(0xA3CF8643,0,0);

}

static void test_afficher_entete_encodeur()
{
    printf("\n\nTest fonction afficher encodeur:\n");
    printf("Entete attendu:\n");

    printf("***************************************************\n");
    printf("Yoan Sapet & Alexis St-Pierre\n");
    printf("Session: Hiver 2024\n");
    printf("MOT ARINC-429 | Est Corrompu | Donnee\n");
    printf("***************************************************\n\n");
    printf("Entete recu apres appel de fonction:\n");
    afficher_entete_decodeur();
}

static void test_decoder_mot_a429()
{
    unsigned int entier_test;
    int est_corrompu;
    int numero_mot;
    double donnee_bnr;
    int donnee_bcd1;
    int donnee_bcd2;
    int donnee_bcd3;
    int donnee_bcd4;

    printf("\n\nTest fonction decoder mot a429:\n");
    printf("Jeu d'essai:\n");

    printf("Entree:\n");
    printf("Valeur: 0x85d3029, est_corrompu = ?, numero_mot = ?, donnee_bnr = ?, donnee_bcd1 = ?, donnee_bcd2 = ?, donnee_bcd3 = ?, donnee_bcd4 = ?\n");
    printf("Sortie attendu:\nest_corrompu = 0,numero_mot = 232,donnee_bnr = ?,donnee_bcd1 = 2,donnee_bcd2 = 24,donnee_bcd3 = 20,donnee_bcd4 = 11\n");
    printf("Sortie:\n");
    decoder_mot_a429(0x85D3029A,&est_corrompu,&numero_mot,&donnee_bnr,&donnee_bcd1,&donnee_bcd2,&donnee_bcd3,&donnee_bcd4);
    printf("est_corrompu = %d,numero_mot = %d,donnee_bnr = ?,donnee_bcd1 = %d,donnee_bcd2 = %d,donnee_bcd3 = %d,donnee_bcd4 = %d\n",est_corrompu,numero_mot,donnee_bcd1,donnee_bcd2,donnee_bcd3,donnee_bcd4);

    printf("\nEntree:\n");
    printf("Valeur: 0x003c90b0, est_corrompu = ?,numero_mot = ?, donnee_bnr = ?, donnee_bcd1 = ?, donnee_bcd2 = ?, donnee_bcd3 = ?, donnee_bcd4 = ?\n");
    printf("Sortie attendu:\nest_corrompu = 0,numero_mot = 260,donnee_bnr = ?,donnee_bcd1 = 16,donnee_bcd2 = 4,donnee_bcd3 = 15,donnee_bcd4 = 0\n");
    printf("Sortie:\n");
    decoder_mot_a429(0x003c90b0,&est_corrompu,&numero_mot,&donnee_bnr,&donnee_bcd1,&donnee_bcd2,&donnee_bcd3,&donnee_bcd4);
    printf("est_corrompu = %d,numero_mot = %d,donnee_bnr = ?,donnee_bcd1 = %d,donnee_bcd2 = %d,donnee_bcd3 = %d,donnee_bcd4 = %d\n",est_corrompu,numero_mot,donnee_bcd1,donnee_bcd2,donnee_bcd3,donnee_bcd4);

    printf("\nEntree:\n");
    printf("Valeur: 0x81eaf68, est_corrompu = ?, numero_mot = ?, donnee_bnr = ?, donnee_bcd1 = ?, donnee_bcd2 = ?, donnee_bcd3 = ?, donnee_bcd4 = ?\n");
    printf("Sortie attendu:\nest_corrompu = 0,numero_mot = 150,donnee_bnr = 77487.0 ,donnee_bcd1 = ?,donnee_bcd2 = ?,donnee_bcd3 = ?,donnee_bcd4 = ?\n");
    printf("Sortie:\n");
    decoder_mot_a429(0x812EAF68,&est_corrompu,&numero_mot,&donnee_bnr,&donnee_bcd1,&donnee_bcd2,&donnee_bcd3,&donnee_bcd4);
    printf("est_corrompu = %d,numero_mot = %d,donnee_bnr = %f,donnee_bcd1 = ?,donnee_bcd2 = ?,donnee_bcd3 = ?,donnee_bcd4 = ?\n",est_corrompu,numero_mot,donnee_bnr);

    printf("\nEntree:\n");
    printf("Valeur: 0x83D2E3C8, est_corrompu = ?, numero_mot = ?, donnee_bnr = ?, donnee_bcd1 = ?, donnee_bcd2 = ?, donnee_bcd3 = ?, donnee_bcd4 = ?\n");
    printf("Sortie attendu:\nest_corrompu = 0,numero_mot = 310,donnee_bnr = 43.102340 ,donnee_bcd1 = ?,donnee_bcd2 = ?,donnee_bcd3 = ?,donnee_bcd4 = ?\n");
    printf("Sortie:\n");
    decoder_mot_a429(0x83D2E3C8,&est_corrompu,&numero_mot,&donnee_bnr,&donnee_bcd1,&donnee_bcd2,&donnee_bcd3,&donnee_bcd4);
    printf("est_corrompu = %d,numero_mot = %d,donnee_bnr = %f,donnee_bcd1 = ?, onnee_bcd2 = ?,donnee_bcd3 = ?,donnee_bcd4 = ?\n",est_corrompu,numero_mot,donnee_bnr);

    printf("\nEntree:\n");
    printf("Valeur: 0x00261AAA, est_corrompu = ?, numero_mot = ?, donnee_bnr = ?, donnee_bcd1 = ?, donnee_bcd2 = ?, donnee_bcd3 = ?, donnee_bcd4 = ?\n");
    printf("Sortie attendu:\nest_corrompu = 1,numero_mot = 252,donnee_bnr = 9754.0,donnee_bcd1 = ?,donnee_bcd2 = ?,donnee_bcd3 = ?,donnee_bcd4 = ?\n");
    printf("Sortie:\n");
    decoder_mot_a429(0x00261AAA,&est_corrompu,&numero_mot,&donnee_bnr,&donnee_bcd1,&donnee_bcd2,&donnee_bcd3,&donnee_bcd4);
    printf("est_corrompu = %d, numero_mot = %d, donnee_bnr = %f, donnee_bcd1 = ?, donnee_bcd2 = ?, donnee_bcd3 = ?, donnee_bcd4 = ?\n",est_corrompu,numero_mot,donnee_bnr);

}

static void test_fonction_main()
{
    printf("\n\nTest fonction main:\n");
    printf("Jeu d'essai:\n");

    printf("Entree: 0x003c90b0\n");
    printf("Resultat attendu:\n0x3c90b0      |         NON| date du vol:            15/4/16\n");
    printf("Resultat obtenu:");
    afficher_mot_a429(0x003c90b0);

    printf("\n\nEntree: 0x811c6268\n");
    printf("Resultat attendu:\n0x811c6268      |          NON| Heure du vol:          20h13m22s\n");
    printf("Resultat obtenu:");
    afficher_mot_a429(0x811c6268);

    printf("\n\nEntree: 0x840834c8\n");
    printf("Resultat attendu:\n0x840834c8      |          NON| Latitude:          45.49968\n");
    printf("Resultat obtenu:\n");
    afficher_mot_a429(0x840834c8);

    printf("\n\nEntree: 0xe68b4bc9\n");
    printf("Resultat attendu:\n0xe68b4bc9      |          NON| Longitude:          -73.766500\n");
    printf("Resultat obtenu:");
    afficher_mot_a429(0xe68b4bc9);

    printf("\n\nEntree: 0x8001abaa\n");
    printf("Resultat attendu:\n0x8001abaa      |          NON| Altitude:          427.0\n");
    printf("Resultat obtenu:");
    afficher_mot_a429(0x8001abaa);

}

#endif
