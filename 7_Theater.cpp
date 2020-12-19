


#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class node
{
    public:
        char seat;
        string name;
        node *next, *prev;
        node()
        {
            seat = 'F';
            name = "";
            next = prev = NULL;
        }
};

class Theater:public node
{
    node *head[10];
    int free, booked;
    public:
        Theater()
        {
            free=70;
            booked=0;
            for(int i=0 ; i<10 ; i++)
                head[i]=NULL;
        }
        void create()
        {
            node *tmp;
            for(int i=0 ; i<10 ; i++)
            {
                tmp = head[i];
                for(int j=0 ; j<7 ; j++)
                {
                    node *newnode = new node;
                    newnode->next = newnode;
                    newnode->prev = newnode;
                    if(tmp==NULL)
                    {
                        head[i] = newnode;
                        tmp = head[i];
                    }
                    else
                    {
                        tmp->next = newnode;
                        newnode->prev = tmp;
                        newnode->next = head[i];
                        head[i]->prev = newnode;
                        tmp = newnode;
                    }
                }
            }
        }
        void display()
        {
            cout<<"\n-\t";
            for(int i=1 ; i<=7 ; i++)
                cout<<i<<"\t";
            cout<<endl;
            char t='A';
            node *ptr;
            for(int i=0 ; i<10 ; i++)
            {
                ptr = head[i];
                cout<<t<<"\t";
                t++;
                for(int j=0 ; j<7 ; j++)
                {
                    cout<<ptr->seat<<"\t";;
                    ptr = ptr->next;
                }
                cout<<endl;
            }
            cout<<"\nSeats Available:"<<free<<"\tSeats Booked:"<<booked;
        }
        bool check(char ch , int i , int j)
        {
            node *ptr;
            ptr = head[i];
            for(int k=1 ; k<j ; k++)
            {
                ptr = ptr->next;
            }
            if(ch!=ptr->seat)
                return true;
            else
                return false;
        }
        void book_cancel(char ch , string s)
        {
            int i,j;
            switch(s[0])
            {
                case 'A' : i=0; break;
                case 'B' : i=1; break;
                case 'C' : i=2; break;
                case 'D' : i=3; break;
                case 'E' : i=4; break;
                case 'F' : i=5; break;
                case 'G' : i=6; break;
                case 'H' : i=7; break;
                case 'I' : i=8; break;
                case 'J' : i=9; break;
                case '1' : j=1; break;
                case '2' : j=2; break;
                case '3' : j=3; break;
                case '4' : j=4; break;
                case '5' : j=5; break;
                case '6' : j=6; break;
                case '7' : j=7; break;
            }
            switch(s[1])
            {
                case 'A' : i=0; break;
                case 'B' : i=1; break;
                case 'C' : i=2; break;
                case 'D' : i=3; break;
                case 'E' : i=4; break;
                case 'F' : i=5; break;
                case 'G' : i=6; break;
                case 'H' : i=7; break;
                case 'I' : i=8; break;
                case 'J' : i=9; break;
                case '1' : j=1; break;
                case '2' : j=2; break;
                case '3' : j=3; break;
                case '4' : j=4; break;
                case '5' : j=5; break;
                case '6' : j=6; break;
                case '7' : j=7; break;
            }
            node *ptr;
            ptr = head[i];
            for(int k=1 ; k<j ; k++)
            {
                ptr = ptr->next;
            }
            if(ch=='B')
            {
                if(ptr->seat=='F')
                {
                    ptr->seat = 'B';
                    cout<<"\nEnter your name:";
                    getline(cin , ptr->name);
                    booked++; free--;
                    cout<<"\nSeat Booked, "<<ptr->name<<"!"<<endl;
                    return;
                }
                else
                {
                    cout<<"\nSorry this seat has already been taken!"<<endl;
                    return;
                }
            }
            else if(ch=='F')
            {
                if(ptr->seat=='B')
                {
                    cout<<ptr->name<<", you would like to cancel this booking? Y/N:";
                    char ch;
                    cin>>ch;
                    cin.ignore();
                    if(ch=='Y' || ch=='y')
                    {
                        cout<<"\nBooking cancelled "<<ptr->name<<"!"<<endl;
                        ptr->name="";
                        ptr->seat='F';
                        booked--; free++;
                        return;
                    }
                    else
                    {
                        return;
                    }
                }
                else
                {
                    cout<<"\nThis seat is already free! Book it? Y/N:";
                    char ch;
                    cin>>ch;
                    cin.ignore();
                    if(ch=='Y')
                    {
                        cout<<"\nEnter your name:";
                        getline(cin , ptr->name);
                        ptr->seat = 'B';
                        booked++; free--;
                        cout<<"\nSeat has been booked "<<ptr->name<<"!"<<endl;
                        return;
                    }
                    else
                    {
                        return;
                    }
                }
            }
        }
        void gui()
        {
            system("reset");
            char ch;
            while(true)
            {
                cout<<"\nD: Display Seats.";
                cout<<"\nB: Book A Seat.";
                cout<<"\nC: Cancel A Booking.";
                cout<<"\nQ: Quit.";
                cout<<"\n:";
                cin>>ch;
                cin.ignore();
                switch(ch)
                {
                    case 'd' : 
                    case 'D' : 
                        display();
                        break;
                    case 'b' : 
                    case 'B' : 
                        while(true)
                        {
                            cout<<"\nEnter seat number:";
                            string s;
                            cin>>s;
                            cin.ignore();
                            if((s[0]>='A' && s[0]<='J' || s[0]>='1' && s[0]<='7') || (s[1]>='A' && s[1]<='J' || s[1]>='1' && s[1]<='7'))
                            {
                                book_cancel('B' , s);
                                break;
                            }
                        }
                        break;
                    case 'c' : 
                    case 'C' : 
                        while(true)
                        {
                            cout<<"\nEnter seat number:";
                            string s;
                            cin>>s;
                            cin.ignore();
                            if((s[0]>='A' && s[0]<='J' || s[0]>='1' && s[0]<='7') || (s[1]>='A' && s[1]<='J' || s[1]>='1' && s[1]<='7'))
                            {
                                book_cancel('F' , s);
                                break;
                            }
                        }
                        break;
                    case 'q' : 
                    case 'Q' : 
                        return;
                }
            }
        }
        void execute()
        {
            create();
            gui();
        }
};

int main()
{
    Theater obj;
    obj.execute();
}
        
