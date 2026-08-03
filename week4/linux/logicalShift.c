#include<stdio.h>

int logicalShift(int x, int n) {
    int mask = ~((~0) << (32 + (~n + 1)));
    return (x >> n) & mask;
}

int main(){
    int num= 0x87654321;
    int n =4;
    // printf("Enter num and n: ");
    // scanf("%d",&num);
    // scanf("%d",&n);

    int res = logicalShift(num,n);
    printf("Logical shift of num=0x%X of n=%d is: 0x%X",num,n,res);
}