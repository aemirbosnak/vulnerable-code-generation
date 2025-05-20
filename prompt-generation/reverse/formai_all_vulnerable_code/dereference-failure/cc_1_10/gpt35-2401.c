//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 4
#define QUEUE_MAX 10

typedef struct {
    pthread_mutex_t lock;
    int data[QUEUE_MAX];
    int front;
    int rear;
} Queue;

Queue* queue_create() {
    Queue* queue = malloc(sizeof(Queue));
    pthread_mutex_init(&queue->lock, NULL);
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

void queue_push(Queue* queue, int data) {
    pthread_mutex_lock(&queue->lock);
    if ((queue->rear + 1) % QUEUE_MAX == queue->front) {
        printf("Queue is full!\n");
    } else {
        queue->data[queue->rear] = data;
        queue->rear = (queue->rear + 1) % QUEUE_MAX;
    }
    pthread_mutex_unlock(&queue->lock);
}

int queue_pop(Queue* queue) {
    int data = -1;
    pthread_mutex_lock(&queue->lock);
    if (queue->front == queue->rear) {
        printf("Queue is empty!\n");
    } else {
        data = queue->data[queue->front];
        queue->front = (queue->front + 1) % QUEUE_MAX;
    }
    pthread_mutex_unlock(&queue->lock);
    return data;
}

void* producer(void* arg) {
    Queue* queue = (Queue*) arg;
    for (int i = 0; i < 20; i++) {
        queue_push(queue, i);
    }
    return NULL;
}

void* consumer(void* arg) {
    Queue* queue = (Queue*) arg;
    int data;
    for (int i = 0; i < 20; i++) {
        data = queue_pop(queue);
        if (data != -1) {
            printf("Data consumed: %d\n", data);
        }
    }
    return NULL;
}

int main() {
    Queue* queue = queue_create();
    pthread_t threads[THREAD_COUNT];
    
    for (int i = 0; i < THREAD_COUNT / 2; i++) {
        pthread_create(&threads[i], NULL, producer, (void*) queue);
    }
    for (int i = THREAD_COUNT / 2; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, consumer, (void*) queue);
    }
    
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}