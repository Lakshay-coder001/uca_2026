#include<stdio.h>
#include<stdlib.h>

void set_mat_zero(int** arr, int n , int m){
    int col = 1;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ;j<m ; j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                if(j != 0){
                    arr[0][j] = 0;
                }
                else{
                    col =0;
                }
            }
        }
    }

    for(int i = 1 ;i<n ; i++){
        for(int j = 1 ; j<m ;j++){
            if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
    }

    if(arr[0][0] == 0){
        for(int j = 0 ;j<m ;j++){
            arr[0][j] = 0;
        }
    }
    if(col == 0){
        for(int i =0 ; i<n ; i++){
            arr[i][0] = 0;
        }
    }
}

int main(){
    int n;
    int m;
    printf("Enter vlaue of n and m: ");
    scanf("%d ",&n);
    scanf("%d ",&m);

    int **arr = (int **)malloc(n * sizeof(int *));
    
    for (int i = 0; i <n; i++) {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    set_mat_zero(arr,n,m);

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}