//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int front, rear, size;
    int *array;
} Queue;

Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

int isFull(Queue *queue) {
    return (queue->rear == queue->size - 1);
}

int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("The queue is full, cannot enqueue!\n");
    } else {
        if (queue->front == -1) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear++;
        }
        queue->array[queue->rear] = data;
    }
}

int dequeue(Queue *queue) {
    int data = -1;
    if (isEmpty(queue)) {
        printf("The queue is empty, cannot dequeue!\n");
    } else {
        data = queue->array[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }
    }
    return data;
}

void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty!\n");
    } else {
        printf("The queue contains:\n");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->array[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue *queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printQueue(queue);

    printf("Dequeueing 3 elements:\n");
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    enqueue(queue, 6);
    enqueue(queue, 7);

    printQueue(queue);

    return 0;
}