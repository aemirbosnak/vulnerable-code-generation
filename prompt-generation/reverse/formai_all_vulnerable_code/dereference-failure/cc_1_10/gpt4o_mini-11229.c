//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5  // Maximum size of the queue

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

// Function to check if the queue is full
bool isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0;  // Set front on the first enqueue
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d to the queue.\n", value);
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  // Return -1 if queue is empty
    }
    int removedValue = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;  // Reset the queue if no elements are left
    }
    printf("Dequeued %d from the queue.\n", removedValue);
    return removedValue;
}

// Function to display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to display.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    Queue* q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    
    // Attempt to enqueue when the queue is full
    enqueue(q, 60);

    display(q);

    dequeue(q);
    dequeue(q);
    
    display(q);
    
    enqueue(q, 60);
    enqueue(q, 70);
    
    display(q);

    // Cleaning up the allocated memory for the queue
    free(q);

    return 0;
}