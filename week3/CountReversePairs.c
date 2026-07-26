#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int s, int mid, int e) {
    int *temp = (int *)malloc((e - s + 1) * sizeof(int));

    int l = s;
    int r = mid + 1;
    int k = 0;

    while (l <= mid && r <= e) {
        if (arr[l] <= arr[r]) {
            temp[k++] = arr[l++];
        } else {
            temp[k++] = arr[r++];
        }
    }

    while (l <= mid) {
        temp[k++] = arr[l++];
    }

    while (r <= e) {
        temp[k++] = arr[r++];
    }

    for (int i = s; i <= e; i++) {
        arr[i] = temp[i - s];
    }

    free(temp);
}

void CountReversePairs(int arr[], int s , int mid , int e,int *count) {
    int r = mid+1;
    for(int i = s ; i<=mid ; i++){
        while(r<=e && arr[i] > 2*arr[r]){
            r++;
        }
        *count += (r -(mid+1));
    }
}

void mergeSort(int arr[], int s, int e, int *count) {
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid,count);
    mergeSort(arr, mid + 1, e, count);
    CountReversePairs(arr,s,mid,e,count);
    merge(arr, s, mid, e);
}



int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 0;
    mergeSort(arr, 0,n-1,&count);
    printf("Total number of revese pairs are: %d",count);

    free(arr);
    return 0;
}