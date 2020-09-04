#include<iostream>
using namespace std; 
int display(int num1, int num2, int num3)
{
	if(num1>num2)
	{
		if(num1>num3)
		{
			cout<<num1<<" is the biggest";
		}else
		{
			cout<<num3<<" is the biggest";
		}
	}else if(num2>num3)
	{
		cout<<num2<<" is the biggest";
	}else
	{
		cout<<num3<<" is the biggest";
	}
}
int main() 
{
	int num1, num2, num3; 
	cin>>num1>>num2>>num3; 
	display(num1, num2, num3);	
}


