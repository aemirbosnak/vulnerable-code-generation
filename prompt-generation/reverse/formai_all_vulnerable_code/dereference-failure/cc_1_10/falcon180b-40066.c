//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue structure
typedef struct {
    int front;
    int rear;
    int *queue;
} Queue;

// Function to initialize an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->queue = (int*)malloc(MAX_SIZE * sizeof(int));
    return q;
}

// Function to add an element to the end of the queue
void enqueue(Queue* q, int element) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = element;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int element = q->queue[q->front];
    q->front++;
    return element;
}

// Function to print the elements of the queue
void printQueue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    printQueue(q);
    int element = dequeue(q);
    printf("Dequeued element: %d\n", element);
    printQueue(q);
    element = dequeue(q);
    printf("Dequeued element: %d\n", element);
    printQueue(q);
    element = dequeue(q);
    printf("Dequeued element: %d\n", element);
    printQueue(q);
    element = dequeue(q);
    printf("Dequeued element: %d\n", element);
    printQueue(q);
    return 0;
}