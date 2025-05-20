//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QUEUE_SIZE 5

typedef struct {
    int *buffer;
    int capacity;
    int front;
    int rear;
    int count;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} Queue;

void init_queue(Queue *queue) {
    queue->buffer = (int *) malloc(sizeof(int) * QUEUE_SIZE);
    queue->capacity = QUEUE_SIZE;
    queue->front = queue->rear = queue->count = 0;
    pthread_mutex_init(&(queue->lock), NULL);
    pthread_cond_init(&(queue->not_empty), NULL);
    pthread_cond_init(&(queue->not_full), NULL);
}

void destroy_queue(Queue *queue) {
    free(queue->buffer);
    pthread_mutex_destroy(&(queue->lock));
    pthread_cond_destroy(&(queue->not_empty));
    pthread_cond_destroy(&(queue->not_full));
}

void enqueue(Queue *queue, int data) {
    pthread_mutex_lock(&(queue->lock));
    while (queue->count >= queue->capacity) {
        pthread_cond_wait(&(queue->not_full), &(queue->lock));
    }
    queue->buffer[queue->rear] = data;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->count++;
    pthread_mutex_unlock(&(queue->lock));
    pthread_cond_signal(&(queue->not_empty));
}

int dequeue(Queue *queue) {
    pthread_mutex_lock(&(queue->lock));
    while (queue->count == 0) {
        pthread_cond_wait(&(queue->not_empty), &(queue->lock));
    }
    int data = queue->buffer[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->count--;
    pthread_mutex_unlock(&(queue->lock));
    pthread_cond_signal(&(queue->not_full));
    return data;
}

void *producer(void *arg) {
    Queue *queue = (Queue *) arg;
    for (int i = 0; i < 10; i++) {
        enqueue(queue, i);
        printf("Producer: Enqueued %d\n", i);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    Queue *queue = (Queue *) arg;
    for (int i = 0; i < 5; i++) {
        int data = dequeue(queue);
        printf("Consumer: Dequeued %d\n", data);
    }
    pthread_exit(NULL);
}

int main() {
    Queue queue;
    init_queue(&queue);

    pthread_t producer_thread, consumer_thread1, consumer_thread2;
    pthread_create(&producer_thread, NULL, producer, &queue);
    pthread_create(&consumer_thread1, NULL, consumer, &queue);
    pthread_create(&consumer_thread2, NULL, consumer, &queue);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread1, NULL);
    pthread_join(consumer_thread2, NULL);

    destroy_queue(&queue);

    return 0;
}