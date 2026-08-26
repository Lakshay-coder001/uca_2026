#include<stdio.h>
#include<string.h>
#include<ctype.h>

int eval_postfix(char *exp, int n){
    char st[n];
    int top = -1;

    for(int i = 0 ; i<n ; i++){
        char ch = exp[i];
        if(isdigit(ch)){
            top++;
            st[top] = ch - '0';
        }
        else{
            int b = st[top--];
            int a = st[top--];

            if (ch == '+') {
                st[++top] = a + b;
            }
            else if (ch == '-') {
                top++;
                st[top] = a - b;
            }
            else if (ch == '*') {
                top++;
                st[top] = a * b;
            }
            else if (ch == '/') {
                st[++top] = a / b;
            }
        }
    }
    return st[top];
}

int main(){
    int n ;
    printf("Enter len of the expression: ");
    scanf("%d",&n);

    char exp[n+1];
    for(int i = 0 ; i<n ; i++){
        scanf(" %c",&exp[i]);
    }
    exp[n] = '\0';
    // for(int i = 0 ; i<n ; i++){
    //     printf("%c ",exp[i]);
    // }

    int res = eval_postfix(exp,n);
    printf("evaluated postfix: %d", res);
}