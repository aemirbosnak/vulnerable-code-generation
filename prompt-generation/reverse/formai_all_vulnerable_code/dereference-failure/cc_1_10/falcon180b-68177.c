//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int front;
    int rear;
    int *arr;
};

void initQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int *) malloc(MAX_SIZE * sizeof(int));
}

void enqueue(struct Queue *queue, int value) {
    if ((queue->rear + 1) % MAX_SIZE == queue->front) {
        printf("Queue is full\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->rear == -1) {
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->arr[queue->rear] = value;
}

int dequeue(struct Queue *queue) {
    if (queue->front == -1 || queue->rear == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = queue->arr[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return value;
}

void displayQueue(struct Queue *queue) {
    if (queue->front == -1 || queue->rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = queue->front; i <= queue->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;

    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    displayQueue(&queue);

    int dequeuedValue = dequeue(&queue);
    printf("Dequeued value: %d\n", dequeuedValue);

    displayQueue(&queue);

    enqueue(&queue, 50);

    displayQueue(&queue);

    return 0;
}