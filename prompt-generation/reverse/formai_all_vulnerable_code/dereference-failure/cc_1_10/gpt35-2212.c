//FormAI DATASET v1.0 Category: Queue ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QUEUE_SIZE 10

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
} Queue;

Queue* queue_create() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->data = (int*) calloc(QUEUE_SIZE, sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

int queue_is_empty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

int queue_is_full(Queue* q) {
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

int queue_size(Queue* q) {
    return q->size;
}

void queue_enqueue(Queue* q, int value) {
    if (queue_is_full(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue_is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % QUEUE_SIZE;
    }
    q->data[q->rear] = value;
    q->size++;
}

int queue_dequeue(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % QUEUE_SIZE;
    }
    q->size--;
    return value;
}

void* producer(void* arg) {
    Queue* q = (Queue*) arg;
    int i;
    for (i = 0; i < 20; i++) {
        queue_enqueue(q, i);
        printf("Producer enqueued: %d\n", i);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    Queue* q = (Queue*) arg;
    int i;
    for (i = 0; i < 10; i++) {
        int value = queue_dequeue(q);
        printf("Consumer dequeued: %d\n", value);
    }
    pthread_exit(NULL);
}

int main() {
    Queue* q = queue_create();
    pthread_t p_tid, c_tid;

    pthread_create(&p_tid, NULL, producer, q);
    pthread_create(&c_tid, NULL, consumer, q);

    pthread_join(p_tid, NULL);
    pthread_join(c_tid, NULL);
    
    free(q->data);
    free(q);

    return 0;
}