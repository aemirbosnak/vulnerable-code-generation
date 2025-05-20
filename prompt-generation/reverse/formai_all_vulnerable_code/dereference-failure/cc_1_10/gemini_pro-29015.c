//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>

#define NUM_THREADS 4

// Data structures for the fitness tracker
typedef struct {
    int steps;
    int distance;
    int calories;
} fitness_data_t;

// Thread-safe queue for fitness data
typedef struct {
    fitness_data_t *data;
    int head;
    int tail;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} fitness_queue_t;

// Initialize the fitness queue
void fitness_queue_init(fitness_queue_t *queue) {
    queue->data = malloc(sizeof(fitness_data_t) * 100);
    queue->head = 0;
    queue->tail = 0;
    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->cond, NULL);
}

// Destroy the fitness queue
void fitness_queue_destroy(fitness_queue_t *queue) {
    free(queue->data);
    pthread_mutex_destroy(&queue->mutex);
    pthread_cond_destroy(&queue->cond);
}

// Enqueue fitness data
void fitness_queue_enqueue(fitness_queue_t *queue, fitness_data_t *data) {
    pthread_mutex_lock(&queue->mutex);
    queue->data[queue->tail] = *data;
    queue->tail = (queue->tail + 1) % 100;
    pthread_cond_signal(&queue->cond);
    pthread_mutex_unlock(&queue->mutex);
}

// Dequeue fitness data
fitness_data_t *fitness_queue_dequeue(fitness_queue_t *queue) {
    pthread_mutex_lock(&queue->mutex);
    while (queue->head == queue->tail) {
        pthread_cond_wait(&queue->cond, &queue->mutex);
    }
    fitness_data_t *data = &queue->data[queue->head];
    queue->head = (queue->head + 1) % 100;
    pthread_mutex_unlock(&queue->mutex);
    return data;
}

// Fitness tracker thread
void *fitness_tracker_thread(void *args) {
    fitness_queue_t *queue = (fitness_queue_t *)args;

    // Generate some random fitness data
    while (1) {
        fitness_data_t data;
        data.steps = rand() % 10000;
        data.distance = rand() % 1000;
        data.calories = rand() % 1000;

        // Enqueue the fitness data
        fitness_queue_enqueue(queue, &data);

        // Sleep for a bit
        sleep(1);
    }

    return NULL;
}

// Main function
int main() {
    // Initialize the fitness queue
    fitness_queue_t queue;
    fitness_queue_init(&queue);

    // Create the fitness tracker threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, fitness_tracker_thread, &queue);
    }

    // Dequeue and process the fitness data
    while (1) {
        // Dequeue the fitness data
        fitness_data_t *data = fitness_queue_dequeue(&queue);

        // Process the fitness data
        printf("Steps: %d, Distance: %d, Calories: %d\n", data->steps, data->distance, data->calories);

        // Sleep for a bit
        sleep(1);
    }

    // Destroy the fitness queue
    fitness_queue_destroy(&queue);

    return 0;
}