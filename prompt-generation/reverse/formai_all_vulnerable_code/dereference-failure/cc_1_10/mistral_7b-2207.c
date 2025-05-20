//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    char data[MAX_QUEUE_SIZE][20];
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void enqueue(Queue *queue, char *str) {
    if (queue->rear >= MAX_QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    strcpy(queue->data[++queue->rear], str);
}

char *dequeue(Queue *queue) {
    if (queue->front == -1 || queue->rear == -1) {
        printf("Queue is empty!\n");
        return NULL;
    }
    char *str = queue->data[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return str;
}

int main() {
    Queue *queue = createQueue();

    enqueue(queue, "First");
    enqueue(queue, "Second");
    enqueue(queue, "Third");

    printf("Dequeued: %s\n", dequeue(queue));
    printf("Dequeued: %s\n", dequeue(queue));

    enqueue(queue, "Fourth");
    enqueue(queue, "Fifth");

    printf("Dequeued: %s\n", dequeue(queue));
    printf("Dequeued: %s\n", dequeue(queue));
    printf("Dequeued: %s\n", dequeue(queue));
    printf("Dequeued: %s\n", dequeue(queue));

    enqueue(queue, "Sixth");

    printf("Dequeued: %s\n", dequeue(queue));
    printf("Dequeued: %s\n", dequeue(queue));
    printf("Dequeued: %s\n", dequeue(queue));
    printf("Dequeued: %s\n", dequeue(queue));
    printf("Dequeued: %s\n", dequeue(queue));
    printf("Dequeued: %s\n", dequeue(queue));

    return 0;
}