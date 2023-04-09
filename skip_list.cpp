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

# define mod 1e6 + 10 
# define N 1000000000
struct node{
	int key;node *left, *right, *up, *down;
	int lls ;
};
struct skip_list{
	vector <node *> heads , tails;
	skip_list(){
		node *h = new node ; node *t = new node ;
		h->key=-N ; t->key= N; h->right=t ; t->left=h;
		h-> lls = t -> lls = 0;
		heads.push_back(h) ; tails.push_back(t);
	}
	void insert(int x){
		node *p=heads[heads.size()-1];
		while(1){
			if(p->right->key<=x){p=p->right;}
			else if (p->down!=NULL){
				p=p->down;
			}
			else{break;}
		}
		node *p_x_n=NULL;
		while(1){
			node *x_n = new node;
			x_n -> key = x ; x_n -> left = p;
			x_n ->right = p-> right ; x_n -> lls = p-> lls ;
			x_n-> down = p_x_n ;
			if (p_x_n != NULL){
				p_x_n -> up = x_n;
			}
			p_x_n = x_n;
			p->right->left = x_n ; p->right = x_n ;
			if (rand()%2){
				node *newp=p;
				while(newp->up==NULL and newp->left!=NULL){
					newp=newp->left;
				}
				if (newp->up==NULL){
					node *h =new node ;node *t = new node ;
					h->key=- N; t->key= N; h->right=t ; t->left=h;
					h-> lls = t-> lls = heads.size();
					h->down=heads.back();t->down=tails.back();
					heads.back()->up=h;tails.back()->up=t;
					heads.push_back(h);tails.push_back(t);
				}
				newp = newp->up ;p = newp;
			}else{break;}
		}
	}
	void erase(node *p){
		if (p==NULL){
			return;
		}
		while(p->down!=NULL){
			p=p->down;
		}
		while(p!=NULL){
			node *l=p->left;node *r=p->right;
			l->right=r;r->left=l;node *pcopy=p;p=p->up;
			delete pcopy;
		}
	}
	node *search(int x){
		node *p=heads.back();
		while(1){
			if (p->key==x){return p;
			}
			else if (p->right->key<=x){p=p->right;
			}
			else if (p->down!=NULL){ p=p->down;
			}
			else{return NULL;
			}
		}
	}
	int max(){
		return tails[0]->left->key  ;}
	int min(){
		return heads[0]->right->key;}
};
signed main(){
    srand(time(0)) ; skip_list l;
    while(1){
        string com;cin>>com;
        if(com=="insert"){
            int x ; cin >> x  ; l.insert(x);
        }
        else if(com=="search"){
            int x; cin>>x;
            node* p = l.search(x);
            if(p==NULL or p->key!=x)
                cout<< "NO" <<endl;
            else
                cout << "YES" << endl;
        }
        else  if (com=="erase"){
        	int x;cin>>x;
        	l.erase(l.search(x));
        }
        else if(com=="max"){
            int j=l.max();
            if(abs(j)== N){
                cout<<"Empty : "<<endl;
            }
            else{
                cout<<j<<endl;
            }
        }
        else if(com=="min"){
            int j=l.min();
            if(abs(j)==N){
                cout<<"Empty : "<<endl;
            }
            else{
                cout<<j<<endl;
            }
        }
		else {
			cout << "Command not found : " << endl ;
		}
	}
	return 0;
}
