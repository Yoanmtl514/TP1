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
#include "utilitaire.h"
#include "icd.h"

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

void decoder_mot_a429(unsigned int entier, int* est_corrompu, int* numero_mot, double* donnee_bnr, int* donnee_bcd1, int* donnee_bcd2, int* donnee_bcd3, int* donnee_bcd4)
{

//Variable pour le numero de mot pour les conditions BNR/BCD
    int num;

// ==== Requis 39: Etat de corruption du mot
    int corruption;
    *est_corrompu=1;
    //On obtiens l
    corruption = calculer_nb_bits_actifs(entier);

    if (corruption%2 !=0)
    {
        *est_corrompu=0;
    }
//==== Requis 32: numero de mot en base octale
    *numero_mot = decimale_a_octale(entier & 0xFF);

    num = *numero_mot;

    // Vérifier le type d'encodage
    if (num == NUMERO_MOT_UTC || num == NUMERO_MOT_ALTITUDE || num == NUMERO_MOT_LATITUDE || num == NUMERO_MOT_LONGITUDE)
    {
        if(num == NUMERO_MOT_UTC || num == NUMERO_MOT_ALTITUDE  )
        {
            *donnee_bnr = (double) ((entier >> 8) & 0x1FFFFF) * RESOLUTION_MOT_UTC ;
        }
        else if( num == NUMERO_MOT_LATITUDE || num == NUMERO_MOT_LONGITUDE)
        {
            *donnee_bnr = (double) ((entier >> 8) & 0x1FFFFF) * RESOLUTION_MOT_LATITUDE ;
        }
    }
        //Recuperation des donnees BCD
    else if (num == NUMERO_MOT_DEPART || num == NUMERO_MOT_DESTINATION || num == NUMERO_MOT_DATE) {
        // Format BCD
        *donnee_bcd1 = (entier >> 8) & 0x1F;   // Les bits 8 à 12
        *donnee_bcd2 = (entier >> 13) & 0x1F;   // Les bits 13 à 17
        *donnee_bcd3 = (entier >> 18) & 0x1F;
        *donnee_bcd4 = (entier >> 23) & 0x1F;
    }
}
