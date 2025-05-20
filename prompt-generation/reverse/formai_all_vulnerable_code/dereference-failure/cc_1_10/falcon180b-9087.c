//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

Queue *queueCreate() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    q->front = 0;
    q->rear = -1;
    return q;
}

int queueIsEmpty(Queue *q) {
    return (q->front == q->rear + 1);
}

int queueIsFull(Queue *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queueEnqueue(Queue *q, int item) {
    if (queueIsFull(q)) {
        printf("Error: Queue is full.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = item;
}

int queueDequeue(Queue *q) {
    int item;
    if (queueIsEmpty(q)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    item = q->items[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return item;
}

void *threadFunc(void *arg) {
    Queue *q = arg;
    for (int i = 0; i < 10; i++) {
        queueEnqueue(q, i);
        usleep(100000); // Sleep for 100ms
    }
    return NULL;
}

int main() {
    Queue *q = queueCreate();
    pthread_t thread1;
    pthread_create(&thread1, NULL, threadFunc, q);
    for (int i = 0; i < 10; i++) {
        int item = queueDequeue(q);
        printf("Dequeued item: %d\n", item);
        usleep(100000); // Sleep for 100ms
    }
    pthread_join(thread1, NULL);
    return 0;
}