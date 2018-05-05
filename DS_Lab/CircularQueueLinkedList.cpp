#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head=NULL;
node *tail=NULL;
void insert();
void del();
void display();
int main(){
	int choice;
	do{
		cout<<"Menu\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
		cin>>choice;
		switch(choice){
			case 1:insert();break;
			case 2:del();break;
			case 3:display();break;
			case 4:cout<<"You have exited from the menu\n";break;
		}
	}while(choice!=4);
	return 0;
}
void insert(){
	node *temp;
	int ele;
	cout<<"Enter the element you want to insert\n";
	cin>>ele;
	temp = new node;
	temp->data=ele;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		tail=temp;
	}
	else{
		tail->next=temp;
		tail=temp;
	}
	cout<<"The element "<<temp->data<<" has been inserted\n";
}
void del(){
	if(head!=NULL){
		node *temp;
		temp=head;
		head=head->next;
		cout<<"The element "<<temp->data<<" has been deleted\n";
		delete temp;
	}
	else{
		cout<<"The list is empty,so cannot delete\n";
	}
}
void display(){
	if(head!=NULL){
		node *temp;
		temp=head;
		cout<<temp->data<<endl;
		while(temp->next!=NULL){
			temp=temp->next;
			cout<<temp->data<<endl;
		}
	}
	else{
		cout<<"The list is empty\n";
	}
}
