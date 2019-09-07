#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	multimap <int, int > m;
	multimap <int, int >::iterator iter; 
	int range, num;
	cin>>range>>num;
	int a,b;
	int pos=0,count=0,tpos=0;
	for(int i=0; i<num; i++){
		cin>>a>>b;
		m.insert(make_pair(a-b,a+b));
	}
	iter = m.begin();
	if( iter->first >0){
		cout<<-1;
		return 0;
		}   
	for(iter = m.begin(); iter!=m.end(); iter++){
		if(iter->first >range){
			break;
		}
		if(iter->first<=pos){
			tpos = max(iter->second, tpos);
			if(tpos >=range){
				count++;
				break;
			}
		}
		else if (iter->first>pos){
			if(iter->first<=tpos){
				pos = tpos;
				tpos = max(iter->second, tpos);
				count++;
			}
			else if (iter->first >tpos){
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
