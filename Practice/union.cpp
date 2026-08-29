#include<iostream>
using namespace std;

int main()
{
    int A[] = {1, 2, 3, 5};
    int B[] = {2, 3, 4, 6};
    int C[8];

    int i=0, j=0, k=0;

    while(i<4 && j<4)
    {
        if(A[i] < B[j])
        {
            C[k] = A[i];
            i++;
        }
        else if(A[i] > B[j])
        {
            C[k] = B[j];
            j++;
        }
        else
        {
            C[k] = A[i];
            i++;
            j++;
        }
        k++;
    }

    while(i<4)
    {
        C[k] = A[i];
        i++;
        k++;
    }

    while(j<4)
    {
        C[k] = B[j];
        j++;
        k++;
    }

    cout << "Union: ";

    for(int i=0; i<k; i++)
    {
        cout << C[i] << " ";
    }

    return 0;
}