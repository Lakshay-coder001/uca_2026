#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int arr[], int i , int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int arr[] , int n , int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[largest] < arr[l]){
        largest = l;
    }
    if(r<n && arr[largest] < arr[r]){
        largest = r;
    }
    if(largest != i){
        swap(arr,i,largest);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n){
    for(int i = n/2 -1 ; i>=0 ; i--){
        heapify(arr,n,i);
    }

    for(int i = n-1 ;i>0 ; i--){
        swap(arr,i,0);
        heapify(arr,i,0);
    }
}

void gen_asc(int arr[] , int n){
    for(int i = 0 ; i<n  ; i++){
        arr[i] = i+1;
    }
}

void gen_desc(int arr[], int n){
    for(int i = 0 ; i<n ; i++){
        arr[i] = n-i;
    }
}

void gen_random(int arr[], int n){
    for(int i = 0 ; i<n ; i++){
        arr[i] = rand();
    }
}

int main(){
    int n;
    printf("enter length of array: ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n*(sizeof(int)));

    gen_random(arr,n);

    gen_asc(arr,n);

    gen_desc(arr,n);


    clock_t start , end;
    double exe_time;

    start = clock();
    heapsort(arr,n);
    end = clock();

    exe_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Execution time is: %f seconds\n", exe_time);

}