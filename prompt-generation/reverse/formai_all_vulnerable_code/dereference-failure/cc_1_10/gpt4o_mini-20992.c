//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 5 // Constants can be quite useful

// Struct to define a queue
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // Mark front position when first element is added
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return INT_MIN; // Indicate queue is empty
    }
    int element = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1; // Reset queue if it becomes empty
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", element);
    return element;
}

// Function to display the current state of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function to demonstrate the queue operations
int main() {
    Queue* q = createQueue();
    
    // Enqueue operations
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    
    // Attempt to enqueue beyond capacity
    enqueue(q, 60); 
    
    // Display queue
    display(q);
    
    // Dequeue operations
    dequeue(q);
    dequeue(q);
    
    // Display queue again
    display(q);
    
    // Enqueue two more elements
    enqueue(q, 60);
    enqueue(q, 70);
    
    // Display final state of queue
    display(q);
    
    // Clean up and free allocated memory
    free(q);
    
    return 0;
}