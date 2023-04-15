#include <iostream>
#include <string.h>
#include "Enseignant.h"
using namespace std;

Enseignant::Enseignant(){}

Enseignant::Enseignant(int a,char n[],char p[], char m[],int c) : Personne( a,n,p,m){
    CNSS=c;
}

void Enseignant::saisi(Enseignant e[],int *nb_en)
{
int c=1;  // entier pour le controle de saisi 0 Id existe 1 si non
do{
c=1;
cout<<" Donnez l ID de l Enseignant : ";
cin>>Id;
cout<<"\n";
for(int i=0;i<*nb_en;i++) { if(Id==e[i].Id){c=0; cout<<" Id existe Tappez un autre SVP ! "<<endl<<endl; }  }
}while(c==0);

cout<<" Donnez le nom de l Enseignant : ";
cin>>Nom;
cout<<"\n";
cout<<" Donnez  le Prenom de l Enseignant : ";
cin>>Prenom;
cout<<"\n";
cout<<" Donnez le mail de l Enseignant : ";
cin>> Mail;
cout<<"\n";
cout<< " Donnez le CNSS de l Enseignant ";
cin>>CNSS;
system("@cls||clear");
FILE *f;
f=fopen("Enseignant.txt","at");
fprintf(f,"%d %s %s %s %d \n",Id,Nom,Prenom,Mail,CNSS);
fclose(f);
*nb_en++;
}

void Enseignant::afficher_Enseignant(int nb_en)
{

    FILE *f;
    f=fopen("Enseignant.txt","rt");
    while(!feof(f))
    {
    fscanf(f,"%d %s %s %s %d \n",&Id,&Nom,&Prenom,&Mail,&CNSS);
    cout<<" id                : "<<Id<<endl;
    cout<<" Nom               : "<<Nom<<endl;
    cout<<" Prenom            : "<<Prenom<<endl;
    cout<<" Email             : "<<Mail<<endl;
    cout<<" numero du CNSS    : "<<CNSS<<endl<<endl;
    }
   cout<<" nbr total des Enseignants : "<<nb_en<<endl<<endl;

    fclose(f);
}

void Enseignant::supprimer_Enseignant(Enseignant e[],int *nb_en)
{
int id;
int c=0;

//cotrole de saisi de l id
do{
cout<<" Donnez l ID de l Enseignant  : ";
cin>>id;
cout<<"\n";
for(int i=0;i<*nb_en;i++) { if (id==e[i].Id){c=1;  break; }  }
if(c==0) {cout<<"  ID non trouver tapez un ID existe SVP : "<<endl<<endl;}
}while(c==0);

FILE *f;
FILE *f1;

f=fopen("Enseignant.txt","rt");
f1=fopen("Enseignant2.txt","wt");

    while(!feof(f))
    {
    fscanf(f,"%d %s %s %s %d \n",&Id,&Nom,&Prenom,&Mail,&CNSS);
    if(Id!=id)
        {
    fprintf(f1,"%d %s %s %s %d \n",Id,Nom,Prenom,Mail,CNSS);
        }
    }
fclose(f);
fclose(f1);

remove("Enseignant.txt");
rename("Enseignant2.txt","Enseignant.txt");

}

void Enseignant::MAJ_Enseignant(Enseignant e[],int *nb_en)
{
    supprimer_Enseignant(e,nb_en);
    chargement_Enseignants(e,nb_en);
    saisi(e,nb_en);
}

void Enseignant::chargement_Enseignants(Enseignant e[],int *nb_en)
{
    int i=0;
    FILE *f;
    f=fopen("Enseignant.txt","rt");
     while(!feof(f))
    {
    fscanf(f,"%d %s %s %s %d \n",&Id,&Nom,&Prenom,&Mail,&CNSS);
    e[i].Id=Id;
    strcpy(e[i].Nom,Nom);
    strcpy(e[i].Prenom,Prenom);
    strcpy(e[i].Mail,Mail);
    e[i].CNSS=CNSS;
    i++;
    }
    *nb_en=i;
    fclose(f);


}

