//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10 // Maximum size of the queue

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a queue
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
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // First element
    }
    q->rear = (q->rear + 1) % MAX; // Circular increment
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element, reset the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX; // Circular increment
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to get the front element of the queue
int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

// Function to get the rear element of the queue
int rear(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->rear];
}

// Function to display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i != q->rear; i = (i + 1) % MAX) {
        printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[q->rear]); // Print the rear element
}

// Function to free the queue
void freeQueue(Queue* q) {
    free(q);
}

int main() {
    Queue* q = createQueue();
    
    // Enqueue some elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    
    // Display queue
    display(q);
    
    // Dequeue some elements
    dequeue(q);
    dequeue(q);
    
    // Display front and rear elements
    printf("Front element: %d\n", front(q));
    printf("Rear element: %d\n", rear(q));
    
    // Enqueue more elements
    enqueue(q, 60);
    enqueue(q, 70);
    
    // Display queue
    display(q);
    
    // Dequeue until empty
    dequeue(q);
    dequeue(q);
    dequeue(q);
    
    // Final display
    display(q);
    
    // Free memory
    freeQueue(q);
    return 0;
}