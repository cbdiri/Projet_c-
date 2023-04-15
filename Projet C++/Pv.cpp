#include <iostream>
#include "string.h"
#include "Pv.h"
#include <windows.h>

using namespace std;
void gotoxy(short a, short b) //Custom gotoxy() function
{
    COORD coordinates; //Data type of co-ordinates
    coordinates.X = a; //Assign value to X- Co-ordinate
    coordinates.Y = b; //Assign value to Y Co-ordinate

SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}

float MoyMat (int ide ,char idm[], Note ns[],int nb_n) //gs[g].ListeEtudiants[j].Id,gs[g].ListeModules[x].ListeMat[x1].IdMat,ns,nb_n
{
    float Moy=0;
    int n=0;
    for(int i=0;i<nb_n;i++)
        if((ide==ns[i].Etu.Id) && strcmp(idm,ns[i].Mat.IdMat)==0){ Moy=Moy+ns[i].Nt; n++; }
        return(Moy/n);
}

void Resultat(float n)
{
    if(n>=10 )cout<<"ADMIS";
    else cout<<"Ajourne";
}

void Mention(float n)
{
       if(n>=10 && n<12) cout<<" Passable ";
       else if(n>= 12 && n<14) cout<<" Assez Bien ";
       else if(n>= 14 && n<16) cout<<"  Bien ";
       else if(n>= 16 && n<18) cout<<" Tres Bien ";
       else if(n>= 18 && n<=20) cout<<" Excellent ";

}

void afficher_PV(Groupe gs[], int nb_g,Note ns[],int nb_n)
{
char ID[5];
int c=0;
int g=-1; // indice de tableau de groupe a afficher
int x=0;
int x1=0;

do{

cout<< " Donnez l ID de Groupe "<<endl<<endl;
cin>>ID;

    for(int i=0;i<nb_g;i++)
    {
    if(strcmp(ID,gs[i].IdGRP)==0){c=1; g=i; break; }
    }
    if(c==0){cout<<" ==> ID Group Non trouver tapez un autre SVP : "<<endl<<endl;}
    }while(c==0);
    system("@cls||clear");

    cout<<endl;
    cout<<" ==> PV "<<gs[g].Niveau<<" "<<gs[g].Diplome<<" "<<gs[g].Specialite<<" "<<gs[g].Num_G<<" : "<<endl<<endl;

    //gotoxy(15,4);
    //cout<<"NomGM :";
    for(x=0;x<gs[g].nb_gs;x++)
    {
        gotoxy((x+1)*30-x,4);
        cout<<"|"<<gs[g].ListeModules[x].NomGM;
    }
    gotoxy((x+1)*30-x,4);
    cout<<" | "<<"Moyenne ";
    cout<<" | "<<"Resultat";
    cout<<" | "<<"Mention ";
    cout<<endl;

    //gotoxy(15,5);
    //cout<<"CoefGM :";
    for(x=0;x<gs[g].nb_gs;x++)
    {
        gotoxy((x+1)*30-x,5);
        cout<<"|"<<gs[g].ListeModules[x].CoefGM;
    }
    gotoxy((x+1)*30-x,5);
    cout<<" | "<<"        ";
    cout<<" | "<<"        ";
    cout<<" | "<<"        ";
    cout<<endl;


    //gotoxy(15,6);
    //cout<<"Nom_Mat :";
    for(x=0;x<gs[g].nb_gs;x++)
    {
        gotoxy((x+1)*30-x,6);
        for(x1=0;x1<gs[g].ListeModules[x].nb;x1++)
        {
        gotoxy((x+1)*30-x+((x1)*10-x1),6);
        cout<<"|"<<gs[g].ListeModules[x].ListeMat[x1].NomMat;
        }
    }
    gotoxy((x+1)*30-x,6);
    cout<<" | "<<"        ";
    cout<<" | "<<"        ";
    cout<<" | "<<"        ";
    cout<<endl;

    gotoxy(5,7);
    cout<<"Listes des Etudiants ";
    for(x=0;x<gs[g].nb_gs;x++)
    {
        gotoxy((x+1)*30-x,7);
        for(x1=0;x1<gs[g].ListeModules[x].nb;x1++)
        {
        gotoxy((x+1)*30-x+((x1)*10-x1),7);
        cout<<"|"<<gs[g].ListeModules[x].ListeMat[x1].Coef;
        }
    }
    gotoxy((x+1)*30-x,7);
    cout<<" | "<<"        ";
    cout<<" | "<<"        ";
    cout<<" | "<<"        ";
    cout<<endl;

    gotoxy(0,8);
    cout<<"------------------------------";
    for(x=0;x<gs[g].nb_gs;x++)
    {
        gotoxy((x+1)*30-x,8);
        for(x1=0;x1<gs[g].ListeModules[x].nb;x1++)
        {
        gotoxy((x+1)*30-x+((x1)*10-x1),8);
        cout<<"|";
        }
    }
    gotoxy((x+1)*30-x,8);
    cout<<" | "<<"        ";
    cout<<" | "<<"        ";
    cout<<" | "<<"        ";
    cout<<endl;

    int j;
    for(j=0;j<gs[g].nb_es;j++){
    gotoxy(0,9+j);
    cout<<gs[g].ListeEtudiants[j].Num_insc;
    gotoxy(5,9+j);
    cout<<" | "<<gs[g].ListeEtudiants[j].Nom;
    gotoxy(16,9+j);
    cout<<" | "<<gs[g].ListeEtudiants[j].Prenom;
    float MGM=0;
    float MG=0;
    float CoefG=0;
    for(x=0;x<gs[g].nb_gs;x++)
    {
        MGM=0;
        gotoxy((x+1)*30-x,9+j);
        for(x1=0;x1<gs[g].ListeModules[x].nb;x1++)
        {
        gotoxy((x+1)*30-x+((x1)*10-x1),9+j);

        cout<<"|"<<MoyMat(gs[g].ListeEtudiants[j].Id,gs[g].ListeModules[x].ListeMat[x1].IdMat,ns,nb_n);
        MGM=MGM + MoyMat(gs[g].ListeEtudiants[j].Id,gs[g].ListeModules[x].ListeMat[x1].IdMat,ns,nb_n)*gs[g].ListeModules[x].ListeMat[x1].Coef;

        }
        gotoxy((x+1)*30-x+((x1)*10-x1),9+j);
        cout<<"| =>: "<<MGM/gs[g].ListeModules[x].CoefGM;
        MG = MG + MGM;
        CoefG = CoefG + gs[g].ListeModules[x].CoefGM;
    }
    gotoxy((x+1)*30-x,9+j);
    cout<<" | "<<MG/CoefG;
    gotoxy((x+1)*30-x+11,9+j);
    cout<<" | ";
    Resultat(MG/CoefG);
    gotoxy((x+1)*30-x+22,9+j);
    cout<<" | ";
    Mention(MG/CoefG);
    cout<<endl;
}
cin>>ID;
}
