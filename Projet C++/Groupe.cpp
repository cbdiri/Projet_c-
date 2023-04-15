#include <iostream>
#include <string.h>
#include "Groupe.h"
using namespace std;

Groupe::Groupe(){}

Groupe::Groupe(char id[],char nv[],char dp[],char sp[],int nm, GroupeModule lm[],Etudiant lE[]){

    strcpy(IdGRP,id);
    strcpy(Niveau,nv);
    strcpy(Diplome,dp);
    strcpy(Specialite,sp);
    Num_G=nm;
    for(int i=0;i<15;i++)
    ListeModules[i]=lm[i];
    for(int i=0;i<50;i++)
    ListeEtudiants[i]=lE[i];

}


void Groupe::saisi_Groupe(Groupe gs[],int *nb_g, GroupeModule gms[], int nb_gm ,Etudiant es[], int nb_e)
{
    int c=1;  // entier pour le controle de saisi 0 Id existe 1 si non
    do{
    c=1;
    cout<<" Donnez l ID du Groupe : ";
    cin>>IdGRP;
    cout<<"\n";
    for(int i=0;i<*nb_g;i++) { if(strcasecmp(IdGRP,gs[i].IdGRP)==0){c=0; cout<<" Id existe Tappez un autre SVP ! "<<endl<<endl; }  }
    }while(c==0);

    do{
    cout<<" Donnez le Niveau de Groupe entre ( Premiere, deuxieme ou troisieme ) : ";
    cin>>Niveau;
    }while((strcmp(Niveau,"Premiere")!=0) && (strcmp(Niveau,"deuxieme")!=0) && (strcmp(Niveau,"troisieme")!=0));
    cout<<"\n";

    do{
    cout<<" Donnez le Diplôme de Groupe entre ( ING, Master ou LMD ) ";
    cin>>Diplome;
    }while(strcmp(Diplome,"ING")!=0 && strcmp(Diplome,"Master")!=0 && strcmp(Diplome,"LMD")!=0);
    cout<<"\n";

    do{
    cout<<" Donnez la Spécialité de Groupe entre ( INF, INDUS ou MATH ) ";
    cin>>Specialite;
    }while(strcmp(Specialite,"INF")!=0 && strcmp(Specialite,"INDUS")!=0 && strcmp(Specialite,"MATH")!=0);
    cout<<"\n";

    do{
    cout<<" Donnez le Numero de Groupe entre ( 1,2 ou 3 ) ";
    cin>>Num_G;
    }while(Num_G!= 1 && Num_G!=2 && Num_G!=3);
    cout<<"\n";

    cout<<" Donnez les nbrs des Groupe_Module associer : ";
    cin>>nb_gs;
    cout<<"\n";

    for(int i=0;i<nb_gs;i++)
    {
        c=0;
        do
        {
        cout<<" Donnez l id de Groupe_Module no : "<<i+1<<" : ";
        cin>>ListeModules[i].IdGM;

        for(int j=0;j<nb_gm;j++)
        {
        if(strcmp(ListeModules[i].IdGM, gms[j].IdGM)==0){c=1; ListeModules[i]=gms[j]; break;}
        }
        if(c==0){cout<<endl<<" ==> ! Groupe_Module n existe pas Tappez un autre ID SVP ! "<<endl<<endl;}
        }while(c==0);
    }

    cout<<" Donnez les nbrs des Etudiants de Groupe : ";
    cin>>nb_es;
    cout<<"\n";

    for(int i=0;i<nb_es;i++)
    {
        c=0;
        do
        {
        cout<<" Donnez l id de l Etudiant  no : "<<i+1<<" : ";
        cin>>ListeEtudiants[i].Id;

        for(int j=0;j<nb_e;j++)
        {
        if(ListeEtudiants[i].Id==es[j].Id){c=1; ListeEtudiants[i]=es[j]; break;}
        }
        if(c==0){cout<<endl<<" ==> ! Etudiant n existe pas Tappez un autre ID SVP ! "<<endl<<endl;}
        }while(c==0);
    }

    system("@cls||clear");
    FILE *f;
    f=fopen("Groupe.txt","at");
    fprintf(f,"%s %s %s %s %d ",IdGRP,Niveau,Diplome,Specialite,Num_G);
    fprintf(f,"%d ",nb_gs);
    for(int i=0;i<nb_gs;i++)
    {
        fprintf(f,"%s ",ListeModules[i].IdGM);
    }
    fprintf(f,"%d ",nb_es);
    for(int i=0;i<nb_es;i++)
    {
        fprintf(f,"%d ",ListeEtudiants[i].Id);
    }
    fprintf(f,"\n");
    *nb_g++;
    fclose(f);
}

void Groupe::afficher_Groupe(Groupe gs[],int nb_g)
{
    for(int c=0;c<nb_g;c++)
{
    cout<<" Id Group          : "<<gs[c].IdGRP<<endl;
    cout<<" Niveau            : "<<gs[c].Niveau<<endl;
    cout<<" Diplôme           : "<<gs[c].Diplome<<endl;
    cout<<" Spécialité        : "<<gs[c].Specialite<<endl ;
    cout<<" Num_G             : "<<gs[c].Num_G<<endl;

    cout<<" ListeModules      : "<<gs[c].nb_gs<<" = { ";
    for(int i=0;i<gs[c].nb_gs;i++){
    cout<<gs[c].ListeModules[i].IdGM<<" : "<<gs[c].ListeModules[i].NomGM<<" " ;}
    cout<<"}"<<endl;

    cout<<" ListeEtudiants    : "<<gs[c].nb_es<<" = { ";
    for(int i=0;i<gs[c].nb_es;i++)
    cout<<gs[c].ListeEtudiants[i].Id<<" : "<<gs[c].ListeEtudiants[i].Nom<<" ";
    cout<<"}"<<endl<<endl;


    }
    cout<<" ==> nbr total des Groupe : "<<nb_g<<endl<<endl;
}


void Groupe::supprimer_Groupe(Groupe gs[],int *nb_g)
{

    char id[5];
    int c=0;

    do{
    cout<<" Donnez l ID du Groupe  : ";
    cin>>id;
    cout<<"\n";
    for(int i=0;i<*nb_g;i++) { if (strcmp(id,gs[i].IdGRP)==0){c=1;  break; }  }
    if(c==0) {cout<<"  ID non trouver tapez un ID existe SVP : "<<endl<<endl;}
    }while(c==0);

    FILE *f;
    FILE *f1;

    f=fopen("Groupe.txt","rt");
    f1=fopen("Groupe2.txt","wt");

        while(!feof(f))
        {
        fscanf(f,"%s %s %s %s %d %d",&IdGRP,&Niveau,&Diplome,&Specialite,&Num_G,&nb_gs);
        for(int j=0;j<nb_gs;j++)
        {
        fscanf(f,"%s ",&ListeModules[j].IdGM);
        }
        fscanf(f,"%d ",&nb_es);
        for(int j=0;j<nb_es;j++)
        {
        fscanf(f,"%d ",&ListeEtudiants[j].Id);
        }

        if(strcmp(IdGRP,id)!=0)
            {
            fprintf(f1,"%s %s %s %s %d ",IdGRP,Niveau,Diplome,Specialite,Num_G);
            fprintf(f1,"%d ",nb_gs);
            for(int i=0;i<nb_gs;i++)
            {
                fprintf(f1,"%s ",ListeModules[i].IdGM);
            }
            fprintf(f1,"%d ",nb_es);
            for(int i=0;i<nb_es;i++)
            {
                fprintf(f1,"%d ",ListeEtudiants[i].Id);
            }
        fprintf(f1,"\n");
            }
        }
    fclose(f);
    fclose(f1);

    remove("Groupe.txt");
    rename("Groupe2.txt","Groupe.txt");


}

void Groupe::MAJ_Groupe(Groupe gs[],int *nb_g, GroupeModule gms[], int nb_gm ,Etudiant es[], int nb_e)
{
    supprimer_Groupe(gs,nb_g);
    chargement_Groupe(gs,nb_g,gms,nb_gm,es,nb_e);
    saisi_Groupe(gs,nb_g,gms,nb_gm,es,nb_e);

}

void Groupe::chargement_Groupe(Groupe gs[],int *nb_g,GroupeModule gms[], int nb_gm,Etudiant es[], int nb_e)
{
    int i=0;
    FILE *f;
    f=fopen("Groupe.txt","rt");

    while(!feof(f))
    {
    fscanf(f,"%s %s %s %s %d %d",&IdGRP,&Niveau,&Diplome,&Specialite,&Num_G,&nb_gs);
    strcpy(gs[i].IdGRP,IdGRP);
    strcpy(gs[i].Niveau,Niveau);
    strcpy(gs[i].Diplome,Diplome);
    strcpy(gs[i].Specialite,Specialite);
    gs[i].Num_G=Num_G;
    gs[i].nb_gs=nb_gs;

    for(int j=0;j<nb_gs;j++)
    {
    fscanf(f,"%s ",&ListeModules[j].IdGM);
        for(int k=0;k<nb_gm;k++)
        {
            if(strcmp(ListeModules[j].IdGM,gms[k].IdGM)==0)
                { gs[i].ListeModules[j] = gms[k] ;  }
        }

    //strcpy(gs[i].ListeModules[j].IdGM,ListeModules[j].IdGM);
    }

    fscanf(f,"%d ",&nb_es);
    gs[i].nb_es=nb_es;

    for(int j=0;j<nb_es;j++)
    {
    fscanf(f,"%d ",&ListeEtudiants[j].Id);

    for(int k=0;k<nb_e;k++)
    {
        if(ListeEtudiants[j].Id==es[k].Id)
            { gs[i].ListeEtudiants[j] = es[k] ;  }

    //gs[i].ListeEtudiants[j].Id=ListeEtudiants[j].Id;
    }
    }

    i++;
    }

    *nb_g=i;
    fclose(f);
}












