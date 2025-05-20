//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct Stack {
    int top;
    int items[MAX_SIZE];
} Stack;

// Structure to represent a queue
typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Function prototypes
Stack* createStack();
int isFullStack(Stack* stack);
int isEmptyStack(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
Queue* createQueue(unsigned capacity);
int isFullQueue(Queue* queue);
int isEmptyQueue(Queue* queue);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);
int front(Queue* queue);

// Utility function to print a stack
void printStack(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("The stack is empty! Oh no!\n");
        return;
    }
    printf("Current stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Utility function to print a queue
void printQueue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("The queue is empty! This is shocking!\n");
        return;
    }
    printf("Current queue: ");
    for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
        printf("%d ", queue->array[i]);
    }
    printf("%d\n", queue->array[queue->rear]); // Print the last element
}

// Main function to demonstrate the stack and queue
int main() {
    printf("Welcome to the shocking Data Structures demonstration!\n");

    // Create a stack
    Stack* stack = createStack();
    printf("A new stack has been created!\n");

    // Push elements onto the stack
    printf("\nPushing elements onto the stack...\n");
    for (int i = 1; i <= 5; i++) {
        printf("Pushing %d...\n", i);
        push(stack, i);
        printStack(stack);
    }

    // Pop an element from the stack
    printf("\nPopping an element from the stack...\n");
    int poppedItem = pop(stack);
    printf("Popped %d from the stack!\n", poppedItem);
    printStack(stack);

    // Create a queue
    Queue* queue = createQueue(5);
    printf("\nA new queue has been created! What's coming next?\n");

    // Add elements to the queue
    printf("\nEnqueuing elements into the queue...\n");
    for (int i = 1; i <= 5; i++) {
        printf("Enqueuing %d...\n", i);
        enqueue(queue, i);
        printQueue(queue);
    }
    
    // Dequeue an element from the queue
    printf("\nDequeuing an element from the queue...\n");
    int dequeuedItem = dequeue(queue);
    printf("Dequeued %d from the queue!\n", dequeuedItem);
    printQueue(queue);

    // Free allocated memory
    free(stack);
    free(queue->array);
    free(queue);

    printf("\nThank you for watching! What a ride!\n");
    
    return 0;
}

// Function implementations
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isFullStack(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFullStack(stack)) {
        printf("Stack Overflow! Can't push %d\n", item);
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack Underflow! Can't pop an item!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int peek(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("The stack is empty! No peek!\n");
        return -1;
    }
    return stack->items[stack->top];
}

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFullQueue(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmptyQueue(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFullQueue(queue)) {
        printf("Queue Overflow! Can't enqueue %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue Underflow! Can't dequeue an item!\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("The queue is empty! Can't get the front!\n");
        return -1;
    }
    return queue->array[queue->front];
}