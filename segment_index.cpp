#include <iostream>
#include <algorithm>
#include <math.h> 
using namespace std;
int global_high;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void construct(long long int input[], long long int segment[], int low, int high, int pos ){
	if(low == high){
		segment[pos] = low ;//input[low]
		return;
	}
	int mid = (low + high)/2;
	construct(input, segment, low, mid, 2*pos+1);
	construct(input, segment, mid+1, high, 2*pos+2);
	if(input[segment[2*pos+1]] >= input[segment[2*pos+2]]){
		segment[pos] = segment[2*pos+1];
	}
	else{
		segment[pos] = segment[2*pos+2];
	}		
}

long long int query(long long int input[],long long int segment[],int tlow, int thigh, int low, int high, int pos/*0*/){
	if(tlow <=low && thigh>=high){  //完全重疊 
		return segment[pos]; //最大index
	}
	if(tlow>high || thigh<low){ //完全不重疊 
		return global_high;
	}
	int mid = (low + high)/2;
	
	long long int a = query(input,segment, tlow, thigh, low ,mid, 2*pos+1);
	long long int b = query(input,segment, tlow, thigh, mid+1 , high, 2*pos+2);		
	//return max(query(segment, tlow, thigh, low ,mid, 2*pos+1),query(segment, tlow, thigh, mid+1, high, 2*pos+2))
	if(input[a] >= input[b]) {
		return a;
	}
	else {
		return b;
	}
}

int main(int argc, char** argv) {
	//長度為n的陣列，segment的長度為2*n+1 
	int n, c;
	cin>>n>>c;
	int t = 2*pow(2,ceil(log2(n)))+1;
	long long int num[n+1];
	for(int i=0; i<n; i++){
		cin>>num[i];
	}
	num[n] = -1;
	int group[c][2];	
	for(int i=0; i<c; i++){
		for(int j=0; j<2; j++){
			cin>>group[i][j];
		}
	}	
	global_high = n;
	long long int segment[t]={0};
	construct(num,segment,0,n-1,0);
	for(int i=0; i<c; i++){
		cout<<query(num,segment,group[i][0]-1,group[i][1]-1,0,n-1,0 )+1<<endl;
	}
	return 0;
}
