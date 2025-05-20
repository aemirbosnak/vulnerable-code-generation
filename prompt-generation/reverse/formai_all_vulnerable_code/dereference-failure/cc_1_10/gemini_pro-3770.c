//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int front, rear, size;
    int *array;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->array = (int *)malloc(sizeof(int) * MAX_SIZE);
    return queue;
}

void enqueue(Queue *queue, int data) {
    if (queue->size == MAX_SIZE) {
        printf("Queue is full!\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = queue->rear = 0;
        queue->array[queue->rear] = data;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->array[queue->rear] = data;
    }

    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    queue->size--;
    return data;
}

int peek(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->array[queue->front];
}

int isFull(Queue *queue) {
    return (queue->size == MAX_SIZE);
}

int isEmpty(Queue *queue) {
    return (queue->size == 0);
}

void printQueue(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->array[queue->rear]);
}

int main() {
    Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printQueue(queue);

    printf("Peek: %d\n", peek(queue));

    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);

    printQueue(queue);

    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        printf("Queue is not full!\n");
    }

    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue is not empty!\n");
    }

    return 0;
}