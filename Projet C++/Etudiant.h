#ifndef Etudiant_H
#define Etudiant_H

#include "Personne.h"

class Etudiant : public Personne{
public:
    int Num_insc ;
public:
    Etudiant();
    Etudiant(int a,char n[],char p[],char m[],int num);
    Etudiant operator <<(Etudiant e);

    void saisi(Etudiant e[],int *nb_e);
    void supprimer_etudiant(Etudiant e[],int *nb_e);
    void afficher_etudiant(int nb_e);
    void MAJ_etudiant(Etudiant e[],int *nb_e);
    void chargement_etudiants(Etudiant e[],int *nb_e);
};
#endif
