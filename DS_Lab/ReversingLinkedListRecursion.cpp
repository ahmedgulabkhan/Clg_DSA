#include<iostream>
using namespace std;
void create();
struct node{
	int data;
	node *next;
};
void rev(node *t1);
node *head=NULL, *tail=NULL;
int main(){
	create();
	node *t1=head;
	rev(t1);
	node *t2=head;
	cout<<t2->data<<" ";
	while(t2->next!=NULL){
		t2=t2->next;
		cout<<t2->data<<" ";
	}
	return 0;
}
void rev(node *t1){
	if(t1->next->next!=NULL){
		rev(t1->next);
	}
	t1->next->next=t1;
	head=tail;
	t1->next=NULL;
}
void create()
{
	struct node *temp;
	int ele;
	cout<<"Enter the element into the linked list(-999 is the end of the list)"<<endl;
	cin>>ele;
	while(ele!=-999){
		temp=new node;
		temp->next=NULL;
		temp->data=ele;
		if(head==NULL){
			head=temp;
			tail=temp;	
		}
		else{
			tail->next=temp;
			tail=temp;	
		}
	cout<<"A node has been created to store the data "<<ele<<endl;
	cout<<"Enter another element other than -999"<<endl;
	cin>>ele;
	}
}
