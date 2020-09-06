#include<iostream>
#include<cmath>
using namespace std;
int getInput(int input)
{
	cout<<"Enter a number to check if palindrome or not: ";
	cin>>input; 
	return input;
}
int palindrome(int input)
{
	int reverse,temp=input, digit; 
	while(temp!=0)
	{
		digit= temp%10;
		reverse= (reverse*10)+digit;
		temp/=10;
	}
	if(reverse==input)
	{
		cout<<"Number is palindrome";
	}
	else
	{
		cout<<"Number is not palindrome";
	}
}
int main() 
{
	int input; 
	input= getInput(input);
	palindrome(input);
	
}



