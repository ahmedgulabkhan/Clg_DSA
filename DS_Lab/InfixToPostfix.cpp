#include<iostream>
using namespace std;
int top=-1;
char input[100],output[100],s[100],temp;
int i,k=0;
class stack{
    public:
        void push(char ele){
            s[++top]=ele;
        }
        int pop(){
            int ele=s[top];
            top--;
            return ele;
        }
        int priority(char ele){
            switch(ele){
                case '+':
                case '-':return 1;break;
                case '*':
                case '/':
                case '%':return 2;break;
                case '^':return 3;break;
            }
            return 0;
        }
};
int main(){
stack st;
cout<<"Enter the expression: "<<endl;
cin>>input;
for(i=0;input[i]!='\0';i++){
    if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z'))
        output[k++]=input[i];
    else if(input[i]=='(')
        st.push(input[i]);
    else if(input[i]==')'){
        while((temp=st.pop())!='(')
            output[k++]=temp;
    }
    else if(top==-1)
        st.push(input[i]);
    else if(s[top]=='(')
        st.push(input[i]);
    else if(st.priority(input[i])>st.priority(s[top]))
        st.push(input[i]);
    else{
        while((st.priority(input[i])<=st.priority(s[top])) && (top!=-1))
            output[k++]=st.pop();
        st.push(input[i]);
    }
}
while(top!=-1)
    output[k++]=st.pop();
output[k]='\0';
cout<<output;
return 0;
}
