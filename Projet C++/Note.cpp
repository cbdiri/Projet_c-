#include <iostream>
#include <string.h>
#include "Note.h"
using namespace std;

Note::Note(){}
Note::Note(Matiere m,Etudiant e,float n, char t[]){}


void Note::saisi_Note(Note ns[],int *nb_n, Matiere ms[], int nb_m ,Etudiant es[], int nb_e)
{

    int c=0;  // entier pour le controle de saisi 0 Id existe 1 si non
    do{
    c=0;
    cout<<" Donnez l ID de la Matiere : ";
    cin>>Mat.IdMat;
    cout<<"\n";
    for(int i=0;i<nb_m;i++) { if(strcasecmp(Mat.IdMat,ms[i].IdMat)==0){c=1; break; }  }
    if(c==0){cout<<" Id n existe pas Tappez un autre SVP ! "<<endl<<endl;}
    }while(c==0);

    do{
    c=0;
    cout<<" Donnez l ID de l Etudiant : ";
    cin>>Etu.Id;
    cout<<"\n";
    for(int i=0;i<nb_e;i++) { if(Etu.Id==es[i].Id){c=1; break; }  }
    if(c==0){cout<<" Id n existe pas Tappez un autre SVP ! "<<endl<<endl;}
    }while(c==0);

    cout<<" Donnez la note de l Etudiant : "<<endl;
    cin>>Nt;
    cout<<endl;


    do{
    cout<<" Donnez le type de la Note ( DS, Examen, TP ) ";
    cin>>Type;
    }while(strcmp(Type,"DS")!=0 && strcmp(Type,"Examen")!=0 && strcmp(Type,"TP")!=0);
    cout<<"\n";

    system("@cls||clear");
    FILE *f;
    f=fopen("Note.txt","at");
    fprintf(f,"%s %d %0.1f %s \n",Mat.IdMat,Etu.Id,Nt,Type);

    *nb_n++;
    fclose(f);

}
void Note::afficher_Note(Note ns[],int nb_n)
{

 for(int c=0;c<nb_n;c++)
{
    cout<<" Id Matiere          : "<<ns[c].Mat.IdMat<<" : "<<ns[c].Mat.NomMat<<endl;
    cout<<" Etudiant            : "<<ns[c].Etu.Id<<endl;
    cout<<" Note                : "<<ns[c].Nt<<endl;
    cout<<" type                : "<<ns[c].Type<<endl<<endl ;

    }
    cout<<" ==> nbr total des Notes : "<<nb_n<<endl<<endl;

}
void Note::supprimer_Note(Note ns[],int *nb_gn)
{

}
void Note::MAJ_Note(Note ns[],int *nb_n, Matiere ms[], int nb_m ,Etudiant es[], int nb_e)
{

}
void Note::chargement_Note(Note ns[],int *nb_n, Matiere ms[], int nb_m ,Etudiant es[], int nb_e)
{

    int i=0;
    FILE *f;
    f=fopen("Note.txt","rt");

    while(!feof(f))
    {
    fscanf(f,"%s %d %f %s \n",&Mat.IdMat,&Etu.Id,&Nt,&Type);
    strcpy(ns[i].Mat.IdMat,Mat.IdMat);
    ns[i].Etu.Id=Etu.Id;
    ns[i].Nt=Nt;
    strcpy(ns[i].Type,Type);

    /*for(int j=0;j<nb_gs;j++)
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
*/
    i++;
    }
    *nb_n=i;
    fclose(f);

}

