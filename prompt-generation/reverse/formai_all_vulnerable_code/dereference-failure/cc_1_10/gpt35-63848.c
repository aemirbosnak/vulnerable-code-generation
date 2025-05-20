//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 10

struct Queue {
    int front, rear;
    int size;
    int arr[QUEUE_CAPACITY];
};

struct Queue* newQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isFull(struct Queue* queue) {
    return queue->size == QUEUE_CAPACITY;
}

int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->arr[queue->rear] = data;
    queue->size++;
    printf("%d enqueued to queue.\n", data);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    queue->size--;
    return data;
}

int main() {
    struct Queue* queue = newQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue.\n", dequeue(queue));
    printf("%d dequeued from queue.\n", dequeue(queue));

    enqueue(queue, 50);
    enqueue(queue, 60);

    printf("Queue Front : %d\n", queue->arr[queue->front]);
    printf("Queue Rear : %d\n", queue->arr[queue->rear]);

    return 0;
}