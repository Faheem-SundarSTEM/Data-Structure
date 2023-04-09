/*
      Author --> Faheem Khan.
      Rotation code for Binary search tree .
*/
// # include <bits/stdc++.h>
# include <iostream>
# include <vector>  
# include <algorithm>
# include <cmath>
# include <set>
# include <map>
# include <string> 
using namespace std ;
# define int long long
# define all(x) (x).begin(),(x).end()
# define f_Actoral ios::sync_with_stdio(false); cin.tie(0) ;
# define print(a) for(auto i:a){cout<<i<<' ';}cout<<endl ;
// M_u_h_a_m_m_a_d  S.A.W  ...</>... 
// a == 97 ; 0 == 48  ; A  == 65 ;

struct  node 
{
	int key ;
	node *parent , *left , * right;	
};
node *root = NULL ;
void rotate(node *x){
	if(x == root or x == NULL){
		return ;
	}
	node *p = x -> parent ; // is not NULL 
	node *g = p -> parent ; // might be NULL
	node *A , *B , *C ; // might be NUll 
	if (p -> left == x){ // case 1 
		A = x -> left;  // might be null ;
		B = x -> right ; // might be null ;
		C = p -> right ; // might be null ;
		if(g != NULL and g -> left == p){
			g -> left = x;
		}
		if(g != NULL and g -> right == p){
			g -> right = x ;
		}
		if (root == p){
			root = x ;
		}  
		x -> parent = g ;
		// x  -> left = A ;
		x -> right = p ;
		if( B != NULL){
			B->parent = p ;
		}
		p -> parent = x ;
		p -> left = B ;
	}
	else {  // if (p -> right == x -- case )
		A = p->left ;
		B = x -> left;
		C = x -> right;
		if (root == p){
			root = x ;
		}
		if(g != NULL and g -> left == p){
			g -> left = x;
		}
		if(g != NULL and g -> right == p){
			g-> right = x ;
		}
		x -> parent= g ;
		x -> left = p;

		p -> parent =x ;
		p -> right = B;
		if (B!= NULL)
			B -> parent = p;
	}
}
