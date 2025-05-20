//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 // Maximum size of the Queue

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

// Function to create a queue and initialize its elements
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
    return q->rear == MAX - 1;
}

// Function to enqueue an element in the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Unable to enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Unable to dequeue\n");
        return -1; // Return -1 to indicate an error
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) { // Reset the queue if it becomes empty
        q->front = q->rear = -1;
    }
    printf("Dequeued %d\n", item);
    return item;
}

// Function to display the contents of the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Function to peek at the front element of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Unable to peek\n");
        return -1; // Return -1 to indicate an error
    }
    return q->items[q->front];
}

// Main function to test the queue implementation
int main() {
    Queue* myQueue = createQueue();
    
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    
    displayQueue(myQueue);
    
    printf("Front element is: %d\n", peek(myQueue));
    
    dequeue(myQueue);
    displayQueue(myQueue);
    
    dequeue(myQueue);
    displayQueue(myQueue);
    
    enqueue(myQueue, 40);
    enqueue(myQueue, 50);
    displayQueue(myQueue);
    
    free(myQueue); // Free the allocated memory for the queue
    return 0;
}