/*
	Author --->  Faheem khan,
	Code for vector , prz all functions of vector .

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

struct vect
{
	int *arr ;
	int sz , max_sz;
	vect()
	{
		arr = new int[1];
		sz = 0;
		max_sz = 1;
	}
	~vect()
	{
		delete[] arr;
	}
	void push_back(int x)
	{
		if(sz == max_sz){
			max_sz *= 2 ;
			int *temp = new int[max_sz] ;
			for (int i = 0; i < sz ;i++){
				temp[i] = arr[i] ;
			}
			delete[] arr ;
			arr = temp ;
		}
		arr[sz] = x ; 
		sz ++ ;
	}
	void pop_back()
	{
		if(sz > 0){
			sz -- ;
		}
	}
	int size()
	{
		return sz ;
	}
	int max_size()
	{
		return max_sz ;
	}
	int at(int i)
	{
		return arr[i] ;
	}

};
 // test cases ... 
signed main(){
	int n ;cin >> n ;
	vect v ;
	for(int i = 0 ;i < n ;i++){
		int a ;cin >> a ;
		v.push_back(a) ;
	}
	cout << "size = " << v.size() << endl;
	cout << "max_size = " << v.max_size() << endl ;
	cout << v.at(0) << ' ' << v.at(1) << ' ' <<  v.at(2) << ' ' << v.at(3) << endl ;
	v.pop_back() ;
	v.pop_back() ;
	cout << v.at(0) << ' ' << v.at(1) << ' '  << endl ;;
	cout << v.size() << endl; 
	cout << v.max_size() << endl ;
}
