//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

// Number of threads
#define NUM_THREADS 5

// Structure to hold thread data
typedef struct {
    int thread_id;
    char message[100];
} ThreadData;

// Function that will be executed by each thread
void* grateful_message(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    printf("Thread %d: %s\n", data->thread_id, data->message);
    free(data); // Free the thread data after use
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    const char* messages[NUM_THREADS] = {
        "Thank you for the gift of life!",
        "I am grateful for each and every experience.",
        "Thank you for my friends and family.",
        "I appreciate the beauty of nature around me.",
        "Grateful for the lessons learned from challenges."
    };

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        ThreadData* data = (ThreadData*)malloc(sizeof(ThreadData));
        data->thread_id = i + 1;
        strcpy(data->message, messages[i]);

        rc = pthread_create(&threads[i], NULL, grateful_message, (void*)data);
        if (rc) {
            fprintf(stderr, "Error: Unable to create thread %d, %d\n", i, rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "Error: Unable to join thread %d, %d\n", i, rc);
            exit(-1);
        }
    }

    printf("All threads have completed their work with gratitude in their hearts!\n");
    pthread_exit(NULL);
}