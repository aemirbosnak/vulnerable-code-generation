//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5

typedef struct {
    int front, rear;
    int *arr;
} Queue;

void init(Queue *q) {
    q->front = q->rear = -1;
    q->arr = (int *)malloc(MAX * sizeof(int));
}

int is_empty(Queue *q) {
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

int is_full(Queue *q) {
    if ((q->rear + 1) % MAX == q->front)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int val) {
    if (is_full(q))
        printf("\nQueue is full");
    else if (is_empty(q)) {
        q->front = q->rear = 0;
        q->arr[q->rear] = val;
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = val;
    }
}

int dequeue(Queue *q) {
    int val;
    if (is_empty(q))
        printf("\nQueue is empty");
    else if (q->front == q->rear) {
        val = q->arr[q->front];
        q->front = q->rear = -1;
    } else {
        val = q->arr[q->front];
        q->front = (q->front + 1) % MAX;
    }
    return val;
}

void *producer(void *arg) {
    Queue *q = (Queue *)arg;
    int i, val;
    for (i = 0; i < 10; i++) {
        val = rand() % 100;
        enqueue(q, val);
        printf("\nProduced: %d", val);
        sleep(1);
    }
}

void *consumer(void *arg) {
    Queue *q = (Queue *)arg;
    int val;
    while (1) {
        val = dequeue(q);
        printf("\nConsumed: %d", val);
        sleep(1);
        if (val == -1)
            break;
    }
}

int main() {
    pthread_t thread_id[2];
    Queue q;
    init(&q);
    pthread_create(&thread_id[0], NULL, producer, &q);
    pthread_create(&thread_id[1], NULL, consumer, &q);
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
    return 0;
}