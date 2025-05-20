//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define a linked list node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define a queue
typedef struct queue {
    node_t *head;
    node_t *tail;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} queue_t;

// Initialize a queue
queue_t *queue_init() {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->cond, NULL);
    return queue;
}

// Enqueue an item to the queue
void queue_enqueue(queue_t *queue, int data) {
    pthread_mutex_lock(&queue->lock);

    // Create a new node
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;

    // If the queue is empty, set the head and tail to the new node
    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        // Otherwise, add the new node to the end of the queue
        queue->tail->next = node;
        queue->tail = node;
    }

    // Signal that the queue is not empty
    pthread_cond_signal(&queue->cond);

    pthread_mutex_unlock(&queue->lock);
}

// Dequeue an item from the queue
int queue_dequeue(queue_t *queue) {
    pthread_mutex_lock(&queue->lock);

    // Wait until the queue is not empty
    while (queue->head == NULL) {
        pthread_cond_wait(&queue->cond, &queue->lock);
    }

    // Get the data from the head of the queue
    int data = queue->head->data;

    // Remove the head of the queue
    node_t *old_head = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(old_head);

    pthread_mutex_unlock(&queue->lock);

    return data;
}

// Destroy the queue
void queue_destroy(queue_t *queue) {
    pthread_mutex_destroy(&queue->lock);
    pthread_cond_destroy(&queue->cond);
    while (queue->head != NULL) {
        node_t *old_head = queue->head;
        queue->head = queue->head->next;
        free(old_head);
    }
    free(queue);
}

// Producer thread
void *producer(void *arg) {
    queue_t *queue = (queue_t *)arg;

    for (int i = 0; i < 1000; i++) {
        queue_enqueue(queue, i);
    }

    return NULL;
}

// Consumer thread
void *consumer(void *arg) {
    queue_t *queue = (queue_t *)arg;

    for (int i = 0; i < 1000; i++) {
        int data = queue_dequeue(queue);
        printf("%d\n", data);
    }

    return NULL;
}

int main() {
    // Create a queue
    queue_t *queue = queue_init();

    // Create a producer thread
    pthread_t producer_thread;
    pthread_create(&producer_thread, NULL, producer, queue);

    // Create a consumer thread
    pthread_t consumer_thread;
    pthread_create(&consumer_thread, NULL, consumer, queue);

    // Join the threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy the queue
    queue_destroy(queue);

    return 0;
}