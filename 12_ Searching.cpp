
#include<iostream>
using namespace std;
class to_search
{
	int a[10];
	int n;
	public:
	void getdata()
	{
		
		cout<<"Enter the number of students"<<endl;
		cin>>n;
		cout<<"enter the roll number of students\n";
		for(int i=0;i<n;i++)
		{
			cout<<"enter the roll number of student number "<<i+1<<"\n";
			cin>>a[i];
			cout<<"\n";
		}
	}
	void linear_search()
	{	
		int flag=0,key;
		cout<<"enter the element to be searched\n";
		cin>>key;
		int i=0;
		while(i<n)
		{
			if(a[i]==key)
			{
				cout<<"key found at"<<i+1<<"\n";
				flag=1;
				i++;
			}
			else
			{
				i++;
			}
		}
		if(flag==0)
		{	
			cout<<"the search element is not found\n";
		}
	}
	void sentinal_search()
	{
		
		int key;
		int i=0;
		
		n=n+1;
		cout<<"enter the search element\n";
		cin>>key;
		a[n]=key;
		while(key!=a[i])
		{
			i++;
		}
		if(i<n-1)
		cout<<"serach element found\n";
		else
		cout<<"search elemet not found\n";
	}
	int binary_search(int a[],int low,int high,int key)
	{
		int mid;
		if(low<=high)
		{
			mid=(low+high)/2;
			if(a[mid]==key)
			{
				return 1;
			}
			else if(key>a[mid])
			{
				binary_search(a,mid+1,high,key);
			}
			else
			{
				binary_search(a,low,mid-1,key);
			}
			return 0;
		}
	}
	void binarysearch()
	{
		int low=0,high=n-1;
		int mid,key;
		cout<<"ENTER THE SEARCH ELEMENT \n";
		cin>>key;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(a[mid]==key)
			{
				cout<<"KEY FOUND AT LOCATION "<<mid<<"\n";
				break;
			
			}
			else if(key>a[mid])
			{
				low=mid+1;
			}
			else
			high=mid-1;
		}
		if(low>high)
		cout<<"KEY NOT FOUND\n";
	}	
			
				
				
	
};	
int main()
{
	to_search x;
	int k=0;
	while(k!=5)
	{
		cout<<"1.LINEAR SEARCH\n";
		cout<<"2.SENTINAL SEARCH\n";
		cout<<"3.BINARY SEARCH WITH RECURSIVE FUNCTION \n";
		cout<<"4.BINARY SEARCH WITHOUT RECURSIVE FUNCTION \n";
		cout<<"5.EXIT\n";
		cout<<"ENTER YOUR OPTION\n";
		cin>>k;
		switch(k)
		{
			case 1:
				cout<<"**************************** \n";
				cout<<"OPERATION OF LINEAR SEARCH\n";
				x.getdata();
				x.linear_search();
				continue;
			case 2:
				cout<<"**************************** \n";
				cout<<"OPERATION OF SENTINAL SEARCH\n";
				x.getdata();
				x.sentinal_search();
				continue;
			case 3:
				cout<<"**************************** \n";
				int num,key;
				int ar[10];
				cout<<"OPERATION OF BINARY SEARCH\n";
			cout<<"FOR BINARY SEARCHING PLEASE ENTER THE ROLL NUMBER OF STUDENTS IN SORTED ORDER\n";
				cin>>num;
				for(int i=0;i<num;i++)
				{
					cout<<"ENTER THE ROLL NUMBER OF STUDENT"<<i+1<<"\n";
					cin>>ar[i];
					cout<<"\n";
				}
				cout<<"ENTER THE SEARCH ELEMENT\n";
				cin>>key;
				int p;
				p=x.binary_search(ar,0,num-1,key);
				if(p==1)
				cout<<"element found\n";
				else
				cout<<"element not found\n";
				cout<<"**************************** \n";
				continue;
			case 4:
			cout<<"FOR BINARY SEARCHING PLEASE ENTER THE ROLL NUMBER OF STUDENTS IN SORTED ORDER\n"; 
				x.getdata();
				x.binarysearch();
				continue;
			case 5:cout<<"THANK YOU\n";
				break;
		}
	}
	return 0;
}


		
