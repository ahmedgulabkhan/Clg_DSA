#include<iostream>
#include<math.h>
using namespace std;
int top=-1;
char post[100];
int s[50],temp,i;
class stack{
    public:
        void push(int ele){
            s[++top]=ele;
        }
        int pop(){
            int ele=s[top];
            top--;
            return ele;
        }
};
int main(){
stack st;
cout<<"Enter the postfix expression: "<<endl;
cin>>post;
for(i=0;post[i]!='\0';i++){
    if(post[i]>='0' && post[i]<='9')
        st.push(post[i]-'0');
    else{
        temp=st.pop();
        switch(post[i]){
            case '+':st.push(st.pop()+temp);break;
            case '-':st.push(st.pop()-temp);break;
            case '*':st.push(st.pop()*temp);break;
            case '/':st.push(st.pop()/temp);break;
            case '%':st.push(st.pop()%temp);break;
            case '^':st.push(pow(st.pop(),temp));break;
        }
    }
}
cout<<s[0];
return 0;
}
