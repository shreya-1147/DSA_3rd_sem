#include <iostream>
using namespace std;
int DAT(int n){
    int fib(int n){
        if(n==1 || n==2)
        return DAT[n]=n-1;
        else{
            if(DAT[n]==0){
                DAT[n]=fib(n-1)+fib(n-2);
            }
            
        }
        return DAT[n];
    }
    DAT[3]==0
    return DAT[3]
    DAT[5]=fib(4)+fib(3)
    DAT[3]=fib(2)+fib(1)
    DAT[4]=fib(3)+fib(2)
}
int main(){
    int n,fib;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<fib(i)<<" "<<endl;
    }
}
