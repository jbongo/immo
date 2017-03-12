#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "immo.h"


// AFFICHAGE DE TOUTES LES ANNONCES
void afficherAnnonce (Liste  liste){

    Annonce *annonceActuelle = liste;

    if (annonceActuelle != NULL){


    unsigned int nombre_piece;

        int cpt = 1;
        while (annonceActuelle->suivant !=NULL)
        {
            printf(" \n\n | %d  | \n\n",cpt);

            printf("Numero annonce : %d \n",annonceActuelle->numero_annonce);
            printf("Type annonce : %d \n",annonceActuelle->type);
            printf("Nombre piece : %d \n",annonceActuelle->numero_annonce);
            printf("Surface habitable : %f \n",annonceActuelle->surface_habitable);
            printf("Montant loyer mensuel : %f \n",annonceActuelle->montant_loyer_mensuel);
            printf("Montant charge mensuelle : %f \n",annonceActuelle->montant_charge_mensuel);

            cpt++;
            annonceActuelle = annonceActuelle->suivant;
        }
    }
}

void afficherAnnonceSelonSurface(Liste liste){

    float surfaceMIN;

    do{
        printf("Surface habitable minimale (postif et > 0)  ?:  ");
        scanf("%f",&surfaceMIN);
    } while(surfaceMIN <=0);

    Annonce *annonceActuelle = liste;

    if(annonceActuelle !=NULL){

        int cpt = 0;


        while(annonceActuelle->suivant!=NULL){

                if(annonceActuelle->surface_habitable >= surfaceMIN){




                    cpt++;
                    printf(" \n\n | %d  | \n\n",cpt);

                    printf("Numero annonce : %d \n",annonceActuelle->numero_annonce);

                    if(annonceActuelle->type == 0){
                        printf("Type annonce : APPARTEMENT \n");
                    }
                    else if(annonceActuelle->type == 1)
                    {
                    printf("Type annonce : MAISON \n");
                    }
                    printf("Nombre piece : %d \n",annonceActuelle->numero_annonce);
                    printf("Surface habitable : %f \n",annonceActuelle->surface_habitable);
                    printf("Montant loyer mensuel : %f \n",annonceActuelle->montant_loyer_mensuel);
                    printf("Montant charge mensuelle : %f \n",annonceActuelle->montant_charge_mensuel);

                    annonceActuelle = annonceActuelle->suivant;
                }


        }
    }

    void sauvegarderAnnonceFichier (Liste liste){

        Annonce *annonceActuelle = liste;

        if(annonceActuelle != NULL){

            FILE *fichier= NULL;

            fichier = fopen("sauvegarde.txt","a");

            if(fichier == NULL){
                exit(EXIT_FAILURE);
            }

            while(annonceActuelle->suivant ){

                fprintf(fichier,"%d\t %s \t %d \t %f\t f% \t%f \t \n",
                        annonceActuelle->numero_annonce,
                        annonceActuelle->type,
                        annonceActuelle->numero_annonce,
                        annonceActuelle->surface_habitable,
                        annonceActuelle->montant_loyer_mensuel,
                        annonceActuelle->montant_charge_mensuel

                        );

                annonceActuelle = annonceActuelle->suivant;

            }

                fclose(fichier);

        }

    }


}

