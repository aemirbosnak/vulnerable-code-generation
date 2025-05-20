//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *items;
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->items = (int *)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

void enqueue(Queue *queue, int item) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full!\n");
        return;
    } else if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    } else if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return queue->items[queue->front - 1];
}

int peek(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->items[queue->front];
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

void printQueue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    enqueue(queue, 60);
    enqueue(queue, 70);
    printQueue(queue);
    return 0;
}