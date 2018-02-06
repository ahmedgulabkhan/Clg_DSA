#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
node *create(node *head);
node *addBeg(node *head);
node *addMid(node *head);
node *addEnd(node *head);
node *delBeg(node *head);
void delMid(node *head);
node *delEnd(node *head);
int main(){
struct node *tail,*head,*atempele;
head=NULL;
tail=NULL;
atempele=NULL;
int choice;
do{
	cout<<"Menu"<<endl<<"1.Create"<<endl<<"2.Insert"<<endl<<"3.Delete"<<endl<<"4.Display"<<endl<<"5.Merge"<<endl<<"6.Exit"<<endl;
	cin>>choice;
	switch(choice){
		case 1: head=create(head);break;
		case 2:{
			int achoice;
			cout<<"1.Beginning"<<endl<<"2.Middle"<<endl<<"3.End"<<endl;
			cin>>achoice;
			switch(achoice){
				case 1: head=addBeg(head);break;
				case 2: atempele=addMid(head);break;
				case 3: tail=addEnd(head);
				        break;	
			}
		}
		break;
		case 3: {
			int dchoice;
			cout<<"1.Beginning"<<endl<<"2.Middle"<<endl<<"3.End"<<endl;
			cin>>dchoice;
			switch(dchoice){
				case 1: head=delBeg(head);break;
				case 2: delMid(head);break;
				case 3: tail=delEnd(head);break;	
			}
		}
		break;
		case 4:{
			if(head!=NULL){
				struct node *traverse;
				traverse=head;
				cout<<traverse->data<<endl;
				while(traverse->next!=NULL){
					traverse=traverse->next;
					cout<<traverse->data<<endl;
				}
			}
			else{
				cout<<"The List is empty"<<endl;
			}
		}
		break;
		case 5:;break;
		case 6: cout<<"You have exited from the menu..."<<endl;break;
	}
}while(choice!=6);
return 0;
}
node *create(node *head)
{
	struct node *tail,*temp;
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
    return head; 
}
node *addBeg(node *head){
	if(head!=NULL){
    	struct node *temp;
    	int ele;
    	cout<<"Enter the element you want to insert at the beginning: "<<endl;
    	cin>>ele;
    	temp=new node;
    	temp->data=ele;
    	temp->next=head;
    	head=temp;
    	cout<<ele<<" has been inserted at the beginning"<<endl;
    	return head;
    }
    else{
    	cout<<"The List is empty, so cannot insert any elements"<<endl;
    	return NULL;
	}
}
node *addMid(node *head){
    struct node *tempele,*tempp,*tempn,*traverse;
    int ele,pos,count=1;
    tempp=head;
    tempn=head;
    traverse=head;
    if(head!=NULL){
    	cout<<"At which position do you want to insert your element(starting from 1)"<<endl;
    	cin>>pos;
    	while(traverse->next!=NULL){
    		traverse=traverse->next;
    		count++;
		}
    	if(pos==1){
    		cout<<"Use 'Insert-->Beginning' option instead"<<endl;
    		return NULL;
    	}
		else if(pos==count){
			cout<<"Use 'Insert-->End' option instead"<<endl;
			return NULL;
		}
		else if(pos>count){
			cout<<"The position you entered is greater than the number of elements in your list"<<endl;
			return NULL;
		}
		else{
    		cout<<"Enter the element you want to insert at the position "<<pos<<endl;
    		cin>>ele;
    		tempele=new node;
    		tempele->data=ele;
    		for(int i=1;i<pos;i++){
        		tempn=tempn->next;
    		}
    		tempele->next=tempn;
    		for(int i=2;i<pos;i++){
        		tempp=tempp->next;
    		}
    		tempp->next=tempele;
    		cout<<"The element "<<ele<<" has been inserted at the position "<<pos<<endl;
			return tempele;
		}
	}
	else{
		cout<<"The List is empty, so cannot insert any elements"<<endl;
		return NULL;
	}
}
node *addEnd(node *head){
	if(head!=NULL){
		struct node *tempele,*templast;
		int ele;
		templast=head;
		cout<<"Enter the element you want to insert at the end"<<endl;
		cin>>ele;
		tempele=new node;
		tempele->data=ele;
		while(templast->next!=NULL){
			templast=templast->next;
		}
		templast->next=tempele;
		tempele->next=NULL;
		templast=tempele;
		cout<<"The element "<<ele<<" has been inserted at the end"<<endl;
		return templast;
	}
	else{
		cout<<"The List is empty, so cannot insert any elements"<<endl;
		return NULL;
	}
}
node *delBeg(node *head){
	if(head!=NULL){
		struct node *temp;
		temp=head;
		head=head->next;
    	cout<<"The element "<<temp->data<<" has been deleted from the beginning"<<endl;
		delete temp;
		return head;
	}
	else{
		cout<<"The List is empty, so cannot delete any elements"<<endl;
		return NULL;
	}
}
void delMid(node *head){
	struct node *tempp,*tempn,*tempele,*traverse;
	int pos,count=1;
	tempp=head;
	tempn=head;
	tempele=head;
	traverse=head;
    if(head!=NULL){
    	cout<<"Enter the position of the element you want to delete(starting from 1)"<<endl;
    	cin>>pos;
    	while(traverse->next!=NULL){
    		traverse=traverse->next;
    		count++;
		}
    	if(pos==1){
    		cout<<"Use 'Delete-->Beginning' option instead"<<endl;
    	}
		else if(pos==count){
			cout<<"Use 'Delete-->End' option instead"<<endl;
		}
		else if(pos>count){
			cout<<"The position you entered is greater than the number of elements in your list"<<endl;
		}
		else{
			for(int i=2;i<pos;i++){
				tempp=tempp->next;
			}
			tempele=tempp->next;
			for(int i=0;i<pos;i++){
				tempn=tempn->next;
			}
			tempp->next=tempn;
    		cout<<"The element "<<tempele->data<<" has been deleted from the position "<<pos<<endl;
    		delete tempele;
		}
	}
	else{
		cout<<"The List is empty, so cannot delete any elements"<<endl;
	}
}
node *delEnd(node *head){
	if(head!=NULL){
		struct node *tempp,*templast,*traverse;
		int count=1;
		traverse=head;
		tempp=head;
		templast=head;
		while(templast->next!=NULL){
			templast=templast->next;
			count++;
		}
		for(int i=2;i<count;i++){
			tempp=tempp->next;
		}
		tempp->next=NULL;
    	cout<<"The element "<<templast->data<<" has been deleted from the end"<<endl;
    	delete templast;
		return tempp;
	}
	else{
		cout<<"The List is empty, so cannot delete any elements"<<endl;
		return NULL;
	}
}
