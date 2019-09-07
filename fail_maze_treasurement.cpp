#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	int a,b;
	cin>>a>>b;
	int count=0;
	char c[a][b];
	int last;
	int t[a],n[a];
	int temp=0;
	int lcount[a]={0},rcount[a]={0};
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cin>>c[i][j];
			if(c[i][j]=='x'){
				count++;
				last=i;
			}
		}
		t[i]=count;
		n[i]=count;
		count=0;
	}
	for(int i=0; i<a; i++){
		while(t[i]){
			if(c[i][temp+1]=='x'){
				t[i]--;
			}
			count++;
			temp++;
		}
		temp=0;
		lcount[i]=count;
		count=0;
	}
	temp = b-1;
	for(int i=0; i<a; i++){
		while(n[i]){
			if(c[i][temp-1]=='x'){
				n[i]--;
			}
			count++;
			temp--;
		}
		temp=b-1;
		rcount[i]=count;
		count=0;
	}
	int l = lcount[last];
	int r = rcount[last];
	for(int i=last-1; i>=0; i--){
		int tl=l;
		int tr=r;
		l=min(tl+lcount[i]*2,tr+b-1);//back to left
		r=min(tr+rcount[i]*2,tl+b-1);//back to right
	}
	cout<<l+last;
	
} 
