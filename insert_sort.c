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




void insert_sort(int a[], int n){
    int x;
    int j;
    for (int i = 1; i<n ; i++){
        x=a[i];
        j=i;
        while (j>0 && a[j-1]>x){
            a[j] = a[j-1];
            j--;
        }
        a[j] = x;
    }
}



int main(){
    int n = 12;
    int a[12] = {75,70,65,84,98,78,100,93,55,61,81,68};
    insert_sort(a,12);
    for (int i = 0; i<n ; i++){
        printf("%d ", a[i]);
    }

}

