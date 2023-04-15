#ifndef GroupeModule_H
#define GroupeModule_H

#include "Matiere.h"

class GroupeModule{
public:
    char IdGM[10];
    char NomGM[10];
    float CoefGM ;
    int nb;  // nbr des matiere du Module
    Matiere ListeMat[10];
public:
    GroupeModule();
    GroupeModule(char id[],char nom[],float c, Matiere l[]);
    GroupeModule operator <<(GroupeModule GM);

    void saisi_GroupeModule(GroupeModule gms[],int *nb_gm, Matiere ms[], int nb_m);
    void afficher_GroupeModule(int nb_gm);
    void supprimer_GroupeModule(GroupeModule gms[],int *nb_gm);
    void MAJ_GroupeModule(GroupeModule gms[],int *nb_gm, Matiere ms[], int nb_m);
    void chargement_GroupeModule(GroupeModule gms[],int *nb_gm,Matiere ms[], int nb_m);


};
#endif
