/*
            1
          1 2 1
        1 2 3 2 1
      1 2 3 4 3 2 1
*/

#include<iostream>
using namespace std; 
int spaces(int temp)
{
	int j;
	for(j=0;j<=temp;j++)
	{
		cout<<"  ";
	}
}


int display(int num1)
{
	int temp,temp1,i,j;
	temp=num1;
	for(i=1;i<num1;i++)
	{
		spaces(temp);
		for(j=1;j<i;j++)
		{
			cout<<j<<" ";
		}
		for(j=i;j>=1;j--)
		{
			cout<<j<<" ";
		}
		cout<<"\n";
		temp--;
	}
}
int main() 
{
	int num1; 
	cin>>num1; 
	display(num1);	
}


