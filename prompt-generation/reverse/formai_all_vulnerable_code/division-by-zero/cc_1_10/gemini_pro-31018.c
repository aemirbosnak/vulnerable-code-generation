//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Define a thread-safe queue
typedef struct queue {
    int *items;
    int head;
    int tail;
    int size;
} queue_t;

// Initialize a queue
int queue_init(queue_t *queue, int size) {
    if (!(queue->items = malloc(size * sizeof(int)))) {
        return -1;
    }
    queue->head = 0;
    queue->tail = -1;
    queue->size = size;
    return 0;
}

// Destroy a queue
int queue_destroy(queue_t *queue) {
    free(queue->items);
    return 0;
}

// Enqueue an item
int queue_enqueue(queue_t *queue, int item) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        return -1;  // Queue is full
    }
    queue->items[(++queue->tail) % queue->size] = item;
    return 0;
}

// Dequeue an item
int queue_dequeue(queue_t *queue, int *item) {
    if (queue->head == queue->tail) {
        return -1;  // Queue is empty
    }
    *item = queue->items[(++queue->head) % queue->size];
    return 0;
}

// Create a thread
int thread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg) {
    return pthread_create(thread, attr, start_routine, arg);
}

// Join a thread
int thread_join(pthread_t thread, void **value_ptr) {
    return pthread_join(thread, value_ptr);
}

// Mutex lock
int mutex_lock(pthread_mutex_t *mutex) {
    return pthread_mutex_lock(mutex);
}

// Mutex unlock
int mutex_unlock(pthread_mutex_t *mutex) {
    return pthread_mutex_unlock(mutex);
}

// Condition variable wait
int cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex) {
    return pthread_cond_wait(cond, mutex);
}

// Condition variable signal
int cond_signal(pthread_cond_t *cond) {
    return pthread_cond_signal(cond);
}

// Thread main function
void *thread_main(void *arg) {
    // Get the queue from the argument
    queue_t *queue = (queue_t *)arg;
    int item;

    // Loop until the queue is empty
    while (queue_dequeue(queue, &item) == 0) {
        // Print the item
        printf("%d\n", item);
    }

    return NULL;
}

// Main function
int main() {
    // Create a queue
    queue_t queue;
    queue_init(&queue, 10);

    // Create a thread
    pthread_t thread;
    thread_create(&thread, NULL, thread_main, &queue);

    // Enqueue some items
    for (int i = 0; i < 10; i++) {
        queue_enqueue(&queue, i);
    }

    // Join the thread
    thread_join(thread, NULL);

    // Destroy the queue
    queue_destroy(&queue);

    return 0;
}