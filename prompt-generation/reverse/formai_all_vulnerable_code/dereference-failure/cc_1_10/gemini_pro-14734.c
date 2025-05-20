//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to get the precedence of an operator
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if an operator is left-associative
int isLeftAssociative(char op) {
    return op != '^';
}

// Function to convert an infix expression to a postfix expression
char* infixToPostfix(char* infix) {
    // Create a stack to store the operators
    char stack[100];
    int top = -1;

    // Create a string to store the postfix expression
    char* postfix = malloc(100);
    int postfixIndex = 0;

    // Iterate over the infix expression
    for (int i = 0; infix[i] != '\0'; i++) {
        // If the current character is an operand, add it to the postfix expression
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[postfixIndex++] = infix[i];
        }
        // If the current character is an operator, push it onto the stack
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (top != -1 && getPrecedence(stack[top]) >= getPrecedence(infix[i]) && isLeftAssociative(infix[i])) {
                postfix[postfixIndex++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        // If the current character is an opening parenthesis, push it onto the stack
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        // If the current character is a closing parenthesis, pop operators from the stack until an opening parenthesis is encountered
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[postfixIndex++] = stack[top--];
            }
            top--;
        }
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        postfix[postfixIndex++] = stack[top--];
    }

    // Null-terminate the postfix expression
    postfix[postfixIndex] = '\0';

    // Return the postfix expression
    return postfix;
}

// Function to evaluate a postfix expression
double evaluatePostfix(char* postfix) {
    // Create a stack to store the operands
    double stack[100];
    int top = -1;

    // Iterate over the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++) {
        // If the current character is an operand, push it onto the stack
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            double operand = postfix[i] - '0';
            stack[++top] = operand;
        }
        // If the current character is an operator, pop two operands from the stack and perform the operation
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            double operand2 = stack[top--];
            double operand1 = stack[top--];
            switch (postfix[i]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
                case '^':
                    stack[++top] = pow(operand1, operand2);
                    break;
            }
        }
    }

    // The top of the stack contains the result of the expression
    return stack[top];
}

int main() {
    // Get the infix expression from the user
    char* infix = malloc(100);
    printf("Enter an infix expression: ");
    gets(infix);

    // Convert the infix expression to a postfix expression
    char* postfix = infixToPostfix(infix);

    // Evaluate the postfix expression
    double result = evaluatePostfix(postfix);

    // Print the result
    printf("Result: %f\n", result);

    // Free the allocated memory
    free(infix);
    free(postfix);

    return 0;
}