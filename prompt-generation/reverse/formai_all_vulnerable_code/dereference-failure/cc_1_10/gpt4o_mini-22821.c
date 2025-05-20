//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define QUEUE_SIZE 10
#define NUM_CONSUMERS 2
#define NUM_PRODUCERS 2
#define NUM_ITEMS 20

typedef struct Queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
    int count;
    pthread_mutex_t lock;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} Queue;

Queue *queue;

void initialize_queue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    pthread_mutex_init(&q->lock, NULL);
    pthread_cond_init(&q->not_full, NULL);
    pthread_cond_init(&q->not_empty, NULL);
}

void enqueue(Queue *q, int item) {
    pthread_mutex_lock(&q->lock);
    while (q->count == QUEUE_SIZE) {
        pthread_cond_wait(&q->not_full, &q->lock);
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->items[q->rear] = item;
    q->count++;
    pthread_cond_signal(&q->not_empty);
    pthread_mutex_unlock(&q->lock);
}

int dequeue(Queue *q) {
    pthread_mutex_lock(&q->lock);
    while (q->count == 0) {
        pthread_cond_wait(&q->not_empty, &q->lock);
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    pthread_cond_signal(&q->not_full);
    pthread_mutex_unlock(&q->lock);
    return item;
}

void* producer(void* arg) {
    int id = *((int*)arg);
    for (int i = 0; i < NUM_ITEMS; i++) {
        int item = id * 100 + i; // Unique item creation
        printf("Producer %d: enqueuing %d\n", id, item);
        enqueue(queue, item);
        sleep(rand() % 2); // Random sleep to simulate work
    }
    return NULL;
}

void* consumer(void* arg) {
    int id = *((int*)arg);
    for (int i = 0; i < NUM_ITEMS; i++) {
        int item = dequeue(queue);
        printf("Consumer %d: dequeued %d\n", id, item);
        sleep(rand() % 3); // Random sleep to simulate work
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    queue = (Queue*)malloc(sizeof(Queue));
    initialize_queue(queue);

    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];
    int producer_ids[NUM_PRODUCERS] = {1, 2};
    int consumer_ids[NUM_CONSUMERS] = {1, 2};

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }

    free(queue);
    pthread_mutex_destroy(&queue->lock);
    pthread_cond_destroy(&queue->not_full);
    pthread_cond_destroy(&queue->not_empty);
    
    return 0;
}