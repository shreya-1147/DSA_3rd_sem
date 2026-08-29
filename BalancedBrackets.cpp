#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isBalanced(char & str)
      stack <char> s;{
        for(char x : str){
            if(x=='()' || x=='[' || x=='{')
            s.push(x);
            else{
                if(s.empty()==True)
                return false;
                if(isMatched(s.top(),x)==false){
                    return false;
                }
                else
                s.pop();
            }
            return(s.empty()==true);
        }
        bool isMatched(char a, char b){
            return(a=='(' && b==')' || a=='[' && b==']' || a=='{' && b=='}');
        }
    int main(){
    string str;
    cin>>str;
    if(isBalanced(str)==true)
    cout<<"Balanced"<<endl;
    else
    cout<<"Imbalanced"<<endl;
    return 0;
}