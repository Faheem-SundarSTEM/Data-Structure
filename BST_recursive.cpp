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
# define print(a) for(auto i:a){cout<<i<<' ';}cout<<endl;
// M_u_h_a_m_m_a_d  S.A.W  ...</>... 
// a == 97 ; 0 == 48  ; A  == 65 ;

struct node
{
    int key;
    node *parent , *left , *right;
    void erase(node *p);
    void insert(int x){
        if (x<=key){
            if (left!=NULL){left->insert(x);}
            else{
                left=new node();
                left->parent = this;
                left-> key = x;}
        }
        else{
            if (right !=NULL){
                right->insert(x);
            }
            else{
                right = new node();
                right -> parent=this;
                right-> key =x;
            }
        }
    }
    node * search(int x){
        if (key==x){return this;}
        else if (x<=key){
            if (left!=NULL){
                return left->search(x);
            }
            else {return NULL;}
        }
        else {
            if (right!=NULL){
                return right->search(x);
            }else{ return NULL; }
        }
    }
    node * max(){
        if (right==NULL){ return this; }
        return right-> max();
    }
    void min(){
        if (left==NULL){ 
            cout << key << endl;
            return;
        }
        left->min();
    }  
};
node *root = NULL;
void node::erase(node *p){
    if (p==NULL){return;}
    if (p->left==NULL and p->right==NULL){
        if (p->parent!=NULL and p->parent->left==p){
            p->parent->left=NULL;
        }
        if (p->parent!=NULL and p->parent->right){
            p->parent->right=NULL;
        }
        if (p==root){
            root=NULL;
        }
        delete p;
    }
    else if (p->left!=NULL and p->right==NULL){
        if (root==p){
            root=p->left;
        }
        if (p->parent != NULL and p->parent->left == p){
            p->parent->left=p->left;
        }
        if (p->parent!=NULL and p->parent->right==p){
            p->parent->right=p->left;
        }
        p->left->parent=p->parent;
        delete p;

    }
    else if (p->left==NULL and p->right!=NULL){
        if (root==p){root=p->right;}
        if (p->parent!=NULL and p->parent->left==p){
            p->parent->left=p->right;
        }
        if (p->parent!=NULL and p->parent->right==p){
            p->parent->right=p->right;
        }
        p->right->parent=p->parent;
        delete p;
    }
    else{
        node *n = p->right->max();
        swap(p->key,n->key);
        erase(n);
    }
}
int main(){
    while (1){
        string command ; cin >> command ;
        if (command == "insert"){
            int x;cin>>x;
            if (root == NULL){
                root = new node;
                root->parent=root;
                root-> key = x;

            }
            else{
                root->insert(x);
            }
        }
        else if (command == "search"){
            int a;cin>>a;
            if (root==NULL){cout<<"Empty"<<endl;}
            else if (root->search(a)!=NULL){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
        else if (command == "max"){
            if (root==NULL){cout<<"Empty : "<<endl;}
            else{cout<<root->max()->key<<endl;}
        }
        else if (command == "min"){
            if (root==NULL){cout<<"Empty : "<<endl;}
            else{root->min();}
        }
        else if (command == "erase"){
            int x ; cin >> x;
            node *t =root->search(x);
            root->erase(t);
        }else{
            cout<<"Command not found : "<<endl;
        }
    }
}
