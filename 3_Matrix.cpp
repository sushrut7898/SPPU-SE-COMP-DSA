


#include<iostream>

#include<cstdlib>

using namespace std;

class matrix

{
   
int mat[100][100],r,c;

	public :

	void inputdata();

	void display();

	int upper();

	int sde();

	void transpose();

	void add();

	void sub();

	void multiply();

};
	
void matrix::inputdata()

{
		
	cout<<"\n\nEnter rows and columns of matrix : \n";

	cin>>r>>c;

	
cout<<"\nEnter the matrix elements";
 
		for(int i=0;i<r;i++)

		{
		   for(int j=0;j<c;j++)
		     {
			 cout<<"\nElement No. ["<<i<<"]["<<j<<"]   :   ";
                         cin>>mat[i][j];
		     }
		}
	
	}
	void matrix::display()
	{
		system("clear");
		cout<<"\n\n\n";
		for(int i=0;i<r;i++)
		{
			cout<<"\n";
			for(int j=0;j<c;j++)
				{
					cout<<mat[i][j]<<"\t";
				}
		}
	}

	int matrix::upper()
	{
		system("clear");
		int flag=0;
		for(int i=1;i<r;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(mat[i][j]==0)
				flag=1;
			}
		}
		if(flag==1)
		{
			cout<<"\nIt is an upper triangular matrix";	
		}
		else
		cout<<"\nNot an upper triangular matrix!";
		return 0;;
	}
	int matrix::sde()
	{
		system("clear");
		int sum=0;
		cout<<"\n\n\n";
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(i==j)
				{
					sum=sum+mat[i][j];
				}	
			}
		}
		cout<<"\nSum of diag. elements : "<<sum;
		return 0;
	}
	void matrix::transpose()
	{
		matrix temp;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				temp.mat[i][j]=mat[j][i];
			}
		}
		temp.r=c;
		temp.c=r;
		temp.display();
		
	}
void matrix::add()
{
	matrix a2,a3;
	system("clear");
	start:
	cout<<"\n\nEnter data for second matrix";
	cout<<"\n(Rows and columns of both matrices should be same for addition) :  \n\n";
	a2.inputdata();
	if((a2.r!=r)||(a2.c!=c))
	{
		cout<<"\n\n-------------------------------------------";
		cout<<"\nRows and columns of both matrix are different!";		
		cout<<"\n---------------------------------------------";
		goto start;
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			a3.mat[i][j]=mat[i][j]+a2.mat[i][j];
		}	
	}
	a3.r=r;
	a3.c=c;
	a3.display();
	cout<<"\n\n^Final matrix after addition^";
}            
void matrix::sub()
{
	matrix a2,a3;
	system("clear");
	start:
	cout<<"\n\nEnter data for second matrix";
	cout<<"\n(Rows and columns of both matrices should be same for subtraction) :  \n\n";
	a2.inputdata();
	if((a2.r!=r)||(a2.c!=c))
	{
		cout<<"\n\n-------------------------------------------";
		cout<<"\nRows and columns of both matrix are different!";		
		cout<<"\n---------------------------------------------";
		goto start;
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			a3.mat[i][j]=mat[i][j]-a2.mat[i][j];
		}	
	}
	a3.r=r;
	a3.c=c;
	a3.display();
	cout<<"\n\n^Final matrix after subtraction^";
}       
void matrix::multiply()
{
	matrix a2,a3;
	system("clear");
	start:
	cout<<"\n\nEnter data for second matrix";
	cout<<"\n(Rows and columns of both matrices should be same for muliplication) :  \n\n";
	a2.inputdata();
	if((a2.r!=r)||(a2.c!=c))
	{
		cout<<"\n\n-------------------------------------------";
		cout<<"\nRows and columns of both matrix are different!";		
		cout<<"\n---------------------------------------------";
		goto start;
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			a3.mat[i][j]=mat[i][j]*a2.mat[i][j];
		}	
	}
	a3.r=r;
	a3.c=c;
	a3.display();
	cout<<"\n\n^Final matrix after multiplication^";
}          

int main()
{
	int opt;
	system("clear");
	do{
		cout<<"\n\n\n1. Input";
		cout<<"\n2. Display original matrix";
		cout<<"\n3. Sum of diagonal elements";
		cout<<"\n4. Check for upper triangular matrix";
		cout<<"\n5. Transpose";
		cout<<"\n6. Addition";
		cout<<"\n7. Subtraciton";
		cout<<"\n8. Multiplication";
		cout<<"\n9. Exit";
		cout<<"\n\n\nEnter option    : ";
		cin>>opt;
		switch(opt)
		{	
			case 1: matrix a1;
				a1.inputdata();
				break;
			case 2: a1.display();
				break;
			case 3: a1.sde();
				break;
			case 4: a1.upper();
				break;
			case 5: a1.transpose();
				break;
			case 6: a1.add();
				break;
			case 7: a1.sub();
				break;
			case 8: a1.multiply();
				break;
		}
	}while(opt!=9);
	return(0);
}

