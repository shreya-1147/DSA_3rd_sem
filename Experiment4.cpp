#include <iostream>
using namespace std;

//Merge Sort
void Merge(int A[], int l, int mid, int r) {
    int n = mid - l + 1;
    int m = r - mid;
    int L[n], R[m];
    for (int i = 0; i < n; i++)
        L[i] = A[l + i];
    for (int j = 0; j < m; j++)
        R[j] = A[mid + j + 1];
    int i = 0, j = 0, k = l;
    while (i < n && j < m) {
        if (L[i] < R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < m) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void Merge_Sort(int A[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        Merge_Sort(A, l, mid);
        Merge_Sort(A, mid + 1, r);
        Merge(A, l, mid, r);
    }
}

//Quick Sort
int Partition(int A[], int l, int r) {
    int pivot = A[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (A[j] < pivot) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;
    return i + 1;
}

void Quick_Sort(int A[], int l, int r) {
    if (l < r) {
        int p = Partition(A, l, r);
        Quick_Sort(A, l, p - 1);
        Quick_Sort(A, p + 1, r);
    }
}

int main() {
    int N, choice;
    cout<<"enter size"<<endl;
    cin >> N;
    cout<<"enter numbers"<<endl;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cout<<"enter choice 1 for merge and 2 for quick"<<endl;
    cin >> choice;
    if (choice == 1)
        Merge_Sort(A, 0, N - 1);
    else if (choice == 2)
        Quick_Sort(A, 0, N - 1);
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    return 0;
}