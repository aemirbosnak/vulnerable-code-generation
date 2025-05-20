//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 10

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

Queue *queueCreate() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

bool queueIsEmpty(Queue *queue) {
    return queue->size == 0;
}

void enqueue(Queue *queue, int data) {
    QueueNode *newNode = (QueueNode *) malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queueIsEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

int dequeue(Queue *queue) {
    if (queueIsEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int data = queue->front->data;
    QueueNode *temp = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    return data;
}

void freeQueue(Queue *queue) {
    QueueNode *current = queue->front;

    while (current != NULL) {
        QueueNode *next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

int main() {
    Queue *queue = queueCreate();

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);

    printf("Front element: %d\n", queue->front->data);
    printf("Rear element: %d\n", queue->rear->data);

    printf("Size of the queue: %d\n", queue->size);

    int data = dequeue(queue);
    printf("Element dequeued: %d\n", data);

    printf("Size of the queue after dequeue: %d\n", queue->size);

    freeQueue(queue);

    return 0;
}