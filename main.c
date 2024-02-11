/****************************************************************************************
/*                                      MAIN                                            *
/****************************************************************************************
Auteur : Yoan Sapet & Alexis St-Pierre
Date   : 24 Janvier 2024

Cette application permet de créer des vecteur et de les modifier tout en gardant
leur 4 composantes cohérentes l'une par rapport à l'autre.

*****************************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#include "configuration.h"

#include "C:/Users/Yoan/Desktop/INF147/H2024TP1/decodeur/a429.h"
#include "udp\port_udp.h"

/****************************************************************************************
*                           DÉFINTION DES TYPES ET CONSTANTES                           *
****************************************************************************************/



/****************************************************************************************
*                           DÉFINITION DES FONCTIONS PUBLIQUES                          *
****************************************************************************************/


#if APPLICATION
int main(void)
{
    //Requis 26 : afficher l'entete du decodeur
    afficher_entete_decodeur();

    //Requis 27 initialiser le port UDP 55001
    int id_port_udp = initialiser_port_udp(55001);

    //Requis 28: Lecture continue sur le port udp 5501

    while(1)
    {
        int mot_arinc429;
        // Lecture sur le port UDP 5501
        recevoir_port_udp(id_port_udp, &mot_arinc429, sizeof(unsigned int));

        // Requis 29 : Afficher les mots ARINC-429 reçus
        afficher_mot_a429(mot_arinc429);
    }

}


#endif
