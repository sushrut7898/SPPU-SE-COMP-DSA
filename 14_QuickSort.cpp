
#include<iostream>
using namespace std;
class quick
{
	float a[30];
	int n;
	float pivot;
	public:
	int partition(int,int);
	void sort(int,int);
	void getdata();
	void display();
	int retsize();
	void top();
};

void quick::getdata()
{
	cout<<"\n\nEnter the number of students : ";
	cin>>n;
	cout<<"\nEnter the percentages : \n";
	for(int i=0;i<n;i++)
	{
		cout<<"For Student "<<i+1<<" : ";
		cin>>a[i];
	}
}

void quick::display()
{
	cout<<"\nINPUT : percentages are : \n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
}

void quick::top()
{
	if(n>=5)
	{
	        cout<<"****************************";
	        cout<<"\nThe top 5 scorers are : \n";
	        cout<<"****************************\n";
	        
	        for(int i=n-1;i>=n-5;i--)
	        {
	                cout<<a[i]<<"\t";
	        }
	        cout<<"\n";
	}
	else
	        cout<<"\nError : Less number of entries in the database to show results. ( Atleast 5 required )\n";
	 
}

int quick::retsize()
{
	return n;
}

int quick::partition(int low,int high)
{
	pivot=a[low];
	int i=low+1,j=high;
	float temp;
	while(i<j)
	{
		while((i<=high)&&(a[i]<pivot))
			i++;
		while((j>=low)&&(a[j]>=pivot))
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
}

void quick::sort(int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(low,high);
		sort(low,j-1);
		sort(j+1,high);
	}
}

int main()
{
        cout<<"\n-------------------------------------\n";
	cout<<"             QUICK SORT\n";
	cout<<"-------------------------------------\n";
	
	quick q;
	q.getdata();
	q.display();
	int z=q.retsize();
	q.sort(0,z-1);
	cout<<"\n----- AFTER SORTING ----\n";
	q.display();
	q.top();
	cout<<"\n\n";
	return 0;
}

