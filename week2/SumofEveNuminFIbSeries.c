#include<stdio.h>

typedef struct  {
    int first;
    int second;
}pair;

pair SumofEvenNumFibSeries(int n, int *ans){ // TC = O(N)
    pair res = {0,0};

    if( n== 1 || n==2){
        res.first  = 1;
        res.second = 0;
        *ans = 0;
        return res;
    }

    int l = 1;
    int r = 1;
    int curr = 0;
    int sumi = 0;
    while(curr<=n){
        curr = l+r;
        l = r;
        r = curr;
        if((curr&1) == 0){
            res.second += curr;
        }
        res.first = r;
    }
    *ans = res.second;
    return res;

}

int optimizedSumEveNumFibSeries(int n){ //TC: O(LogN)
    int sumi = 0;
    int first_num = 2;
    int second_num = 8;
    while(first_num<=n){
        sumi += first_num;
        int compute = 4*(second_num) + first_num;
        first_num = second_num;
        second_num = compute;
    }
    return sumi;
}
int main(){
    int n;
    printf("Enter number n: ");
    scanf("%d", &n);
    int ans = 0;

    pair res = SumofEvenNumFibSeries(n, &ans);
    printf("The sum of even number till %d th number is: %d\n" , n, ans);

    int res2 = optimizedSumEveNumFibSeries(n);
    printf("optimized solution : %d" , res2);
}