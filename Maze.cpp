#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int a,b;
	cin>>a>>b;
	int count =0;
	char temp;
	char t[b+1];
	t[0]='1';
	for(int i=0; i<a; i++){
		for(int j=1; j<b+1; j++){
			cin>>temp;
			if(count==0){
				if(temp=='x'||t[j-1]=='0'){
					t[j] = '0';
				}
				else {
					t[j] = '1';
				}
			}
			else if (count>0){
				t[0]='0';
				if((t[j-1]=='0' && t[j]=='0') || temp=='x'){
					t[j] = '0';
				}
				else {
					t[j] = '1';
				}
			}
		}
		count++;
	}
	if(t[b]=='1'){
		cout<<"Yes"<<'\n';
	}
	else{
		cout<<"No"<<'\n';
	} 
	return 0;
}
