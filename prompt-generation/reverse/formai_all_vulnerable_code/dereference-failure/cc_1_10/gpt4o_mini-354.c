//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for a dynamic stack
typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

// Structure for a dynamic queue
typedef struct {
    int front, rear, size;
    int capacity;
    int *array;
} Queue;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to create a queue of given capacity
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the stack is full
int isFullStack(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to the stack
void push(Stack* stack, int item) {
    if (isFullStack(stack)) {
        printf("Stack overflow! Can't push %d\n", item);
        return;
    }
    stack->array[++stack->top] = item;
    printf("Pushed %d onto stack\n", item);
}

// Function to remove an item from the stack
int pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack underflow! Can't pop from an empty stack\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to check if the queue is full
int isFullQueue(Queue* queue) {
    return queue->size == queue->capacity;
}

// Function to check if the queue is empty
int isEmptyQueue(Queue* queue) {
    return queue->size == 0;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item) {
    if (isFullQueue(queue)) {
        printf("Queue overflow! Can't enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("Enqueued %d to queue\n", item);
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue underflow! Can't dequeue from an empty queue\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Function to display the stack
void displayStack(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("The stack is empty!\n");
        return;
    }
    printf("Current Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to display the queue
void displayQueue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("The queue is empty!\n");
        return;
    }
    printf("Current Queue: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

// Main function to demonstrate stack and queue operations
int main() {
    Stack* stack = createStack(5);
    Queue* queue = createQueue(5);

    printf("Welcome to the Data Structures Visualization!\n");

    // Stack operations
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    displayStack(stack);

    printf("Popping from stack: %d\n", pop(stack));
    displayStack(stack);

    // Queue operations
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    displayQueue(queue);

    printf("Dequeuing from queue: %d\n", dequeue(queue));
    displayQueue(queue);

    // Cleanup memory
    free(stack->array);
    free(stack);
    free(queue->array);
    free(queue);

    return 0;
}