
#include <iostream>
using namespace std;
class pass
{
	char x[6];
	int i,j,k,l;
	int wor,wr;
	public:
	void getchar();
	void withoutrep();
	void withrep();
};
void pass::getchar()
{
	cout<<"\n\nEnter six characters whose possible passwords are to be generated\n\n";
	for(i=0;i<6;i++)
	{
		cin>>x[i];
	}
	cout<<"\n\nThe entered characters are : ";
	for(i=0;i<6;i++)
	{
		cout<<"\t"<<x[i];
	}
}
void pass::withoutrep()
{	wor=0;
	cout<<"\n\nThe non-repetitive passwords are as follows : \n\n";
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			if(x[j]==x[i])
			continue;
			for(k=0;k<6;k++)
			{
				if(x[k]==x[i]||x[k]==x[j])
				continue;
				for(l=0;l<6;l++)
				{
					if(x[l]==x[i]||x[l]==x[j]||x[l]==x[k])
					continue;
					cout<<x[i]<<x[j]<<x[k]<<x[l];
					cout<<"\t";
					wor++;                     
				}
			}
		}
	}
	cout<<"\n\nThe total number of passwords is "<<wor<<"\n\n";
}	
void pass::withrep()
{	wr=0;
	cout<<"\n\nThe repetitive passwords are as follows : \n\n";
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			for(k=0;k<6;k++)
			{
				for(l=0;l<6;l++)
				{
					cout<<x[i]<<x[j]<<x[k]<<x[l];
					cout<<"\t";
					wr++;                     
				}
			}
		}
	}
	cout<<"\n\nThe total number of passwords is "<<wr<<"\n\n";
}		
int main()
{
	int op=0;	
	pass p;
	p.getchar();	
   do{
	cout<<"\n\n1. Display passwords without repetition";
	cout<<"\n2. Display passwords with repetition";
	cout<<"\n3. Exit";
	cout<<"\n\nEnter option (1-3) :";
	cin>>op;
	switch(op)
	{
		case 1:	p.withoutrep();
			break;
		case 2:p.withrep();
			break;	
	
	}
   }while (op!=3);
	return 0;
}	

