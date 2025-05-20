//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front, rear, capacity;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(capacity * sizeof(int));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

int isFull(Queue *queue) {
    return (queue->rear == queue->capacity - 1);
}

int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

void enqueue(Queue *queue, int item) {
    if (isFull(queue))
        return;
    if (queue->front == -1)
        queue->front = 0;
    queue->arr[++queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->arr[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;
    return item;
}

int front(Queue *queue) {
    if (isEmpty(queue))
        return -1;
    return queue->arr[queue->front];
}

int rear(Queue *queue) {
    if (isEmpty(queue))
        return -1;
    return queue->arr[queue->rear];
}

void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->arr[i]);
    printf("\n");
}

int main() {
    Queue *queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    display(queue);

    printf("Front of the queue: %d\n", front(queue));
    printf("Rear of the queue: %d\n", rear(queue));

    dequeue(queue);
    dequeue(queue);

    display(queue);

    printf("Front of the queue: %d\n", front(queue));
    printf("Rear of the queue: %d\n", rear(queue));

    return 0;
}