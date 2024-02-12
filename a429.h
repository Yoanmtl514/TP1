/****************************************************************************************
/*                                      a429.h                                          *
/****************************************************************************************
    Auteur : Yoan Sapet & Alexis St-Pierre
    Date   : 24 Janvier 2024


    Liste des fonctions publiques:
        - afficher_entete_decodeur
        - afficher_mot_a429
        - decoder_mot_a429

*****************************************************************************************/
#ifndef __H2024TP1_a429__
#define __H2024TP1_a429__

/*
    AFFICHER_ENTETE_DECODEUR

    Cette fonction permet d'afficher l'entete du decodeur quand l'application est lancee

    Paramètres:
        - Aucun

    Retour:
        - Aucun.
*/
void afficher_entete_decodeur();

/*
    AFFICHER_MOT_A429

    Cette fonction permet

    Paramètres:
        - Un entier non signé contenant le mot ARINC-429.

    Retour:
        - Aucun
*/
void afficher_mot_a429(unsigned int entier);

/*
    DECODER_MOT_A429

    Cette fonction permet de decoder un mot ARINC-429 et inscrire les valeurs dans des references soit BCD soit BNR dependamment du mot recu

    Paramètres:
        - Un entier non signé contenant le mot ARINC-429.
        - Une référence vers un entier dans laquelle l'état de corruption du mot sera inscrit.
        - Une référence vers un entier dans laquelle le numéro du mot sera inscrit.
        - Une référence vers un double dans laquelle la donnée du mot sera inscrite s'il est encodé dans le format BNR.
        - Quatre références vers des entiers dans lesquels seront inscrites les données du mot s'il est encodé dans le
          format BCD.

    Retour:
        - Aucun.
*/
void decoder_mot_a429(unsigned int entier, int* est_corrompu,int* numero_mot, double* donnee_bnr, int* donnee_bcd1, int* donnee_bcd2, int* donnee_bcd3, int* donnee_bcd4);

#endif
