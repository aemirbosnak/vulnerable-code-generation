//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *data;
    int top;
    int size;
} Stack;

Stack *createStack(int size) {
    Stack *stack = malloc(sizeof(Stack));
    stack->data = malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

void push(Stack *stack, int data) {
    if (stack->top + 1 >= stack->size) {
        printf("Error: Stack is full.\n");
        return;
    }
    stack->data[++stack->top] = data;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Error: Stack is empty.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(Stack *stack) {
    if (stack->top == -1) {
        printf("Error: Stack is empty.\n");
        return -1;
    }
    return stack->data[stack->top];
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

    printf("The disks have been moved from the source tower to the destination tower.\n");

    return 0;
}