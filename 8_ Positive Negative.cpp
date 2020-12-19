
#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *next;
	
};
class list
{
	private:
	int count=0;
	int a=0,b=0,c=0;
	node *n1,*head=NULL;
	node *n2,*n3,*head2=NULL,*head3=NULL;
	public:
	node* create();
	node* seperate();
	void display();
	node* del();
	node* sorting();
};
node* list::create()
{
	char ch;
	node *last;
	do
	{
		n1=new node();
		cout<<"enter data ";
			cin>>n1->data;
			n1->next=NULL;
			if(head==NULL)
			{
				head=n1;last=n1;
			}
			else
			{
				last->next=n1;
				last=n1;
			}
			count++;
			cout<<"do you want to continue \n";
			cin>>ch;
		}while(ch=='y');
}
node* list::seperate()
{
	
	node *temp=head;
	node *temp2=head2,*temp3=head3;
	for(int i=0;i<count;i++)
	{
		
		if(temp->data>=0)
		{
			n2=new node();
			n2->data=temp->data;
			n2->next=NULL;
			if(head2==NULL)
			{
				head2=n2;temp2=n2;
			}
			else
			{
				temp2->next=n2;
				temp2=n2;
			}
			a++;
		}
		else
		{
			n3=new node();
			n3->data=temp->data;
			n3->next=NULL;
			if(head3==NULL)
			{
				head3=n3;temp3=n3;
			}
			else
			{
				temp3->next=n3;
				temp3=n3;
			}
			b++;
		}
		temp=temp->next;
	}
	//dispaying positive and negative created linked lists
	
	if(a>0)
	{
		cout<<"POSITIVE LIST \n";
		node *temp2;
		temp2=head2;
		while(temp2->next!=NULL)
		{
			cout<<temp2->data<<"->";
			temp2=temp2->next;
		}
		cout<<temp2->data;
		cout<<endl;
	}
	else
	cout<<"NO POSITIVE NUMBERS IN LIST \n";
	
	if(b>0)
	{
		cout<<"NEGATIVE LIST \n";
		node *temp3;
		temp3=head3;
		while(temp3->next!=NULL)
		{
			cout<<temp3->data<<"->";
			temp3=temp3->next;
		}
		cout<<temp3->data;
		cout<<endl;
	}
	else
	cout<<"NO NEGATIVE NUMBERS IN LIST \n";
}
void list::display()
{
	cout<<"INITIAL LIST \n";
	node *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<endl;
}	
	

node* list::del()
{
	cout<<"THE DELETED LIST IS \n";
	node *prev=NULL;
	node *temp=head;
	//node *temp4;
	while(temp!=NULL)
	{
		if(head->data<0)
		{
			temp=head->next;
			
			delete head;
			head=temp;
		}
		if(temp->data<0)
		{
			prev->next=temp->next;
			//temp4=temp->next;
			delete temp;
		}
		else
		{
		prev=temp;
		temp=temp->next;
		}
	}
	
	
	//if(a>0)
	//{
	temp=head;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<endl;
	//}
	//else
	//cout<<"NO POSITIVE NUMBERS IN LIST \n";
}


int main()
{
	list l,x;
	l.create();
	l.seperate();
	l.display();
	l.del();
	
	return 0;
}
