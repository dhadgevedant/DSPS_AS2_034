/*
*/

#include<iostream>
#include<string>
#include<cctype>
#include <vector>
using namespace std;




int main(){

	cout<<"Enter your string: ";
	string str;
	cin>>str;
		
	vector <char> vec = {str[0]};
			
	for(int i=1;i<str.length();i++){
		
		bool init = 0;
		
		for(int j = 0; j< vec.size();j++){
			
			if(str[i] == vec[j]) init = 1;
		}
		
		if(init == 0){
			
			vec.push_back(str[i]);
		}
		
	}
	
	cout<<"\n\nin string \""<<str<<"\" :\n"<<endl;
	
	for(int j = 0; j< vec.size();j++){
		
		int count = 0;
		vector<int> pos;
		for(int i=0; i<str.length();i++){
			
			if(vec[j] == str[i]){
				count++;
				pos.push_back(i);
			}
		
		}
		
		cout<<"\'"<<vec[j]<< "\' occurs "<<count<<" times, on these positions: ";
		for(int k =0;k<pos.size();k++) cout<<pos[k]<<" ";
		cout<<endl;
	}	
	
	
	
	
	
	cout<<endl;
	return 0;
}

/*

 	FUNC TO GENRATE Uarray
 	
	itterate to array
	if element is unique 
		push into uarray
	else 
		continue
		
	vector <char> vec = {str[i]};
			
	for(int i=1;i<str.length();i++){
		
		bool init = 0;
		
		for(int j = 0; j< vec.length();j++){
			
			if(str[i] == vec[j]) init = 1;
			
		}
		
		if(init == 0){
			
			vec.push_back(str[i]);
		}
		
	}
				

*/


/*

	char s1[100],s2[100];
	
	cout<<"Enter the string: ";
	cin>>s1;
	
	//CALCULATINE LENGHT OF STRING 1;	
	int templen = 0,len = 0;
	while(s1[len]!='\0')len++;
	
	templen = len;
	
	cout<<"\nLength pf the string is: "<<len<<endl;
	
	//COPYING S1 TO S2
	for(int i=0;i<len;i++) s2[i] = s1[i];

	cout<<"\nCopied string from s1 to s2: ";
	for(int i=0;i<len;i++) cout<<s2[i];
	
	//CONCATNATING S1 AND S2 AND STORING INTO S1
	for(int i = templen, j=0; s2[j] != '\0'; j++, i++, len++) s1[i] = s2[j];
	
	cout<<"\n\nConcatonated string: ";
	for(int i=0;i<len;i++) cout<<s1[i];
	
	//REVERSING S1 AND STORING INTO S2
	for(int i=len-1,j=0;i>=0;i--,j++)s2[j] = s1[i];
	
	cout<<"\n\nReversed string: ";
	for(int i=0;i<len;i++) cout<<s2[i];
	
	cout<<"\n\n";


*/
