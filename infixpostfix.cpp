#include <iostream>
#include <string>
using namespace std;
int main() {
   string exp;
   cin>>exp;
   int i=0;
   while(exp[i]!='/0'){
    if(isalpnum(exp[i]))
    cout<<exp[i];
    else if(exp[i]=='(')
    push(exp[i])
   }
}