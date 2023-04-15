#include <iostream>
#include <string.h>
#include "Matiere.h"

using namespace std;

Matiere::Matiere(){}
Matiere::Matiere(char id[],char nom[],float c,Enseignant e)
{
    strcpy(IdMat,id);
    strcpy(NomMat,nom);
    Coef=c;
    Ens=e;
}

void Matiere::saisi_Matiere(Matiere ms[],int *nb_m, Enseignant ens[],int nb_en)
{
    int c=1;  // entier pour le controle de saisi 0 Id existe 1 si non
    do{
    c=1;
    cout<<" Donnez l ID de la Matiere : ";
    cin>>IdMat;
    cout<<"\n";
    for(int i=0;i<*nb_m;i++) { if(strcasecmp(IdMat,ms[i].IdMat)==0){c=0; cout<<" Id existe Tappez un autre SVP ! "<<endl<<endl; }  }
    }while(c==0);

    cout<<" Donnez le nom de la Matiere : ";
    cin>>NomMat;
    cout<<"\n";
    cout<<" Donnez  le Coefecion de la Matiere : ";
    cin>>Coef;
    cout<<"\n";

    do{
    c=0;
    cout<<" Donnez l Enseigant de cette Matiere : ";
    cin>>Ens.Id;
    for(int i=0;i<nb_en;i++){if(Ens.Id==ens[i].Id){c=1; break;    }  }
    if(c==0){cout<<" Id Enseignant n existe pas , tapez un autre ID SVP "<<endl<<endl;}
    }while(c==0);

    system("@cls||clear");
    FILE *f;
    f=fopen("Matiere.txt","at");
    fprintf(f,"%s %s %.1f %d \n",IdMat,NomMat,Coef,Ens.Id);
    fclose(f);
}

void Matiere::afficher_Matiere(int nb_m)
{
    FILE *f;
    f=fopen("Matiere.txt","rt");
    while(!feof(f))
    {
    fscanf(f,"%s %s %f %d \n",&IdMat,&NomMat,&Coef,&Ens.Id);
    cout<<" IdMat           : "<<IdMat<<endl;
    cout<<" NomMat          : "<<NomMat<<endl;
    cout<<" Coef            : "<<Coef<<endl;
    cout<<" Id Enseignant   : "<<Ens.Id<<endl<<endl;
    }
    cout<<" nbr total des Matiere : "<<nb_m<<endl<<endl;
    fclose(f);

}

void Matiere::supprimer_Matiere(Matiere ms[],int *nb_m)
{
    char id[5];
    int c=0;

    do{
    cout<<" Donnez l ID de la Matiere  : ";
    cin>>id;
    cout<<"\n";
    for(int i=0;i<*nb_m;i++) { if (strcmp(id,ms[i].IdMat)==0){c=1;  break; }  }
    if(c==0) {cout<<"  ID non trouver tapez un ID existe SVP : "<<endl<<endl;}
    }while(c==0);

    FILE *f;
    FILE *f1;

    f=fopen("Matiere.txt","rt");
    f1=fopen("Matiere2.txt","wt");

        while(!feof(f))
        {
        fscanf(f,"%s %s %f %d \n",&IdMat,&NomMat,&Coef,&Ens.Id);
        if(strcmp(IdMat,id)!=0)
            {
        fprintf(f1,"%s %s %.1f %d \n",IdMat,NomMat,Coef,Ens.Id);
            }
        }
    fclose(f);
    fclose(f1);

    remove("Matiere.txt");
    rename("Matiere2.txt","Matiere.txt");

}

void Matiere::MAJ_Matiere(Matiere ms[],int *nb_m, Enseignant ens[],int nb_en)
{
supprimer_Matiere(ms,nb_m);
chargement_Matieres(ms,nb_m);
saisi_Matiere(ms,nb_m,ens,nb_en);

}

void Matiere::chargement_Matieres(Matiere m[],int *nb_m)
{
    int i=0;
    FILE *f;
    f=fopen("Matiere.txt","rt");
     while(!feof(f))
    {
    fscanf(f,"%s %s %f %d \n",&IdMat,&NomMat,&Coef,&Ens.Id);
    strcpy(m[i].IdMat,IdMat);
    strcpy(m[i].NomMat,NomMat);
    m[i].Coef=Coef;
    m[i].Ens.Id=Ens.Id;
    i++;
    }
    *nb_m=i;
    fclose(f);

}




