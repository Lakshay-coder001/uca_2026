#include<stdio.h>

int getByte(int num,int n){
    int res = num >> (n<<3);
    res = res & 0xFF;
    return res;
}

int main(){
    int num= 0x12345678;
    int n = 1;
    // printf("Enter num and n: ");
    // scanf("%d",&num);
    // scanf("%d",&n);
    int res = getByte(num,n);
    printf("%dth byte of 0x%X is: 0x%X",n,num,res);
    return 0;
}