//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>

#define MAX_QUEUE_SIZE 1000

typedef struct {
    int front, rear;
    int size;
    int *array;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->array = (int *)malloc(MAX_QUEUE_SIZE * sizeof(int));
    return queue;
}

void enqueue(Queue *queue, int data) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }
    else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->array[queue->rear] = data;
        queue->size++;
    }
}

int dequeue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    else {
        int data = queue->array[queue->front];
        queue->front++;
        queue->size--;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return data;
    }
}

int peek(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    else {
        return queue->array[queue->front];
    }
}

int isFull(Queue *queue) {
    return queue->rear == MAX_QUEUE_SIZE - 1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

void deleteQueue(Queue *queue) {
    free(queue->array);
    free(queue);
}

int main() {
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Queue: ");
    while (!isEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");

    deleteQueue(queue);

    return 0;
}