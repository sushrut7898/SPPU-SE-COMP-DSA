/*

Write C++ program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending
order using :

a) Selection Sort

b) Bubble sort and display top five scores.

*/

#include<iostream>
using namespace std;

class bubble
{
	float a[50],temp;
	int i,n,p,j,k,min,loc;
	int count=1;
	
	public :
	
	void accept()
	{
	       cout<<"\nHow many people you want to include to enter %Percentage% ? --> ";
	       cin>>n;
	       
	       for(i=0 ; i<n ; i++)
	       {
	              cout<<"\nEnter percentage of STUDENT NUMBER "<<i<<" : ";
	              cin>>a[i];
	       }
	
	}
	
	void display()
	{
	       for(i=0 ; i<n ; i++)
	       {
	              cout<<a[i]<<"   ";
	       }
	       cout<<endl;
	}
	
	void bubblesort()
	{
	       cout<<"\n------------ BUBBLE SORT ---------------\n";
	       accept();
	       cout<<"\n------------ RESULT : BUBBLE SORT ---------------\n";
	       
	       cout<<"\n\n";
	       for(p=0;p<n;p++)             // Loop for Pass
              {
                     for(j=0;j<n;j++)
                     {
                            if(a[j]>a[j+1])
                            {
                                   temp=a[j];                      // Interchange Values
                                   a[j]=a[j+1];
                                   a[j+1]=temp;
                            }
                     }

              }

              cout<<"\nAfter Sorting ( BY BUBBLE SORT IS ) : \n";
              display();
              cout<<endl;
              cout<<"--------------------------------------------------------------\n";
         }
         
         void selectionsort()
         {
              cout<<"\n------------ SELECTION SORT -----------------------\n";
              
              accept();
              cout<<"\n------------ RESULT : SELECTION SORT ---------------";
              
	       for(p=0;p<n-1;p++)              // Loop for Pass 
              {
                     min=a[p];                        // Element Selection
                     loc=p;

                     for(k=p+1;k<n;k++)              // Finding Min Value
                     {
                            if(min>a[k])
                            {
                                   min=a[k];
                                   loc=k;
                            }
                     }

                     temp=a[p];                        // Swap Selected Element and Min Value
                     a[p]=a[loc];
                     a[loc]=temp;

	              
	       }
	       cout<<"\nAfter Sorting ( BY SELECTION SORT IS ) : \n";
	       display();
	       cout<<"--------------------------------------------------------------\n";
	       
	       
	       if(n>=5)
	       {
	              cout<<"The top 5 scorers in FE are ! \n";
	              for(int i=n-1 ; i>=n-5 ; i--)
	              {
	                     cout<<count<<" . "<<a[i]<<"  ";
	                        count++;
	              }
	              cout<<endl;
	       }
	       else cout<<"There are less entities in the database. Cannot show top 5 scorers !\n";
	   }
	   
	   
	
	       
};

int main()
{
     /*  bubble b;
       b.accept();
       cout<<"BEFORE SORTING THE ENTERED ELEMENTS ARE -\n";
       b.display();
       cout<<"\n\n";
       b.bubblesort();
       cout<<"\n\n";
       b.accept();
       b.selectionsort();
       return 0;
       */
       
       bubble b;
       int choice=0;
       char ans;
       cout<<"---------------------------------\n";
       cout<<"| WELCOME FIRST YEAR STUDENTS ! |\n";
       cout<<"---------------------------------\n\n";

      // do
       //{
       
               while(choice!=4)
               {
               cout<<"For students to enter their percentage -\n\n";
              cout<<"********************************\n";
              cout<<"Press 1 : TO USE BUBBLE SORT\n";
              cout<<"Press 2 : TO USE SELECTION SORT\n";
              
              cout<<"Press 3 : EXIT\n";
              cout<<"********************************\n";
              cout<<"\n\nWhat's your choice ? ";
              cin>>choice;
             
              
                     switch(choice)
                     {
                            case 1 : b.bubblesort(); 
                                     continue;
                              
                            case 2 : b.selectionsort();
                                     continue;
                              
                           
                                     
                            case 3 : cout<<"\n\nThank You !\n\n";
                                     break;     
                                     
                              
                            default : cout<<"Enter appropriate choice !\n\n";
                                      continue;
                     }
              }
             
        
       
       
       

}
       
	       
	       
	       
	
