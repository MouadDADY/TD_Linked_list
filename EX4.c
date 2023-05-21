#include<stdio.h>
#include<stdlib.h>

struct monome{
	float coef ; 
	int exp ;
};

typedef struct monome monome  ;

struct poly{
	monome m ;
	struct poly* suivant ;
};

typedef struct poly poly ;
typedef poly* Poly  ;

monome creeMonome(int exp , int coef){
	monome m ;
	
	m.exp = exp ;
	m.coef = coef ;
	return m ;
}

Poly ajoutMonome(Poly p , monome  m){
	Poly debut = p ;
	Poly nouveau = (poly*)malloc(sizeof(poly));
	nouveau->m.exp = m.exp ; 
	nouveau->m.coef = m.coef ;
	nouveau->suivant  = NULL ;
	
	if(p == NULL)
	return nouveau ;
	
	if(p->m.exp < nouveau->m.exp)
	{
	nouveau->suivant = p ;
	return nouveau ; 
	}
	while(p->suivant  !=NULL && p->suivant->m.exp >= nouveau->m.exp)
		p=p->suivant ;
	
	if(p->suivant->m.exp  == nouveau->m.exp){
		
		p->suivant->m.coef = p->suivant->m.coef + nouveau->m.coef ;
		
	}
	
	if(p->suivant->m.exp > nouveau->m.exp)
	{
	p->suivant = nouveau ;
	nouveau->suivant = p->suivant->suivant;
	
	}
	
	return debut ;
}
void affichagePoly(Poly p){
	while(p!=NULL){
		
		printf("%f{x}^%d -> ",p->m.coef ,p->m.exp);
		p=p->suivant ;
	}
	printf("NULL");
}


Poly copie(Poly p){
	Poly c = NULL ;
	while(p != NULL){
		c = ajoutMonome(c,p->m);
		p=p->suivant;
	}
	return c ;
}
/*
Poly SommeDeuxPoly(Poly a , Poly b){
	poly c = NULL ;
	monome m ;
	while(a != NULL || b != NULL){
		if(a->m.exp > b->m.exp){
			c= ajoutMonome(c,a->m.exp);
			a=a->suivant;
		}
		
		if(a->m.exp < b->m.exp){
			c= ajoutMonome(c,b->m.exp);
			b=b->suivant;
		}
		
		if(a->m.exp == b->m.exp){
			m.exp = a->m.exp ;
			m.coef = a->m.coef + b->m.coef ;
			c=ajoutMonome(c,m);
			b=b->suivant;
			a=a->suivant;
		}
		
	}
	return c ;
	
}
Poly derive(Poly) p{
	while(p !=NULL){
		p->m.coef = p->m.coef*p->m.exp ;
		p->m.exp = p->m.exp -1 ;
		p=p->suivant ;
	}
	
}
*/
int main(){
	
	Poly p = NULL ;
	monome m   ;
	monome m1 ;
	monome m2 ;
	m.exp =4;
	m.coef = 5 ;
	
	m1.exp =3 ;
	m1.coef = 3 ;
	
	m2.exp =1 ;
	m2.coef = 7 ;
	
	p=ajoutMonome(p,m);
	p=ajoutMonome(p,m1);
	
	affichagePoly(p);	
}
