
#include<iostream>
#include<string>
using namespace std;
class string1
{
 string str;
 	public:
 	void getstring();
 	void putstring();
 	void frequency();
 	void palindrome();
 void replace1();
 void del();
   };
 void string1::getstring()
 {
  cout<<"Enter a string:";
  getline(cin,str);
  }
  void string1::putstring()
  {
  cout<<"You Entered the following string:"<<endl<<str;
  }
  void string1::frequency()
  {
  char ch;
  int count=0;
  cout<<"Enter character to search:";
  cin>>ch;
  for(int i=0;i<str.length();i++)
  	{
  	if(str[i]==ch)
  	count++;
  	}
  cout<<"frequency of"<<ch<<"is:"<<count;
  }
  void string1::palindrome()
  {
   string temp;
   int j=0;
   for(int i=string.length()-1;i>=0;i--)
   {
    temp[j]=str[i];
    j++;
   }
    	if(temp==str)    		cout<<"palindrome";
    	else
    		cout<<"not a palindrome";
   }
void string1::replace1()
        {
         int z,x;
         string j;
         cout<<"Enter the position,number of characters,string which you want to replace:\t";
         cin>>z;
         cin>>x;
         cin>>j;
         cout<<endl;
         string b;
         b=str.replace(z,x,j);
         cout<<"The new string after replacement is:\t"<<b<<endl;
       }
      void string1::del()
       {
        int q,w;
        cout<<"Enter the starting point and number of characters you want to delete:\t";
        cin>>q;
        cin>>w;
        cout<<endl;
        string d;
        d=str.erase(q,w);
        cout<<"The new string after deletion is:\t"<<d<<endl;
      } 
      
int main()
   
{
int o=0;
	string1 s;

	s.getstring();

	s.putstring();


	do 
	{
	cout<<"\n1.FREQUENCY:\n";
	cout<<"\n2.PALINDROME:\n";
	cout<<"\n3.REPLACE:\n";
	cout<<"\n4.DELETE:\n";
	cout<<"\n5.EXIT:\n";
	cout<<"\nEnter option (1-5) :";

	cin>>o;
		switch(o)
		{
		case1:s.frequency();
	      		break;
		case2:s.palindrome();
	      		break;
		case3:s.replace1();
	     		 break;
		case4:s.del();
	    		  break;
		}


	}while (op!=5);

return 0;

}
  
