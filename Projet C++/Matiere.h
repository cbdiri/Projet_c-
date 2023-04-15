#ifndef Matiere_H
#define Matiere_H
#include "Enseignant.h"

class Matiere{
 public:
  char IdMat[5];
  char  NomMat[10];
  float Coef;
  Enseignant Ens;
 public:
    Matiere ();
    Matiere (char id[],char nom[],float c,Enseignant e );
    Matiere operator <<(Matiere m);

    void saisi_Matiere(Matiere ms[],int *nb_m, Enseignant ens[],int nb_en);
    void afficher_Matiere(int nb_m);

    void supprimer_Matiere(Matiere ms[],int *nb_m);

    void MAJ_Matiere(Matiere ms[],int *nb_m, Enseignant ens[],int nb_en);
    void chargement_Matieres(Matiere m[],int *nb_m);



};
#endif
