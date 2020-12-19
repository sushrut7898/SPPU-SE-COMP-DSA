
#include<iostream>

using namespace std;

class student

{

int m,setA[50],setB[50],countA,countB;

public:

void getdata();

void display();

void intersect();

void union1();

void fifthcase();
};

	void student::getdata()

 	{

 	cout<<"Enter number of students in a class=";
  
	cin>>m;
 
       cout<<"Enter the number of students who play only cricket =";
 
 	cin>>countA;

        cout<<"Enter the number of students who play only badmintton=";

  	cin>>countB;

 	cout<<"Enter the roll no. of students who play only cricket="<<endl;

 	for(int i=0;i<countA;i++)

    		{

      		cout<<"Enter ["<<i<<"]:";
 
    		cin>>setA[i]<<endl;

   		}
    
 		cout<<"Enter the roll no. of students who play only badmintton="<<endl;
 
      		for(int i=0;i<countB;i++)

          		{
   
        		 cout<<"Enter ["<<i<<"]:";
  
         	 	 cin>>setB[i]<<endl;
          
 			}

 	}
  
  	 void student::display()

   	 {

    	 cout<<"total number of students in a class="<<m<<endl;
 
   	 cout<<"total  number of students who  play only cricket ="<<countA<<endl;

   	 cout<<"total  number of students who play only badmintton="<<countB<<endl;

    	 cout<<"Roll no. of students who play only cricket="<<endl;

     	 for(int i=0;i<countA;i++)

     		{
     	
		cout<<setA[i]<<endl;

     		}
     	
		 cout<<"Roll no. of students who play only badmintton="<<endl;

     		for(int i=0;i<countB;i++)

     	  	 {
    
 	   	  cout<<setB[i]<<endl;
    
 	  	 }
     
	}
        
	  void student::intersect()
    
   	 {
  
         int temp[50];

         int k=0;
        
  	 for(int i=0;i<countA;i++)
     
   	   {
          	
	  	for(int j=0;j<countB;j++)

          	 {
       
   	   	     if(setA[i]==setB[j]) 
          	
      
          	
    			{
          	   
          	    
 			    temp[k]=setA[i];
          	    
  			    k++;
          	
          	  
  			}
          	
 		 }
        
 	   }	     	   
     	
     	
	cout<<"students who play both="<<endl;
     
        for(int i=0;i<k;i++)
     
 		 {
     	  
 		    cout<<temp[i]<<endl;
     	
  		 }
     	
         }   
     		
	    void student::union1()
     		
	    {
     		 
 	     int temp[50],k=0;
     		 
  	     for(int i=0;i<countA;i++)
     		   
 		{
     		 
   		 temp[i]=setA[i];
     		 
   		}
     		 
   		 k=countA;
     			
     		for(int i=0;i<countB;i++)
     		  
   			 {
     		     
 			  for(int j=0;j<countA;j++)
     		       
				 {
     		       
 			  if(setB[i]!=setA[j])
     		      
   					{
     		        
 	 				 temp[k]=setB[i];
     		   
        				 k++;
     		     
   					}
		
   				 }
     		 
   	  		 }
     		

    	 cout<<"students who play either cricket or badmintton or both="<<endl;
     		
     	 for(int i=0;i<k;i++)
    
		{ 		   
 		 cout<<temp[i]<<endl;
     
	  	}			
	    }
		void student::fifthcase() 
		 {
		  int temp1=0;
		  if(countA>countB)
			{
		  	temp1=countA-countB;
			} 
		  else
			temp1=countB-countA;
		  cout<<"Number of students who play neither cricket nor badmintton"<<temp1<<endl;
     		 }    
     		
int main()
     		
{
  
student s;
int op;   		
 do
	{
	
	cout<<"\n\n1.Get input";

	cout<<"\n2.Display the accepted data";

	cout<<"\n3.Intersection";

	cout<<"\n4.Union :";

	cout<<"\n5.Difference:";
	cout<<"\n6.Exit:";
	cout<<"\n\nEnter option (1-6) :";

	cin>>op;

		switch(op)

		{

		case 1:	s.getdat();

			break;

		case 2:s.desplay();

			break;


		case 3:s.intersect();
			break;
	
	case 4:s.union1();
			break;
		case 5:s.fifthcase();
			break;
		}	

	}while (op!=6);

   		
return 0;
     		
}	




     		
             
