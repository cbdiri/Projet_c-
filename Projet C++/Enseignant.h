#ifndef Enseignant_H
#define Enseignant_H

#include "Personne.h"

class Enseignant : public Personne{
public:
    int CNSS;
public:
    Enseignant();
    Enseignant(int a,char n[],char p[],char m[],int c);
    Enseignant operator <<(Enseignant E);

    void saisi(Enseignant e[],int *nb_en);
    void afficher_Enseignant(int nb_en);
    void supprimer_Enseignant(Enseignant e[],int *nb_en);
    void MAJ_Enseignant(Enseignant e[],int *nb_en);
    void chargement_Enseignants(Enseignant e[],int *nb_en);
};
#endif
