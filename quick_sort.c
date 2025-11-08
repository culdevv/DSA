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

void Partition(int A[], int n, int first, int last) {
    if (first >= last) return;

    int c = A[first];   // chọn pivot là phần tử đầu
    int i = first + 1;
    int j = last;

    while (i <= j) {
        while (A[i] <= c && i <= j) i++;
        while (A[j] > c && i <= j) j--;

        if (i < j) {
            swap(A, n, i, j);
            display(A, n);
        }
    }

    // Đưa pivot về đúng vị trí
    swap(A, n, first, j);
    display(A, n);

    // Đệ quy sắp xếp 2 phần còn lại
    Partition(A, n, first, j - 1);
    Partition(A, n, j + 1, last);
}

// Hàm quick_sort gọi Partition
void quick_sort(int arr[], int n) {
    Partition(arr, n, 0, n - 1);
}

int main(){
    int n = 12;
    int a[12] = {75,70,65,84,98,78,100,93,55,61,81,68};
    quick_sort(a,12);
    for (int i = 0; i<n ; i++){
        printf("%d ", a[i]);
    }

}