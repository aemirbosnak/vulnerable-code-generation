//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int front, rear;
    int *items;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->items = (int *)malloc(sizeof(int) * MAX_QUEUE_SIZE);
    return queue;
}

void enqueue(Queue *queue, int item) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is Full\n");
        return;
    } else if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
}

int dequeue(Queue *queue) {
    int item;
    if (queue->front == -1) {
        printf("Queue is Empty\n");
        return (-1);
    } else if (queue->front == queue->rear) {
        item = queue->items[queue->front];
        queue->front = -1;
        queue->rear = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
    }
    return item;
}

int peek(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is Empty\n");
        return (-1);
    } else {
        return queue->items[queue->front];
    }
}

int isFull(Queue *queue) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(Queue *queue) {
    if (queue->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

void display(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is Empty\n");
    } else {
        int i;
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d  ", queue->items[i]);
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
    display(queue);
    printf("Front: %d\n", peek(queue));
    printf("Rear: %d\n", queue->items[queue->rear]);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    printf("Front: %d\n", peek(queue));
    printf("Rear: %d\n", queue->items[queue->rear]);
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    enqueue(queue, 100);
    display(queue);
    printf("Front: %d\n", peek(queue));
    printf("Rear: %d\n", queue->items[queue->rear]);
    return 0;
}