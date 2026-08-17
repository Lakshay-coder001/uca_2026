#include<stdio.h>
#include<stdlib.h>

int find4freqnum(int arr[], int n){
    for(int i = 0 ; i<n ; i++){
        int num = arr[i]%n;
        arr[num] += n;
    }

    for(int i = 0 ; i<n ; i++){
        if(arr[i]/n == 4){
            return i;
        }
    }
    return -1;
}

int main(){
    int n ;
    printf("Enter len of arr: ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    int res = find4freqnum(arr,n);
    printf("The num repeating 4 times is: %d",res);
    return 0;
}