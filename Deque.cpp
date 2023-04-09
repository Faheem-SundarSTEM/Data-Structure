/*
	Author --->  Faheem khan
	Code for deque , prz all function of deque ,
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

struct deque
{
	int *arr, *starting ;
	int sz , max_sz;
	deque()
	{
		arr = new int[2] ;
		starting =  &arr[1]; // sub...
		sz = 0 ;
		max_sz = 2 ;
	}
	~deque()
	{
		delete[] arr ;
	}
	void push_back(int x)
	{
		if(/*(arr[max_sz-1]) == (starting[sz - 1])*/ sz == max_sz-1){
			max_sz *= 2 ;
			int *temp = new int[max_sz] ;
			for (int i = max_sz/4 ; i < max_sz/4 + sz  ; i++){
				temp[i] = starting[i- (max_sz/4)] ;
			}
			delete[] arr ;
			arr = temp ;
			starting = arr+max_sz/4;
		}
		starting[sz] = x; 
		sz ++ ;
	}
	void push_front(int x){
		if(arr == starting){
			max_sz *= 2 ;
			int *temp = new int[max_sz] ;
			for (int i = max_sz/4; i < max_sz/4 + sz  ; i++){
				temp[i] = starting[i- max_sz/4] ;
			}
			delete[] arr ;
			arr = temp ;
			starting = arr + max_sz/4;
		}
		sz++;
		starting -- ;
		starting[0] = x ;
	}
	void pop_front(){
		if(starting != arr + max_sz - 1){
			starting++;
			sz --;
		}
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
		return starting[i] ;
	}

};
 // test cases ... 
signed main(){
	int n ;
	cin >> n ;
	deque v ;
	for(int i = 0 ;i < n ;i++){
		int a ;
		cin >> a ;
		v.push_front(a);
	}
	cout << "size = " << v.size() << endl;
	cout << "max_size = " << v.max_size() << endl ;

	for (int i = 0; i < v.size(); ++i)
		cout << v.at(i) << " ";
	cout << endl;

	v.pop_back() ;
	v.pop_back() ;
	v.pop_front();
	v.pop_front();
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for(int i =0 ;i < v.size(); i++){
		cout << v.at(i) << ' ';
	}cout << endl;
	cout << v.size() << endl; 
	cout << v.max_size() << endl ;
}

