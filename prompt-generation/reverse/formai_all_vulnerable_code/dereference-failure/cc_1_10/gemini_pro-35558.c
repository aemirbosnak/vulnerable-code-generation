//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int front, rear;
    int size;
    int *arr;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->arr = (int *)malloc(MAX_QUEUE_SIZE * sizeof(int));
    return queue;
}

void enqueue(Queue *queue, int data) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->arr[queue->rear] = data;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    queue->size--;
    return data;
}

int peek(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->front];
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

void printQueue(Queue *queue) {
    printf("Queue: ");
    if (queue->front == -1) {
        printf("Empty\n");
    } else {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    printQueue(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);

    printQueue(queue);

    printf("Front of the queue: %d\n", peek(queue));

    printf("Is queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");

    return 0;
}