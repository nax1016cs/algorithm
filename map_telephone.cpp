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
	map<string, int > search;			//�ŧimap 
   	map<string, int >::iterator iter;	//�����}�C��index 
	while(in--){
		search.clear();  //�M��map 
		char ttt;
		while(scanf("%c", &ttt)!=EOF && scanf("%c", &ttt)!='\n'){
		cin>>num;
		string  str="";
		char temp;   //�ȦsŪ�i�Ӫ��r�� 
		int t=0;     //�O���s�X����� 
		int x = 0;   //�����ثe���X�ӼƦr�Ϊ̦r�� 
		for (int i=0; ; i++){
			cin>>temp;
			if(temp >=48 && temp <=57 ){  
				str +=temp; 			//�����[��Ū��r��᭱ 
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
			if(x/7){					//�s�n7�ӼƦr 
				if(!search.count(str)){	//��map�̭����S���s�L�q�ܸ��X 
					search.insert(make_pair(str, 1)); // �S�����ܫh�s�i�h�q�ܸ��X�A���Ƴ]��1 
				}
				else {				
					iter = search.find(str);	//�w�g�s�L���ܧ�X�q�ܸ��X�b���� ����+1 
					iter->second ++;			 
				}
				str="";  //���s�]���Ŧr�� 
				x=0;      
				t++;
			}
			if(t==num){
				break;
			}
		}
		bool test = false;
		for (iter = search.begin(); iter != search.end(); iter++){  //�L�X�j��1���q�ܸ��X 
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
