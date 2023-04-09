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

int mod = 1e6 ;
struct node{
    int key , priority;
    node *left,*right;
};
node *r_r(node * y){
    node * x = y->left , * t = x->right;
    x->right = y ; y->left = t;
    return x;
}
node *l_r(node * x){
    node *y = x->right , * t = y->left;
    y->left = x ; x->right = t;
    return y;
}
node *insert(node *root ,int saa){
    if(root == NULL){
        int k = rand() % mod;
        node * temp = new node;
        temp -> key = saa;
        temp ->priority = k;
        temp -> left = temp -> right= NULL;
        return temp ;
    }
    if(saa <= root->key){
        root->left = insert(root->left,saa);
        if(root->priority < root->left->priority){
            root = r_r(root);
        }
    }else{
        root->right = insert(root->right,saa);
        if(root->priority < root->right->priority){
            root = l_r(root);
        }
    }
    return root;
}   

string search(node *root , int saa){
    if(root==NULL){
        return "0";
    }else{
        int y = 0;
        node * x = root;
        while(y!=1){
            if(x->key == saa){
                y = 1;
            }else if(x-> key < saa){
                if(x->right==NULL){break;}
                else
                    x = x->right;
            }else{
                if(x->left==NULL){break;}
                else
                    x = x->left;
            }
        }
        if(y==1){
            return "1";
        }else
            return "0";
    }
}

void min(node *root){
    if(root==NULL)
        cout << "EMPTY : " << endl;
    else{
        node * x = root;
        node * y;
        while(x!=NULL){
            y = x;
            x = x->left;
        }
        cout << y-> key << endl;
    }
}
void max(node *root){
    if(root==NULL)
        cout << "EMPTY :" << endl;
    else{
        node * x = root;
        node * y;
        while(x!=NULL){
            y = x;
            x = x->right;
        }
        cout << y-> key << endl;
    }
}

node * erase(node *root , int saa){
    if(root==NULL){
        return NULL;
    }if(saa<root->key){
        root->left = erase(root->left,saa);
    }else if(saa > root->key){
        root->right = erase(root->right,saa);
    }else{
        if(root->left==NULL){
            node * t =  root->right;
            delete(root);root = t;
        }else if(root->left!=NULL){
            node * t = root->left;
            delete(root);root = t;
        }else if(root->left->priority <= root->right->priority){
            root  = l_r(root);
            root->left = erase(root->left , saa);
        }else if(root->left->priority > root->right->priority){
            root = r_r(root);
            root->right =  erase(root->right,saa);
        }
    }
    return root;
}

signed main(){
    srand(time(0));
    node  *root = NULL ;
    while (true){
        string s ;cin >> s ;
        if(s == "insert"){
            int i ;cin >> i ;
            root = insert(root ,i);
        }
        else if(s == "max"){
            max(root);
        }
        else if(s == "min"){
            min(root);
        }
        else if(s == "search"){
            int a;cin >> a ;
            string bin = search(root , a) ;
            if(bin == "1"){
                cout << "YES" << endl; 
            }else{
                cout << "NO" << endl ;
            }
        }
        else if(s == "erase"){
            int a;cin >> a ; 
            erase(root , a);
        }
        else{
            cout << "Command not found :" << endl ;
        }
    }        
}


