#include <iostream>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a,b;
	cin>>a>>b;
	int num[a];
	int s1[b],s2[b];
	for(int i=0; i<a; i++){
		cin>> num[i];
	}
	for(int i=0; i<b; i++){
		cin>>s1[i]>>s2[i];
	}
	int sum[1000010]={0};
	for(int i=0; i<a; i++){
		sum[num[i]]++;
	}
	for(int i=1; i<1000000; i++){
		sum[i]= sum[i] + sum[i-1];
	}
	for(int i=0; i<b; i++){
		cout<<sum[s2[i]] - sum[s1[i]-1]<<endl;
	} 
	return 0;
}
