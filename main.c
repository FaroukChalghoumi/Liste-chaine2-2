#include "header.h"

int main ()
{
    Liste tete = NULL ;
    Patient p;
    int rdv=0 ;
    int sansrdv=0;
    int choix ;

    do
    {
        do
        {
            printf("\n1.Saisir patient(test)");
            printf("\n2.Ajouter patient");
            printf("\n3.Compter les RDV");
            printf("\n4.Supprimer patient");
            printf("\n5.Sauvegarder patients");
            printf("\n6.Recupperer patients");
            printf("\n7.Afficher liste patients");
            printf("\n0.QUITTER");
            printf("\nTapez votre choix = ");
            scanf("%d",&choix);
            
        } while (choix<0 || choix>7);

        switch (choix)
            {
            case 1:
                saisirPatient(&p);
                afficherPatient(p);
                break;
            case 2:
                saisirPatient(&p);
                tete = AjoutPatient(tete , p);
                break;
            case 3 : 
                RendezVous(tete,&rdv,&sansrdv);
                break;
            case 4 :
                tete = SupprimerPatient(tete);
                break;
            case 5 :
                sauvgarderPatients(tete,"backup.txt");
                break; 
            case 6 :
                tete = recupererListePatients(tete , "backup.txt");
                break;
            case 7 : 
                afficher_liste(tete);
                break;
            
            default:
                break;
            }
        
    } while (choix !=0 );
    

    

    return 0 ;
}