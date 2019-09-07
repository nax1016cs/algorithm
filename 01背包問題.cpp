#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a,b;
	cin>>a>>b;
	long long int dp[a+1][b+1];
	long long int p[a][2];
	memset(p,0,sizeof(p));
	memset(dp,0,sizeof(dp));
	for(int i=0; i<a; i++){
		for(int j=0; j<2; j++){
			cin>>p[i][j];
		}
	}
    for (int i = 0; i < a; i++) {        //種類 
         for (int j = 0; j <= b; j++){   //重量 
            if (j - p[i][0] < 0){
               dp[i+1][j] = dp[i][j];       	
			}
            else{
                 dp[i+1][j] = max(dp[i][j], dp[i][j - p[i][0]] + p[i][1]);	
			}        	
		}   	
	}	
	cout<<dp[a][b]<<endl;   



	return 0;
}
