#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Stack{
	
	
	public:
	
		vector<char> cvec;

		void push(char inp){

			cvec.push_back(inp);
		}
		
		char pop(){
			
			char res;
	
			if(cvec.size()==0){
				cout<<"STACK UNDERFLOW"<<endl;
			}

			else{
				res = cvec[cvec.size()-1];
				cvec.pop_back();
			}

			return res;	
		}
};

int main(){
	
	
	//DECLARATION AND USER INPUT
	
		Stack stack;
		
		cout<<"\nEnter string to check palindrome: ";
		string inps; getline(cin,inps);
	//-----------------------------------------------//
	
	
	//PUSHING INTO STACK, AVOIDING SPACES AND CAPITAL LETTERS

		for(int i=0 ; i < inps.length() ; i++){
			
			if(inps[i] == ' ')
				
				continue;//IGNORING SPACE WHILE PUSHING
				
			else if(isupper(inps[i]))
				
				stack.push( inps[i] + 32);//CONVERTING UPPERCASE TO LOWERCASE,THEN PUSHING INTO STACK
		
			else
				stack.push(inps[i]);
		
		}
	
	//---------------------------------------------------------------------------//	
	
	//COPYING VECTOR TO CHECK RIGHT TO LEFT ELEMENTS
		vector<char> palincheck = stack.cvec;
						
	//------------------------------------------------//
	
	//POPING FROM STACK AND CHECKING EACH ELEMENT
		
		bool flag = 1;
		
		for(int i = 0; i < palincheck.size(); i++){
			
			char a = stack.pop();
			
			if(palincheck[i] != a) flag = 0;
					
		}
	//----------------------------------------------------//
	
	
	//CHECKING FLAG AND GIVING CORRESPONDING OUTPUT
	
		if(flag)
			cout<<"\nGiven string is palindrome"<<endl;
		else
			cout<<"\nGiven string is NOT palindrome"<<endl;		
	//----------------------------------------------------//	
	return 0;
}

