//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

// Function to create a circular queue
CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

// Check if the queue is full
int isFull(CircularQueue* q) {
    return (q->front == (q->rear + 1) % MAX);
}

// Enqueue operation
void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued %d to the queue\n", value);
}

// Dequeue operation
int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) { // Queue has only one element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued %d from the queue\n", value);
    return value;
}

// Display queue elements
void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    if (q->rear >= q->front) {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    } else {
        for (int i = q->front; i < MAX; i++) {
            printf("%d ", q->items[i]);
        }
        for (int i = 0; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    }
    printf("\n");
}

// Main function to demonstrate circular queue operations
int main() {
    CircularQueue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    
    dequeue(q);
    display(q);
    
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60); // This should indicate the queue is full
    display(q);
    
    dequeue(q);
    dequeue(q);
    display(q);
    
    enqueue(q, 70);
    enqueue(q, 80);
    display(q);
    
    // Clean up
    free(q);
    
    return 0;
}