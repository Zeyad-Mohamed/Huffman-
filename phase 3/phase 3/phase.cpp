#include <iostream>
#include <stdio.h>
using namespace std;

class ctreenode
{
public:
	int value;
	char exp[5000];
	ctreenode *pleft;
	ctreenode *pright;
};
class cnode
{
	public :
		int value;
		char exp[5000];
		cnode *pnext;
		ctreenode *pdown;
};
class codenode
{
	public :
		char exp;
		int code[100];
		int ct;
		codenode *pnext;
};
class codelist
{
	public :
	codenode *phead ;
	codenode *ptail ;

	codelist ()
	{
		phead = NULL ;
		ptail = NULL ;
	}

	~codelist () 
	{
		codenode *ptrav;

		ptrav=phead;

		while ( ptrav != NULL )
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead ;
		}
	}
	void attach ( codenode *pnn )
	{
		codenode *pb;
		codenode *ptrav;

		pb=NULL;
		ptrav=phead;

		while ( ptrav != NULL )
		{
			if ( ptrav->ct > pnn ->ct )
			{
				break;
			}
			pb=ptrav;
			ptrav=ptrav->pnext;
		}
		if ( pb != NULL )
		{
			pb->pnext=pnn;
		}
		else
		{
			phead=pnn;
		}
		pnn->pnext=ptrav;
	}
	void dispall ()
	{
		codenode *ptrav ;
		ptrav = phead ;
		while ( ptrav != NULL )
		{
			cout<<"EXP"<<"  >>  ";
			cout<<ptrav->exp;
			cout<<endl;
			int i=0;
			cout<<"CODE"<<"  >>  ";
			while ( i < ptrav->ct )
			{
			cout<<ptrav->code[i]<<'|';
			i++;
			}
			cout<<endl;
			ptrav=ptrav->pnext;
		}
	}
};

class clist
{
public :
	cnode *phead ;

	clist ()
	{
		phead = NULL ;
	}
	void attach ( cnode *pnn )
	{
		cnode *pb;
		cnode *ptrav;

		pb=NULL;
		ptrav=phead;

		while ( ptrav != NULL )
		{
			if ( ptrav->value > pnn ->value )
			{
				break;
			}
			pb=ptrav;
			ptrav=ptrav->pnext;
		}
		if ( pb != NULL )
		{
			pb->pnext=pnn;
		}
		else
		{
			phead=pnn;
		}
		pnn->pnext=ptrav;
	}
	void dispall ()
	{
		cnode *ptrav;

		ptrav=phead;

		while ( ptrav != NULL )
		{
			int i=0;
			while ( ptrav->exp[i] != NULL )
			{
			cout<<ptrav->exp<<"|";
			i++;
			}
			cout<<endl;
			cout<<ptrav->value;
			cout<<endl;
			cout<<"-------------";
			cout<<endl;
			ptrav=ptrav->pnext;
		}
	}


};

class compnode
{
public :
	int value;
	int ct;
	compnode *pnext;
};

class listcomp
{
		public :
	compnode *phead ;
	compnode *ptail ;

	listcomp ()
	{
		phead = NULL ;
		ptail = NULL ;
	}

	~listcomp () 
	{
		compnode *ptrav;

		ptrav=phead;

		while ( ptrav != NULL )
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead ;
		}
	}
	void attach ( compnode *pnn )
	{
		if ( phead == NULL )
		{
			pnn->ct++;
			phead = pnn ;
			ptail = pnn ;
		}
		else
		{
			pnn->ct=ptail->ct;
			pnn->ct++;
			ptail -> pnext = pnn ;
			ptail = pnn ;
		}
	}
	void dispall ()
	{
		compnode *ptrav ;
		ptrav = phead ;
		while ( ptrav != NULL )
		{
			cout<<ptrav->value;
			cout<<endl;
			ptrav=ptrav->pnext;
		}
	}
};





void main ()
{
	clist L;
	codelist hk;
	listcomp lc;
	cnode *ptrav;
	cnode *ptrav2;
	cnode *pnn;
	ctreenode *parent;
	ctreenode *pchildl;
	ctreenode *pchildr;

	//------------

	char x[5000];
	char y[5000];
	int ct;
	int k;
	int i;
	char f;
	int g;
	int flag;
	int q=0;
	char zero;
	char one;
	int ibit;

	gets(x);

	ptrav = L.phead;
	for ( i=0 ; x[i] != NULL ; i++ )
	{
		ptrav = new cnode;
		for ( int f=0 ; f<5000 ; f++ )
		{
			ptrav->exp[f]=' ';
		}
		f=0;
		ptrav->value=0;
		ptrav->exp[f]=x[i];
		ptrav->exp[f+1]=NULL;
		g=0;
		while ( x[g] != NULL )
		{
			if ( ptrav->exp[f] == x[g] )
			{
				ptrav->value++;
			}
			g++;
		}
		ptrav->pdown=NULL;
		ptrav->pnext=NULL;

		ptrav2=L.phead;
		flag=0;
		while ( ptrav2 != NULL )
		{
			int k=0;

			if ( ptrav2->exp[k] == ptrav->exp[k] )
			{
				flag=1;
			}
			ptrav2=ptrav2->pnext;
		}
		if ( flag == 0 )
		{
		L.attach(ptrav);
		}
	}
	cnode *dum;
	dum=L.phead;

	while ( dum->pnext != NULL )
	{
		int k;
		k=0;
		ptrav=dum;

		ptrav2=ptrav->pnext;
		L.phead=ptrav2->pnext;
	
		int flagd=0;


		if ( ptrav->pdown == NULL && ptrav2->pdown == NULL && flagd==0)
		{
			flagd=1;
			k=0;
			pnn = new cnode;

			pnn->value=ptrav->value+ptrav2->value;
			pnn->exp[k]=ptrav->exp[k];
			pnn->exp[k+1]=ptrav2->exp[k];
			pnn->exp[k+2]=NULL;


			parent = new ctreenode;

			parent->value=pnn->value;
			parent->exp[k]=pnn->exp[k];
			parent->exp[k+1]=pnn->exp[k+1];
			parent->exp[k+2]=pnn->exp[k+2];

			pchildl=new ctreenode;

			pchildl->value=ptrav->value;
			pchildl->exp[k]=ptrav->exp[k];
			pchildl->exp[k+1]=NULL;
			pchildl->pleft=NULL;
			pchildl->pright=NULL;

			pchildr=new ctreenode;

			pchildr->value=ptrav2->value;
			pchildr->exp[k]=ptrav2->exp[k];
			pchildr->exp[k+1]=NULL;
			pchildr->pleft=NULL;
			pchildr->pright=NULL;

			parent->pleft=pchildl;
			parent->pright=pchildr;
			pnn->pdown=parent;


			ptrav->pnext=NULL;
			ptrav2->pnext=NULL;
			delete ptrav;
			delete ptrav2;
		}

		if ( ptrav->pdown != NULL && ptrav2->pdown != NULL && flagd==0)
		{
			flagd=1;
			pnn = new cnode;
			k=0;
			pnn->value=ptrav->value+ptrav2->value;
			int t;
			t=k;
			while ( ptrav->exp[t] != NULL )
			{
			pnn->exp[t]=ptrav->exp[t];
			t++;
			}

			while ( ptrav2->exp[k] != NULL )
			{
				pnn->exp[t]=ptrav2->exp[k];
				t++;
				k++;
			}
			pnn->exp[t]=NULL;


			parent = new ctreenode;

			parent->value=pnn->value;
	
			k=0;
			while ( pnn->exp[k] != NULL )
			{
				parent->exp[k]=pnn->exp[k];
				k++;
			}
			parent->exp[k]=NULL;
			parent->pleft=ptrav->pdown;
			parent->pright=ptrav2->pdown;

			pnn->pdown=parent;


			ptrav->pnext=NULL;
			ptrav2->pnext=NULL;
			delete ptrav;
			delete ptrav2;
	
		}

		if ( ptrav->pdown != NULL && ptrav2->pdown == NULL && flagd==0 )
		{
			flagd=1;
			pnn = new cnode;

			pnn->value=ptrav->value+ptrav2->value;
			int t;
			k=0;
			t=k;
			while ( ptrav->exp[t] != NULL )
			{
				pnn->exp[t]=ptrav->exp[t];
				t++;
			}
			while ( ptrav2->exp[k] != NULL )
			{
				pnn->exp[t]=ptrav2->exp[k];
				t++;
				k++;
			}
			pnn->exp[t]=NULL;


			parent = new ctreenode;

			parent->value=pnn->value;
			k=0;
			while ( pnn->exp[k] != NULL )
			{
				parent->exp[k]=pnn->exp[k];
				k++;
			}
			parent->exp[k]=NULL;
			parent->pleft=ptrav->pdown;
	
			pchildr=new ctreenode;
			k=0;
			pchildr->value=ptrav2->value;
			pchildr->exp[k]=ptrav2->exp[k];
			pchildr->exp[k+1]=NULL;
			pchildr->pleft=NULL;
			pchildr->pright=NULL;

			parent->pright=pchildr;

			pnn->pdown=parent;


			ptrav->pnext=NULL;
			ptrav2->pnext=NULL;
			delete ptrav;
			delete ptrav2;
	
		}


		if ( ptrav->pdown == NULL && ptrav2->pdown != NULL && flagd==0)
		{
			flagd=1;
			pnn = new cnode;
			k=0;
			pnn->value=ptrav->value+ptrav2->value;
			int t;
			t=k;
			while ( ptrav->exp[t] != NULL )
			{
				pnn->exp[t]=ptrav->exp[t];
				t++;
			}
			while ( ptrav2->exp[k] != NULL )
			{
				pnn->exp[t]=ptrav2->exp[k];
				t++;
				k++;
			}
			pnn->exp[t]=NULL;



			parent = new ctreenode;

			parent->value=pnn->value;
			k=0;
			while ( pnn->exp[k] != NULL )
			{
				parent->exp[k]=pnn->exp[k];
				k++;
			}
			parent->exp[k]=NULL;
			parent->pright=ptrav2->pdown;
			k=0;
			pchildl=new ctreenode;

			pchildl->value=ptrav->value;
			pchildl->exp[k]=ptrav->exp[k];
			pchildl->exp[k+1]=NULL;
			pchildl->pleft=NULL;
			pchildl->pright=NULL;

			parent->pleft=pchildl;

			pnn->pdown=parent;


			ptrav->pnext=NULL;
			ptrav2->pnext=NULL;
			delete ptrav;
			delete ptrav2;
		}
	
		L.attach(pnn);

		dum=L.phead;
	}



	ptrav=L.phead;



	


	ctreenode *tempp;
	ctreenode *templ;
	ctreenode *tempr;
	codenode *hcode;
	codenode *hcoder;

	char dss;
	
	tempp=ptrav->pdown;
	hcode=new codenode;
	hcode->ct=0;
	dss=tempp->exp[0];
	hcode->pnext=NULL;
	int v=0;
	int j=0;
	
	while ( ptrav->pdown->exp[v] != NULL )
	{
		
		
		templ=tempp->pleft;
		tempr=tempp->pright;
		
		
	
				int u=0;

			for  ( ; ;  )
			{

				if ( dss == templ->exp[u] )
				{
					hcode->code[j]=0;
					hcode->ct++;
					j++;
					
					tempp=templ;
					break;
				}
				if(templ->exp[u]==NULL)
				{
					break;
				}
				u++;
			}

			    
				u=0;

			for  ( ; ;  )
			{
				if ( dss == tempr->exp[u] )
				{
					hcode->code[j]=1;
					hcode->ct++;
					j++;
					
					
					tempp=tempr;
					break;
				}
				if(tempr->exp[u]==NULL)
				{
					break;
				}
				
				u++;
			}

			if (tempp->pleft==NULL&&tempp->pright==NULL)
			{
					hcode->exp=ptrav->pdown->exp[v];
					hk.attach(hcode);
					hcode= new codenode;
					hcode->ct=0;
					j=0;
					hcode->pnext=NULL;
					tempp=ptrav->pdown;
					v++;
					dss=ptrav->pdown->exp[v];
			}
	}

	hk.dispall();



	codenode *trav;

	int m=0;
	zero = 0;
	one = 1;
	ibit = 7;
	int r=0;
	int e=0;


	while ( x[m] != NULL )

	{ 
		if ( m > 0 && r < trav->ct )
		{
		while ( r < trav->ct )
			{
			
				if ( trav->code[r] == 1 )
				{
					zero = zero | ( one << ibit );
				}
				else
				{
				}

			ibit-- ; 
			r++;
			}
		}
		
		trav=hk.phead;

		while ( trav != NULL )
		{
			
			if ( trav->exp == x[m] )
			{
				break;
			}
			trav=trav->pnext;
		}

		r=0;
			while ( r < trav->ct && ibit >=0 )
			{
			
				if ( trav->code[r] == 1 )
				{
					zero = zero | ( one << ibit );
				}
				else
				{
				}

			ibit-- ; 
			r++;
			}


			if ( ibit < 0 || x[m+1] == NULL )
			{
				y[e]=zero;
				e++;
				y[e]=NULL;
				ibit = 7;
				zero=0;
			}
			m++;
	}
	cout<<y;
	cout<<endl;
		


	int c=0;
	char s[5000];
	char target;
	char check;
	char res;
	int b=0;
	int o=0;

	ibit = 7;
	check=1;


	compnode *trav2;
	codenode *trav3;

	trav3=hk.phead;

	while ( y[c] != NULL )
	{

		target=y[c];

		while ( ibit >= 0 )
		{
		trav2 = new compnode;
		trav2->ct=0;

		res=target & ( check << ibit );
		if ( res != 0 )
		{
			trav2->value=1;
		}
		else
		{
			trav2->value=0;
		}

		trav2->pnext=NULL;
		lc.attach(trav2);

		ibit--;
		trav3=hk.phead;


		while ( trav3 != NULL )
		{
			o=0;
			trav2=lc.phead;

			if ( lc.ptail->ct == trav3->ct )
			{
				while ( o < trav3->ct )
				{
					if ( trav2->value == trav3->code[o] )
					{
						o++;
						trav2=trav2->pnext;
					}
					else
					{
						break;
					}
				}
			}
			if ( o == trav3->ct )
			{
				break;
			}

			trav3=trav3->pnext;
		}
		if ( trav3 != NULL )
		{
		if ( o == trav3->ct )
			{
				s[b]=trav3->exp;
				b++;
				s[b]=NULL;
				lc.~listcomp();
				break;
			}
		}

		}
		if ( ibit < 0 )
		{
			ibit=7;
			c++;
		}
		
}
	cout<<endl;
	cout<<endl;
	cout<<s;
	cout<<endl;
	}
	