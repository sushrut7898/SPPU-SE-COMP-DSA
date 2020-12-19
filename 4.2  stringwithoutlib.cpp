
#include <iostream>

using namespace std;

class stringop

{

char str[20];

	public:

		void getstring();
		
int strlength();
		
void strcopy();
		
int strcompare(stringop ,stringop);

		void strconcat(stringop);

		void reverse();
		void substring();

};

void stringop::getstring()

{

cout<<"Enter a string:"<<endl;

cin>>str;

cout<<"you entered the following string:  "<<str<<endl;

}



int stringop::strlength()

{

int i=0;

while(str[i]!='\0')

{

i++;

}

return i;

}



void stringop::strcopy()

{

int i;

char str1[20];

for(i=0;str[i]!='\0';i++)

	{

	str1[i]=str[i];

	}

str1[i]='\0';

cout<<"The copied string: "<<str1<<endl;

}



int stringop::strcompare(stringop s1,stringop s2 )

{

int count=0,l1,l2;

l1=s1.strlength();

l2=s2.strlength();

if(l1==l2)

 {

  	for(int i=0;i<l1;i++)

  	  {
	
  if(s1.str[i]==s2.str[i])

  	  count++;

          }

 }

 if(count==l1)

 	return 0;

 else
 	return 1;

}



void stringop::strconcat(stringop s2)

{

int l1,l2,i=0;

int j=0;

l1=strlength();

l2=s2.strlength();

char s3[20];

	while(i<l1)

	{
	
	s3[i]=str[i];

	i++;

	}

	while(j<l1+l2)

	{
		
	s3[i]=s2.str[j];

	j++;
	i++;

	}

	cout<<"The concatenated string is:"<<s3<<endl;

}

void stringop::reverse()
{
char temp[50];
int j=0;
for(int i=strlength()-1;i>=0;i--)
	{
	 temp[j]=str[i];
	 j++;
	}	
temp[j]='\0';
cout<<"The reversed string is : "<<temp<<"\n\n";
}


void stringop::substring()

{

 stringop substr;


 int i=0,j=0,count=0;

 cout<<"Enter substring: ";

 cin>>substr.str;


 while(str[i]!='\0')

 {

 	if(str[i]==substr.str[j])

 	{

 		i++;

 		j++;

 		count++;

 	}

 	else

 	{

 	i++;

 	j=0;

 	}

 }

 if(count==substr.strlength())
 	cout<<"Substring occurs at "<<i-substr.strlength();

 else

 	cout<<"not a substring";

}

 
int main()
 
{

int c,q;

stringop s,s1,s3,s2;

s.getstring();

cout<<"Length is: ";

c=s.strlength();

cout<<c<<endl;

s.strcopy();

s1.getstring();

q=s3.strcompare(s,s1);

if(q==0)

	cout<<"Equal"<<endl;

else

	cout<<"Not Equal"<<endl;

s2.getstring();

s.strconcat(s2);

s.reverse();
s.substring();




return 0;

}

