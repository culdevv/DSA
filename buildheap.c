#include <stdio.h>

void swap(int *Arr,int  i, int j){
    int tmp = Arr[i];
    Arr[i] = Arr[j];
    Arr[j] = tmp;
    return;
}
void buildheap(int *A, int n, int i){
    int e = A[i];
    int j = 2+i+1;

    while (j < n){
        int k=j+1;
        if (k<n && A[j]<A[k])
            j=k;
        if (A[j]<e) break;
        A[i] = A[j];
        i=j;
        j+2*i+1;
    }
    A[i] = e;
}

void heapsort(int *A, int n){
    for (int i = n/2 - 1; i>0; i--){
        buildheap(A, n, i);
    while (n>1){
        swap(A,0,n-1);
        n=n-1;
        buildheap(A,n,0);
    }
    }
}
int main(){
    int Arr[10] = {1,4,2,3,7,5,6,9,8,0};
    int n = 10;
    int i = 0;
    buildheap(Arr, n, i);
    for (int i = 0 ; i < n-1; i++){
        printf("%d", Arr[i]);
    }
}