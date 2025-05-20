//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Structure to represent a stack
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Function prototypes
void initStack(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char item);
char pop(Stack *s);
char peek(Stack *s);
int precedence(char operator);
void infixToPostfix(char *infix, char *postfix);
int evaluatePostfix(char *postfix);

// Main function
int main() {
    char infix[MAX], postfix[MAX];
    
    // Exciting input from users!
    printf("Welcome to the Expression Parser!\n");
    printf("Enter a mathematical expression (e.g., A+B*(C-D)):\n");
    fgets(infix, MAX, stdin);
    
    infix[strcspn(infix, "\n")] = 0; // Remove the newline character

    printf("Infix Expression: %s\n", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix Expression: %s\n", postfix);
    
    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);
    
    return 0;
}

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(Stack *s, char item) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = item;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Function to pop an item from the stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack Underflow!\n");
        return '\0';
    }
}

// Function to peek at the top item of the stack
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    } else {
        return '\0';
    }
}

// Function to determine the precedence of operators
int precedence(char operator) {
    switch (operator) {
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

// Function to convert infix expression to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int i, j = 0;
    
    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) {  // If the token is an operand
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from stack
        } else {  // The token is an operator
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null terminate the postfix expression
}

// Function to evaluate the postfix expression
int evaluatePostfix(char *postfix) {
    Stack stack;
    initStack(&stack);
    int i;

    for (i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];

        if (isdigit(token)) {
            push(&stack, token - '0'); // Convert char to int
        } else { // Operator
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            switch (token) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
                // Here you can add more cases for more operators!
            }
        }
    }
    
    return pop(&stack); // The result will be the last item on the stack
}