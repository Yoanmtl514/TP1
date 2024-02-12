/****************************************************************************************
/*                                      UTILITAIRE.C                                    *
/****************************************************************************************
Auteur : Yoan Sapet & Alexis St-Pierre
Date   : 24 Janvier 2024

Fonction publique:
    - afficher_heure
    - decimale_a_octale
    - calculer_nb_bits_actifs
    - afficher_bits

Ce module contient les fonctions utilitaires du projet
*****************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "utilitaire.h"

//
// Converti des secondes en heures et affiche l'heure au format 00h00m00s
//
void afficher_heure(unsigned int entier)
{
    int h, m, s;

    // Calcul des heures, minutes et secondes
    h = entier / 3600;
    m = (entier % 3600) / 60;
    s = entier % 60;

    // Affichage des heures, minutes et secondes avec deux chiffres et les unités
    printf("%02dh%02dm%02ds\n", h, m, s);
}

//
// Converti un entier non signe en base 10 en entier non signer en base 8
//
int decimale_a_octale (unsigned int entier_decimal)
{
    int entier_octal = 0;
    int i = 1;

    // Tant que l'entier décimal n'est pas égal à zéro
    while (entier_decimal != 0) {

        // Calcul de l'entier octalt  en divisant l'entier decimal par 8 et en prenant le reste puis on mutiplie par i
        // pour le mettre a la bonne position
        entier_octal = entier_octal +  (entier_decimal % 8) * i;

        // Division de l'entier décimal par 8 pour passer au prochain chiffre
        entier_decimal = entier_decimal / 8;

        // Multiplication du multiplicateur par 10 pour passer à la position suivante
        i = i*10;
    }

    //Retourne la valeur de l'entier converti en octal
    return entier_octal;
}

//
// Calcul le nombre de bits actifs d'un entier donne
//
int calculer_nb_bits_actifs( unsigned int valeur)
{
    int compteur=0;

    // Boucle tant que la valeur n'est pas égale à zéro
    while ( valeur != 0)
    {
        //On verifie si le bit le plus a droite a comme valeur 1
       if (valeur%2 ==1)
       {
           //si c'est le cas on incremente le compteur de une
           compteur++;
       }

       //On divise la valeur par deux pour "decaler" les bits vers la droite
       valeur = valeur/2;

    }

    //On retourne un entier contenant le nombre de bits actifs dans la valeur
    return compteur;

}

//
//affiche les bits d'une valeur par paquet de 4 et ce a partir d'un bit de depart et jusqu'a un bit de fin voulue
//
void afficher_bits(unsigned int valeur, int bit_depart, int bit_fin) {

    //On affiche d'abord la valeur dans un format hexa-decimal avec un format de 8chiffres
    printf("(0x%08X) : ", valeur);

    //On parcous tout les bits , du bit de fin jusqu'au bit de depart
    for (int i = bit_fin; i >= bit_depart; i--)
    {
        //Affichage du bit actuel en prenant la valeur decale de i position vers la droite, et en prenant le bit de poids
        //le plus faible avec & avec 1
        printf("%d", (valeur >> i) & 1);

        //Pour afficher des groupes de 4 bits, si on a un multiple de 4 on mets un espace
        if ((i - bit_depart) % 4 == 0)
            printf(" ");
    }

}
