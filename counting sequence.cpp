#include <iostream>
#include <algorithm>
#include "string.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a,b;
	cin>>a>>b;
	int num[b];
	for(int i=0; i<b; i++){
		cin>>num[i];
	}
	sort(num,num+b);
	int count[1000002];
	memset(count,0,sizeof(count));
	for(int i=0; i<b; i++){
		count[num[i]]++;
	}	
	for(int i=0; i<=a; i++){
		for(int j=0; j<b; j++){
			if(i-num[j]>0){
				count[i] +=  count[i-num[j]];
				count[i] %= 1000000007;			
			}
		} 
	}
	cout<<count[a]<<'\n';
	return 0;
}
