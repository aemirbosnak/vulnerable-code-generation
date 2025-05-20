//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Baggage queue
struct baggage_queue {
    int capacity;
    int size;
    struct baggage *head;
    struct baggage *tail;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
};

// Baggage item
struct baggage {
    int id;
    int weight;
    int destination;
    struct baggage *next;
};

// Create a new baggage queue
struct baggage_queue *baggage_queue_create(int capacity) {
    struct baggage_queue *queue = malloc(sizeof(struct baggage_queue));
    if (!queue) {
        return NULL;
    }

    queue->capacity = capacity;
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->not_empty, NULL);
    pthread_cond_init(&queue->not_full, NULL);

    return queue;
}

// Destroy a baggage queue
void baggage_queue_destroy(struct baggage_queue *queue) {
    pthread_mutex_destroy(&queue->lock);
    pthread_cond_destroy(&queue->not_empty);
    pthread_cond_destroy(&queue->not_full);
    free(queue);
}

// Enqueue a baggage item
void baggage_queue_enqueue(struct baggage_queue *queue, struct baggage *baggage) {
    pthread_mutex_lock(&queue->lock);

    while (queue->size == queue->capacity) {
        pthread_cond_wait(&queue->not_full, &queue->lock);
    }

    if (!queue->head) {
        queue->head = baggage;
    } else {
        queue->tail->next = baggage;
    }

    queue->tail = baggage;
    queue->size++;

    pthread_cond_signal(&queue->not_empty);
    pthread_mutex_unlock(&queue->lock);
}

// Dequeue a baggage item
struct baggage *baggage_queue_dequeue(struct baggage_queue *queue) {
    pthread_mutex_lock(&queue->lock);

    while (queue->size == 0) {
        pthread_cond_wait(&queue->not_empty, &queue->lock);
    }

    struct baggage *baggage = queue->head;
    queue->head = queue->head->next;

    if (!queue->head) {
        queue->tail = NULL;
    }

    queue->size--;

    pthread_cond_signal(&queue->not_full);
    pthread_mutex_unlock(&queue->lock);

    return baggage;
}

// Create a new baggage item
struct baggage *baggage_create(int id, int weight, int destination) {
    struct baggage *baggage = malloc(sizeof(struct baggage));
    if (!baggage) {
        return NULL;
    }

    baggage->id = id;
    baggage->weight = weight;
    baggage->destination = destination;
    baggage->next = NULL;

    return baggage;
}

// Destroy a baggage item
void baggage_destroy(struct baggage *baggage) {
    free(baggage);
}

// Baggage handling thread
void *baggage_handling_thread(void *arg) {
    struct baggage_queue *queue = arg;

    while (1) {
        struct baggage *baggage = baggage_queue_dequeue(queue);

        // Handle the baggage item

        baggage_destroy(baggage);
    }

    return NULL;
}

int main() {
    // Create a baggage queue
    struct baggage_queue *queue = baggage_queue_create(100);

    // Create baggage handling threads
    int num_threads = 4;
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, baggage_handling_thread, queue);
    }

    // Enqueue baggage items
    for (int i = 0; i < 1000; i++) {
        struct baggage *baggage = baggage_create(i, rand() % 100, rand() % 10);
        baggage_queue_enqueue(queue, baggage);
    }

    // Join baggage handling threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy baggage queue
    baggage_queue_destroy(queue);

    return 0;
}