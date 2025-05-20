//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS 5
#define BUFFER_SIZE 10

typedef struct {
    int id;
    char message[BUFFER_SIZE];
} thread_data;

pthread_mutex_t mutex;
pthread_cond_t condvar;
int current_index = 0;
thread_data message_queue[NUM_THREADS];

void* producer(void* arg) {
    thread_data* data = (thread_data*)arg;

    for (int i = 0; i < 3; i++) {
        pthread_mutex_lock(&mutex);
        
        // Simulate work by sleeping
        snprintf(data->message, BUFFER_SIZE, "Message from Thread %d - %d", data->id, i);
        printf("Producer %d: produced -> %s\n", data->id, data->message);

        // Add message to queue
        message_queue[current_index] = *data;
        current_index++;

        // Signal the consumer that new data is available
        pthread_cond_signal(&condvar);
        
        pthread_mutex_unlock(&mutex);
        sleep(1); // Simulate time delay of work
    }
    return NULL;
}

void* consumer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        
        // Wait until producer signals that there is data
        while (current_index == 0) {
            pthread_cond_wait(&condvar, &mutex);
        }

        // Consume the message
        current_index--;
        printf("Consumer: consumed -> %s\n", message_queue[current_index].message);

        pthread_mutex_unlock(&mutex);
        sleep(2); // Simulate processing time
    }
    return NULL;
}

int main() {
    pthread_t producers[NUM_THREADS];
    pthread_t consumer_thread;

    // Initialize mutex and condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condvar, NULL);

    // Create producer threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data* data = malloc(sizeof(thread_data));
        data->id = i + 1; // Thread IDs from 1 to NUM_THREADS
        pthread_create(&producers[i], NULL, producer, data);
    }

    // Create a single consumer thread
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for all producer threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(producers[i], NULL);
    }

    // Optional: stop consumer after all producers are finished (for clean termination)
    pthread_cancel(consumer_thread);

    // Clean up mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condvar);

    return 0;
}