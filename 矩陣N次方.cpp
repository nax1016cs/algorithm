#include <iostream>
#define p 999999937
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
unsigned long long int caculate(int n){
	int power=1;
	unsigned long long int matrix[2][2]={1,2,1,0};
	unsigned long long int tmatrix[2][2]={1,2,1,0};
	unsigned long long int a=1, b=1;
	unsigned long long int ta=1, tb=1;		
	while(power!=n){
		if( n==1 || n==0){
			break;
		}		
		while(power*2<= n){
			matrix[0][0] = (tmatrix[0][0]%p*tmatrix[0][0]%p+tmatrix[0][1]%p*tmatrix[1][0]%p)%p;
			matrix[0][1] = (tmatrix[0][0]%p*tmatrix[0][1]%p+tmatrix[0][1]%p*tmatrix[1][1]%p)%p;
			matrix[1][0] = (tmatrix[1][0]%p*tmatrix[0][0]%p+tmatrix[1][1]%p*tmatrix[1][0]%p)%p;
			matrix[1][1] = (tmatrix[1][0]%p*tmatrix[0][1]%p+tmatrix[1][1]%p*tmatrix[1][1]%p)%p;	
			tmatrix[0][0]=matrix[0][0]; tmatrix[0][1]=matrix[0][1]; tmatrix[1][0]=matrix[1][0];tmatrix[1][1]=matrix[1][1];
			power *=2;
			if(power*2>n){
				n = n - power;
				power=1;
				break;
			}							
		}
		a = (matrix[0][0]%p*ta + matrix[0][1]%p *tb)%p;
		b = (matrix[1][0]%p*ta + matrix[1][1]%p *tb)%p;	
		ta = a; tb = b;	
		matrix[0][0]=1; matrix[0][1] = 2; matrix[1][0] = 1; matrix[1][1]=0;
		tmatrix[0][0]=1; tmatrix[0][1] = 2; tmatrix[1][0] = 1; tmatrix[1][1]=0;			
	}	
	    if(n==1){
	    	a = (ta%p + 2*tb%p)%p;	
		}
	    return a; 
}
int main(int argc, char** argv) {
	int n;
	while(cin>>n){
		unsigned long long int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		for(int i=0; i<n; i++){
			if(a[i]==1 || a[i]==2){
				cout<<1<<endl;
			}
			else{
				cout<<caculate(a[i]-2)<<endl;		
			}
		}
	}
	
	return 0;
}
