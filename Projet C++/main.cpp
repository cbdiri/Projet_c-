#include <iostream>
#include "Etudiant.h"
#include "Enseignant.h"
#include "Matiere.h"
#include "GroupeModule.h"
#include "Groupe.h"
#include "Note.h"
#include "Pv.h"

using namespace std;


int main()
{
    int o=0;
    int nb_e=0;
    int nb_en=0;
    int nb_m=0;
    int nb_gm=0;
    int nb_g=0;
    int nb_n=0;

    Etudiant e;
    Enseignant en;
    Matiere m;
    GroupeModule gm;
    Groupe g;
    Note n;

    Etudiant es[20];
    e.chargement_etudiants(es,&nb_e);

    Enseignant ens[20];
    en.chargement_Enseignants(ens,&nb_en);

    Matiere ms[20];
    m.chargement_Matieres(ms,&nb_m);

    GroupeModule gms[20];
    gm.chargement_GroupeModule(gms,&nb_gm,ms,nb_m);

    Groupe gs[20];
    g.chargement_Groupe(gs,&nb_g,gms,nb_gm,es,nb_e);

    Note ns[100];
    n.chargement_Note(ns,&nb_n,ms,nb_m,es,nb_e);


while(1){
    menu_principal:
    o=0;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t**********************************    welocom    **********************************"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t*                                                                                 *"<<endl;
    cout<<"\t\t\t* - Tapez [1] pour Ajout/ Suppression/ MAJ un Etudiant                            *"<<endl;
    cout<<"\t\t\t* - Tapez [2] pour Ajout/ Suppression/ MAJ un Enseignant                          *"<<endl;
    cout<<"\t\t\t* - Tapez [3] pour Ajout/ Suppression/ MAJ une Matiere                            *"<<endl;
    cout<<"\t\t\t* - Tapez [4] pour Ajout/ Suppression/ MAJ un GroupeModule                        *"<<endl;
    cout<<"\t\t\t* - Tapez [5] pour Ajout/ Suppression/ MAJ un Groupe                              *"<<endl;
    cout<<"\t\t\t* - Tapez [6] pour Ajout/ Suppression/ MAJ une NOTE                               *"<<endl;
    cout<<"\t\t\t* - Tapez [7] pour Afficher le PV                                                 *"<<endl;
    cout<<"\t\t\t* - Tapez [8] pour Quiter                                                         *"<<endl;
    cout<<"\t\t\t*                                                                                 *"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cin>>o;
    system("@cls||clear");


    if(o==1)
        {
    menu_Etudiant:
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t**********************************    Etudiant    **********************************"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t*                                                                                 *"<<endl;
    cout<<"\t\t\t* - Tapez [1] pour Ajout d un Etudiant                                            *"<<endl;
    cout<<"\t\t\t* - Tapez [2] pour Suppression d un Etudiant                                      *"<<endl;
    cout<<"\t\t\t* - Tapez [3] pour MAJ d un  Etudiant                                             *"<<endl;
    cout<<"\t\t\t* - Tapez [4] pour afficher les  Etudiant                                         *"<<endl;
    cout<<"\t\t\t* - Tapez [5] pour retourner au menu principal                                    *"<<endl;
    cout<<"\t\t\t* - Tapez [6] pour Quiter                                                         *"<<endl;
    cout<<"\t\t\t*                                                                                 *"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cin>>o;

    if(o==1){system("@cls||clear");      e.saisi(es,&nb_e);                   e.chargement_etudiants(es,&nb_e);       goto menu_Etudiant;}
    else if(o==2){system("@cls||clear"); e.supprimer_etudiant(es,&nb_e);      e.chargement_etudiants(es,&nb_e);       goto menu_Etudiant;}
    else if(o==3){system("@cls||clear"); e.MAJ_etudiant(es,&nb_e);            e.chargement_etudiants(es,&nb_e);       goto menu_Etudiant;}
    else if(o==4){system("@cls||clear"); e.afficher_etudiant(nb_e);                                                   goto menu_Etudiant;}
    else if(o==5){system("@cls||clear");                                                                              goto menu_principal;}
    else if(o==6){system("@cls||clear");                                                                              goto exit;}
        }

    else if(o==2)
        {
    menu_Enseignant:
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t**********************************  Enseignant   **********************************"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t*                                                                                 *"<<endl;
    cout<<"\t\t\t* - Tapez [1] pour Ajout d un Enseignant                                          *"<<endl;
    cout<<"\t\t\t* - Tapez [2] pour Suppression d un Enseignant                                    *"<<endl;
    cout<<"\t\t\t* - Tapez [3] pour MAJ d un  Enseignant                                           *"<<endl;
    cout<<"\t\t\t* - Tapez [4] pour afficher les  Enseignant                                       *"<<endl;
    cout<<"\t\t\t* - Tapez [5] pour retourner au menu principal                                    *"<<endl;
    cout<<"\t\t\t* - Tapez [6] pour Quiter                                                         *"<<endl;
    cout<<"\t\t\t*                                                                                 *"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cin>>o;

        if(o==1){system("@cls||clear");      en.saisi(ens,&nb_en);                en.chargement_Enseignants(ens,&nb_en);         goto menu_Enseignant;}
        else if(o==2){system("@cls||clear"); en.supprimer_Enseignant(ens,&nb_en); en.chargement_Enseignants(ens,&nb_en);         goto menu_Enseignant;}
        else if(o==3){system("@cls||clear"); en.MAJ_Enseignant(ens,&nb_en);       en.chargement_Enseignants(ens,&nb_en);         goto menu_Enseignant;}
        else if(o==4){system("@cls||clear"); en.afficher_Enseignant(nb_en);  goto menu_Enseignant;}
        else if(o==5){system("@cls||clear"); goto menu_principal;}
        else if(o==6){system("@cls||clear"); goto exit;}

        }

    else if(o==3)
        {
         menu_Matiere:
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t**********************************    Matiere    **********************************"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t*                                                                                 *"<<endl;
    cout<<"\t\t\t* - Tapez [1] pour Ajout d un Matiere                                             *"<<endl;
    cout<<"\t\t\t* - Tapez [2] pour Suppression d un Matiere                                       *"<<endl;
    cout<<"\t\t\t* - Tapez [3] pour MAJ d un  Matiere                                              *"<<endl;
    cout<<"\t\t\t* - Tapez [4] pour afficher les  Matiere                                          *"<<endl;
    cout<<"\t\t\t* - Tapez [5] pour retourner au menu principal                                    *"<<endl;
    cout<<"\t\t\t* - Tapez [6] pour Quiter                                                         *"<<endl;
    cout<<"\t\t\t*                                                                                 *"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cout<<"\t\t\t***********************************************************************************"<<endl;
    cin>>o;
        if(o==1){system("@cls||clear");         m.saisi_Matiere(ms,&nb_m,ens,nb_en);       m.chargement_Matieres(ms,&nb_m);             goto menu_Matiere;}
        else if(o==2){system("@cls||clear");    m.supprimer_Matiere(ms,&nb_m);             m.chargement_Matieres(ms,&nb_m);             goto menu_Matiere;}
        else if(o==3){system("@cls||clear");    m.MAJ_Matiere(ms,&nb_m,ens,nb_en);         m.chargement_Matieres(ms,&nb_m);             goto menu_Matiere;}
        else if(o==4){system("@cls||clear");    m.afficher_Matiere(nb_m);                                                               goto menu_Matiere;}
        else if(o==5){system("@cls||clear"); goto menu_principal;}
        else if(o==6){system("@cls||clear"); goto exit;}
        }


    else if(o==4)
        {
            menu_GroupeModule:
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cout<<"\t\t\t********************************   GroupeModule   *********************************"<<endl;
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cout<<"\t\t\t*                                                                                 *"<<endl;
            cout<<"\t\t\t* - Tapez [1] pour Ajout d un GroupeModule                                        *"<<endl;
            cout<<"\t\t\t* - Tapez [2] pour Suppression d un GroupeModule                                  *"<<endl;
            cout<<"\t\t\t* - Tapez [3] pour MAJ d un  GroupeModule                                         *"<<endl;
            cout<<"\t\t\t* - Tapez [4] pour afficher d un GroupeModule                                     *"<<endl;
            cout<<"\t\t\t* - Tapez [5] pour retourner au menu principal                                    *"<<endl;
            cout<<"\t\t\t* - Tapez [6] pour Quiter                                                         *"<<endl;
            cout<<"\t\t\t*                                                                                 *"<<endl;
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cin>>o;

            if(o==1){system("@cls||clear");         gm.saisi_GroupeModule(gms,&nb_gm,ms,nb_m);      gm.chargement_GroupeModule(gms,&nb_gm,ms,nb_m);     goto menu_GroupeModule;}
            else if(o==2){system("@cls||clear");    gm.supprimer_GroupeModule(gms,&nb_gm);          gm.chargement_GroupeModule(gms,&nb_gm,ms,nb_m);     goto menu_GroupeModule;}
            else if(o==3){system("@cls||clear");    gm.MAJ_GroupeModule(gms,&nb_gm,ms,nb_m);        gm.chargement_GroupeModule(gms,&nb_gm,ms,nb_m);     goto menu_GroupeModule;}
            else if(o==4){system("@cls||clear");    gm.afficher_GroupeModule(nb_gm);                                                            goto menu_GroupeModule;}
            else if(o==5){system("@cls||clear"); goto menu_principal;}
            else if(o==6){system("@cls||clear"); goto exit;}
        }

    else if(o==5)
        {
             menu_Groupe:
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cout<<"\t\t\t***********************************   Groupe   ************************************"<<endl;
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cout<<"\t\t\t*                                                                                 *"<<endl;
            cout<<"\t\t\t* - Tapez [1] pour Ajout d un Groupe                                              *"<<endl;
            cout<<"\t\t\t* - Tapez [2] pour Suppression d un Groupe                                        *"<<endl;
            cout<<"\t\t\t* - Tapez [3] pour MAJ d un  Groupe                                               *"<<endl;
            cout<<"\t\t\t* - Tapez [4] pour afficher d un Groupe                                           *"<<endl;
            cout<<"\t\t\t* - Tapez [5] pour retourner au menu principal                                    *"<<endl;
            cout<<"\t\t\t* - Tapez [6] pour Quiter                                                         *"<<endl;
            cout<<"\t\t\t*                                                                                 *"<<endl;
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cin>>o;

            if(o==1){system("@cls||clear");      g.saisi_Groupe(gs,&nb_g,gms,nb_gm,es,nb_e); g.chargement_Groupe(gs,&nb_g,gms,nb_gm,es,nb_e);  goto menu_Groupe;}
            else if(o==2){system("@cls||clear"); g.supprimer_Groupe(gs,&nb_g);               g.chargement_Groupe(gs,&nb_g,gms,nb_gm,es,nb_e);  goto menu_Groupe;}
            else if(o==3){system("@cls||clear"); g.MAJ_Groupe(gs,&nb_g,gms,nb_gm,es,nb_e);   g.chargement_Groupe(gs,&nb_g,gms,nb_gm,es,nb_e);   goto menu_Groupe;}
            else if(o==4){system("@cls||clear"); g.afficher_Groupe(gs,nb_g);                                                           goto menu_Groupe;}
            else if(o==5){system("@cls||clear"); goto menu_principal;}
            else if(o==6){system("@cls||clear"); goto exit;}
    }

    else if(o==6)
        {   menu_Note:
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cout<<"\t\t\t***********************************   Note   ************************************"<<endl;
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cout<<"\t\t\t*                                                                                 *"<<endl;
            cout<<"\t\t\t* - Tapez [1] pour Ajout d une Note                                               *"<<endl;
            cout<<"\t\t\t* - Tapez [2] pour Suppression d une Note                                         *"<<endl;
            cout<<"\t\t\t* - Tapez [3] pour MAJ d une Note                                                 *"<<endl;
            cout<<"\t\t\t* - Tapez [4] pour afficher les Notes                                             *"<<endl;
            cout<<"\t\t\t* - Tapez [5] pour retourner au menu principal                                    *"<<endl;
            cout<<"\t\t\t* - Tapez [6] pour Quiter                                                         *"<<endl;
            cout<<"\t\t\t*                                                                                 *"<<endl;
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cout<<"\t\t\t***********************************************************************************"<<endl;
            cin>>o;

            if(o==1){system("@cls||clear");      n.saisi_Note(ns,&nb_n,ms,nb_m,es,nb_e);     n.chargement_Note(ns,&nb_n,ms,nb_m,es,nb_e);  goto menu_Note;}
            else if(o==2){system("@cls||clear"); n.supprimer_Note(ns,&nb_n);                 n.chargement_Note(ns,&nb_n,ms,nb_m,es,nb_e);  goto menu_Note;}
            else if(o==3){system("@cls||clear"); n.MAJ_Note(ns,&nb_n,ms,nb_m,es,nb_e);     n.chargement_Note(ns,&nb_n,ms,nb_m,es,nb_e);  goto menu_Note;}
            else if(o==4){system("@cls||clear"); n.afficher_Note(ns,nb_n);                                                               goto menu_Note;}
            else if(o==5){system("@cls||clear"); goto menu_principal;}
            else if(o==6){system("@cls||clear"); goto exit;}
    }

    else if(o==7){ system("@cls||clear"); cout<<" ici option 7"<<endl; afficher_PV(gs,nb_g,ns,nb_n); goto menu_principal;}

    else if(o>=8){ system("@cls||clear"); cout<<" ici option 8"<<endl;goto exit;}

     /*   Etudiant e(1,"chokri","bdiri","b.chokri@pitn",22380);
        Enseignant en;

        en.saisi();
        en.afficher_Enseignant();
        e.afficher_etudiant();*/




}
    exit:
    return 0;
}
