#include <iostream>
#include<map>
#include<string>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int in;  
	int num;
	cin>>in;
	map<string, int > search;			//宣告map 
   	map<string, int >::iterator iter;	//類似陣列的index 
	while(in--){
		search.clear();  //清空map 
		char ttt;
		while(scanf("%c", &ttt)!=EOF && scanf("%c", &ttt)!='\n'){
		cin>>num;
		string  str="";
		char temp;   //暫存讀進來的字元 
		int t=0;     //記錄存幾筆資料 
		int x = 0;   //紀錄目前有幾個數字或者字母 
		for (int i=0; ; i++){
			cin>>temp;
			if(temp >=48 && temp <=57 ){  
				str +=temp; 			//直接加到空的字串後面 
				if(str.length() ==3){
					str = str+'-';
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
				str +=temp;
				if(str.length() ==3){
					str = str+'-';
				}
				x++;							
			}
			if(x/7){					//存好7個數字 
				if(!search.count(str)){	//看map裡面有沒有存過電話號碼 
					search.insert(make_pair(str, 1)); // 沒有的話則存進去電話號碼，次數設為1 
				}
				else {				
					iter = search.find(str);	//已經存過的話找出電話號碼在哪裡 次數+1 
					iter->second ++;			 
				}
				str="";  //重新設為空字串 
				x=0;      
				t++;
			}
			if(t==num){
				break;
			}
		}
		bool test = false;
		for (iter = search.begin(); iter != search.end(); iter++){  //印出大於1的電話號碼 
			if(iter->second>1){
				cout<<iter->first<<" "<<iter->second<<'\n';
				test = true;
			}
		}
		if(!test){
			cout<<"No duplicate."<<'\n';
		}
		break;
		}
	}
	return 0;
}
