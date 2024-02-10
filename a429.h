/****************************************************************************************
/*                                      a429.h                                       *
/****************************************************************************************
    Auteur : Yoan Sapet & Alexis St-Pierre
    Date   : 24 Janvier 2024


    Liste des fonctions publiques:


*****************************************************************************************/
#ifndef __H2024TP1_a429__
#define __H2024TP1_a429__

/*
    AFFICHER_ENTETE_DECODEUR

    Cette fonction permet d'afficher une entete quand l'application est lancee

    Paramètres:
        - Aucun

    Retour:
        - Aucun.
*/
void afficher_entete_decodeur();

void afficher_mot_a429(unsigned int entier);

void decoder_mot_a429(unsigned entier, int* est_corrompi,int* numero_mot, double* donnee_bnr, int* donnee_bcd1, int* donnee_bcd2, int* donnee_bcd3, int* donnee_bcd4);

#endif
