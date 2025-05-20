//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct queue {
    int *data;
    int front, rear, size;
} queue;

void enqueue(queue *q, int item) {
    if (q->size == MAX_SIZE) {
        printf("Queue is full, cannot enqueue item %d\n", item);
        return;
    }

    if (q->rear == MAX_SIZE - 1) {
        q->rear = 0;
    } else {
        q->rear++;
    }

    q->data[q->rear] = item;
    q->size++;
}

int dequeue(queue *q) {
    if (q->size == 0) {
        printf("Queue is empty, cannot dequeue item\n");
        return -1;
    }

    int item = q->data[q->front];
    q->data[q->front] = 0;
    q->size--;
    if (q->front > q->rear) {
        q->front = q->rear;
    } else {
        q->front++;
    }

    return item;
}

void print_queue(queue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    queue q;
    q.data = (int*)malloc(MAX_SIZE * sizeof(int));
    q.front = 0;
    q.rear = 0;
    q.size = 0;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    print_queue(&q);
    printf("Dequeued: %d\n", dequeue(&q));
    print_queue(&q);
    printf("Dequeued: %d\n", dequeue(&q));
    print_queue(&q);

    return 0;
}