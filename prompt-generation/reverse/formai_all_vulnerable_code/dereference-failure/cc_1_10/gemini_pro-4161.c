//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Fitness tracker data structure
typedef struct {
    int steps;
    int calories;
    int heart_rate;
} fitness_data_t;

// Queue to store fitness data
typedef struct {
    fitness_data_t *data;
    int head;
    int tail;
    int size;
} queue_t;

// Mutex to protect queue access
pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;

// Initialize a queue
void queue_init(queue_t *queue, int size) {
    queue->data = malloc(sizeof(fitness_data_t) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
}

// Push data into the queue
void queue_push(queue_t *queue, fitness_data_t data) {
    pthread_mutex_lock(&queue_mutex);
    queue->data[queue->tail] = data;
    queue->tail = (queue->tail + 1) % queue->size;
    pthread_mutex_unlock(&queue_mutex);
}

// Pop data from the queue
fitness_data_t queue_pop(queue_t *queue) {
    pthread_mutex_lock(&queue_mutex);
    fitness_data_t data = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    pthread_mutex_unlock(&queue_mutex);
    return data;
}

// Fitness tracker thread
void *fitness_tracker_thread(void *arg) {
    queue_t *queue = (queue_t *)arg;

    // Generate random fitness data
    while (1) {
        fitness_data_t data;
        data.steps = rand() % 10000;
        data.calories = rand() % 1000;
        data.heart_rate = rand() % 150;

        // Push data into the queue
        queue_push(queue, data);

        // Sleep for a random amount of time
        sleep(rand() % 10);
    }

    return NULL;
}

// Fitness display thread
void *fitness_display_thread(void *arg) {
    queue_t *queue = (queue_t *)arg;

    // Display fitness data
    while (1) {
        // Pop data from the queue
        fitness_data_t data = queue_pop(queue);

        // Display data
        printf("Steps: %d\n", data.steps);
        printf("Calories: %d\n", data.calories);
        printf("Heart rate: %d\n", data.heart_rate);

        printf("\n");

        // Sleep for a random amount of time
        sleep(rand() % 10);
    }

    return NULL;
}

int main() {
    // Create a queue to store fitness data
    queue_t queue;
    queue_init(&queue, 100);

    // Create fitness tracker thread
    pthread_t fitness_tracker_thread_id;
    pthread_create(&fitness_tracker_thread_id, NULL, fitness_tracker_thread, &queue);

    // Create fitness display thread
    pthread_t fitness_display_thread_id;
    pthread_create(&fitness_display_thread_id, NULL, fitness_display_thread, &queue);

    // Join threads
    pthread_join(fitness_tracker_thread_id, NULL);
    pthread_join(fitness_display_thread_id, NULL);

    return 0;
}