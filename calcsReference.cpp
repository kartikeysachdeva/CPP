#include<iostream>
#include<cmath>
using namespace std;
void sumAvgProd(float num1, float num2, float &sum, float &avg, float &prod)
{
	sum= num1+num2; 
	avg= sum/(2);
	prod= (num1*num2);
}
void input(float &num1, float &num2)
{
	cout<<"Enter two float values: ";
	cin>>num1>>num2;
}
void output(float num1, float num2, float sum, float avg, float prod)
{
	cout<<"\nSum: "<<sum;
	cout<<"\nAverage: "<<avg;
	cout<<"\nProduct: "<<prod; 
}

int main() 
{
	float x,y,sum,avg,prod;
	input(x,y);
	sumAvgProd(x,y,sum,avg,prod);
	output(x,y,sum,avg,prod);
}



