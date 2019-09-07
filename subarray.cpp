#include <iostream>
using namespace std;


int main(int argc, char** argv) {
	int length;
	int l=1, r=1;
	int temp;
	cin>>length;	
	int count=0;
	long long int arr[length];
	for(int i=0; i<length; i++){
		cin>>arr[i];
	}
	int ttt=-99999999;
	int tti;
	long long int max = -1;
	long long int sum = 0;
	int templ;
	for(int i = 0; i<length; i++){
		sum+=arr[i];
		if(arr[i]<0){
			count++;
			if(arr[i]>ttt){
				ttt=arr[i];
				tti=i+1;
			}
		}
		if(sum<0){
			sum=0;
			templ=i+1;
		}
		if(sum>max){
			max = sum;
			r=i+1;
			l=templ;
		}
	}
	if(count==length){
		cout<<tti<<" "<<tti;
	}
	else {
		cout<<l+1<<" "<<r<<endl;	
	}

}
