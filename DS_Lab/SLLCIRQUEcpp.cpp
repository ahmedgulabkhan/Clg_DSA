#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
node* head=0;
node* tail=0;
void insert(int data)
{
cout<<"enter the data"<<endl;
cin>>data;

node* temp=new node();
temp->data=data;
temp->next=0;
if(head==0)
{head=temp;
tail=temp;
}
else
{tail->next=temp;
tail=temp;
tail->next=head;
}




	

}
void display()
{node* temp1=head;
if(head==tail&&head!=0)
{cout<<head->data<<endl;
}
else if(head==0)
{cout<<"circular queue is empty"<<endl;
}
else
{temp1=head;
cout<<temp1->data<<endl;
temp1=temp1->next;

while(temp1!=head)
{cout<<temp1->data<<endl;
temp1=temp1->next;
}
}
}
void del()
{
	if(head==0)
	{cout<<"que is empty to delete"<<endl;

	}
	else if(head==tail&&head!=0)
	{head=0;
	tail=0;
	}
	else
	{node* temp=head;
	tail->next=head->next;
	head=head->next;
	delete temp;
	}
}
	

int main()
{int p,b;


do
{
cout<<"1.insert  2.delete  3.display"<<endl;
cout<<"enter choice"<<endl;
cin>>p;
	switch(p)
	{case 1:insert(b);
	break;
	case 2:del();
	break;
	case 3:
		display();
		break;
	}
	
	
}
while(p!=4);



}
