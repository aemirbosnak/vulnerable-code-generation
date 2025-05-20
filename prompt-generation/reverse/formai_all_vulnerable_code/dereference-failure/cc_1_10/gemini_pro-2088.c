//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Queue node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Queue
typedef struct queue {
    node_t *head;
    node_t *tail;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} queue_t;

// Initialize a queue
queue_t *queue_init() {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->not_empty, NULL);
    pthread_cond_init(&queue->not_full, NULL);
    return queue;
}

// Destroy a queue
void queue_destroy(queue_t *queue) {
    node_t *current = queue->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    pthread_mutex_destroy(&queue->lock);
    pthread_cond_destroy(&queue->not_empty);
    pthread_cond_destroy(&queue->not_full);
    free(queue);
}

// Enqueue an item
void queue_enqueue(queue_t *queue, int data) {
    pthread_mutex_lock(&queue->lock);
    while (queue->tail == NULL || queue->tail->next != NULL) {
        pthread_cond_wait(&queue->not_full, &queue->lock);
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (queue->tail == NULL) {
        queue->head = new_node;
    } else {
        queue->tail->next = new_node;
    }
    queue->tail = new_node;
    pthread_cond_signal(&queue->not_empty);
    pthread_mutex_unlock(&queue->lock);
}

// Dequeue an item
int queue_dequeue(queue_t *queue) {
    pthread_mutex_lock(&queue->lock);
    while (queue->head == NULL) {
        pthread_cond_wait(&queue->not_empty, &queue->lock);
    }
    node_t *current = queue->head;
    int data = current->data;
    queue->head = current->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(current);
    pthread_cond_signal(&queue->not_full);
    pthread_mutex_unlock(&queue->lock);
    return data;
}

// Main function
int main() {
    // Create a queue
    queue_t *queue = queue_init();

    // Create a thread to enqueue items
    pthread_t enqueue_thread;
    pthread_create(&enqueue_thread, NULL, (void *(*)(void *))queue_enqueue, queue);

    // Create a thread to dequeue items
    pthread_t dequeue_thread;
    pthread_create(&dequeue_thread, NULL, (void *(*)(void *))queue_dequeue, queue);

    // Join the threads
    pthread_join(enqueue_thread, NULL);
    pthread_join(dequeue_thread, NULL);

    // Destroy the queue
    queue_destroy(queue);

    return 0;
}