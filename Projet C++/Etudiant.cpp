#include <iostream>
#include <string.h>
#include <cstdio>
#include "Etudiant.h"
using namespace std;

Etudiant::Etudiant(){}

Etudiant::Etudiant(int a,char n[],char p[],char m[],int num) : Personne( a,n,p,m)
{
    Num_insc=num;
}

void Etudiant::saisi(Etudiant e[],int *nb_e)
{

int c=1;  // entier pour le controle de saisi 0 Id existe 1 si non
do{
c=1;
cout<<" Donnez l ID de l etudiant : ";
cin>>Id;
cout<<"\n";
for(int i=0;i<*nb_e;i++) { if(Id==e[i].Id){c=0; cout<<" Id existe Tappez un autre SVP ! "<<endl<<endl; }  }
}while(c==0);

cout<<" Donnez le nom de l etudiant : ";
cin>>Nom;
cout<<"\n";
cout<<" Donnez  le Prenom de l etudiant : ";
cin>>Prenom;
cout<<"\n";
cout<<" Donnez le mail de l etudiant : ";
cin>> Mail;
cout<<"\n";
cout<< " Donnez un numri d inscription a l etudiant ";
cin>>Num_insc;
system("@cls||clear");
FILE *f;
f=fopen("Etudiant.txt","at");
fprintf(f,"%d %s %s %s %d \n",Id,Nom,Prenom,Mail,Num_insc);
fclose(f);
*nb_e++;
}

void Etudiant::afficher_etudiant(int nb_e)
{
    FILE *f;
    f=fopen("Etudiant.txt","rt");
    while(!feof(f))
    {
    fscanf(f,"%d %s %s %s %d \n",&Id,&Nom,&Prenom,&Mail,&Num_insc);
    cout<<" id                : "<<Id<<endl;
    cout<<" Nom               : "<<Nom<<endl;
    cout<<" Prenom            : "<<Prenom<<endl;
    cout<<" Email             : "<<Mail<<endl;
    cout<<" numero d inscrit  : "<<Num_insc<<endl<<endl;
    }
    cout<<" nbr total des Etudiants : "<<nb_e<<endl<<endl;
    fclose(f);
}

void Etudiant::supprimer_etudiant(Etudiant e[],int *nb_e)
{
int id;
int c=0;

//cotrole de saisi de l id
do{
cout<<" Donnez l ID de l Etudiant  : ";
cin>>id;
cout<<"\n";
for(int i=0;i<*nb_e;i++) { if (id==e[i].Id){c=1;  break; }  }
if(c==0) {cout<<"  ID non trouver tapez un ID existe SVP : "<<endl<<endl;}
}while(c==0);


FILE *f;
FILE *f1;

f=fopen("Etudiant.txt","rt");
f1=fopen("Etudiant2.txt","wt");

    while(!feof(f))
    {
    fscanf(f,"%d %s %s %s %d \n",&Id,&Nom,&Prenom,&Mail,&Num_insc);
    if(Id!=id)
        {
    fprintf(f1,"%d %s %s %s %d \n",Id,Nom,Prenom,Mail,Num_insc);
        }
    }
fclose(f);
fclose(f1);

remove("Etudiant.txt");
rename("Etudiant2.txt","Etudiant.txt");

}

void Etudiant::MAJ_etudiant(Etudiant e[],int *nb_e)
{
int i;
supprimer_etudiant(e,nb_e);
chargement_etudiants(e,nb_e);
saisi(e,nb_e);

}

void Etudiant::chargement_etudiants(Etudiant e[],int *nb_e)
{

    int i=0;
    FILE *f;
    f=fopen("Etudiant.txt","rt");
     while(!feof(f))
    {
    fscanf(f,"%d %s %s %s %d \n",&Id,&Nom,&Prenom,&Mail,&Num_insc);
    e[i].Id=Id;
    strcpy(e[i].Nom,Nom);
    strcpy(e[i].Prenom,Prenom);
    strcpy(e[i].Mail,Mail);
    e[i].Num_insc=Num_insc;
    i++;
    }
    *nb_e=i;
    fclose(f);

}







