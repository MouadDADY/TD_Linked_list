#include <stdio.h>
#include <stdlib.h>
#include "function1.h"

void main(){
   liste l=NULL;
   int Som,Min,Max;
   float Moy;
   l=AjoutElemFin(5,l);
   l=AjoutElemFin(1,l);
   l=AjoutElemFin(12,l);
   l=AjoutElemFin(44,l);
   l=AjoutElemFin(9,l);
   l=AjoutElemFin(26,l);
   l=AjoutElemFin(3,l);
   printf("L affichage de la liste :\n");
   AfficherList(l);
   printf("le nombre des elments de la liste est : %d\n",nbrElement(l));
   SomMoyList(l,&Som,&Moy);
   printf("la somme est : %d et la moyenne est : %.2f\n",Som,Moy);
   MinMaxList(l,&Min,&Max);
   printf("le min est : %d et la max est : %d\n",Min,Max);
   l=SuppFOIList(l,5);
   printf("La liste apres suppression de valeur 5:\n");
   AfficherList(l);
   l=SuppFORList(l,3);
   printf("La liste apres suppression du valeur 3:\n");
   AfficherList(l);
   l=InverserList(l);
   printf("La liste Inversee :\n");
   AfficherList(l);
   printf("la liste triee :\n");
   AfficherList(TriList(l));
   printf("La liste detruit :\n");
   AfficherList(SuppList(l));
   
}
