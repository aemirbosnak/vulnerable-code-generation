//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

// Function prototypes
void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char value);
char pop(Stack *s);
char peek(Stack *s);
int precedence(char operator);
void infixToPostfix(const char *infix, char *postfix);
int evaluatePostfix(const char *postfix);
int isOperator(char ch);

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression (or 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(infix, MAX, stdin);

        if (strncmp(infix, "exit", 4) == 0) {
            break;
        }

        // Remove newline character
        infix[strcspn(infix, "\n")] = 0;

        infixToPostfix(infix, postfix);
        int result = evaluatePostfix(postfix);

        printf("Postfix: %s\n", postfix);
        printf("Result: %d\n", result);
    }

    return 0;
}


void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0'; // Return null character when stack is empty
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0'; // Return null character when stack is empty
}

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
    }
    return -1; // Non-operator
}

void infixToPostfix(const char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            // If the character is an operand, add it to output
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            // If the character is '(', push it to stack
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            // If the character is ')', pop and output from the stack
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from stack
        } else if (isOperator(infix[i])) {
            // Operator
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    // Pop all the operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int evaluatePostfix(const char *postfix) {
    Stack stack;
    initStack(&stack);
    int i;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            // Convert character to integer and push to stack
            int num = postfix[i] - '0';
            push(&stack, num);
        } else if (isOperator(postfix[i])) {
            // Pop two operands
            int right = pop(&stack);
            int left = pop(&stack);
            int result;
            switch (postfix[i]) {
            case '+':
                result = left + right;
                break;
            case '-':
                result = left - right;
                break;
            case '*':
                result = left * right;
                break;
            case '/':
                result = left / right;
                break;
            }
            push(&stack, result);
        }
    }
    return pop(&stack); // The final result
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}