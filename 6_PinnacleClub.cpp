


#include<iostream>
#include<string>
using namespace std;
class node
{
	public:
		string name,prn;
		node *next;
		node()
		{
			name="";
			prn="";
			next=NULL;
		}
};

class SLL:public node
{
	public:
		node *head, *tail;
		int count;
		SLL()
		{
			head=tail=NULL;
			count=0;
		}
		void getData(node *ptr)
		{
			cout<<"\nName:";
			getline(cin , ptr->name);
			cout<<"\nPRN:";
			getline(cin , ptr->prn);
		}
		void displayData(node *ptr)
		{
			cout<<"\nName:"<<ptr->name;
			cout<<"\nPRN:"<<ptr->prn<<endl;
		}
		void createList()
		{
			while(true)
			{
				node *newnode = new node;
				getData(newnode);
				if(head==NULL)
				{
					head = tail = newnode;
					
					count++;
				}
				else
				{
					tail->next = newnode;
					tail = newnode;
					count++;
				}
				cout<<"\nEnter more data? Y/N:";
				char ch;
				cin>>ch;
				cin.ignore();
				if(ch=='n' || ch=='N')
					return;
			}
		}
		void display(node *ptr)
		{
			if(ptr==NULL)
				return;
			else
			{
				if(ptr==head)
					cout<<"\nPresident:";
				else if(ptr==tail)
					cout<<"\nSecratary:";
				displayData(ptr);
				display(ptr->next);
			}
		}
		void displayReverse(node *ptr)
		{
			if(ptr==NULL)	
				return;
			else
			{
				displayReverse(ptr->next);
				if(ptr==head)
					cout<<"\nPresident:";
				else if(ptr==tail)
					cout<<"\nSecratary:";
				displayData(ptr);
			}
		}
		void add_pres()
		{
			node *newnode = new node;
			getData(newnode);
			newnode->next = head;
			head = newnode;
			count++;
		}
		void add_sec()
		{
			node *newnode = new node;
			getData(newnode);
			tail->next = newnode;
			tail = newnode;
			count++;
		}
		void add_pos(int pos)
		{
			if(pos==0)
				add_pres();
			else if(pos==(count-1))
				add_sec();
			else if(pos>0 && pos<(count-1))
			{
				int c=1;
				node *ptr;
				ptr = head;
				while(c!=pos)
				{
					c++;
					ptr = ptr->next;
				}
				node *newnode = new node;
				getData(newnode);
				newnode->next = ptr->next;
				ptr->next = newnode;
				count++;
			}
			else
			{
				cout<<"\nPosition does not exist."<<endl;
			}
		}
		void del_pres()
		{
			node *tmp;
			tmp = head;
			head = head->next;
			tmp->next = NULL;
			delete(tmp);
			count--;
		}
		void del_sec()
		{
			node *tmp;
			tmp = head;
			while(tmp->next!=tail)
			{
				tmp = tmp->next;
			}
			delete(tail);
			tmp->next = NULL;
			tail = tmp;
			count--;
		}
		void del_pos(int pos)
		{
			if(pos==0)
				del_pres();
			else if(pos==(count-1))
				del_sec();
			else
			{
				int c=1;
				node *ptr;
				ptr = head;
				while(c<pos)
				{
					c++;
					ptr = ptr->next;
				}
				node *tmp = ptr->next;
				ptr->next = ptr->next->next;
				tmp->next = NULL;
				delete(tmp);
				count--;
			}
		}
		friend SLL operator+(SLL list1 , SLL list2)
		{
			SLL list3;
			list3.count = list1.count + list2.count;
			list3.head = list1.head;
			list3.tail = list2.tail;
			list1.tail->next = list2.head;
			return list3;
		}
		void execute()
		{
			while(true)
			{
				cout<<"\n1. Display List.";
				cout<<"\n2. Display List In Reverse Order.";
				cout<<"\n3. Add A Student.";
				cout<<"\n4. Delete A Student.";
				cout<<"\n5. Total Members Of The Club.";
				cout<<"\n'X' to exit.";
				cout<<"\n:";
				int pos;
				char ch;
				cin>>ch;
				cin.ignore();
				switch(ch)
				{
					case '1' : 
						display(head);
						break;
					case '2' : 
						displayReverse(head);
						break;
					case '3' : 
						cout<<"\nEnter a position:";
						cin>>pos;
						cin.ignore();
						add_pos(pos);
						break;
					case '4' : 
						cout<<"\nEnter a position:";
						cin>>pos;
						cin.ignore();
						del_pos(pos);
						break;
					case '5' : 
						cout<<"\nTotal number of members:"<<count;
						break;
					case 'X':
						break;
					case 'x' : 
						break;
					default : 
						cout<<"\nWrong choice!"<<endl;
						break;
				}
				if(ch=='x' || ch=='X')
					return;
			}
		}
};

int main()
{
	SLL list1,list2,list3;
	char ch;
	int flag=0;
	int i=1;
	while(i<=2)
	{
		SLL *list;
		list = &list1;
		if(flag==1)
			list = &list2;
		cout<<"\n1. Create a new list.";
		cout<<"\n2. List functions.";
		cout<<"\n3. Concatinate two strings.";
		cout<<"\n'Q' to quit.";
		cout<<"\n:";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{
			case '1' : 
				if(list->head!=NULL)
				{
					cout<<"\nList is already created.";
					cout<<"\nCreate another list? Y/N:";
					char c;
					cin>>c;
					cin.ignore();
					if(c=='y' || c=='Y')
					{
						flag=1;
						i++;
					}
					break;
				}
				else
				{
					list->createList();
				}
				break;
			case '2' : 
				list->execute();
				break;
			case '3' : 
				if(list2.head==NULL)
				{
					cout<<"\nSecond list is empty!";
					cout<<"\nCreate new list? Y/N:";
					char c;
					cin>>c;
					cin.ignore();
					if(c=='y' || c=='Y')
					{
						flag=1;
						i++;
						break;
					}
				}
				else
				{
					list3 = list1+list2;
					list3.execute();
					break;
				}
				break;
			case 'q' : 
			case 'Q' : break;
			default : 
				cout<<"\nWrong choice.";
				break;
		}
		if(ch=='q' || ch=='Q')
			return 0;
	}
}
