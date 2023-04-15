#ifndef Note_H
#define Note_H

#include "Matiere.h"
#include "Etudiant.h"

class Note{
 public:
     Matiere Mat;
     Etudiant Etu;
     float Nt;
     char Type[10];
 public:
    Note();
    Note(Matiere m,Etudiant e,float n, char t[]);
    Note operator <<(Note n);

    void saisi_Note(Note ns[],int *nb_n, Matiere ms[], int nb_m ,Etudiant es[], int nb_e);
    void afficher_Note(Note ns[],int nb_n);
    void supprimer_Note(Note ns[],int *nb_gn);
    void MAJ_Note(Note ns[],int *nb_n, Matiere ms[], int nb_m ,Etudiant es[], int nb_e);
    void chargement_Note(Note ns[],int *nb_n, Matiere ms[], int nb_m ,Etudiant es[], int nb_e);


};
#endif
