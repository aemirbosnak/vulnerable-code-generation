//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the stack data structure
typedef struct {
    int top;
    int *data;
    size_t capacity;
    size_t size;
} Stack;

// Function to create a new stack
Stack *createStack(size_t capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->data = (int *)malloc(capacity * sizeof(int));
    stack->capacity = capacity;
    stack->size = 0;
    return stack;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = value;
    stack->size++;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    int value = stack->data[stack->top];
    stack->top--;
    stack->size--;
    return value;
}

// Function to print the stack
void printStack(Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Function to create a new thread that prints the stack
void *printStackThread(void *arg) {
    Stack *stack = (Stack *)arg;
    printStack(stack);
    pthread_exit(NULL);
}

// Main function
int main() {
    // Create a new stack with capacity of 10
    Stack *stack = createStack(10);
    
    // Create a new thread to print the stack
    pthread_t thread;
    pthread_create(&thread, NULL, printStackThread, stack);
    
    // Push elements onto the stack
    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    push(stack, 20);
    
    // Print the stack
    printStack(stack);
    
    // Pop elements from the stack
    printf("Pop %d\n", pop(stack));
    printf("Pop %d\n", pop(stack));
    printf("Pop %d\n", pop(stack));
    printf("Pop %d\n", pop(stack));
    
    // Wait for the thread to finish
    pthread_join(thread, NULL);
    
    // Free memory
    free(stack->data);
    free(stack);
    
    return 0;
}