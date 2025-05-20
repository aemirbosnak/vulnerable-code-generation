//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define QUEUE_SIZE 5

typedef struct Queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
    int count;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->not_empty, NULL);
    pthread_cond_init(&queue->not_full, NULL);
    return queue;
}

void destroyQueue(Queue* queue) {
    pthread_mutex_destroy(&queue->lock);
    pthread_cond_destroy(&queue->not_empty);
    pthread_cond_destroy(&queue->not_full);
    free(queue);
}

void enqueue(Queue* queue, int value) {
    pthread_mutex_lock(&queue->lock);
    while (queue->count == QUEUE_SIZE) {
        pthread_cond_wait(&queue->not_full, &queue->lock);
    }
    
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->items[queue->rear] = value;
    queue->count++;
    
    printf("Enqueued: %d\n", value);
    
    pthread_cond_signal(&queue->not_empty);
    pthread_mutex_unlock(&queue->lock);
}

int dequeue(Queue* queue) {
    pthread_mutex_lock(&queue->lock);
    while (queue->count == 0) {
        pthread_cond_wait(&queue->not_empty, &queue->lock);
    }
    
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % QUEUE_SIZE;
    queue->count--;
    
    printf("Dequeued: %d\n", item);
    
    pthread_cond_signal(&queue->not_full);
    pthread_mutex_unlock(&queue->lock);
    
    return item;
}

void* producer(void* param) {
    Queue* queue = (Queue*)param;
    for (int i = 0; i < 10; i++) {
        usleep(rand() % 100000); // simulate variable work
        enqueue(queue, i);
    }
    return NULL;
}

void* consumer(void* param) {
    Queue* queue = (Queue*)param;
    for (int i = 0; i < 10; i++) {
        usleep(rand() % 150000); // simulate variable work
        dequeue(queue);
    }
    return NULL;
}

int main() {
    srand(time(NULL));

    Queue* queue = createQueue();
    
    pthread_t prod_thread, cons_thread;
    
    pthread_create(&prod_thread, NULL, producer, queue);
    pthread_create(&cons_thread, NULL, consumer, queue);
    
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);
    
    destroyQueue(queue);
    
    return 0;
}