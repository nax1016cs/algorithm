#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int main(){
	int n,m,r1,r2,w;
	priority_queue <pair<int, int> > q;
	bool find[10001];
	int t;
	int index=0;
	int mi = 99999;
	memset(find,false ,10001);
	cin>>n>>m;
	vector<pair<int,int> >arr[10001];
	vector<pair<int,int> >::iterator it;
	for(int i=0; i<m; i++){
		cin>>r1>>r2>>w;
		arr[r1].push_back(make_pair(w,r2));
		arr[r2].push_back(make_pair(w,r1));		
	}
	q.push(make_pair(mi,0));
	while(1){
		pair<int, int> top = q.top();
		t = top.second;
		mi = top.first;
		if(t==n-1){
			mi = top.first;
			break;
	}
		find[t]=true;
		q.pop();
		for(it=arr[t].begin(); it!=arr[t].end(); it++){
			if(!find[it->second]){
				q.push(make_pair(min(it->first,mi),it->second));
			}
		}
	}
	cout<<mi;
}
