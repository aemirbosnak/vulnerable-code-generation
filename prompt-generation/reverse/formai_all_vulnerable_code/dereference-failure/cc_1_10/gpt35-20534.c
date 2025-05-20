//FormAI DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue* queue, int value);
int dequeue(struct Queue* queue);
void display(struct Queue* queue);

int main() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);

    display(queue);

    dequeue(queue);

    printf("\nAfter dequeueing head element\n");
    display(queue);

    return 0;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("\nQueue is full\n");
        return;
    }

    if (queue->front == -1)
        queue->front = 0;

    queue->rear++;
    queue->items[queue->rear] = value;
    printf("\nInserted -> %d", value);
}

int dequeue(struct Queue* queue) {
    int item;
    if (queue->front == -1) {
        printf("\nQueue is empty\n");
        return -1;
    }

    item = queue->items[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    printf("\nDeleted element -> %d\n", item);
    return item;
}

void display(struct Queue* queue) {
    int i;
    if (queue->rear == -1) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nQueue elements are:\n");
    for (i = queue->front; i <= queue->rear; i++)
        printf("%d  ", queue->items[i]);
}