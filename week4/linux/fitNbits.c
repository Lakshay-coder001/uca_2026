#include<stdio.h>
int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);   // 32 - n
    return !(((x << shift) >> shift) ^ x);
}

int main(){
    int x;
    int n;
    printf("Enter x and n: ");
    scanf("%d",&x);
    scanf("%d",&n);

    int res = fitsBits(x,n);
    if(res == 1){
        printf("Yes it can be represented in n bits\n");
    }
    else{
        printf("No !");
    }
    return 0;
}