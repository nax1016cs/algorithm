#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int range,num;
	cin>>range>>num;
	pair<int, int > c[num];
	int a,b;
	for(int i=0; i<num; i++){
		cin>>a>>b;
		c[i].first = a-b;
		c[i].second = a+b;
	}
	sort(c,c+num);
	int pos=0, tpos=0, count=0;
	if( c[0].first >0){
		cout<<-1;
		return 0;
		}  
	for(int i=0; i<num; i++){
		if(c[i].first >range){
			break;
		}
		if(c[i].first<=pos){
			tpos = max(c[i].second, tpos);
			if(tpos >=range){
				count++;
				break;
			}
		}
		else if (c[i].first>pos){
			if(c[i].first<=tpos){
				pos = tpos;
				tpos = max(c[i].second, tpos);
				count++;
			}
			else if (c[i].first >tpos){
				cout<<-1;
				return 0;
			}
		}
	}
	if(tpos<range ){
		cout<<-1;
	}
	else {
		cout<<count;
	}
}
