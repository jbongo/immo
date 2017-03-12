#ifndef IMMO_H_INCLUDED
#define IMMO_H_INCLUDED

typedef enum Type {  // Definition du type d'une annonce
        APPARTEMENT, MAISON
    }Type;

typedef struct Annonce {

    unsigned int numero_annonce;
    Type type;
    unsigned int nombre_piece;
    float surface_habitable;
    float montant_loyer_mensuel;
    float montant_charge_mensuel;
    struct Annonce *suivant;
}Annonce;

typedef Annonce *Liste;


void afficherAnnonce (Liste liste); // QUESTION 2

void afficherAnnonceSelonSurface(Liste liste); // QUESTION 5

void sauvegarderAnnonceFichier (Liste liste); //QUESTION 8



#endif // IMMO_H_INCLUDED
