#include<stdio.h>
#include<stdlib.h>

//..............Qst n�1...........
typedef struct cellule 
{
  double coef;
  int exp;
  struct cellule* svt;
}Poly;
//..........Qst n�2.........
Poly* SaisiMonome(int E ,double C)
{
Poly* p=(Poly*)malloc(sizeof(Poly));
  if(E<0)
   printf("Erreur\n");
  else
  {
   p->exp=E;
   p->coef=C;
   p->svt=NULL;
  }
 return p;
}

//............Qst n°3..........
Poly* AjoutMonome(Poly *p,int E,int C)
{  
	Poly *nv, *r ;
	if(p == NULL)
	   return SaisiMonome(E,C);	
	else
       {
        if(E > p->exp)
	      {
           nv=SaisiMonome(E,C);
	       nv->svt = p ;
	       return nv ; 
	       }
           else
               if(E==p->exp)
                 p->coef=p->coef+C;
               else{
                  r=p;     
	              while(r->svt!=NULL && r->svt->exp > E)
		                r=r->svt ;
	              if(r->svt!=NULL && r->svt->exp==E)
		             r->svt->coef=p->svt->coef+C;
	              else 
	                  {
                       nv=SaisiMonome(E,C);
	                   nv->svt = r->svt;
	                   r->svt = nv;
	                  }
                 } 
				 return p ;
         }   
}
//.............Qst n°4..............
Poly * CopiePoly(Poly *P)
{
 Poly* cp=NULL;
 Poly *R=P;
 while(R){
      cp=AjoutMonome(cp,R->coef,R->exp);
      R=R->svt;
      }
 return cp;
}
//..............Qst n°5............
Poly *Somme(Poly *p, Poly *q)
{
Poly* Som=CopiePoly(p);
Poly* R=q;
while(R){
   Som=AjoutMonome(Som, R->exp ,R->coef );
   R=R->svt ;
   }
return Som;
}
//..................Qst n�6........................
Poly* derive(Poly* p){
	while(p !=NULL){
		p->coef = p->coef*p->exp ;
		p->exp = p->exp -1 ;
		p=p->svt ;
	}
}
//..........Qst n°7............
void affichPoly(Poly *p){
	while(p!=NULL){
		
		printf("%.2lf{x}^%d -> ",p->coef ,p->exp);
		p=p->svt ;
	}
	printf("NULL\n");
}
//............................................................
void main(){
	int i,n,e;
	double c;
	Poly *p = NULL;
    Poly *q = NULL;
    Poly *d = NULL;
    Poly *copie = NULL;
    Poly *som = NULL;
	printf("Entrer le nombre de monome Dans votre Poly 1:");
	scanf("%d",&n);
    for(i=0;i<n;i++){
    	printf("Entrer monome %d: Coef puis exp\t ",i);
    	scanf("%lf %d",&c,&e);
    	p=AjoutMonome(p,e,c);
	}
	printf("Entrer le nombre de monome Dans votre Poly 2:");
	scanf("%d",&n);
    for(i=0;i<n;i++){
    	printf("Entrer monome %d: Coef puis exp\t ",i);
    	scanf("%lf %d",&c,&e);
    	q=AjoutMonome(q,e,c);
	}
	affichPoly(p);
    affichPoly(q);
    d=derive(p);
    copie=CopiePoly(q);
    som=Somme(p,q);
    affichPoly(d);
    affichPoly(som);
    affichPoly(copie);
}

