#include <stdio.h>
#include <stdlib.h>
typedef struct cellule 
  { 
	int val;
	struct cellule *svt;
	
  }Liste,*liste;
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
void Afficher(liste l)
{
	while(l!=NULL)
	{
		printf("(%d)->",l->val);
		l=l->svt;
	}
	printf("NULL");
}

//....................................
liste FusionnerList(liste l1,liste l2)
  {
  	liste p1=l1,p2=l2;
  	liste l=NULL;
  	while( p1!=NULL && p2!=NULL)
  	   {
  	   	if(p1->val<p2->val)
  	   	    {
            l=AjoutElemFin(p1->val,l);
  	   		p1=p1->svt;
			 }
		else
		   {
            l=AjoutElemFin(p2->val,l);
  	   		p2=p2->svt;
		   }
       } 
       if(p1==NULL)
         {  
		 while(p2!=NULL){
         	l=AjoutElemFin(p2->val,l);
         	p2=p2->svt;
			 }
		 }
		if(p2==NULL)
         {  
		 while(p1!=NULL){
         	l=AjoutElemFin(p1->val,l);
         	p1=p1->svt;
		 }
		 }
  
  	return l;	
  }
//.....................................
void main() {
   liste l1=NULL, l2=NULL, l=NULL;
   l1=AjoutElemFin(0,l1);
   l1=AjoutElemFin(1,l1);
   l1=AjoutElemFin(11,l1);
   l1=AjoutElemFin(21,l1);
   l1=AjoutElemFin(30,l1);
   Afficher(l1);
   printf("\n");
   l2=AjoutElemFin(3,l2);
   l2=AjoutElemFin(5,l2);
   l2=AjoutElemFin(8,l2);
   l2=AjoutElemFin(9,l2);
   l2=AjoutElemFin(20,l2);
  l2=AjoutElemFin(44,l2);
   l2=AjoutElemFin(44,l2);
   Afficher(l2);
   printf("\n");
   l=FusionnerList(l1,l2);
   Afficher(l);
   printf("\n");
}
