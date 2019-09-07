#include <algorithm>
#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	long long int a[n]={0};
	for(int i=0; i<n; i++)
	{
		cin>>a[i];	
	}
	if(n==1)
	{
		cout<<a[0];
	}
	else{
		int mid = n/2;
		long long int leftsum =0;
		long long int leftmax=0;
		long long int rightsum=0;	
		long long int rightmax=0;
		for(int i=mid; i>0; i--){
			leftsum+=a[i];
			if(leftsum>leftmax){
				leftmax = leftsum;
			}
		}
		for(int i=mid+1; i<n; i++){
			rightsum+=a[i];
			if(rightsum>rightmax){
				rightmax = rightsum;
			}
		}
		long long int MAX;
		if(rightmax>leftmax){
			MAX = max(leftmax+rightmax,rightmax);
		}
		else if(leftmax>rightmax){
			MAX = max(leftmax, leftmax+rightmax);
		}
		else{
			MAX = leftmax+rightmax;
		}
		cout<<MAX<<endl;		
	}
	return 0;
}

