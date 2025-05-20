//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void parseSyntax(char *input) {

    int i, n = strlen(input);
    int flag = 1;    //to check if balanced or not
    char *stack = (char*)malloc(n*sizeof(char));  //memory allocation for stack
    int top = -1;   //stack pointer initialization
    
    for(i=0;i<n;i++) {

        if(input[i] == '(' || input[i] == '{' || input[i] == '[') {
            stack[++top] = input[i];
        }

        if(input[i] == ')') {
            if(top == -1 || stack[top] != '(') {
                flag = 0;
                break;
            }
            top--;
        }

        if(input[i] == '}') {
            if(top == -1 || stack[top] != '{') {
                flag = 0;
                break;
            }
            top--;
        }

        if(input[i] == ']') {
            if(top == -1 || stack[top] != '[') {
                flag = 0;
                break;
            }
            top--;
        }
    }

    if(top == -1 && flag == 1) {
        printf("Valid Syntax");
    }
    else {
        printf("Invalid Syntax");
    }
}

int main() {
    printf("Enter a Syntax to Evaluate: ");
    char input[100];
    scanf("%s",input);
    parseSyntax(input);
    return 0;
}