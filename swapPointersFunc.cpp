#include<iostream>
#include<cmath>
using namespace std;
int swap(int *num1, int*num2)
{
	int temp; 
	temp=*num1;
	*num1=*num2; 
	*num2=temp; 
}

int main() 
{
	int x,y;
	cout<<"Enter Num 1: ";
	cin>>x;
	cout<<"Enter Num 2: ";
	cin>>y;
	cout<<"\nBEFORE\n";
	cout<<"Num 1: "<<x<<"\nNum 2: "<<y;
	swap(&x,&y);
	cout<<"\nAFTER";
	cout<<"\nNum 1: "<<x<<"\nNum 2: "<<y;
}



