#include <iostream>
using namespace std;
void MERGE(int A[], int B[], int m, int n)
{
    int i=0,j=0,k=0,C[m+n];
    while(i<m && j<n)
    {
        if(A[i]<B[j])
        {
            C[k]=A[i];
            i++;
        }
        else
        {
            C[k]=B[j];
            j++;
        }
        k++;
    }
    while(i<m)
    {
        C[k]=A[i];
        i++;
        k++;
    }
    while(j<n)
    {
        C[k]=B[j];
        j++;
        k++;
    }
}
int main()
{
    cout<<"Enter the size of first array: ";
    int m;
    cin>>m;
    cout<<"Enter the size of second array: ";
    int n;
    cin>>n;
    int A[m],B[n],C[m+n];
    cout<<"Enter the elements of first array: ";
    for(int i=0;i<m;i++)
        cin>>A[i];
    cout<<"Enter the elements of second array: ";
    for(int i=0;i<n;i++)
        cin>>B[i];
    MERGE(A,B,m,n);
    cout<<"The merged array is: ";
    for(int i=0;i<m+n;i++)
        cout<<C[i]<<" ";
    return 0;
}