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


void MergeArrays(int A[],int m, int n, int p){
	int i=m,j=n+1;
	while (i<j && j<=p){
		if (A[i]<=A[j]) i++;
		else {//chen Aj vao vi tri i
			int x=A[j];
			for (int k=j-1;k>=i;k--) 
				A[k+1]=A[k];
			A[i]=x;
			i++; j++;
		}
	}
}

void merge_sort(int a[] , int first, int last){
    if (first >= last) return;
    else{
        int m = (last+first)/2;
        merge_sort(a,first, m);
        merge_sort(a,m+1, last);
        MergeArrays(a, first,m, last);
    }
}

int main(){
    int n = 12;
    int a[12] = {75,70,65,84,98,78,100,93,55,61,81,68};
    merge_sort(a,0,11);
    for (int i = 0; i<n ; i++){
        printf("%d ", a[i]);
    }

}