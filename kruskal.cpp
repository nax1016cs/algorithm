#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int root[100005];
int find(int x){
	if(root[x]==x){
		return x;
	}
	else{
		return find(root[x]);
	}
}
int unite(int x,int y){
	int a = find(x);
	int b = find(y);
	root[a]=b;
}
int main(){
	int n,m,r1,r2,w,tr1,tr2,tw;  // n->room, m-->corridor
	cin>>n>>m;
	int mi=9999999;
	int n_corr=0;
	for(int i=0; i<100005; i++){
		root[i]=i;
	}
	vector <pair<pair<int, int >,int > > edge;
	for(int i=0; i<m; i++){
		cin>>r1>>r2>>w;
		edge.push_back(make_pair(make_pair(r1,r2), -1*w));
	}
	sort(edge.begin(),edge.end());
	while(1){
		r1 = edge[n_corr].first.first;
		r2= edge[n_corr].first.second;
		w= edge[n_corr].second*-1;
		tr1 = edge[n_corr+1].first.first;
		tr2= edge[n_corr+1].first.second;
		tw= edge[n_corr+1].second*-1;		
		if(find(r1)!=find(r2)){
			unite(r1,r2);
			mi = min(mi,w);
			if(r2==n-1){
				break;
			}
		}
	n_corr++;
	}
	cout<<mi;
}
