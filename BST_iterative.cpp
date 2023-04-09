/*
      Author  --> Faheem khan
      Code for Binary search tree iterative (insertion ,search ,deletion , minimum element ,maximum element ) . 
*/
// # include <bits/stdc++.h>
# include <iostream>
# include <vector>  
# include <algorithm>
# include <cmath>
# include <set>
# include <map>
# include <string>
# include <climits>
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
node *search(int x){
	node *p = root;
	while (p != NULL){
		if(p -> key== x){
			return p ;
		}else if (x < p ->key){
			p = p->left;
		} else {
			p = p ->right ;
		}
	}
	return NULL ;
}
void insert(int x){
	node *p = root ;
	node *parent = NULL ;
	while (p != NULL){
		if(x  < p-> key){
			// go left ;
			parent = p; 
			p = p -> left ;
		}
		else {
		    // go right; 
			parent = p ;
			p =p -> right ;
		}
	}
	p = new node() ;
	p -> key = x ;
	p -> parent = parent ;
	if (parent != NULL and p -> key < parent -> key){
		parent -> left = p;
	}
	else if(parent != NULL){
		parent -> right = p ;
	}if(root == NULL){	
		root = p ;
	} 
}
node * min(){
	node * p = root ;
	while(p != NULL and p -> left != NULL){
		p =p -> left ;
	}
	return p ;
}
node *max (node *p = NULL){
	if(p == NULL){
		p = root ;
	}
	while (p != NULL and p -> right != NULL){
		p = p->right ;
	}
	return p ; 
} 
void erase(node *p){
	if(p == NULL){
		return ;
	}
	if(p -> left == NULL and p -> right == NULL){ // p is a leaf 
		if(p -> parent!= NULL and p -> parent -> left == p){
			p-> parent ->left = NULL ;
		}
		if(p -> parent != NULL and p -> parent->right == p/**/){
			p -> parent -> right = NULL ;
		}
		if(p == root){
			root = NULL ;
		}
		delete p ;
	}
	else if (p -> left != NULL and p -> right ==NULL){// p has only a left child
		if(root == p ){
			root = p->left ;
		}
		if(p -> parent != NULL and p -> parent -> left == p){
			p -> parent -> left = p -> left;
		}
		if(p->parent!= NULL and p->parent->right == p){
			p-> parent -> right = p->left ;
		}
		p->left->parent = p->parent;
		delete p ;
	}

	else if (p -> left != NULL and p -> right != NULL){// p has only a left child
		if(root == p ){
			root = p-> right ;
		}
		if(p -> parent != NULL and p -> parent -> left == p){
			p -> parent -> left = p -> right;
		}
		if(p->parent!= NULL and p->parent->right == p){
			p-> parent -> right = p->right ;
		}
		p-> right ->parent = p-> parent;
		delete p ;
	}else { // p has two children  
		node *n = max(p->left);
		swap(p->key, n->key) ;
		erase(n) ;
	}
}

signed main(){

	// srand(20231401);
	while(1){
		string command ; cin >> command ;
		if(command == "insert"){
			int x ;cin >> x;
			insert(x);
		}// insert
		else if (command == "search"){
			int x ; cin >> x ;
			if(search(x) == NULL){
				cout << "NO" << endl;
			}else {
				cout << "YES" << endl ;
			}
		}
		else if (command == "min"){
			 // cout << (min() == NULL ? -1 : min() -> key ) << endl ; 
			if(min() == NULL){
				cout << "Empty : " << endl ;
			}else {
				cout << min()-> key << endl ;
			}
		} 
		else if (command == "max"){
			 //cout << (max() == NULL ? -1 : max()->key )<< endl ;
			if(max() == NULL){
				cout << "Empty : " << endl ;
			}else {
				cout << max()->key << endl ; 
			}
		}else if(command == "erase"){
			int x ; cin >> x;
			erase(search(x)) ;
		}
		else {
			cout << "Command not Found ! " << endl ;
		} 
	}
	return 0 ;
} 
