#include <iostream>
#include <algorithm>
using namespace std;

void box(pair<int,int> a[],int n){
	long long t[n+1];
	t[0] = 0;	
	for(int i=1; i<= n ;i++){
		t[i] = 1000000000;
	}
	for (int i = 0; i < n; ++i){
		for (int j = n-1; j > 0; --j){
			if(a[i].second + t[j-1] <= a[i].first){
				t[j] = min(t[j],t[j-1] + a[i].second);	
			}	
		}
	}
	for(int i=0 ;i<=n ;i++){
		if(t[i] == 1000000000){
			cout << i-1;
			break;
		}
	}
}
int main(){
	int n;
	cin >> n;
	pair <int,int> p[n];
	for(int i=0; i<n; i++){
		cin>>p[i].second>>p[i].first;
	}
	sort(p,p+n);
	box(p,n);
	return 0;
}
