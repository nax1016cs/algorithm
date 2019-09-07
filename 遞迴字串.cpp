#include<stdio.h>
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
bool equ(char *a, char *b, int length){
	if(!strncmp(a,b,length)){//完全相同 
		return true;
	} 	
	else  if(!(length%2)){    //偶數 
		int mid = length/2;

		if(equ(a, b,mid) && equ(a+mid, b+mid, mid)){
			
			return true;
		}
		else if(equ(a+mid, b,mid) && equ(a,b+mid,mid)){
		
			return true;
		}
		else {						
			return false;
			
		}
	}
	else  //奇數 
	{
			return false;
	}

}
int main()
{
	char a[300005], b[300005];
	cin>>a>>b;
		int length = strlen(a);
		if(equ (a,b,length) && strlen(a) == strlen(b)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
    return 0;
}
