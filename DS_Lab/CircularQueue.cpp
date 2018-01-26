#include <iostream>
using namespace std;
int front=-1,rear=-1;
class cqueue{
    public:
    void insert(int cq[],int size){
            if((front==-1 && rear==size-1) || ((rear>front) && ((rear)%size==front))){
                cout<<"Queue is full..."<<endl;
            }
            else{
                int ele;
                cout<<"Enter the element you want to insert: "<<endl;
                cin>>ele;
                rear++;
                cq[rear]=ele;
                cout<<ele<<" has been inserted into the queue"<<endl;
            }
    }
    void del(int cq[],int size){
        if(front==rear)
            cout<<"Queue is empty"<<endl;
        else if(front==-1){
            front++;
            cout<<cq[front]<<" has been deleted"<<endl;
        }
        else{
            front++;
            cout<<cq[front]<<" has been deleted"<<endl;
        }

    }
    void display(int cq[],int size){
        for(int i=front+1;i<=rear;i++){
            cout<<cq[i]<<endl;
        }
    }
};
int main()
{
cqueue CQ;
int size,choice;
cout<<"Enter the size of the Circular Queue"<<endl;
cin>>size;
int cq[size];
do{
    cout<<"Menu"<<endl<<"1.Insert"<<endl<<"2.Delete"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
    cin>>choice;
    switch(choice){
        case 1:CQ.insert(cq,size);break;
        case 2:CQ.del(cq,size);break;
        case 3:CQ.display(cq,size);break;
        case 4:cout<<"You have exited from the menu..."<<endl;break;
    }
}while(choice!=4);
return 0;
}
