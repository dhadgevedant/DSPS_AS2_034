/*
		TO DO LIST:
		
			1. add something to control new line during complex number printing
			2. subtraction is wrong because it is innitially getting subtracted from 0
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
		
		void operator<<(Complex const &obj){
		
			cout<<obj.real<<" + i"<<obj.imag;
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
	
	/*
	Complex a(2,5), b(3,5),d(4,5);
	
	cout<<"a = ";
		print<<a; cout<<endl;
		
	cout<<"b = ";
		print<<b; cout<<endl;
	cout<<"d = ";
		print<<d;	cout<<endl;	
	
	Complex c = a+b+d;
	
	cout<<"a + b + d = ";
		print << c; cout<<endl;
	
	c = d-a;
	cout<<"d - a = ";
	print<<c;	cout<<endl;
	*/
	bool flag = 1;
	
	do{
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
				for(int i = 0; i<n;i++){
					
					cout<<i+1<<". Enter real and imaginary part : ";
					opr>>arr[i];
					
					result  = result - arr[i];
				}
				
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
		
		cout<<"\n\nDo you want to continue: ";
		cin>>flag;
	}while(flag);
	
	
	return 0;
	
}
