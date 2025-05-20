//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Queue struct
typedef struct Queue {
    int* array;
    int front;
    int rear;
    int size;
} Queue;

// Function to initialize Queue
void initQueue(Queue* queue, int size) {
    queue->array = (int*)malloc(size * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
}

// Function to check if Queue is empty
int isQueueEmpty(Queue* queue) {
    return (queue->front == -1);
}

// Function to check if Queue is full
int isQueueFull(Queue* queue) {
    return (queue->rear == queue->size - 1);
}

// Function to dequeue from Queue
void dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    if (queue->front == 0)
        queue->rear = (queue->rear + 1) % queue->size;

    printf("Dequeued: %d\n", item);
}

// Function to enqueue to Queue
void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    }

    if (queue->rear == -1) {
        queue->rear = 0;
    }

    queue->array[++queue->rear] = item;
    printf("Enqueued: %d\n", item);
}

// Function to print Queue
void printQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->array[i]);
    printf("\n");
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    initQueue(queue, 5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    free(queue->array);
    free(queue);

    return 0;
}