#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//************************************Includes************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//************************************Structs************************************

typedef struct 
{
    char nom[20];
    char prenom[20];
    int rdv;
}Patient;

struct Cellule
{
    Patient data;
    struct Cellule* next;
};

typedef struct Cellule* Liste;

//************************************Fuctions************************************
void saisirPatient(Patient *p);
void afficherPatient(Patient p);
Liste AjoutPatient(Liste tete , Patient p);
void RendezVous(Liste tete , int *rdv , int * sansrdv);
Liste SupprimerPatient (Liste tete);
void sauvgarderPatients( Liste tete , char *chemin );
Liste recupererListePatients( Liste tete , char *chemin );
void afficher_liste(Liste tete);







#endif