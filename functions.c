#include "header.h"

void saisirPatient(Patient *p)
{
    printf("\n NOM = ");
    fflush(stdin);
    gets(p->nom);
    printf("\n PRENOM = ");
    fflush(stdin);
    gets(p->prenom);
    printf("\n*********************************************\n0.Sans RDV\n1.Avec RDV\n RDV =");
    scanf("%d",&p->rdv);

}

void afficherPatient(Patient p)
{
    printf("\n NOM = %s ",p.nom);
    printf("\n PRENOM = %s ",p.prenom);
    printf("\n RDV = %d",p.rdv);
}

Liste AjoutPatient(Liste tete , Patient p)
{
    struct Cellule *ptr=NULL;
    struct Cellule *parcour;

    ptr = (struct Cellule*)malloc(sizeof(struct Cellule));

    if(ptr == NULL)
        exit(EXIT_FAILURE);
        else 
        {
            ptr->data = p ; 
            ptr->next = NULL ; 
        }
    if (tete == NULL)
    {      
        tete = ptr;
    }
    else 
    {
        parcour = tete ; 
        while (parcour->next != NULL)
        {
            parcour = parcour->next;
        }
        
        parcour->next = ptr ;
    }
    return tete;
}

void RendezVous(Liste tete , int *rdv , int *sansrdv)
{
    struct Cellule *ptr;
    if(tete == NULL)
        printf("\n Liste vide ! ");
        else 
        {
            ptr = tete ; 
            while (ptr != NULL )
            {
                if ( ptr->data.rdv == 0 )
                    (*rdv)++;
                    else if ( ptr->data.rdv == 1)
                        (*sansrdv)++;

                ptr = ptr->next ; 
            }
        }
}

Liste SupprimerPatient (Liste tete)
{
    struct Cellule *ptr1 , *ptr2 /*, *ptr , *temp*/; 
    int test = 0 ;
    if(tete == NULL)
        {
            printf("\n Liste vide ! ");
            return NULL;
        }
        else
        {
            //###############################1ere methode boucle while###################################
            /*ptr = tete ; 
            while (ptr->next != NULL)
            {
                if ( ptr->next->data.rdv == 1 )
                {
                    temp = ptr->next;
                    ptr->next = ptr->next->next;
                    free(temp);
                    test =1 ;
                    break;
                }
                
            }

            */
             
            
            ptr1 = tete ;
            ptr2 = tete->next ; 
            while ( ptr2 != NULL )
            {
                if ( ptr2->data.rdv == 1 )
                    {
                        ptr1->next = ptr2->next;
                        free(ptr2);
                        test = 1 ;
                        break;
                    }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            if ( test == 0 )
            {
                ptr1 = tete ; 
                tete = tete->next;
                free(ptr1);
            }
 
            return tete;
            
        } 
    
}

void sauvgarderPatients( Liste tete , char *chemin )
{
    FILE *f;
        struct Cellule *ptr;

    f = fopen(chemin,"a");
    if ( f==NULL )
        printf("\nChemin inexistant ! ");
        else 
        {
                if(tete == NULL)
                    fclose(f);
                    else
                    {
                        ptr = tete ; 
                        while( ptr != NULL )
                        {
                            fprintf(f,"%s\t%s\t\t%d\n",ptr->data.nom,ptr->data.prenom,ptr->data.rdv);
                            ptr = ptr->next;
                        }
                        fclose(f);
                    }
        }
}


Liste recupererListePatients( Liste tete , char *chemin )
{
 FILE *f;
        struct Cellule *parcour ;
        Patient p;
    f = fopen(chemin,"r");
    if ( f==NULL )
        printf("\nChemin inexistant ! ");
        else
        {
            while ( feof(f)==0 )
            {
                fscanf(f,"%s\t%s\t\t%d\n",p.nom,p.prenom,&p.rdv);
                
                //NOTES : 
                    //Cette condition sert a remplir une nouvelle liste d'un ficher externe 
                    //mais le probleme c'est que lors de remplissage du fichier de recupperation la liste va etre inversée
                    //donc je serait obligé a chaque fois de faire l'ajout a la fin pour que je puisse trouver la meme liste
                tete = AjoutPatient(tete , p);  
                
                //##################1ere methode pour inverser la liste( boucle infinie )######################
               /* 
                if ( tete == NULL )
                    tete = ptr;
                    else 
                    {
                        parcour = tete ; 
                        
                        while ( parcour != NULL)
                            parcour = parcour->next;

                        parcour->next = ptr ;                        
                    }
                */

              
            }

            fclose(f);
            return tete ;            
        } 
   
}


void afficher_liste(Liste tete)
{
    Liste ptr;
    ptr = tete ; 
    while (ptr != NULL)
    {
        afficherPatient(ptr->data);
        ptr = ptr->next;
    }
    
}