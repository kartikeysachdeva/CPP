#include<iostream>
using namespace std; 
main()
{
	int x,y,temp;
	cout<<"Enter a num 1 - ";
	cin>>x;
	cout<<"Enter a num 2 - ";
	cin>>y;
	
	cout<<"num 1 before - "<<x<<" num 2 before - "<<y;
	
	temp=x;
	x=y;
	y=temp;
	
	cout<<"\nnum 1 after - "<<x<<" num 2 after - "<<y;	
}
