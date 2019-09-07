#include <bits/stdc++.h> 
using namespace std; 

int d[100001]; 

int bfs(int init, vector<int> arr[], int n) 
{ 
	int i;
    queue<int> q; 
    q.push(init); 
    int visited[n + 1]; 
    for (int i = 0; i <= n; i++) { 
        visited[i] = 0; 
        d[i]=0;
	}
    visited[init] = 1; 
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        for (int i = 0; i < arr[u].size(); i++) { 
            if (visited[arr[u][i]] == 0) { 
                visited[arr[u][i]] = 1; 
                d[arr[u][i]] = d[u] + 1; 
                q.push(arr[u][i]); 
            } 
        } 
    }
    int max =0;
    for( i=0; i<=n; i++){
    	if(d[i]>d[max])
    		max = i;
	}
	return max;
}   



int main() 	
{ 
    int n;
    cin>>n;
    int a,b;
    vector<int> arr[n]; 
    for(int i=0; i<n-1; i++){
    	cin>>a>>b;
    	arr[a].push_back(b);
    	arr[b].push_back(a);
	}
    int k = bfs(0, arr, n); 
    int l = bfs(k, arr, n);
    cout<<d[l];

  
    return 0; 
}
