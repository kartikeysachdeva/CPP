#include<iostream>
using namespace std; 
main()
{
	int i,j,num, temp, digit=0, sum=0, count=0;
	cout<<"Enter a number: ";
	cin>>num;
	
	for(i=0;i<num;i++)
	{
		for(j=1;j<=i;j++)
		{	
			count++;
			cout<<count;
		}
		cout<<"\n";
	}
}
