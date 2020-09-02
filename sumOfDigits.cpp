#include<iostream>
using namespace std; 
main()
{
	int temp, digit=0, sum=0, num;
	cout<<"Enter a number: ";
	cin>>num;
	
	temp=num;
	while(temp!=0)
	{
		digit=temp%10;
		sum+=digit;
		temp/=10;
	}
	cout<<"The sum of digits of "<<num<<" is "<<sum; 
}
