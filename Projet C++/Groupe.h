#ifndef Groupe_H
#define Groupe_H

#include "GroupeModule.h"
#include "Etudiant.h"

class Groupe{
 public:
    char IdGRP[10];
    char Niveau[10];
    char Diplome[10];
    char Specialite[10];
    int Num_G;
    GroupeModule ListeModules[15];
    int nb_gs; //nbrs des Group_Module associer
    Etudiant ListeEtudiants[50];
    int nb_es;  //nbrs des Etudiant associer
 public:
    Groupe();
    Groupe(char id[],char nv[],char dp[],char sp[],int nm, GroupeModule lm[],Etudiant lE[]);
    Groupe operator <<(Groupe g);


    void saisi_Groupe(Groupe gs[],int *nb_g, GroupeModule gms[], int nb_gm ,Etudiant es[], int nb_e );
    void afficher_Groupe(Groupe gs[],int nb_g);
    void supprimer_Groupe(Groupe gs[],int *nb_g);
    void MAJ_Groupe(Groupe gs[],int *nb_g, GroupeModule gms[], int nb_gm ,Etudiant es[], int nb_e);
    void chargement_Groupe(Groupe gs[],int *nb_g,GroupeModule gms[], int nb_gm,Etudiant es[], int nb_e);


};
#endif // Groupe_H
