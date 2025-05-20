//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define stack structure
typedef struct stack {
    int top;
    char* array;
} stack;

// Create a new stack
stack* createStack(int capacity) {
    stack* s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    s->array = (char*)malloc(capacity * sizeof(char));
    return s;
}

// Check if stack is empty
int isEmpty(stack* s) {
    return s->top == -1;
}

// Push a character onto the stack
void push(stack* s, char c) {
    s->array[++s->top] = c;
}

// Pop a character off the stack
char pop(stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->array[s->top--];
}

// Peek at the top of the stack
char peek(stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->array[s->top];
}

// Get precedence of operator
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

// Convert infix notation to postfix using Shunting Yard algorithm
char* infixToPostfix(char* infix) {
    stack* s = createStack(100);
    int i, j;
    char* postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(s, infix[i]);
        } else if (infix[i] == ')') {
            while (peek(s) != '(') {
                postfix[j++] = pop(s);
            }
            pop(s);
        } else {
            while (!isEmpty(s) && precedence(infix[i]) <= precedence(peek(s))) {
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
        }
    }
    while (!isEmpty(s)) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    return postfix;
}

// Evaluate postfix notation
int evaluatePostfix(char* postfix) {
    stack* s = createStack(100);
    int i, op1, op2;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(s, postfix[i]-'0');
        } else {
            op2 = pop(s);
            op1 = pop(s);
            switch (postfix[i]) {
                case '+': push(s, op1 + op2); break;
                case '-': push(s, op1 - op2); break;
                case '*': push(s, op1 * op2); break;
                case '/': push(s, op1 / op2); break;
            }
        }
    }
    return pop(s);
}

int main() {
    char infix[100], *postfix;
    int result;
    printf("Enter an expression in infix notation: ");
    scanf("%s", infix);
    postfix = infixToPostfix(infix);
    printf("Postfix notation: %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}