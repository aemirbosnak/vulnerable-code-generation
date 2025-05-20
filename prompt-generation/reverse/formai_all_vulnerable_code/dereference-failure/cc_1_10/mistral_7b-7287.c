//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10

typedef struct {
    int data[QUEUE_SIZE];
    int head;
    int tail;
    int count;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*) malloc(sizeof(CircularQueue));
    q->head = -1;
    q->tail = -1;
    q->count = 0;
    return q;
}

void enqueue(CircularQueue* q, int value) {
    if (q->count == QUEUE_SIZE) {
        printf("Queue is full.\n");
        return;
    }

    if (q->tail == -1) {
        q->tail = 0;
        q->head = 0;
    } else {
        q->tail = (q->tail + 1) % QUEUE_SIZE;
    }

    q->data[q->tail] = value;
    q->count++;

    printf("Element %d added to the queue.\n", value);
}

int dequeue(CircularQueue* q) {
    if (q->count == 0) {
        printf("Queue is empty.\n");
        return -1;
    }

    int value = q->data[q->head];

    if (q->head == QUEUE_SIZE - 1) {
        q->head = 0;
    } else {
        q->head++;
    }

    q->count--;

    printf("Element %d removed from the queue.\n", value);
    return value;
}

void printQueue(CircularQueue* q) {
    int i;

    if (q->count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    if (q->head > q->tail) {
        for (i = q->head; i < QUEUE_SIZE + q->head; i++) {
            printf("%d ", q->data[i % QUEUE_SIZE]);
        }
    } else {
        for (i = q->head; i < QUEUE_SIZE; i++) {
            printf("%d ", q->data[i]);
        }
        for (i = 0; i <= q->tail; i++) {
            printf("%d ", q->data[i]);
        }
    }
    printf("\n");
}

int main() {
    CircularQueue* q = createQueue();

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);

    printQueue(q);

    dequeue(q);
    dequeue(q);

    printQueue(q);

    enqueue(q, 20);

    printQueue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    printQueue(q);

    dequeue(q); // Empty queue, so an error message will be printed

    free(q);

    return 0;
}