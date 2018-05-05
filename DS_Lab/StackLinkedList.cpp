#include<iostream>
using namespace std;
struct node
{int data;
node* next;
};
node* head;
node* tail;
void insert(int data)
{node* temp=new node();
temp->next=0;
cout<<"enter data"<<endl;
cin>>data;
temp->data=data;
if(head==0)
{head=temp;
tail=temp;
}
else
{tail->next=temp;
tail=temp;}}
void pop()
{
if(head==0)
{cout<<"stack id empty"<<endl;
}
else
{
node* temp1=head;
while(temp1->next->next!=0)
{
temp1=temp1->next;
}
tail=temp1;

tail->next=0;
delete temp1->next;
}
}
void display()
{node* temp1=head;
if(temp1==0)
{cout<<"stack is empty"<<endl;
}
while(temp1!=0)
{cout<<temp1->data<<endl;
temp1=temp1->next;
}
}
int main()
{int n;int data;
head=0;
tail=0;
do
{
cout<<"1.insrt2.del3.disply4.exit"<<endl;
cout<<"enter choice"<<endl;
cin>>n;
switch(n)
{case 1: {insert(data);
break;}
case 2:
{pop();
break;
}
case 3:{display();
break;
}}}
while(n!=4);

}
