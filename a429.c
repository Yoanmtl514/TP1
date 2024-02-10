/****************************************************************************************
/*                                      a429.c                                       *
/****************************************************************************************
    Auteur : Yoan Sapet & Alexis St-Pierre
    Date   : 24 Janvier 2024


    Liste des fonctions publiques:


*****************************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#include "a429.h"

//
// On affiche l'entete de l'application
//
void afficher_entete_decodeur()
{
    printf("Yoan Sapet & Alexis St-Pierre\n");
    printf("Session: Hiver 2024\n");
    printf("MOT ARINC-429 | Est Corrompu | Donnee\n");

}

void afficher_mot_a429(unsigned int entier)
{
    // Affichage des bits du mot ARINC-429
    for (int i = 32 - 1; i >= 0; i--) {
        printf("%d", (entier >> i) & 1);
        if (i % 4 == 0)
            printf(" "); // Ajouter un espace après chaque groupe de 4 bits
    }
}

void decoder_mot_a429(unsigned entier, int* est_corrompi,int* numero_mot, double* donnee_bnr, int* donnee_bcd1, int* donnee_bcd2, int* donnee_bcd3, int* donnee_bcd4)
{
    //obtention du mot en base hexa
    *numero_mot = entier & 0x1FF;

}

