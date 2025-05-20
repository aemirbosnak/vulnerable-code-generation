//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define QUEUE_SIZE 10

typedef struct Queue {
    int front, rear;
    int size;
    int *array;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = QUEUE_SIZE;
    queue->array = (int *)calloc(QUEUE_SIZE, sizeof(int));
    return queue;
}

int isFull(Queue *queue) {
    return (queue->rear == queue->size - 1);
}

int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->array[queue->rear] = item;
    printf("Enqueued %d\n", item);
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    printf("Dequeued %d\n", item);
    return item;
}

void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);

    display(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue is not empty!\n");
    }

    return 0;
}