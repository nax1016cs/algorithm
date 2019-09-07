#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm>
#include <set>
using namespace std;
int s[1001][1001]={2147483647};

void dij(int n, int start,  vector <pair<int, int > > arr[]){
	int dis[n+1];
	vector <pair<int, int > > ::iterator it;
	set< pair<int, int> > ss; 
	for(int i=1; i<=n; i++){
		dis[i] = 2147483647;	 
	}
	dis[start] = 0;
	int find[n+1];
	for(int i=0; i<=n; i++){
		find[i]=0;
	}
	int count =0;
	int t;
	int v;
	ss.insert(make_pair(0,start));
	while(!ss.empty()){	
			pair<int, int> tmp = *(ss.begin()); 
        	ss.erase(ss.begin()); 
			int t = tmp.second; 
			find[t]=1;
		for(it=arr[t].begin(); it!=arr[t].end(); it++){
				if(dis[it->first]>it->second+dis[t]){
					dis[it->first] = it->second + dis[t];	
					if( dis[it->first]==2147483647){
						cout<<"it->first: "<<it->first<<endl;
  						ss.erase(ss.find(make_pair(dis[it->first], it->first)));						
					}
					ss.insert(make_pair(dis[it->first], it->first)); 
				}	  
		}		
	}
	for(int i=1; i<=n; i++){
		s[start][i] = dis[i];
	}
	
} 
int main(){
	int n,m,q; 							
	int a,b,c;
	cin>>n>>m>>q;
	vector <pair<int, int > > arr[n+1];
	vector <pair<int, int > > ::iterator it;
	int d[n+1], pre[n+1];
	int qr[q][2];
	for(int i=0; i<m; i++){
		cin>>a>>b>>c;
		arr[0].push_back(make_pair(a,0));
		arr[a].push_back(make_pair(b,c));
	}
	for(int i=0; i<q; i++){
		cin>>qr[i][0]>>qr[i][1];
	}

	for(int i=0; i<n; i++){
		pre[i] = -1;
		d[i] = 0;
	}
	for(int j=0; j<n-1; j++){   //???? 
		for(int i=1; i<=n; i++){
			for(it=arr[i].begin(); it!=arr[i].end(); it++){
				if(d[it->first]>it->second+d[i]){
					d[it->first] = it->second + d[i];
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(it=arr[i].begin(); it!=arr[i].end(); it++){
			it->second = it->second + d[i] - d[it->first];
		}
	}		
	for(int i=1; i<=n ; i++){
		dij(n,i,arr);
	}
	for(int i=0; i<q; i++){
		if(s[qr[i][0]][qr[i][1]]==2147483647){
			cout<<"no path"<<endl;
		}
		else{
			cout<<s[qr[i][0]][qr[i][1]]-d[qr[i][0]]+d[qr[i][1]]<<endl;			
		}

	} 
}
