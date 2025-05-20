//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create and initialize the queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
bool isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 for empty queue
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Queue becomes empty
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

// Function to get the front element of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        return -1;
    }
    return q->items[q->front];
}

// Function to display the contents of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < MAX; i++) {
        if (q->items[i] != 0) {
            printf("%d ", q->items[i]);
        }
    }
    printf("\n");
}

// Driver program to test the queue implementation
int main() {
    Queue* q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    
    printf("Front element: %d\n", peek(q));
    
    dequeue(q);
    display(q);
    
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    
    dequeue(q);
    dequeue(q);
    display(q);
    
    printf("Front element: %d\n", peek(q));
    
    // Enqueue more elements
    for (int i = 60; i <= 90; i += 10) {
        enqueue(q, i);
    }
    
    display(q);
    
    // Try to enqueue one more element to test the full condition
    enqueue(q, 100);
    
    // Dequeue all elements
    while (!isEmpty(q)) {
        dequeue(q);
    }
    
    display(q);
    
    // Free the allocated queue
    free(q);
    
    return 0;
}