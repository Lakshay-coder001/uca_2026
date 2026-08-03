#include<stdio.h>

int sign(int num){
    int res = num >>31;
    res = res | (!!num);
    return res;
}

int main(){
    int num;
    printf("Enter num: ");
    scanf("%d",&num);

    if(sign(num) == 1){
        printf("Positive");
    }
    else if(sign(num) == 0){
        printf("Zero");
    }
    else{
        printf("Negative");
    }
    return 0;
}