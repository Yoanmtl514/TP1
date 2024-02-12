/****************************************************************************************
/*                                      a429.c                                       *
/****************************************************************************************
    Auteur : Yoan Sapet & Alexis St-Pierre
    Date   : 24 Janvier 2024


    Liste des fonctions publiques:
        - afficher_entete_decodeu
        - afficher_mot_a429
        - decoder_mot_a429

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
    printf("***************************************************\n");
    printf("Yoan Sapet & Alexis St-Pierre\n");
    printf("Session: Hiver 2024\n");
    printf("MOT ARINC-429 | Est Corrompu | Donnee\n");
    printf("***************************************************\n");

}

//
//On afficher le mot ARINC-429 en hexacimal, l'etat de corruption, et la donnee extraite
//
void afficher_mot_a429(unsigned int entier)
{

    //Creation de variables necessaires a l'envois et reception de donnee de la fonctions decode mot
    int est_corrompu, numero_mot;
    double donnee_bnr;
    int donnee_bcd1, donnee_bcd2,donnee_bcd3,donnee_bcd4;

    decoder_mot_a429(entier,&est_corrompu,&numero_mot,&donnee_bnr, &donnee_bcd1,&donnee_bcd2,&donnee_bcd3,&donnee_bcd4);


    //Comme les chaines de caracteres n'ont pas ete vu de maniere trop poussees durant le cours on a pour chaque cas deux
    //conditions pour l'affichage de l'etat de corruption (Oui ou Non)

    //Quand numero_mot = 150, on affiche l'heure en utilisant la fonction afficher_heure a la laquelle on donne l'entier
    //contenu dans la variable donnee_bnr
    if(numero_mot == NUMERO_MOT_UTC)
    {
        if(est_corrompu==1)
        {
            printf("\n\n0x%X    |           OUI| Heure du vol:           ",entier);
            afficher_heure(donnee_bnr);
        }
        else
        {
            printf("\n\n0x%X    |           NON| Heure du vol:           ",entier);
            afficher_heure(donnee_bnr);
        }
    }

    //Quand  numero_mot = 232 On affiche l'aeroport de depart en utilisant les donnee_bcd auquel on ajoute A
    else if( numero_mot == NUMERO_MOT_DEPART)
    {
        if(est_corrompu==1)
        {
            printf("\n0x%X    |           OUI| Depart de l'aeroport:   %i%i%i%i",entier,donnee_bcd1+'A',donnee_bcd2+'A', donnee_bcd3+'A', donnee_bcd4+'A');
        }
        else
        {
            printf("\n0x%X    |           NON| Depart de l'aeroport:   %i%i%i%i",entier,donnee_bcd1+'A',donnee_bcd2+'A', donnee_bcd3+'A', donnee_bcd4+'A');
        }

    }

    //Quand le numero_mot= 252 on affiche l'altitude en utilisant la variable donnee_bnr
    else if( numero_mot == NUMERO_MOT_ALTITUDE)
    {
        if(est_corrompu==1)
        {
            printf("\n0x%X    |           OUI| Altitude:               %f",entier,donnee_bnr);
        }
        else
        {
            printf("\n0x%X    |           NON| Altitude:               %f",entier,donnee_bnr);
        }
    }

    //Quand le numero_mot= 255 on affiche l'aeroport de destination en utilisant les  donnee_bcd auquel on ajoute A
    else if( numero_mot == NUMERO_MOT_DESTINATION)
    {
        if(est_corrompu==1)
        {
            printf("\n0x%X    |           OUI| Arrive a l'aeroport:    %i%i%i%i",entier,donnee_bcd1+'A',donnee_bcd2+'A', donnee_bcd3+'A', donnee_bcd4+'A');
        }
        else
        {
            printf("\n0x%X    |              | Arrive a l'aeroport:    %i%i%i%i",entier,donnee_bcd1+'A',donnee_bcd2+'A', donnee_bcd3+'A', donnee_bcd4+'A');
        }
    }

    //Quand numero_mot= 260 on affiche la date en utilisant les  donnee_bcd.
    //donnee_bcd3 = l'annee, donnee_bcd2 = le mois et donnee_bcd1 = le jour (donnee_bcd4 est ici inutilise)
    else if( numero_mot == NUMERO_MOT_DATE)
    {
        if(est_corrompu==1)
        {
            printf("\n0x%X      |           OUI| Date du vol:            %i/%i/%i",entier,donnee_bcd3,donnee_bcd2,donnee_bcd1);
        }
        else
        {
            printf("\n0x%X      |           NON| Date du vol:            %i/%i/%i",entier,donnee_bcd3,donnee_bcd2,donnee_bcd1);
        }

    }

    //Quand numero_mot= 310 on affiche la latitude en utilisant la variable donnee_bnr
    else if( numero_mot == NUMERO_MOT_LATITUDE)
    {
        if(est_corrompu==1)
        {
            printf("0x%X    |           OUI| Lattitude:              %f",entier,donnee_bnr);
        }
        else
        {
            printf("0x%X    |           NON| Lattitude:              %f",entier,donnee_bnr);
        }

    }

    //Quand numero_mot= 311 on affiche la longitude en utilisant la variable donnee_bnr
    else if( numero_mot == NUMERO_MOT_LONGITUDE)
    {
        if(est_corrompu==1)
        {
            printf("\n0x%X    |           OUI| Longitude:              %f",entier,donnee_bnr);
        }
        else
        {
            printf("\n0x%X    |           NON| Longitude:              %f",entier,donnee_bnr);
        }
    }

}

//
//Fonction pour decoder le mot recu en ARINC-429
//
void decoder_mot_a429(unsigned int entier, int* est_corrompu, int* numero_mot, double* donnee_bnr, int* donnee_bcd1, int* donnee_bcd2, int* donnee_bcd3, int* donnee_bcd4)
{

    //Variable pour le numero de mot pour les conditions BNR/BCD
    int num;

    // Variable pour l'etat de corruption du mot
    int corruption;

    //On part du principe que le mot est corrompu on met la variable a 1
    *est_corrompu=1;

    //Un mot etant corrompu lorsque le mot a nombre de bits actif est pair, on calcul donc son nombre de bits
    corruption = calculer_nb_bits_actifs(entier);

    //Si on a un nombre pair de bits dans le mot on mets l'etat de corruption a 0
    if (corruption%2 !=0)
    {
        *est_corrompu=0;
    }

    //On converti le mot dans une base octale pour savoir quel donnee on doit extraire du mot
    *numero_mot = decimale_a_octale(entier & 0xFF);

    //Variable pour gerer les cas de donnee
    num = *numero_mot;

    //On veririfie les types d'encodages, si le numero de mot est egale a 150,252,310, ou 311 on decode le mot sous
    //un format BNR
    if (num == NUMERO_MOT_UTC || num == NUMERO_MOT_ALTITUDE || num == NUMERO_MOT_LATITUDE || num == NUMERO_MOT_LONGITUDE)
    {

        // Si le mot a une valeur de 150 ou 252
        if(num == NUMERO_MOT_UTC || num == NUMERO_MOT_ALTITUDE  )
        {
            //On utilise double pour convertir le resultat de l'expression
            //On decale les bits de l'entier de 8 position vers la droite puis on utilise un masque pour conserver
            //les 21bits suivants a gauche
            *donnee_bnr = (double) ((entier >> 8) & 0x1FFFFF) * RESOLUTION_MOT_UTC ;
        }

            // Si le mot a une valeur de 310 ou 311
        else if( num == NUMERO_MOT_LATITUDE || num == NUMERO_MOT_LONGITUDE)
        {
            //On cree deux variable pour extraire les bits 29 et 30 et connaitre le signe de l'entier
            int ss_1 = (entier >> 29) & 0x01; // 29ème bit
            int ss_2 = (entier >> 30) & 0x01; // 30ème bit

            //si les bits 29 et 30 sont a 1 on a un chiffre negatif
            if (ss_1 == 1 && ss_2 ==1)
            {
                //On mets un - pour avoir un chiffre negatif
                //On utilise double pour convertir le resultat de l'expression
                //On decale les bits de l'entier de 8 position vers la droite puis on utilise un masque pour conserver
                //les 21bits suivants a gauche
                *donnee_bnr = -((double)((entier >> 8) & 0x1FFFFF)) * RESOLUTION_MOT_LATITUDE;
            }

            //Sinon on a un chiffre positife
            else {

                //On mets un - pour avoir un chiffre negatif
                //On utilise double pour convertir le resultat de l'expression
                //On decale les bits de l'entier de 8 position vers la droite puis on utilise un masque pour conserver
                //les 21bits suivants a gauche
                *donnee_bnr = (double)((entier >> 8) & 0x1FFFFF) * RESOLUTION_MOT_LATITUDE;
            }
        }
    }


    //On veririfie les types d'encodages, si le numero de mot est egale a 232,255,ou 260 on decode le mot sous
    //un format BCD
    else if (num == NUMERO_MOT_DEPART || num == NUMERO_MOT_DESTINATION || num == NUMERO_MOT_DATE) {

        //On donne a la variable donnee_bcd1 la valeur contenu dans les bits 8 a 12
        *donnee_bcd1 = (entier >> 8) & 0x1F;

        //On donne a la variable donnee_bcd2 la valeur contenu dans les bits 13 a 17
        *donnee_bcd2 = (entier >> 13) & 0x1F;

        //On donne a la variable donnee_bcd3 la valeur contenu dans les bits 18 a 22
        *donnee_bcd3 = (entier >> 18) & 0x1F;

        //On donne a la variable donnee_bcd4 la valeur contenu dans les bits 23 a 18
        *donnee_bcd4 = (entier >> 23) & 0x1F;
    }
}
