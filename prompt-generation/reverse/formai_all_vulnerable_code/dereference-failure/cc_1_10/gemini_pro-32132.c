//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>

// A structure to represent a stack
typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

// A utility function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (int *)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// A utility function to push an item to stack
void push(Stack *stack, int item) {
    if (stack->top == stack->capacity - 1)
        return;
    stack->arr[++stack->top] = item;
}

// A utility function to pop an item from stack
int pop(Stack *stack) {
    if (stack->top == -1)
        return -1;
    return stack->arr[stack->top--];
}

// A utility function to print the contents of stack
void printStack(Stack *stack) {
    for (int i = 0; i <= stack->top; i++)
        printf("%d ", stack->arr[i]);
    printf("\n");
}

// The main function to solve Tower of Hanoi problem
void towerOfHanoi(int n, Stack *source, Stack *destination, Stack *auxiliary) {
    if (n == 1) {
        push(destination, pop(source));
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    push(destination, pop(source));
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Driver program to test above functions
int main() {
    int n = 4;  // Number of disks
    Stack *source = createStack(n);
    Stack *destination = createStack(n);
    Stack *auxiliary = createStack(n);

    // Push the disks in the source stack
    for (int i = n; i >= 1; i--)
        push(source, i);

    printf("Source stack: ");
    printStack(source);
    printf("Destination stack: ");
    printStack(destination);
    printf("Auxiliary stack: ");
    printStack(auxiliary);

    towerOfHanoi(n, source, destination, auxiliary);

    printf("Source stack: ");
    printStack(source);
    printf("Destination stack: ");
    printStack(destination);
    printf("Auxiliary stack: ");
    printStack(auxiliary);

    return 0;
}