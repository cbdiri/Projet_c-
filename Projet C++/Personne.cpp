#include <iostream>
#include <string.h>
#include "Personne.h"

using namespace std;

Personne::Personne(){}

Personne::Personne(int a,char n[],char p[],char m[]){
Id=a;
strcpy(Nom,n);
strcpy(Prenom,p);
strcpy(Mail,m);
strcpy(Mail,m);
}




