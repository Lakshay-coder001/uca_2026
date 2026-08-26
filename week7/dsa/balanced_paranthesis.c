#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isbal_para(char *str){
    char st[31];
    int top = -1;
    for(int i = 0 ; str[i] != '\0' ; i++){
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            top++;
            st[top] = ch;
        }
        else if(ch == ')' || ch==']' || ch == '}'){
            if(top == -1){
                return false;
            }
            if((ch == ')' && st[top] == '(') || (ch == ']' && st[top] == '[') || (ch == '}' && st[top] == '{')){
                top--;
            }
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    char input[31];
    // for(int i = 0 ; i<31 ; i++){
    //     scanf("%c", &input[i]);
    // }
    scanf("%30s",input);

    if(isbal_para(input)){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}