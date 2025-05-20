//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5  // Maximum size of the queue

// Structure to represent the queue
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a queue and initialize its properties
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
bool isFull(Queue* q) {
    return (q->rear == MAX - 1);
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to insert an element into the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // First element enqueue
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued to the queue\n", value);
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        // Reset the queue once all elements are dequeued
        q->front = -1;
        q->rear = -1;
    }
    printf("%d dequeued from the queue\n", item);
    return item;
}

// Function to peek at the front element of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, nothing to peek\n");
        return -1;
    }
    return q->items[q->front];
}

// Function to display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, nothing to display\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    Queue* q = createQueue();
    
    // Demonstrating enqueue operations
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    
    display(q);

    // Attempting to enqueue into a full queue
    enqueue(q, 60);  // This should fail

    // Demonstrating dequeue operations
    dequeue(q);
    dequeue(q);
    
    display(q);
    
    // Enqueue more elements after dequeuing
    enqueue(q, 60);
    display(q);

    // Peek at the front element of the queue
    int front = peek(q);
    if (front != -1) {
        printf("Front element is: %d\n", front);
    }

    // Dequeue all elements
    while (!isEmpty(q)) {
        dequeue(q);
    }

    display(q); // Queue should be empty now

    // Cleanup
    free(q);
    return 0;
}