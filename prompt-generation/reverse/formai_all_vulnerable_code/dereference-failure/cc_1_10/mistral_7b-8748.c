//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QUEUE_MAX_SIZE 10

typedef struct Queue {
    int front;
    int rear;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = size;
    queue->front = queue->rear = -1;
    queue->array = (int*) calloc(size, sizeof(int));
    return queue;
}

bool isFull(Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

void addElement(Queue* queue, int element) {
    if (isFull(queue)) {
        fprintf(stderr, "Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
}

int removeElement(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }
    int element = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return element;
}

void destroyQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

void printQueue(Queue* queue) {
    int i;
    printf("Queue: ");
    for (i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
        printf("%d ", queue->array[i]);
    }
    printf("%d\n", queue->array[queue->rear]);
}

void testQueue() {
    Queue* queue = createQueue(QUEUE_MAX_SIZE);

    addElement(queue, 5);
    addElement(queue, 10);
    addElement(queue, 15);

    printQueue(queue);

    removeElement(queue);
    printQueue(queue);

    addElement(queue, 20);
    printQueue(queue);

    destroyQueue(queue);
}

int main() {
    testQueue();
    return 0;
}