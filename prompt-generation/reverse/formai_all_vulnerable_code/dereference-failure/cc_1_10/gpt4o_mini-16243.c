//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 10

// Structure for the Queue
typedef struct {
    int items[QUEUE_SIZE];
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

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
bool isFull(Queue* q) {
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

// Function to add an item to the queue
void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", data);
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
    }
    
    q->rear = (q->rear + 1) % QUEUE_SIZE; // Wrap around using modulus
    q->items[q->rear] = data;
    printf("Enqueued %d\n", data);
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    
    int data = q->items[q->front];
    
    // If there is only one element, reset the queue
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % QUEUE_SIZE; // Wrap around
    }
    
    printf("Dequeued %d\n", data);
    return data;
}

// Function to peek at the front of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1;
    }
    return q->items[q->front];
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = q->front; i != q->rear; i = (i + 1) % QUEUE_SIZE) {
        printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[q->rear]);
}

// Main function to test the queue implementation
int main() {
    Queue* q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    displayQueue(q);
    
    dequeue(q);
    dequeue(q);
    displayQueue(q);
    
    enqueue(q, 60);
    enqueue(q, 70);
    displayQueue(q);
    
    printf("Front element is: %d\n", peek(q));
    
    for (int i = 0; i < 8; i++) {
        enqueue(q, i * 10);
    }
    
    displayQueue(q);
    
    while (!isEmpty(q)) {
        dequeue(q);
    }
    
    displayQueue(q);
    
    free(q); // Free allocated memory
    return 0;
}