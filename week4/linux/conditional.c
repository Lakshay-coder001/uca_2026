#include<stdio.h>

int conditional(int x, int y, int z) {
    int mask = ~(!!x) + 1;
    return (mask & y) | (~mask & z);
}

int main(){
    int num1,num2,num3;
    printf("Enter numbers: ");
    scanf("%d",&num1);
    scanf("%d",&num2);
    scanf("%d",&num3);

    int res = conditional(num1,num2,num3);
    printf("condtional of num1,num2 and num3 is: %d",res);
}