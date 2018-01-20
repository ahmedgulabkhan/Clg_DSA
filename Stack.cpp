#include <iostream>
using namespace std;
int top=-1;
class stack{
public:
    void push(int a[],int size){
        int ele;
        if(top==size-1)
            cout<<"Stack overflow";
        else{
            cout<<"Enter the element you want to push"<<endl;
            cin>>ele;
            cout<<ele<<" has been pushed into the stack"<<endl;
            a[++top]=ele;
        }
    }
    void pop(int a[],int size){
        int ele;
        if(top>-1){
            ele=a[top];
            cout<<ele<<" has been popped"<<endl;
            top--;
        }
        else
            cout<<"Stack underflow";
    }
    void display(int a[],int size){
        for(int i=top;i>-1;i--)
            cout<<a[i]<<endl;
    }
};
int main()
{
stack st;
int size,choice;
cout<<"Enter the size of the stack";
cin>>size;
int a[size];
do{
    cout<<"Menu"<<endl<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
    cin>>choice;
    switch(choice){
        case 1:st.push(a,size);break;
        case 2:st.pop(a,size);break;
        case 3:st.display(a,size);break;
        case 4:cout<<"You have exited from the menu..."<<endl;break;
    }
}while(choice!=4);
return 0;
}
