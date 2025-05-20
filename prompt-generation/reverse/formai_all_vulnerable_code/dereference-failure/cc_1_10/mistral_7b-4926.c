
//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

typedef struct {
    int front;
    int rear;
    int capacity;
    int* array;
} Queue;

void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->capacity = MAX_QUEUE_SIZE;
    q->array = (int*)malloc(q->capacity * sizeof(int));
}

int isFull(Queue* q) {
    return (q->rear + 1) % q->capacity == q->front;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    q->array[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    return value;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    printf("Queue: ");
    do {
        printf("%d ", q->array[i]);
        i = (i + 1) % q->capacity;
    } while (i != q->rear);
    printf("\n");
}

void destroyQueue(Queue* q) {
    free(q->array);
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 15);

    printQueue(&queue);

    dequeue(&queue);

    printQueue(&queue);

    enqueue(&queue, 20);

    printQueue(&queue);

    destroyQueue(&queue);

    return 0;
}