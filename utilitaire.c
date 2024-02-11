/****************************************************************************************
/*                                      UTILITAIRE.C                                    *
/****************************************************************************************
Auteur : Yoan Sapet & Alexis St-Pierre
Date   : 24 Janvier 2024

Fonction publique:

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

    while (entier_decimal != 0) {
        entier_octal = entier_octal +  (entier_decimal % 8) * i;
        entier_decimal = entier_decimal / 8;
        i = i*10;
    }

    return entier_octal;
}

//
// Calcul le nombre de bits actifs d'un entier donne
//
int calculer_nb_bits_actifs( unsigned int valeur)
{
    int compteur=0;

    while ( valeur != 0)
    {
       if (valeur%2 ==1)
       {
           compteur++;
       }

       valeur = valeur/2;

    }

    return compteur;

}

void afficher_bits(unsigned int valeur, int bit_depart, int bit_fin) {

    printf("(0x%08X) : ", valeur);

    for (int i = bit_fin; i >= bit_depart; i--) {
        printf("%d", (valeur >> i) & 1);

        //Pour afficher des groupes de 4 bits,
        if ((i - bit_depart) % 4 == 0 && i != bit_depart)
            printf(" ");
    }

}
