//FormAI DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

/* Configurable Queue Implementation */
typedef struct {
    int front, rear;
    int* array;
    unsigned int size;
} Queue;

Queue* createQueue(unsigned int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->size = 0;
    queue->rear = size - 1;
    queue->array = (int*)malloc(size * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == MAX_QUEUE_SIZE);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is Full!");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->array[queue->rear] = item;
    queue->size += 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty!");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size -= 1;
    return item;
}

int main() {
    Queue* queue = createQueue(MAX_QUEUE_SIZE);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Queue Front: %d\n", queue->array[queue->front]);
    printf("Queue Rear: %d\n", queue->array[queue->rear]);

    return 0;
}