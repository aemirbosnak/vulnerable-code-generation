//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front;
    int rear;
    int size;
    int* queue;
} queue_t;

queue_t* create_queue(int size) {
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    q->queue = (int*)malloc(sizeof(int) * size);
    return q;
}

void enqueue(queue_t* q, int data) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->queue[q->rear] = data;
}

int dequeue(queue_t* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->queue[q->front];
    q->front = (q->front + 1) % q->size;
    return data;
}

void* producer(void* arg) {
    queue_t* q = (queue_t*)arg;
    int i;
    for (i = 0; i < 10; i++) {
        enqueue(q, i);
        printf("Produced: %d\n", i);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    queue_t* q = (queue_t*)arg;
    int i;
    for (i = 0; i < 10; i++) {
        int data = dequeue(q);
        printf("Consumed: %d\n", data);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t tid[2];
    queue_t* q = create_queue(MAX_QUEUE_SIZE);
    int i;
    for (i = 0; i < 2; i++) {
        pthread_create(&tid[i], NULL, (i == 0)? producer : consumer, q);
    }
    for (i = 0; i < 2; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}