//FormAI DATASET v1.0 Category: Syntax parsing ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100
#define MAX_OPERATORS 10

// Data structure to store the operator and its precedence
struct operator {
    char name;
    int precedence;
};

// Stack structure for infix to postfix conversion
struct stack {
    int top;
    char data[MAX_LENGTH];
};

// Function to check if a character is an operator
int isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infixExpression[], char postfixExpression[]) {
    int i, j;
    struct operator operators[MAX_OPERATORS];
    int operatorsCount = 0;
    struct stack s;
    s.top = -1;

    for(i=0; i<strlen(infixExpression); i++) {
        if(infixExpression[i] >= '0' && infixExpression[i] <= '9') {
            // Operand, add to postfix expression
            postfixExpression[j++] = infixExpression[i];
        }
        else if(isOperator(infixExpression[i])) {
            // Operator, check precedence and add to postfix expression
            while(s.top >= 0 && getPrecedence(s.data[s.top]) >= getPrecedence(infixExpression[i])) {
                postfixExpression[j++] = s.data[s.top--];
            }
            s.data[++s.top] = infixExpression[i];
        }
        else if(infixExpression[i] == '(') {
            // Open bracket, add to stack
            s.data[++s.top] = infixExpression[i];
        }
        else if(infixExpression[i] == ')') {
            // Close bracket, pop out all operators until open bracket is found
            while(s.top >= 0 && s.data[s.top] != '(') {
                postfixExpression[j++] = s.data[s.top--];
            }
            if(s.top >= 0 && s.data[s.top] == '(') {
                s.top--;
            }
        }
    }

    // Pop out all remaining operators from the stack
    while(s.top >= 0) {
        postfixExpression[j++] = s.data[s.top--];
    }
    postfixExpression[j] = '\0';
}

int main() {
    char infixExpression[MAX_LENGTH];
    char postfixExpression[MAX_LENGTH];
    printf("Enter the infix expression: ");
    scanf("%s", infixExpression);
    infixToPostfix(infixExpression, postfixExpression);
    printf("Postfix expression is: %s", postfixExpression);
    return 0;
}