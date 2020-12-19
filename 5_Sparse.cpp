
//PROGRAM TO DO OPERATIONS ON SPARSE MATRIX

#include<iostream>
using namespace std;
class sparse
{
        int mat[10][10],sp[20][3];
        int r,c;
        
        public:
        
        void getmatrix();
        void putmatrix();
        void createsparse();
        void putsparse();
        void addition(sparse,sparse);
        void transpose();
        void fasttranspose();
};

void sparse::getmatrix()
{
        cout<<"\nEnter the number of rows of matrix : ";
        cin>>r;
        cout<<"\nEnter the number of columns of matrix : ";
        cin>>c;
        cout<<"\nEnter the elements of the matrix : ";
        for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
                        cout<<"\nMAT["<<i<<"]"<<"["<<j<<"] : ";
                        cin>>mat[i][j];
                }
        }
}

void sparse::putmatrix()
{
        cout<<"\nThe matrix is : \n\n";
        for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
                        cout<<mat[i][j]<<"\t";
                }
                cout<<"\n";
        }
}                

void sparse::putsparse()
{
        cout<<"\n\nThe sparse matrix is : \n\n";
        for(int i=0;i<=sp[0][2];i++)
        {
                for(int j=0;j<3;j++)
                {
                        cout<<sp[i][j]<<"\t";
                }
                cout<<"\n";
        }
        cout<<"\n";
}

void sparse::createsparse()
{
        int k=1;
        for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
                        if(mat[i][j]!=0)
                        {
                                sp[k][2]=mat[i][j];
                                sp[k][0]=i;
                                sp[k][1]=j;
                                k++;
                        }
                }
        }
        sp[0][0]=r;
        sp[0][1]=c;
        sp[0][2]=k-1;
}

void sparse::addition(sparse s1,sparse s2)
{
        int i=1,j=1,k=1;
        if(s1.sp[0][0]==s2.sp[0][0]&&s1.sp[0][1]==s2.sp[0][1])
        {
                while(i<=s1.sp[0][2]&&j<=s2.sp[0][2])
                {
                        if(s1.sp[i][0]==s2.sp[j][0])     
                        {
                                if(s1.sp[i][1]==s2.sp[i][1])
                                {
                                        sp[k][2]=s1.sp[i][2]+s2.sp[j][2];
                                        sp[k][0]=s1.sp[i][0];
                                        sp[k][1]=s1.sp[i][1];
                                        k++;
                                        j++;
                                        i++;
                                }
                                else if(s1.sp[i][1]<s2.sp[j][1])
                                {
                                        sp[k][0]=s1.sp[i][0];   
                                        sp[k][1]=s1.sp[i][1];
                                        sp[k][2]=s1.sp[i][2];  
                                        k++;
                                        i++;
                                }
                                else
                                {
                                        sp[k][0]=s2.sp[j][0];   
                                        sp[k][1]=s2.sp[j][1];
                                        sp[k][2]=s2.sp[j][2];  
                                        k++;
                                        j++;
                                }
                        }
                        else if(s1.sp[i][0]<s2.sp[j][0])
                        {
                                sp[k][0]=s1.sp[i][0];   
                                sp[k][1]=s1.sp[i][1]; 
                                sp[k][2]=s1.sp[i][2];  
                                k++;
                                i++;
                        }
                        else
                        {
                                sp[k][0]=s2.sp[j][0];   
                                sp[k][1]=s2.sp[j][1];
                                sp[k][2]=s2.sp[j][2];  
                                k++;
                                j++;
                        }
                }
                while(i<=s1.sp[0][2])
                {
                        sp[k][0]=s1.sp[i][0];   
                        sp[k][1]=s1.sp[i][1]; 
                        sp[k][2]=s1.sp[i][2];  
                        k++;
                        i++;
                }
                while(j<=s1.sp[0][2])
                {
                        sp[k][0]=s1.sp[j][0];   
                        sp[k][1]=s1.sp[j][1]; 
                        sp[k][2]=s1.sp[j][2];  
                        k++;
                        j++;
                }
                sp[0][0]=s1.sp[0][0];
                sp[0][1]=s1.sp[0][1];
                sp[0][2]=k-1;
        }
}

void sparse::transpose()
{
	sparse trans;
	int i,j,k=1;
	for(i=0;i<sp[0][1];i++)
	{
		for(j=1;j<=sp[0][2];j++)
		{
			if(sp[j][1]==i)
			{
				trans.sp[k][2]=sp[j][2];
				trans.sp[k][0]=sp[j][1];
				trans.sp[k][1]=sp[j][0];
				k++;
			}
		}
	}
	trans.sp[0][2]=sp[0][2];
	trans.sp[0][0]=sp[0][1];
	trans.sp[0][1]=sp[0][0];
	cout<<"\nThe transpose sparse matrix is : ";
        trans.putsparse();
}   
    
void sparse::fasttranspose()
{
      sparse trans;
      int rterm[10],rpos[10];
      int i,j;
      for(i=0;i<sp[0][1];i++)
      {
            rterm[i]=0;
      }
      for(i=1;i<=sp[0][2];i++)
      {
            rterm[sp[i][0]]++;
      }
      rpos[0]=1;
      for(i=1;i<sp[0][1];i++)
      {
            rpos[i]=rpos[i-1]+rterm[i-1];
      }
      for(i=1;i<=sp[0][2];i++)
      {
            j=rpos[sp[i][1]];
            trans.sp[j][0]=sp[i][1];      
            trans.sp[j][1]=sp[i][0];
            trans.sp[j][2]=sp[i][2];
            rpos[sp[i][1]]++;
      }
      trans.sp[0][0]=sp[0][1];
      trans.sp[0][1]=sp[0][0];
      trans.sp[0][2]=sp[0][2];
      cout<<"\nThe fast transpose sparse matrix is : ";
      trans.putsparse();
}

void choose()
{
    cout<<"\n\nPlease select any of the following functions\n\n";
	cout<<"1 : Enter a matrix and display sparse matrix.\n";
	cout<<"2 : Add two sparse matrices.\n";
	cout<<"3 : Transpose of matrix as sparse matrix.\n";
	cout<<"4 : Fast transpose of sparse matrix.\n";
	cout<<"5 : Exit.\n\n";
}

int main()
{
        sparse s1,s2,s3;
        int x;
        do
        {
                choose();
                cin>>x;
                switch(x)
                {
                        case 1:
                        {
                                s1.getmatrix();
                                s1.putmatrix();
                                s1.createsparse();
                                s1.putsparse();
                                break;
                        }
                        case 2:
                        {
                                cout<<"\nFirst matrix : ";
                                s1.getmatrix();
                                s1.putmatrix();
                                s1.createsparse();
                                s1.putsparse();
                                cout<<"\nSecond matrix : ";
                                s2.getmatrix();
                                s2.putmatrix();
                                s2.createsparse();
                                s2.putsparse();
                                s3.addition(s1,s2);
                                cout<<"\nThe addition of sparse matrices is : ";
                                s3.putsparse();
                                break;
                        }
                        case 3:
                        {
                                s1.getmatrix();
                                s1.putmatrix();
                                s1.createsparse();
                                s1.putsparse();
                                s1.transpose();
                                break;
                        }  
                        case 4:
                        {
                                s1.getmatrix();
                                s1.putmatrix();
                                s1.createsparse();
                                s1.putsparse();
                                s1.fasttranspose();                      
                                break;
                        }        
                        case 5:
                        {
                                cout<<"\n\n";
                                break;
                        }
                        default:
                        {
                                cout<<"\nError : Enter another option";
                        }
                 }
        }
        while(x!=5);
        return 0;
}
