	/*
		TO DO LIST:

*/

#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

class Complex{
	

	public:
		
		double real;
		double imag;
		
		void disp(){

			cout<<real<<" + i"<<imag<<endl;
		}


	//OVERLOADED OPERATORS	
		
		Complex operator+( Complex obj){
			
			Complex res;
			res.real = real + obj.real;
			res.imag = imag + obj.imag;
			
			return res;

		}
		
		Complex operator-( Complex obj){
			
			Complex res;
			res.real = real - obj.real;
			res.imag = imag - obj.imag;
			
			return res;

		}
		
		void operator<<(Complex obj){
			
			if(obj.imag>=0)
			cout<<obj.real<<" + i"<<obj.imag;
			
			else{
				obj.imag*=-1;
				cout<<obj.real<<" - i"<<obj.imag;
			}
		}
		
		void operator>>(Complex &obj){
			cin>>obj.real;
			cin>>obj.imag;
		}
		
		
		
	//CONSTRUCTORS
		Complex(){
			
			real = 0;
			imag = 0;

		}
		
		Complex(double real, double imag){
			
			this->real = real;
			this->imag = imag;
			
		}
	
	
}print,input,opr;


int main(){
	
	//main_loop:
	
		cout<<"Main Menue\n\n\t1. Add Complex numbers\n\t2. Subtract Complex numbers\n\nEnter your choice: ";
		int ch; cin>>ch;
		
		switch(ch){
	
			case 1:{
				
				Complex result;
				
				cout<<"How many numbers do you want to add: ";
				int n;	cin>>n;
				
				Complex arr[n];
				for(int i = 0; i<n;i++){
					
					cout<<i+1<<". Enter real and imaginary part : ";
					opr>>arr[i];
					
					result  = result + arr[i];
				}
			
			//PRINTING OUTPUT
				
				for(int i = 0; i<n-1;i++){

					cout<<"(";
					opr<<arr[i];
					cout<<") + ";
				}
					cout<<"(";
					opr<<arr[n-1];
					cout<<") = ";
					
					opr<<result;
												
				break;
			}
			
			case 2:{
				
				Complex result;
				
				cout<<"\nHow many numbers do you want to subtract: ";
				int n;	cin>>n;
				
				Complex arr[n];
				cout<<1<<". Enter real and imaginary part : ";
				opr>>arr[0];
				
				result = arr[0];
					
				for(int i = 1; i<n;i++){
					
					cout<<i+1<<". Enter real and imaginary part : ";
					opr>>arr[i];
					
					result  = result - arr[i];
				}
				
				
			//PRINTING OUTPUT
							
				for(int i = 0; i<n-1;i++){

					cout<<"(";
					opr<<arr[i];
					cout<<") - ";
				}
					
					cout<<"(";
					opr<<arr[n-1];
					cout<<") = ";
					
					opr<<result;
												
				break;
			}

		}
		
		char yn;

		user_ch: //user_ch GOTO JUMP point
			
			cout<<"\n\nDo you want to continue(y/n): ";
			cin>>yn;
				
			if(yn == 'y'||yn == 'Y')main();
			else if(yn == 'n'||yn == 'N')return 0;
		else goto user_ch;//JUMP TO user_ch
			
}


