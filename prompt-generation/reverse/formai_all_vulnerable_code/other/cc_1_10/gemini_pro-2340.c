//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define QUEUE_SIZE 10

typedef struct queue {
    int front, rear;
    int* arr;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int*)malloc(sizeof(int) * QUEUE_SIZE);
    assert(queue);
    return queue;
}

void enqueue(Queue* queue, int data) {
    if ((queue->front == 0 && queue->rear == QUEUE_SIZE - 1) ||
        (queue->rear == (queue->front - 1) % (QUEUE_SIZE - 1))) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->rear == QUEUE_SIZE - 1 && queue->front != 0) {
        queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->arr[queue->rear] = data;
}

int dequeue(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else if (queue->front == QUEUE_SIZE - 1) {
        queue->front = 0;
    } else {
        queue->front++;
    }
    return data;
}

int peek(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}

void display(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        if (i == QUEUE_SIZE - 1) {
            i = 0;
        } else {
            i++;
        }
    }
    printf("%d\n", queue->arr[i]);
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    display(queue);

    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Dequeued item: %d\n", dequeue(queue));

    display(queue);

    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);

    display(queue);

    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Dequeued item: %d\n", dequeue(queue));

    display(queue);

    return 0;
}