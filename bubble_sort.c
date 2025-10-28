#include <stdio.h>

void swap (int arr[], int n, int i,int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    return;
}

void display( int arr[], int n){
    for (int i=0; i<n; i++){ printf("%d ", arr[i]);}
    printf("\n");
}

void bubble_sort(int a[], int n)
{
    int i, j;
    for (i=0 ; i<n-1; i++){
        for (j=n-1 ; j>=i+1; j--){
            if (a[j]<a[j-1]) swap(a,n,j,j-1);
        }

    }
}

int main(){
    int n = 12;
    int a[12] = {75,70,65,84,98,78,100,93,55,61,81,68};
    bubble_sort(a,12);
    for (int i = 0; i<n ; i++){
        printf("%d ", a[i]);
    }

}