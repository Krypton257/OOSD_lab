#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	float a,b,add,sub;
	int z;
	cout<<"Enter the two numbers"<<endl;
	cin>>a>>b;
	add=a+b;
	sub=a-b;
	cout<<"type 1 for addition and type 2 for subtraction"<<endl;
	cin>>z;
	if(z==1)
		printf("%0.5f",add);
	else if(z==2)
		printf("%0.5f",sub);

}