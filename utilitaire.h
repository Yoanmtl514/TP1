/****************************************************************************************
/*                                      utilitaire.h                                       *
/****************************************************************************************
    Auteur : Yoan Sapet & Alexis St-Pierre
    Date   : 24 Janvier 2024


    Liste des fonctions publiques:


*****************************************************************************************/
#ifndef __H2024TP1_utilitaire__
#define __H2024TP1_utilitaire__

/*
    AFFICHER_HEURE

    Cette fonction permet d'afficher une heure au format 00h00m00s a partir d'un temps
    en secondes

    Paramètres:
        - Un entier  non signe representant le nombres de secondes a convertir

    Retour:
        - Aucun.

*/
void afficher_heure(unsigned int entier);

/*
    DECIMALE_A_OCTALE

    Cette fonction permet de convertir un entier non signe en base 10 en entier non signe de base 8

    Paramètres:
        - Un entier non signe en decimal

    Retour:
        - Un entier non signe en octal.

*/
int decimale_a_octale (unsigned int entier_decimal);

/*
    CALCULER_NB_BITS_ACTIFS

    Cette fonction permet de compter le nombre de bits actifs (bit ayant une valeur de 1) a partir d'un
    entier non signe.

    Paramètres:
        - Un entier non signe

    Retour:
        - Un entier non signe representant le nombre de bits actifs dans la valeur recu en parametre.

*/
int calculer_nb_bits_actifs( unsigned int valeur);

/*
    AFFICHER_BITS

    Cette fonction permet d'afficher une valeur recu en hexadecimal en valeur binaire regroupe par groupe de 4bits
    et ce du bit de depart souhaite jusuq'au bit de fin souhaite

    Paramètres:
        - Un entier non signe contenant la valeur a afficher.
        - Un entier représentant la position bit affiché ayant le poids le plus faible.
        - Un entier représentant la position bit affiché ayant le poids le plus fort.

    Retour:
        - Aucun.

*/
void afficher_bits ( unsigned int valeur, int bit_faible, int bit_fort);

#endif
