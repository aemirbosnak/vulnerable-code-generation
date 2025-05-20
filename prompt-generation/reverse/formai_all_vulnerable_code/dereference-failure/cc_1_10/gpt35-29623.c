//FormAI DATASET v1.0 Category: Queue ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// Data structure that represents a Queue
typedef struct queue {
    int arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize a queue
Queue* initializeQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if queue is empty
int isQueueEmpty(Queue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Function to check if queue is full
int isQueueFull(Queue* q) {
    if (q->front == 0 && q->rear == MAX_QUEUE_SIZE-1) {
        return 1;
    }
    if (q->front == q->rear+1) {
        return 1;
    }
    return 0;
}

// Function to add element to queue
void enqueue(Queue* q, int val) {
    if (isQueueFull(q)) {
        printf("Queue is full! Cannot add element\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->arr[q->rear] = val;
    printf("Element %d is enqueued\n", val);
}

// Function to remove element from queue
void dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty! Cannot remove element\n");
        return;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front+1) % MAX_QUEUE_SIZE;
    }
    printf("Element %d is dequeued\n", val);
}

// Function to display elements of queue
void displayQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    int i = q->front;
    if (q->front <= q->rear) {
        while (i <= q->rear) {
            printf("%d ", q->arr[i]);
            i++;
        }
    } else {
        while (i < MAX_QUEUE_SIZE) {
            printf("%d ", q->arr[i]);
            i++;
        }
        i = 0;
        while (i <= q->rear) {
            printf("%d ", q->arr[i]);
            i++;
        }
    }
    printf("\n");
}

// Main function
int main() {
    Queue* q = initializeQueue();

    // Enqueue elements to queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Display elements of queue
    displayQueue(q);

    // Dequeue elements from queue
    dequeue(q);
    dequeue(q);

    // Display elements of queue
    displayQueue(q);

    // Enqueue elements to queue
    enqueue(q, 60);
    enqueue(q, 70);

    // Display elements of queue
    displayQueue(q);

    return 0;
}