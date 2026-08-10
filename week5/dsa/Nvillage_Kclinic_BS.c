//Max Heap problem
//can also be of BS

#include<stdio.h>
#include<stdlib.h>

int canhave(int a[] , int n , int k , int mid){
    int clinic = 0;
    for(int i = 0 ; i<n ; i++){
        int req = (a[i]+mid-1)/mid;
        clinic += req;
        if(clinic > k){
            return 0;
        }
    }
    return 1;
}

int solve(int a[] , int n , int k , int s, int e){
    int res = -1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(canhave(a,n,k, mid) == 1){
            res = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return res;
}
int main(){
    int n;
    printf("Enter no of vilages:");
    scanf("%d",&n);
    int *popu;
    popu = (int *)malloc(n*sizeof(int));
    int maxi = -1;
    for(int i = 0 ; i<n ; i++){
        scanf("%d", &popu[i]);
        if(popu[i] > maxi){
            maxi = popu[i];
        }
    }

    int k;
    printf("Enter no of clinics: ");
    scanf("%d",&k);

    int *res;
    res = (int *)malloc(n*sizeof(int));

    int min_clinic = solve(popu ,n,k,1,maxi);
    printf("max heads on a clinic is: %d",min_clinic);
    free(popu);
    free(res);
}