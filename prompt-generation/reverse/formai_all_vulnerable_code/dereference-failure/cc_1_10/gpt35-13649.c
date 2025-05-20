//FormAI DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct cqueue {
    int front, rear;
    int size;
    void** data;
} cqueue;

cqueue* cqueue_init(int size) {
    cqueue* cq = malloc(sizeof(cqueue));
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;
    cq->data = malloc(sizeof(void*) * size);
    return cq;
}

bool cqueue_empty(cqueue* cq) {
    return cq->front == cq->rear;
}

bool cqueue_full(cqueue* cq) {
    return (cq->rear+1) % cq->size == cq->front;
}

void cqueue_push(cqueue* cq, void* item) {
    if (cqueue_full(cq)) return;
    cq->data[cq->rear] = item;
    cq->rear = (cq->rear+1) % cq->size;
}

void* cqueue_pop(cqueue* cq) {
    if (cqueue_empty(cq)) return NULL;
    void* item = cq->data[cq->front];
    cq->front = (cq->front+1) % cq->size;
    return item;
}

void* cqueue_peek(cqueue* cq) {
    if (cqueue_empty(cq)) return NULL;
    return cq->data[cq->front];
}

void cqueue_destroy(cqueue* cq) {
    free(cq->data);
    free(cq);
}

pthread_t tid1, tid2;

void* producer(void* arg) {
    cqueue* cq = (cqueue*)arg;
    int i;
    for (i=0; i<10; i++) {
        int* item = malloc(sizeof(int));
        *item = i;
        while (cqueue_full(cq));
        cqueue_push(cq, item);
        printf("Producer added item: %d\n", *item);
    }
    return NULL;
}

void* consumer(void* arg) {
    cqueue* cq = (cqueue*)arg;
    while (true) {
        while (cqueue_empty(cq));
        int* item = cqueue_pop(cq);
        printf("Consumer removed item: %d\n", *item);
        free(item);
    }
    return NULL;
}

int main() {
    cqueue* cq = cqueue_init(5);
    pthread_create(&tid1, NULL, producer, cq);
    pthread_create(&tid2, NULL, consumer, cq);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    cqueue_destroy(cq);
    return 0;
}