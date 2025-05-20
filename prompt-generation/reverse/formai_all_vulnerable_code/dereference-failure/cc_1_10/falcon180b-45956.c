//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int top;
    int capacity;
    int *stack;
} Stack;

// Function to create a new stack with given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->stack = (int*) malloc(capacity * sizeof(int));
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top >= stack->capacity - 1) {
        printf("Stack Overflow\n");
        exit(0);
    }
    stack->top++;
    stack->stack[stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top < 0) {
        printf("Stack Underflow\n");
        exit(0);
    }
    int value = stack->stack[stack->top];
    stack->top--;
    return value;
}

// Function to display the elements in the stack
void display(Stack* stack) {
    if (stack->top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the stack are: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->stack[i]);
    }
    printf("\n");
}

// Function to move n disks from source to destination using the given source, destination and auxiliary stacks
void towerOfHanoi(int n, Stack* source, Stack* destination, Stack* auxiliary) {
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

    srand(time(NULL));
    int capacity = rand() % 100 + 1;

    Stack* source = createStack(capacity);
    Stack* destination = createStack(capacity);
    Stack* auxiliary = createStack(capacity);

    int i;
    for (i = n; i >= 1; i--) {
        push(source, i);
    }

    printf("Initial configuration:\n");
    display(source);

    towerOfHanoi(n, source, destination, auxiliary);

    printf("\nFinal configuration:\n");
    display(destination);

    return 0;
}