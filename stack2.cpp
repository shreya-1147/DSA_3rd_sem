#include <iostream>
using namespace std;
struct node{
    int data;
    node*next;

}*head;
void push()
{
    int val;
    cin>>val;
    node*temp=new node();
    if(head==NULL){
    temp->data=val;
    temp->next=head;
    head=temp;
}
else{
    temp->data=val;
    temp->next=head;
    head=temp;
}
}
int pop( ){
    if(head==NULL){
        cout<<"Underflow";
        return -1;
    }
    else{
        int x=head->data;
        node*temp=head;
        head=head->next;
        delete (temp);
        return x;
    }
}
void display(){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
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