//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the node structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the stack structure using an array
typedef struct {
    int top;
    int capacity;
    int* stackArray;
} Stack;

// Function prototypes
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
bool isEmpty(Stack* stack);
bool isFull(Stack* stack);

int main() {
    // Initialize the stack
    Stack myStack = {0, MAX_SIZE, (int*)malloc(MAX_SIZE * sizeof(int))};

    // Push some values onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // Print the top value of the stack
    printf("Top value: %d\n", peek(&myStack));

    // Pop a value from the stack
    int poppedValue = pop(&myStack);
    printf("Popped value: %d\n", poppedValue);

    // Print the top value of the stack again
    printf("Top value after pop: %d\n", peek(&myStack));

    // Check if the stack is empty
    if (isEmpty(&myStack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}

// Push a value onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }

    stack->stackArray[++stack->top] = value;
}

// Pop a value from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }

    return stack->stackArray[stack->top--];
}

// Peek at the top value of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->stackArray[stack->top];
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}