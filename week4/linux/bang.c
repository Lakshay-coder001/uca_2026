#include<stdio.h>

int bang(int num){
    int res = ((num | (~num + 1)) >> 31) + 1;
    return res;
}

int main(){
    int num ;
    printf("Enter number: ");
    scanf("%d",&num);

    int res = bang(num);
    printf("bang of num=%d without using(!) is: %d",num,res);
    return 0;
}