#include<iostream>
using namespace std;
int q1[50],q2[50];
int index=-1;
int main(){
	int choice;
	do{
		cout<<"Menu\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
		cin>>choice;
		switch(choice){
			case 1:{
				int ele;
				cout<<"Enter the element you want to insert\n";
				cin>>ele;
				q1[++index]=ele;
				cout<<ele<<" has been inserted\n";
				//cout<<q1<<endl;
				break;
			}
			case 2:{
				if(index!=-1){
					for(int i=0;i<index;i++){
						q2[i]=q1[index-1-i];
					}
					cout<<q1[index]<<" has been popped\n";
					index--;
					for(int i=0;i<=index;i++){
						q1[i]=q2[index-i];
					}
				}
				else{
					cout<<"The stack is empty\n";
				}
				break;
			}
			case 3:{
				if(index!=-1){
					for(int i=0;i<=index;i++){
						q2[i]=q1[index-i];
					}
					for(int k=0;k<=index;k++)
						cout<<q2[k]<<endl;
				}
				else{
					cout<<"The stack is empty\n";
				}
				break;
			}
			case 4:{
				cout<<"You chose to exit from the menu\n";
				break;
			}
		}
	}while(choice!=4);
	return 0;
}
