
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
#include "decodeur/a429.h"
#include "udp/port_udp.h"

/****************************************************************************************
*                           DÉFINTION DES TYPES ET CONSTANTES                           *
****************************************************************************************/



/****************************************************************************************
*                           DÉFINITION DES FONCTIONS PUBLIQUES                          *
****************************************************************************************/


#if APPLICATION
int main(void)
{

    afficher_entete_decodeur();

    int id_port_udp = initialiser_port_udp(55001);

    while(1)
    {
    }
}
