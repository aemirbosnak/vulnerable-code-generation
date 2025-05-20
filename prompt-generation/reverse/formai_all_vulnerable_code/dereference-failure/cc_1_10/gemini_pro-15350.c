//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int size;
} Stack;

Stack *createStack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (int *)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

void push(Stack *stack, int data) {
    if (stack->top == stack->size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void towerOfHanoi(int n, Stack *source, Stack *destination, Stack *auxiliary) {
    if (n == 1) {
        push(destination, pop(source));
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, destination);
    push(destination, pop(source));
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

void printStack(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }

    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack *source = createStack(n);
    Stack *destination = createStack(n);
    Stack *auxiliary = createStack(n);

    for (int i = n; i >= 1; i--) {
        push(source, i);
    }

    towerOfHanoi(n, source, destination, auxiliary);

    printf("Source:\n");
    printStack(source);

    printf("Destination:\n");
    printStack(destination);

    printf("Auxiliary:\n");
    printStack(auxiliary);

    return 0;
}