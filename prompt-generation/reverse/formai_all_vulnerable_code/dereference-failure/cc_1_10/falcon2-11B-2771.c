//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue
typedef struct queue {
    int front;
    int rear;
    int size;
    int* array;
} Queue;

// Function to create a new queue
Queue* createQueue(int size) {
    Queue* newQueue = malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("Failed to create new queue\n");
        exit(1);
    }
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->size = size;
    newQueue->array = malloc(size * sizeof(int));
    if (newQueue->array == NULL) {
        printf("Failed to allocate memory for queue array\n");
        exit(1);
    }
    return newQueue;
}

// Function to enqueue an element in the queue
void enqueue(Queue* q, int data) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->array[q->rear] = data;
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->array[q->front];
    if (q->front == q->rear) {
        q->front = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return data;
}

// Function to print the queue
void printQueue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front: %d\n", q->array[q->front]);
    printf("Rear: %d\n", q->array[q->rear]);
    printf("Array:\n");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

int main() {
    int size = 5;
    Queue* queue = createQueue(size);

    if (queue == NULL) {
        return 1;
    }

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    return 0;
}