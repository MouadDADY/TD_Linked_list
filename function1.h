typedef struct cellule 
  { 
	int val;
	struct cellule *svt;
	
  }Liste,*liste;
//...............Qst N 1.........................................
int nbrElement(liste l)
   {
   	int cpt=0;
   	while(l){
   		cpt++;   		
   		l=l->svt;
	   }
    return cpt;
   }
//.................Qst N 2.......................................
void SomMoyList(liste l,int *s,float *m)
   {
   	int n=nbrElement(l);
   	*s=0;
   	while(l){
   		*s+=l->val;
   		l=l->svt;
	   }
   	*m=(float)*s/n;
   	
   	
   }
//..................Qst N 3.............................
void MinMaxList(liste l,int *min,int *max)
   {
   
   	liste p=l->svt;
   	liste q=l->svt;
	*min=l->val;
   	*max=l->val;
   	while(p)
	   {
	    if(p->val<*min)
   		 *min=p->val;
   		p=p->svt;
	   }
	while(q)
	  {
	    if(q->val>*max)
   		  *max=q->val;
   		q=q->svt;
	   }
	}
//.................Qst N 4...........................
//............. Methode iterative...........................
liste SuppFOIList(liste l,int v)
   {
   	liste lp1,lp2;
   	if(l!=NULL)
   	   if(l->val==v)
   	      {
   	      	lp1=l;
   	      	l=l->svt;
   	      	free(lp1);
		   }
		else
		  {
		  	lp2=l;
		  	while(lp2->svt!=NULL && lp2->svt->val!=v)
		  	    lp2=lp2->svt;
		  	if(lp2->svt!=NULL){
		  		lp1=lp2->svt;
		  		lp2->svt=lp2->svt->svt;
		  		free(lp1);
			  }
		  }
		  return l;
   }
//............. Methode recursive.......................
liste SuppFORList(liste l,int v)
   {
   	liste lp;
   	if(l!=NULL)
   	  if(l->val==v)
   	    {
   	    	lp=l;
   	    	l=l->svt;
   	    	free(lp);
		}
	  else
	    {
	    	l->svt=SuppFORList(l->svt,v);
		}
	return l;
   }
//..................Qst N 5..................
liste InverserList(liste l)
   {
   	liste p,q,nv=NULL;
   	q=l;
   	while(q)
   	   {
   	   	p=q->svt;
   	   	q->svt=nv;
   	   	nv=q;
   	   	q=p;
		 }
	return nv;
	 
   }
//...........Qst N 6.....................
liste TriList(liste l)
   {
   	liste q,p;
   	int tmp;
   	if(l!=NULL)
   	  {
   	  	for(q=l;q->svt!=NULL;q=q->svt)
   	  	   for(p=q->svt;p!=NULL;p=p->svt)
   	  	     {
   	  	     	if(p->val<q->val){
   	  	     		tmp=p->val;
   	  	     		p->val=q->val;
   	  	     		q->val=tmp;
					  }
				  }
		 }
		return l;
   }
//.................Qst N 7............
liste SuppList(liste l)
  {
  	liste p;
  	if(l!=NULL)
  	    
  	   while(l)
	     { 
		    p=l;
	     	l=l->svt;
	    	free(p);
	     }
	return l;
  }
//.............................
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
//........................................
void AfficherList(liste l)
   {
   	while(l)
   	  {
   		printf("(%d)->",l->val);
   		l=l->svt;
	  }
	  printf("NULL\n");
   }
   
   
