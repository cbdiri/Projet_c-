#include <iostream>
#include <string.h>
#include "GroupeModule.h"

using namespace std;
GroupeModule::GroupeModule(){}
GroupeModule::GroupeModule(char id[],char nom[],float c, Matiere l[])
{
    strcpy(IdGM,id);
    strcpy(NomGM,nom);
    for(int i=0;i<10;i++)
    {
        ListeMat[i]=l[i];
    }
     CoefGM=0;
    for(int i=0;i<10;i++)
    {
         CoefGM= CoefGM+ListeMat[i].Coef;
    }
}

void GroupeModule::saisi_GroupeModule(GroupeModule gms[],int *nb_gm, Matiere ms[], int nb_m)
{

    int c=1;  // entier pour le controle de saisi 0 Id existe 1 si non
    do{
    c=1;
    cout<<" Donnez l ID du GroupeModule : ";
    cin>>IdGM;
    cout<<"\n";
    for(int i=0;i<*nb_gm;i++) { if(strcasecmp(IdGM,gms[i].IdGM)==0){c=0; cout<<" Id existe Tappez un autre SVP ! "<<endl<<endl; }  }
    }while(c==0);

    CoefGM=0;
    cout<<"\n";

    cout<<" Donnez le nom du GroupeModule : ";
    cin>>NomGM;
    cout<<"\n";

    cout<<" Donnez les nbrs des Matieres associer : ";
    cin>>nb;
    cout<<"\n";

    for(int i=0;i<nb;i++)
    {   c=0;
        do
        {
        cout<<" Donnez l id de la mtiere no : "<<i+1<<" : ";
        cin>>ListeMat[i].IdMat;
        for(int j=0;j<nb_m;j++)
        {
        if(strcmp(ListeMat[i].IdMat,ms[j].IdMat)==0){c=1; ListeMat[i]=ms[j]; break;}
        }
        if(c==0){cout<<" Matiere n existe pas Tappez un autre SVP ! "<<endl<<endl;}
        }while(c==0);
    }

    for(int i=0;i<nb;i++)
    {
        CoefGM=CoefGM+ListeMat[i].Coef;
    }

    system("@cls||clear");
    FILE *f;
    f=fopen("GroupeModule.txt","at");
    fprintf(f,"%s %s %.1f %d ",IdGM,NomGM,CoefGM,nb);
    for(int i=0;i<nb;i++)
    {
        fprintf(f,"%s ",ListeMat[i].IdMat);
    }
    fprintf(f,"\n");
    *nb_gm++;
    fclose(f);
}

void GroupeModule::afficher_GroupeModule(int nb_gm)
{
    FILE *f;
    f=fopen("GroupeModule.txt","rt");
    while(!feof(f))
    {
    fscanf(f,"%s %s %f %d ",&IdGM,&NomGM,&CoefGM,&nb);
    cout<<" Id Group Mod      : "<<IdGM<<endl;
    cout<<" Nom Group Mod     : "<<NomGM<<endl;
    cout<<" Coef Group Mod    : "<<CoefGM<<endl;
    cout<<" nbr des matieres  : "<<nb<<endl;

    for(int i=0;i<nb;i++)
    {
    fscanf(f,"%s ",&ListeMat[i].IdMat);
    cout<<" IdMat             : "<<ListeMat[i].IdMat<<endl;
    }
    cout<<endl;
    }
    cout<<" ==> nbr total des GroupeModules : "<<nb_gm<<endl<<endl;
    fclose(f);
}

void GroupeModule::supprimer_GroupeModule(GroupeModule gms[],int *nb_gm)
{
    char id[5];
    int c=0;

    do{
    cout<<" Donnez l ID du GroupeModule  : ";
    cin>>id;
    cout<<"\n";
    for(int i=0;i<*nb_gm;i++) { if (strcmp(id,gms[i].IdGM)==0){c=1;  break; }  }
    if(c==0) {cout<<"  ID non trouver tapez un ID existe SVP : "<<endl<<endl;}
    }while(c==0);

    FILE *f;
    FILE *f1;

    f=fopen("GroupeModule.txt","rt");
    f1=fopen("GroupeModule2.txt","wt");

        while(!feof(f))
        {
        fscanf(f,"%s %s %f %d ",&IdGM,&NomGM,&CoefGM,&nb);
        for(int i=0;i<nb;i++)
        {
           fscanf(f,"%s ",&ListeMat[i].IdMat);
        }
        if(strcmp(IdGM,id)!=0)
            {
            fprintf(f1,"%s %s %.1f %d ",IdGM,NomGM,CoefGM,nb);
            for(int i=0;i<nb;i++)
            {
                fprintf(f1,"%s ",ListeMat[i].IdMat);
            }
            fprintf(f1,"\n");
            }
        }
    fclose(f);
    fclose(f1);

    remove("GroupeModule.txt");
    rename("GroupeModule2.txt","GroupeModule.txt");

}

void GroupeModule::MAJ_GroupeModule(GroupeModule gms[],int *nb_gm, Matiere ms[], int nb_m)
{
    supprimer_GroupeModule(gms,nb_gm);
    chargement_GroupeModule(gms,nb_gm,ms,nb_m);
    saisi_GroupeModule(gms,nb_gm,ms,nb_m);
}

void GroupeModule::chargement_GroupeModule(GroupeModule gms[],int *nb_gm,Matiere ms[], int nb_m)
{
    int i=0;
    FILE *f;
    f=fopen("GroupeModule.txt","rt");
     while(!feof(f))
    {
    fscanf(f,"%s %s %f %d ",&IdGM,&NomGM,&CoefGM,&nb);
    strcpy(gms[i].IdGM,IdGM);
    strcpy(gms[i].NomGM,NomGM);
    gms[i].CoefGM=CoefGM;
    gms[i].nb=nb;
    for(int j=0;j<nb;j++)
    {
    fscanf(f,"%s ",&ListeMat[j].IdMat);
    for(int k=0;k<nb_m;k++)
    if(strcmp(ListeMat[j].IdMat,ms[k].IdMat)==0){gms[i].ListeMat[j]=ms[k]; }
    //strcpy(gms[i].ListeMat[j].IdMat,ListeMat[j].IdMat);
    }
    i++;
    }
    *nb_gm=i;
    fclose(f);
}






