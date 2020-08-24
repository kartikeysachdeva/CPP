#include <iostream>
using namespace std;
main()
{
	int temp, num1, num2; 
	cout<<"Enter 1st num = ";
	cin>>num1;
	cout<<"Enter 2nd num = ";
	cin>>num2;
	cout<<"\nBefore switch 1st num = "<< num1<< " 2nd num = "<< num2;
	temp= num1;
	num1=num2;
	num2=temp;
	cout<<"\nAfter switch 1st num = "<< num1<< " 2nd num = "<< num2;
}
