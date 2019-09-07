#include <iostream>
#include <set>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int d,n;
	cin>>d>>n;
	multiset<int> s;
	int temp;
	for(int i=0; i<n; i++){
		cin>>temp;
		s.insert(temp);		
	}
	for(int i=0; i<n-1; i++){
		it = s.end();
		it--;
		temp = *it -d;
		s.erase(it);			
		it = s.end();
		it--;
		s.erase(it);
		s.insert(temp);				
	}
	cout<<*s.begin();
	return 0;
}
