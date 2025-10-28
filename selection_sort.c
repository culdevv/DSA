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

void selection_sort (int arr[], int n){
    
    for (int i = 0; i<n-1; i++){
        int locate = -1;
        int min  = arr[i];
        for (int j = i; j < n ; j++){
            if (arr[j]<min){
                locate = j;
                min = arr[j];
        if (locate != -1) {swap(arr, n, i ,locate);}
        
            }
        }
        display(arr, n);
    }
}

int main(){
    int n = 12;
    int a[12] = {75,70,65,84,98,78,100,93,55,61,81,68};
    selection_sort(a,12);
    for (int i = 0; i<n ; i++){
        printf("%d ", a[i]);
    }

}