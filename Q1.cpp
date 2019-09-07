#include <iostream>
#include <set> 
using namespace std;

int main(){
	multiset<long long int> s;
	multiset<long long int> ::iterator it;
	long long int n,temp,t;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>temp;
		s.insert(temp);
	}
	while(s.size()>1){
		it = s.begin();
		temp = *it;
		s.erase(it);
		it = s.begin();
		t = *it;
		s.erase(it);
		s.insert(t*2+temp*2);
	}
	it = s.begin();
	cout<<*it;
} 
