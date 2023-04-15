#ifndef PERSONNE_H
#define PERSONNE_H

class Personne{
public:
    int Id;
    char Nom[10];
    char Prenom[10];
    char Mail[15];
public:
    Personne();
    Personne(int a,char n[],char p[],char m[]);
    Personne operator <<(Personne p);
};
#endif
