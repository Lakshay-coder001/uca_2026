#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
void swap(int arr[], int i , int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int s , int e){
    int pivot = arr[e];
    int i = s;
    for(int j= s; j<e ; j++){
        if(arr[j] <= pivot){
            swap(arr,i,j);
            i++;
        }
    }
    swap(arr,i,e);
    return i;
}

void quickselect(int arr[], int s, int e, int k){
    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);
    if(p == k){
        return;
    }
    else if(p >k){
        quickselect(arr,s,p-1,k);
    }
    else{
        quickselect(arr,p+1,e,k);
    }
}
int main() {
    int sizes[] = {1000, 2000, 5000, 10000, 20000, 50000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    for (int x = 0; x < numSizes; x++) {

        int n = sizes[x];
        int k = n / 2;

        int *arr = (int *)malloc(n * sizeof(int));
        int *temp = (int *)malloc(n * sizeof(int));

        if (arr == NULL || temp == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        clock_t start = clock();

        for (int r = 0; r < 100; r++) {
            memcpy(temp, arr, n * sizeof(int));
            quickselect(temp, 0, n - 1, k - 1);
        }

        clock_t end = clock();

        double runtime = ((double)(end - start) / CLOCKS_PER_SEC) / 100.0;

        printf("%d\t\t%.8f\n", n, runtime);

        free(arr);
        free(temp);
    }

}