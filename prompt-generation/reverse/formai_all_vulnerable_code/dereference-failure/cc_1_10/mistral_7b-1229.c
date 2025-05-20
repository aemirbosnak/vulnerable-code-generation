//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CQueue {
    int front, rear;
    int capacity;
    int* array;
} CQueue;

CQueue* createQueue(int size) {
    CQueue* queue = (CQueue*) malloc(sizeof(CQueue));
    queue->capacity = size;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int*) calloc(size, sizeof(int));
    return queue;
}

void enqueue(CQueue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}

int dequeue(CQueue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return item;
}

void printQueue(CQueue* queue) {
    int i = queue->front;
    if (i == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while (i <= queue->rear) {
        printf("%d ", queue->array[i]);
        i++;
    }
    printf("\n");
}

int main() {
    int size = 5;
    CQueue* queue = createQueue(size);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printQueue(queue);

    int dequeued = dequeue(queue);
    printf("Dequeued: %d\n", dequeued);

    printQueue(queue);

    dequeued = dequeue(queue);
    printf("Dequeued: %d\n", dequeued);

    enqueue(queue, 60);

    printQueue(queue);

    free(queue->array);
    free(queue);

    return 0;
}