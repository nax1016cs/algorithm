#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define mk(x, y) make_pair(x, y)
using namespace std;
typedef pair<int, int> pa;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
    vector<pair<int, int> > con[n+2];

	for(int i=0, tmpx, tmpy, w; i<m; i++){
		cin >> tmpx >> tmpy >> w;
		con[tmpx].push_back(mk(tmpy, w));
	}

	for(int i=1; i<=n; i++){
		con[0].push_back(mk(i, 0));
	}

	//Bellman
	int d[n+1];
	for(int i=0; i<=n; i++) d[i] = 1e9;

	d[0] = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<=n; j++){
			for(int k=0; k<con[j].size(); k++){
				int p = con[j][k].first;
				int w = con[j][k].second;
				if(d[j]!=1e9){
					if(d[j]+ w < d[p])
						d[p] = d[j]+w;
				}
			}
		}
	}
	for(int i=0; i<=n; i++){
  cout << "d:" <<i << ' '<<  d[i] << '\n';
 }
	//reweight
	for(int i=1; i<=n; i++){
		for(int j=0; j<con[i].size(); j++){
			int p = con[i][j].first; 
			con[i][j].second += d[i]-d[p];
		}
	}
	//dijkstra


	int distance[n+1][n+1];
	bool judge[n+1][n+1];
	memset(judge, false, sizeof(judge));

	memset(distance, 1, sizeof(distance));
	int visit[n+1];
	int di[n+1];
	priority_queue<pa, std::vector<pa>, std::greater<pa> > pq;
	
	for(int i=1; i<=n; i++){
		memset(visit, 0, sizeof(visit));
		for(int h=0; h<=n; h++) di[h] = 1e9;
		pq = priority_queue<pa, std::vector<pa>, std::greater<pa> >();
		di[i] = 0;

		pq.push(mk(0, i));

		for(int j=0; j<n; j++){
			int a = -1;
			while(!pq.empty() && visit[a = pq.top().second])
				pq.pop();
			if(a==-1){
				break;
			}
			distance[i][a] = di[a]+d[a]-d[i];
			judge[i][a] = true;
			visit[a] = 1;
			for(int k=0; k<con[a].size(); k++){
				int w = con[a][k].second;
				int p = con[a][k].first; 
				if(di[a]+w < di[p]){

					di[p] = di[a]+w;
					if(!visit[p])
						pq.push(mk(di[p], p));
				}
			}
		}

	}
	for(int i=0, qx, qy; i<q; i++){
		cin >> qx >> qy;
		if(distance[qx][qy]!=16843009)
			cout << distance[qx][qy] << '\n';	
		else cout << "no path" << '\n';
	}

}