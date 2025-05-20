//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define a structure for a queue
typedef struct {
    int front;
    int rear;
    int size;
    int* queue;
} Queue;

// Function to create a new queue object
Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->queue = malloc(MAX_SIZE * sizeof(int));
    return q;
}

// Function to add an element to the back of the queue
void enqueue(Queue* q, int value) {
    if (q->size == MAX_SIZE) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->queue[q->rear] = value;
    q->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    q->size--;
    return value;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->size == 0);
}

// Function to get the size of the queue
int size(Queue* q) {
    return q->size;
}

// Function to get the element at the front of the queue
int front(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->queue[q->front];
}

// Function to get the element at the rear of the queue
int rear(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->queue[q->rear];
}

// Main function
int main() {
    Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Front: %d\n", front(q));
    printf("Rear: %d\n", rear(q));

    int value = dequeue(q);
    printf("Dequeued: %d\n", value);

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }

    return 0;
}