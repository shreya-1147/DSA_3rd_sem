#include<iostream>
using namespace std;
 #define MAXSIZE 50
int stack [MAXSIZE];
int top=-1;
void push()
{
    if(top>MAXSIZE-1)
    cout<<"Overflow";

    else{
        int x;
        cin>>x;
        top++;
        stack[top]=x;
    }
}
int pop(){
    if(top==-1)
    cout<<"Underflow";
}
    else{
        int x=stack[top];
        top=top-1;
        return x;
    }
}
    void display(){
        for(int i=top;i>=0;i--){
        cout<<stack[i];
    }
}

int main(){
   

    int choice;
    do{
        
        cin>>choice;
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            cout<<pop();
            break;
            case 3:
            display();
            break;
            default:
            cout<<"You have entered wrong choice";
            exit(0);
        }
    }
    while(choice<=3);
}
    

