//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a node in the linked list
struct Node {
    int value;
    struct Node* next;
};

// Define a struct for the Stack data structure
struct Stack {
    int top;
    int size;
    int* array;
};

// Define a struct for the Queue data structure
struct Queue {
    int front;
    int rear;
    int size;
    int* array;
};

// Function to initialize a Stack with a given size
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->size = size;
    stack->array = (int*) malloc(size * sizeof(int));
    return stack;
}

// Function to push an integer onto the Stack
void push(struct Stack* stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("ERROR: Stack overflow\n");
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}

// Function to pop an integer off the Stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("ERROR: Stack underflow\n");
        return -1;
    }
    int value = stack->array[stack->top];
    stack->top--;
    return value;
}

// Function to initialize a Queue with a given size
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
    queue->array = (int*) malloc(size * sizeof(int));
    return queue;
}

// Function to enqueue an integer onto the Queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == queue->size - 1) {
        printf("ERROR: Queue overflow\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}

// Function to dequeue an integer off the Queue
int dequeue(struct Queue* queue) {
    if (queue->front > queue->rear) {
        printf("ERROR: Queue underflow\n");
        return -1;
    }
    int value = queue->array[queue->front];
    queue->front++;
    return value;
}

// Function to print the contents of a Stack
void printStack(struct Stack* stack) {
    printf("Stack:\n");
    printf("size: %d, top: %d\n", stack->size, stack->top);
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->array[i]);
    }
}

// Function to print the contents of a Queue
void printQueue(struct Queue* queue) {
    printf("Queue:\n");
    printf("size: %d, front: %d, rear: %d\n", queue->size, queue->front, queue->rear);
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\n", queue->array[i]);
    }
}

int main() {
    // Create a Stack and push some values onto it
    struct Stack* stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // Create a Queue and enqueue some values onto it
    struct Queue* queue = createQueue(5);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);

    // Pop the top value off the Stack and enqueue it onto the Queue
    int value = pop(stack);
    printf("Popped off Stack: %d\n", value);
    enqueue(queue, value);

    // Dequeue the first value off the Queue and push it onto the Stack
    value = dequeue(queue);
    printf("Dequeued from Queue: %d\n", value);
    push(stack, value);

    // Print the contents of the Stack and Queue
    printStack(stack);
    printQueue(queue);

    // Clean up the memory used by the Stack and Queue
    free(stack->array);
    free(stack);
    free(queue->array);
    free(queue);

    return 0;
}