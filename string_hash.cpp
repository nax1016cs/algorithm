#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	hash <string> h;
	int a,b;
	cin>>a>>b;
	string str[2*a]={""};
	string temp,repeat;
	int num;
	for(int i=0; i<a; i++){
		cin>>temp;
		num = h(temp);
		if(num<0){
			num=num*-1;
		}
		num %=a;	
		do{
			if(temp==str[num]){
				repeat=temp;
			}	
			num+=1;
		}while(str[num]!="");
		str[num] = temp;
	}
	cout<<repeat<<'\n';
	
	return 0;
}


