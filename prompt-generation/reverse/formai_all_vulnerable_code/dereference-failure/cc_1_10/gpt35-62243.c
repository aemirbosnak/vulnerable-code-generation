//FormAI DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int size;
    int array[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

int isFull(Queue* queue) {
    return (queue->size == MAX_QUEUE_SIZE);
}

void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Error: Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
    queue->array[queue->rear] = element;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty!\n");
        return -1;
    }
    int element = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    queue->size--;
    return element;
}

int main() {
    Queue* queue = createQueue();
    printf("Initial size of queue: %d\n", queue->size);

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    printf("Size of queue after 3 enqueues: %d\n", queue->size);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Size of queue after 2 dequeues: %d\n", queue->size);

    enqueue(queue, 20);
    printf("Enqueued element: %d\n", 20);
    printf("Size of queue after 1 enqueue: %d\n", queue->size);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Size of queue after 3 dequeues: %d\n", queue->size);

    enqueue(queue, 25);
    enqueue(queue, 30);
    enqueue(queue, 35);
    enqueue(queue, 40);
    enqueue(queue, 45);
    enqueue(queue, 50);
    printf("Enqueued 6 elements: %d, %d, %d, %d, %d, %d\n", 25, 30, 35, 40, 45, 50);
    printf("Size of queue after 6 enqueues: %d\n", queue->size);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("Dequeued 6 elements!\n");

    enqueue(queue, 55);
    printf("Enqueued element: %d\n", 55);
    printf("Size of queue after 1 enqueue: %d\n", queue->size);

    dequeue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Size of queue after 1 dequeue: %d\n", queue->size);
    
    return 0;
}