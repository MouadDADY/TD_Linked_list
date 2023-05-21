#include <stdio.h>
#include <stdlib.h>
#define N 50
typedef struct cellule 
  { 
	int val;
	struct cellule *svt;
	
  }Liste,*liste;
//.........................
int nbrElements(liste l)
   {
   	int cpt=0;
   	while(l){
   		cpt++;   		
   		l=l->svt;
	   }
    return cpt;
   }
/*........Ajout Fin .......................*/
    liste AjoutElemFin(int v,liste l){
    	liste ln,lp;
    	ln=malloc(sizeof(Liste));
     	ln->val=v;
    	ln->svt=NULL;
    	if(l==NULL)
    	  return ln;
    	lp=l;
    	while(lp->svt!=NULL)
    	   lp=lp->svt;
    	lp->svt=ln;
    	return l;
	}

/*...............Affichage d une liste............*/
void AfficherList(liste l)
{
	while(l!=NULL)
	{
		printf("(%d)->",l->val);
		l=l->svt;
	}
	printf("NULL");
        printf("\n");
}
//............................
void AfficherTab(int* t,int n)
{
 int i;
 for(i=0;i<n;i++)
   printf("%d|",t[i]);
 printf("\n");
}
//....................................
liste TabToList(int *t,int n)
{
  liste l=NULL;
  int i;
  for(i=0;i<n;i++)
    l=AjoutElemFin(t[i],l);
  return l ;
}
//..........................
int* ListToTab(liste l)
{
 int n=nbrElements(l);
 int *T=(int*)malloc(n*sizeof(int));
 int *P=T;
 while(l)
  {
    *P=l->val;
    P++;
    l=l->svt;
  }
return T;
}
//.......................
void main(){

int i,v,n;
int Tab[N];
liste L=NULL;
/*printf("Entrer la taille de la liste --> ");
scanf("%d",&n);
printf("Entrez les elements de la liste : \n");
for(i=0;i<n;i++)
{
 printf("l element %d -->\t ",i);
 scanf("%d",&v);
 L=AjoutElemFin(v,L);
}
printf("Affichage de la liste :\n");
AfficherList(L);
//T=ListToTab(L);
AfficherTab(T,n);*/
printf("Entrer la taille du tableau : --->");
scanf("%d",&n);
for(i=0;i<n;i++){
   printf("Tab[%d]=",i);
   scanf("%d",&Tab[i]);
   }
L=TabToList(Tab,n);
AfficherList(L);
}

