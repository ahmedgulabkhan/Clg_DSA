#include<iostream>
using namespace std;
int front=-1,rear=-1;
class queue{
    public:
        void insert(int q[],int size){
            if(rear==size-1)
                cout<<"Queue is full"<<endl;
            else{
                int ele;
                cout<<"Enter the element you want to insert"<<endl;
                cin>>ele;
                q[++rear]=ele;
            }
        }
        void del(int q[],int size){
            if(front==rear)
                cout<<"Queue is empty"<<endl;
            else{
                front++;
                cout<<q[front]<<" has been deleted"<<endl;
            }
        }
        void display(int q[],int size){
            for(int i=front+1;i<=rear;i++)
                cout<<q[i]<<endl;
        }
};
int main(){
queue Q;
int size,choice;
cout<<"Enter the size of the queue"<<endl;
cin>>size;
int q[size];
do{
    cout<<"Menu"<<endl<<"1.Insert"<<endl<<"2.Delete"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
    cin>>choice;
    switch(choice){
        case 1:Q.insert(q,size);break;
        case 2:Q.del(q,size);break;
        case 3:Q.display(q,size);break;
        case 4:cout<<"You have exited from the menu..."<<endl;break;
    }
}while(choice!=4);
return 0;
}
