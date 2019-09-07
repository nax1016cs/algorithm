#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int in;
	int num;
	cin>>in;
	while(in--){
		char tt;
		while(scanf("%c", &tt)!=EOF && scanf("%c", &tt)!='\n'){
		cin>>num;
		int count[num]={0};  //all are -1, save for telephone number;
		char temp;
		int x =0;
		for (int i=0; ; i++){
			cin>>temp;
			if(temp >=48 && temp <=57 ){
			  	temp = temp -48;
			  	if(count[x/7]==0){
			  		count[x/7]+=temp;
				  }
				else {
					count[x/7] = count[x/7]*10+temp;	
				}
				x++;
			}
			else if (temp >=65 && temp<=89){
				if(temp =='A' || temp == 'B' || temp =='C'){
				 temp ='2';
				}
				else if(temp =='D' || temp == 'E' || temp =='F'){
				 temp ='3';
				}
				else if(temp =='G' || temp == 'H' || temp =='I'){
				 temp ='4';
				}
				else if(temp =='J' || temp == 'K' || temp =='L'){
				 temp ='5';
				}
				else if(temp =='M' || temp == 'N' || temp =='O'){
				 temp ='6';
				}
				else if(temp =='P' || temp == 'R' || temp =='S'){
				 temp ='7';
				}
				else if(temp =='T' || temp == 'U' || temp =='V'){
				 temp ='8';
				}
				else if(temp =='W' || temp == 'X' || temp =='Y'){
				 temp ='9';
				}
			  	temp = temp -48;
			  	if(count[x/7]==0){
			  		count[x/7]+=temp;
				  }
				else {
					count[x/7] = count[x/7]*10+temp;	
				}
				x++;							
			}
			if(x==7*num){
				break;
			}
		}
	 sort(count, count+num);
	 int out [num][2]={0};
	 int c = 0;
	 int t ;
	 t = count[0];
	 int y=0;
	 for(int i=0; i<num; i++){
	 	if(count[i+1] == t){
	 		if(c==0){
	 			c+=2;
			 }
			 else {
		 		c++;		 	
			 }
		 }
		 else {
		 	if(c>0){
			 	out [y][0] = t;
		 		out [y][1] = c;
		 		y++;
			 }
		 	t = count[i+1];
		 	c = 0;
		 }
	 }
	 if(out[0][1]==0){
	 	cout<<"No duplicate."<<endl;
	 }
	 else {
	 	for(int i=0; ; i++){
	 		if(out[i][1]==0){
	 			break;
			 }
			else {
				cout<< setw(3)<<setfill('0')<<out[i][0]/10000<<"-"<<setw(4)<<setfill('0')<<out[i][0]%10000<<" "<<out[i][1]<<endl;
			} 
		}
	}
	break;
}
	}
	
	return 0;
}
