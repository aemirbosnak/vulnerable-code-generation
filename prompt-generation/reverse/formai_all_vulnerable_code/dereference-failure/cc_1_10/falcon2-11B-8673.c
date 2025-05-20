//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure
typedef struct Stack {
    int top;
    int *data;
    int size;
} Stack;

// Push a value onto the stack
void push(Stack *s, int value) {
    if (s->top >= s->size) {
        s->size *= 2;
        s->data = realloc(s->data, s->size * sizeof(int));
    }
    s->data[s->top] = value;
    s->top++;
}

// Pop a value off the stack
int pop(Stack *s) {
    int value = s->data[s->top - 1];
    s->top--;
    return value;
}

// Is the stack empty?
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Is the stack full?
int isFull(Stack *s) {
    return s->top == s->size - 1;
}

// Convert a string to a C expression
int stringToExpression(char *s) {
    Stack *stack = malloc(sizeof(Stack));
    stack->top = -1;
    stack->data = malloc(sizeof(int) * 1000);
    stack->size = 1000;

    int i = 0;
    while (i < strlen(s)) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            push(stack, s[i] - '0');
        } else if (s[i] == '(') {
            push(stack, 1);
        } else if (s[i] == ')') {
            int oper = pop(stack);
            while (oper!= 1) {
                push(stack, oper);
                oper = pop(stack);
            }
        }
        i++;
    }

    int result = 0;
    while (!isEmpty(stack)) {
        result = pop(stack) + result;
    }

    free(stack->data);
    free(stack);
    return result;
}

int main() {
    char s[] = "1 + 2 * 3 - 4";
    int result = stringToExpression(s);
    printf("The result of the expression '%s' is: %d\n", s, result);
    return 0;
}