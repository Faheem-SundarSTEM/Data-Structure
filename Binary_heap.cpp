/*
    Author --> Faheem khan.
    this is the code for binary heap...
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
# define print(a) for(auto i:a){cout<<i<<' ';}cout<<endl;
// M_u_h_a_m_m_a_d  S.A.W  ...</>... 
// a == 97 ; 0 == 48  ; A  == 65 ;

int const limit = 1e7 ;
int heap[limit] ;
int num = 0, n = 1 ;
// bubble up function 
void b_up(int i){
    if (heap[i/2] < heap[i] && i!=1){
        swap(heap[i],heap[i/2]) ;
        b_up(i/2);
    }
}
// bubble down function.
void b_down(int i){
    if (2*i <= n && heap[i]<heap[2*i] && (2*i+1 <= n or heap[2*i+1] < heap[2*i])){
        swap(heap[2*i],heap[i]);
        b_down(2*i) ;
    }
    if (2*i+1 <= n && heap[2*i+1] > heap[i]){
        swap(heap[2*i+1],heap[i]);
        b_down(2*i+1) ;
    }
}

signed main(){
    while(true){
        string command ; cin >> command ;
        if (command == "insert"){
            int a ; cin >> a ;heap[n] = a ;n++ ;
            b_up(n-1);
        }
        else if(command == "max"){
            if (n<=1){cout <<"Empty : "<< endl;}
            else{cout<<heap[1]<<endl;}
        }
        else if (command == "delete_max"){
            swap(heap[1],heap[n]); n--;
            b_down(1) ;
        }
        else if (command == "increase_key"){
            int s,d;cin>>s>>d;heap[s]+=d ;
            b_up(s);
        }
        else if(command == "decrease_key"){
            int s,d;cin>>s>>d;heap[s]-=d;
            b_down(s);
        }
        else if (command == "make_heap"){
            cin>>n;
            for (int t=1;t<=n;t++){
                int f;cin>>f;heap[t]=f;
            }
            n++;
            for(int i=n;i>=1;i--){
                b_down(i);
            }
        }else {
            cout << "Command not Found ! " << endl;
        }
    }
}
