//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue_s {
    int *elements;
    int front;
    int rear;
    int size;
} queue_t;

void enqueue(queue_t *queue, int element) {
    if (queue->rear == queue->size - 1) {
        fprintf(stderr, "Queue is full.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->elements[queue->rear] = element;
}

int dequeue(queue_t *queue) {
    if (queue->front == queue->rear) {
        fprintf(stderr, "Queue is empty.\n");
        return -1;
    }
    int element = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    return element;
}

int isEmpty(queue_t *queue) {
    return (queue->front == queue->rear);
}

int main() {
    queue_t queue;
    queue.size = 5;
    queue.front = 0;
    queue.rear = 0;

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    printf("Front element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", dequeue(&queue));

    if (isEmpty(&queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}