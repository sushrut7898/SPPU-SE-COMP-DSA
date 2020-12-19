

#include<iostream>
#include<string.h>
using namespace std;
class stackin
{
	int top,size;
	char st[20],exp[20];
	public:
	void push(char);
	char pop();
	void inpost();
	int precedence(char);
	void inpre();
};

void stackin::inpost()
{
	cout<<"\nEnter the infix expression : \n";
	cin>>exp;
	top=-1;
	char post[20];
	int k=0;
	char ch;
	for(int i=0;exp[i]!='\0';i++)
	{
		if(isalpha(exp[i])||isdigit(exp[i]))
		{
			post[k]=exp[i];
			k++;
		}
		else if(exp[i]=='(')
		{
			push('(');
		}
		else if(exp[i]==')')
		{
			while((ch=pop())!='(')
			{
				post[k]=ch;
				k++;
			}
		}
		else
		{
			while(precedence(st[top])>=precedence(exp[i]))
			{
				post[k]=pop();
				k++;
			}
			push(exp[i]);
		}
	}
	while(top>=0)
	{
		post[k]=pop();
		k++;
	}
	post[k]='\0';
	cout<<"\nThe post fix expression is : \n"<<post<<"\n";
}

void stackin::push(char ch)
{
	top++;
	st[top]=ch;
}

char stackin::pop()
{
	char ch;
	ch=st[top];
	top--;
	return ch;
}

int stackin::precedence(char c)	
{
	if(c=='('||c==')')
		return(0);
	if(c=='+'||c=='-')
		return(1);
	if(c=='*'||c=='/')
		return(2);
	if(c=='^')
		return(3);
}

void stackin::inpre()
{
	top=-1;
	cout<<"\nEnter the infix expression : \n";
	cin>>exp;
	char pre[20],temp[20];
	int i,k=0,l;
	char ch;
	l=strlen(exp);
	for(i=0;i<l;i++)
	{
		if(exp[l-1-i]==')')
		{
			temp[i]='(';
		}
		if(exp[l-1-i]=='(')
		{
			temp[i]=')';
		}
		else
		{
			temp[i]=exp[l-1-i];
		}
	}
	temp[i]='\0';
	strcpy(exp,temp);
	for(i=0;exp[i]!='\0';i++)
	{
		if(isalpha(exp[i])||isdigit(exp[i]))
		{
			pre[k]=exp[i];
			k++;
		}
		else if(exp[i]=='(')
		{
			push('(');
		}
		else if(exp[i]==')')
		{
			while((ch=pop())!='(')
			{
				pre[k]=ch;
				k++;
			}
		}
		else
		{
			while(precedence(st[top])>=precedence(exp[i]))
			{
				pre[k]=pop();
				k++;
			}
			push(exp[i]);
		}
	}
	while(top>=0)
	{
		pre[k]=pop();
		k++;
	}
	pre[k]='\0';
	l=strlen(pre);
	for(i=0;i<l;i++)
	{
		temp[i]=pre[l-1-i];
	}
	temp[i]='\0';
	strcpy(pre,temp);
	cout<<"\nThe prefix expression is : \n"<<pre<<"\n";
}


class stackpost
{
	char stack[20][20];
	int top;
	char postfix[20];
	char infix[20],prefix[20];
	public:
	stackpost()
	{
		top=-1;
	}
	void postin();
	void postpre();
};

void stackpost::postin()
{
	char st[5];
	int l;
	cout<<"\nEnter the postfix expression : ";
	cin>>postfix;
	for(int i=0;postfix[i]!='\0';i++)
	{
		if(isalpha(postfix[i])||isdigit(postfix[i]))
		{
			st[0]=postfix[i];
			st[1]='\0';
			top++;
			strcpy(stack[top],st);
		}
		else
		{
			char st1[20];
			st1[0]='(';
			st1[1]='\0';
			strcat(st1,stack[top-1]);
			l=strlen(st1);
			st1[l]=postfix[i];
			st1[l+1]='\0';
			strcat(st1,stack[top]);
			l=strlen(st1);
			st1[l]=')';
			st1[l+1]='\0';
			top--;
			top--;
			top++;
			strcpy(stack[top],st1);
		}
	}
	strcpy(infix,stack[top]);
	cout<<"The infix expession is : "<<infix;
}

void stackpost::postpre()
{
	char st[5];
	int l;
	cout<<"\nEnter the postfix expression : ";
	cin>>postfix;
	for(int i=0;postfix[i]!='\0';i++)
	{
		if(isalpha(postfix[i])||isdigit(postfix[i]))
		{
			st[0]=postfix[i];
			st[1]='\0';
			top++;
			strcpy(stack[top],st);
		}
		else
		{
			char st1[20];
			st1[0]=postfix[i];
			st1[1]='\0';
			strcat(st1,stack[top-1]);
			strcat(st1,stack[top]);
			top--;
			top--;
			top++;
			strcpy(stack[top],st1);
		}
	}
	strcpy(prefix,stack[top]);
	cout<<"The prefix expession is : "<<prefix;
}


class stackpre
{
	char stack[20][20];
	int top;
	char postfix[20],infix[20],prefix[20];
	public:
	stackpre()
	{
		top=-1;
	}
	void prein();
	void prepost();
};

void stackpre::prein()
{
	char st[5];
	int l,l1;
	cout<<"\nEnter the prefix expression : ";
	cin>>prefix;
	l1=strlen(prefix);
	for(int i=l1-1;i>=0;i--)
	{
		if(isalpha(prefix[i])||isdigit(prefix[i]))
		{
			st[0]=prefix[i];
			st[1]='\0';
			top++;
			strcpy(stack[top],st);
		}
		else
		{
			char st1[20];
			st1[0]='(';
			st1[1]='\0';
			strcat(st1,stack[top]);
			l=strlen(st1);
			st1[l]=prefix[i];
			st1[l+1]='\0';
			strcat(st1,stack[top-1]);
			l=strlen(st1);
			st1[l]=')';
			st1[l+1]='\0';
			top--;
			top--;
			top++;
			strcpy(stack[top],st1);
		}
	}
	strcpy(infix,stack[top]);
	cout<<"The infix expession is : "<<infix;
}

void stackpre::prepost()
{
	char st[5];
	int l,l1;
	cout<<"\nEnter the prefix expression : ";
	cin>>prefix;
	l1=strlen(prefix);
	for(int i=l1-1;i>=0;i--)
	{
		if(isalpha(prefix[i])||isdigit(prefix[i]))
		{
			st[0]=prefix[i];
			st[1]='\0';
			top++;
			strcpy(stack[top],st);
		}
		else
		{
			char st1[20];
			st[0]=prefix[i];
			st[1]='\0';
			strcpy(st1,stack[top]);
			strcat(st1,stack[top-1]);
			top--;
			top--;
			strcat(st1,st);
			top++;
			strcpy(stack[top],st1);
		}
	}
	strcpy(postfix,stack[top]);
	cout<<"The postfix expession is : "<<postfix;
}

int main()
{ 
	stackin s1;
	stackpost s2;
	stackpre s3;
	int x;
	char c;
	do
	{
		cout<<"\n\nSelect any of the following : ";
		cout<<"\n(1) Infix to prefix.";
		cout<<"\n(2) Infix to postfix.";
		cout<<"\n(3) Postfix to infix.";
		cout<<"\n(4) Postfix to prefix.";
		cout<<"\n(5) Prefix to infix.";
		cout<<"\n(6) Prefix to postfix.";
		cout<<"\n(7) Exit.\n";
		cin>>x;
		switch(x)
		{	
			case 1:
				s1.inpre();
				break;
			case 2:
				s1.inpost();
				break;
			case 3:
				s2.postin();
				break;
			case 4:
				s2.postpre();
				break;
			case 5:
				s3.prein();
				break;
			case 6:
				s3.prepost();
				break;
			case 7:
				break;
		}
		cout<<"\nDo you wish to continue? (y/n) : ";
		cin>>c;
	}
	while(c=='y');
	return 0;
}
	
