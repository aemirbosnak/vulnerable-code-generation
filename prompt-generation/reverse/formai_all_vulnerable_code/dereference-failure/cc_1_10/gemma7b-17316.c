//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = MAX_SIZE;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

void enqueue(Queue *queue, int data) {
    if (queue->size == queue->rear + 1) {
        printf("Oops, the queue is full!\n");
        return;
    }

    queue->arr[++queue->rear] = data;
}

int dequeue(Queue *queue) {
    if (queue->front == -1) {
        printf("The queue is empty!\n");
        return -1;
    }

    return queue->arr[++queue->front];
}

int main() {
    Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    int data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    data = dequeue(queue);
    printf("Dequed data: %d\n", data);

    return 0;
}