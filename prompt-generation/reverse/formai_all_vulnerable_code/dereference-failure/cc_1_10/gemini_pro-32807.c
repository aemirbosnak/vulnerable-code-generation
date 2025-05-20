//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Queue node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Queue
typedef struct queue {
    node_t *head;
    node_t *tail;
    sem_t lock;
    pthread_cond_t not_empty;
} queue_t;

// Initialize queue
queue_t *queue_init() {
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue) {
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    sem_init(&queue->lock, 0, 1);
    pthread_cond_init(&queue->not_empty, NULL);

    return queue;
}

// Destroy queue
void queue_destroy(queue_t *queue) {
    while (queue->head) {
        node_t *tmp = queue->head;
        queue->head = queue->head->next;
        free(tmp);
    }

    sem_destroy(&queue->lock);
    pthread_cond_destroy(&queue->not_empty);
    free(queue);
}

// Enqueue
void queue_enqueue(queue_t *queue, int data) {
    node_t *node = malloc(sizeof(node_t));
    if (!node) {
        return;
    }

    node->data = data;
    node->next = NULL;

    sem_wait(&queue->lock);

    if (queue->tail) {
        queue->tail->next = node;
    } else {
        queue->head = node;
    }

    queue->tail = node;

    pthread_cond_signal(&queue->not_empty);
    sem_post(&queue->lock);
}

// Dequeue
int queue_dequeue(queue_t *queue) {
    sem_wait(&queue->lock);
    while (!queue->head) {
        pthread_cond_wait(&queue->not_empty, &queue->lock);
    }

    node_t *tmp = queue->head;
    int data = tmp->data;

    queue->head = queue->head->next;
    if (!queue->head) {
        queue->tail = NULL;
    }

    free(tmp);

    sem_post(&queue->lock);
    return data;
}

// Producer thread
void *producer(void *arg) {
    queue_t *queue = (queue_t *)arg;

    for (int i = 0; i < 100; i++) {
        queue_enqueue(queue, i);
        printf("Produced: %d\n", i);
    }

    return NULL;
}

// Consumer thread
void *consumer(void *arg) {
    queue_t *queue = (queue_t *)arg;

    for (int i = 0; i < 100; i++) {
        int data = queue_dequeue(queue);
        printf("Consumed: %d\n", data);
    }

    return NULL;
}

// Main function
int main() {
    queue_t *queue = queue_init();

    pthread_t producer_thread;
    pthread_t consumer_thread;

    pthread_create(&producer_thread, NULL, producer, queue);
    pthread_create(&consumer_thread, NULL, consumer, queue);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    queue_destroy(queue);

    return 0;
}