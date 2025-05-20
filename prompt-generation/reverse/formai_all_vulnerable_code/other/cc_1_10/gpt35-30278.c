//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define CAPACITY 10

typedef struct queue {
    int items[CAPACITY];
    int front;
    int rear;
} Queue;

void initialize(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);

int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int main() {
    Queue q;
    initialize(&q);

    pthread_t producer, consumer;

    pthread_create(&producer, NULL, (void *)enqueue, (void *)&q);
    pthread_create(&consumer, NULL, (void *)dequeue, (void *)&q);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    return 0;
}

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, int data) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (count == CAPACITY) {
            printf("Queue is full. Producer waiting...\n");
            pthread_cond_wait(&cond, &mutex);
        }

        if (q->rear == CAPACITY - 1) {
            q->rear = -1;
        }

        q->rear++;
        q->items[q->rear] = data;
        count++;
        printf("Inserted %d to queue\n", data);

        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);

        sleep(1);
    }
}

int dequeue(Queue *q) {
    int data;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (count == 0) {
            printf("Queue is empty. Consumer waiting...\n");
            pthread_cond_wait(&cond, &mutex);
        }

        if (q->front == CAPACITY - 1) {
            q->front = -1;
        }

        q->front++;
        data = q->items[q->front];
        count--;
        printf("Removed %d from queue\n", data);

        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);

        sleep(1);
    }
}