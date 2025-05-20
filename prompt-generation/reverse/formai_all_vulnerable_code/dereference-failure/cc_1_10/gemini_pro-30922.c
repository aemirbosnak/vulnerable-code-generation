//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// A utility function to create a stack of given capacity
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// A utility function to push an item to stack
void push(Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full!\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// A utility function to pop an item from stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// A utility function to print the contents of stack
void printStack(Stack* stack) {
    int i;
    for (i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// A utility function to transfer the top of one stack to another
void transfer(Stack* from, Stack* to) {
    int item = pop(from);
    push(to, item);
}

// A utility function to solve the Tower of Hanoi problem
void solveTowerOfHanoi(int num, Stack* from, Stack* to, Stack* aux) {
    if (num == 1) {
        transfer(from, to);
        return;
    }
    solveTowerOfHanoi(num - 1, from, aux, to);
    transfer(from, to);
    solveTowerOfHanoi(num - 1, aux, to, from);
}

// Driver program to test the above functions
int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    Stack* from = createStack(num_disks);
    Stack* to = createStack(num_disks);
    Stack* aux = createStack(num_disks);
    // Push the disks onto the from stack
    for (int i = num_disks; i >= 1; i--) {
        push(from, i);
    }
    printf("Initial state of the stacks:\n");
    printStack(from);
    printStack(to);
    printStack(aux);
    solveTowerOfHanoi(num_disks, from, to, aux);
    printf("Final state of the stacks:\n");
    printStack(from);
    printStack(to);
    printStack(aux);
    return 0;
}