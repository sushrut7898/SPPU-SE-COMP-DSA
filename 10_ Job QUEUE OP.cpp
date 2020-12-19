
#include<iostream>
using namespace std;

class queue1
{
int queue[5];
int maxsize;
int front,rear;
public:
queue1()
{
for(int i=0;i<5;i++)
queue[i]=0;
maxsize=5;
front=rear=-1;


}
	void insert()
	{int t=isfull();
	if(t!=1){
	rear++;
	cout<<"\nEnter Order id : ";
	cin>>queue[rear];
	cout<<"\n ";
	display();}
	}
	int isempty()
	{
	if(front==rear)
	return 1;
	else 
	return 0;
	}
	int isfull()
	{
	if(rear==(maxsize-1))
	return 1;
	else 
	return 0;
	
	}
	void deletes()
	{
	int t=isempty();
	if(t!=1)
	{
	front++;
	cout<<"\n Deleted Value is : "<<queue[front];
	display();
	}
	}
	
	void display()
	{
	
	cout<<"\nThe Queue is.\n";
	for(int i=front+1;i<=rear;i++)
	{cout<<queue[i]<<"  ";}
	}
	
};

int main()
{
int p;
char ch;
queue1 q;
do
{

cout<<"\nEnter 1 to Add element in queue.\n Enter 2 to delete element from queue.\nEnter 3 to Display queue.\n Enter 4 to check if queue is full.\n Enter 5 to check if queue is empty.\n : ";
cin>>p;
switch(p)
{
case 1:q.insert();
	break;
case 2: q.deletes();
	break;
case 3: q.display();
	break;
case 4:int m;m=q.isfull();
	if(m!=1)
	cout<<"Queue is not Full.\n";
	else 
	cout<<"Queue is Full.\n";
	break;
case 5:int n;n=q.isempty();
	if(m!=1)
	cout<<"Queue is not Empty.\n";
	else 
	cout<<"Queue is Empty.\n";
	break;
default:cout<<"Not a Valid Choice.\n";

}

cout<<"Enter choice :";
cin>>ch;
}while(ch=='y');

}


/*
orders are served in first come first services .order once placed cant be canceled. write c++ program to simulate link list using circular queue using array.*/

