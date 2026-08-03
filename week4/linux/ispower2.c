#include<stdio.h>

int isPower2(int x) {
    return !(x >> 31) & !!x & !(x & (x + ~0));
}

int main(){
    int num;
    printf("Enter number: ");
    scanf("%d",&num);

    int res = isPower2(num);
    if(res == 1){
        printf("It is power of 2\n");
    }
    else{
        printf("No");
    }
}