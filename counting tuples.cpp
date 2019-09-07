#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a;
	long long int b;
	unordered_map<long long int, int> sum;
	unordered_map<long long int, int>::iterator iter;
	cin>>a>>b;
	long long int temp;
	long long int count = 0;
	long long int s1[a],s2[a],s3[a],s4[a];
	for(int i=0; i<a; i++){
		cin>>s1[i];
	} 
	for(int i=0; i<a; i++){
		cin>>s2[i];
	} 
	for(int i=0; i<a; i++){
		cin>>s3[i];
	} 
 	for(int i=0; i<a; i++){
		cin>>s4[i];
	}
	for(int i=0; i<a; i++){
		for(int j=0; j<a; j++){
			temp = s1[i]+s2[j];
			if(!sum.count(temp)){	
					sum.insert(make_pair(temp, 1));
				}
				else {				
					sum.at(temp)++;		 
				}
		}
	}
	for(int i=0; i<a; i++){
		for(int j=0; j<a; j++){
			temp =  b - s3[i] - s4[j];
			if(sum.count(temp)){	
					count = count + sum.at(temp);
				}
		}
	}	

	cout<<count<<'\n';
	return 0;
}
