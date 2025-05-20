//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define NUM_THREADS 5

pthread_mutex_t log_mutex;
FILE *log_file;

void log_event(const char *event) {
    pthread_mutex_lock(&log_mutex);
    
    // Get the current time
    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline character

    // Write to log file
    fprintf(log_file, "[%s] %s\n", time_str, event);
    fflush(log_file); // Ensure it's written to the file

    pthread_mutex_unlock(&log_mutex);
}

void *event_producer(void *thread_id) {
    int id = *((int *)thread_id);
    char event_message[50];

    for (int i = 0; i < MAX_EVENTS; i++) {
        snprintf(event_message, sizeof(event_message), "Thread %d produced event %d", id, i);
        log_event(event_message);
        sleep(rand() % 3); // Random sleep to simulate work
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize mutex and log file
    pthread_mutex_init(&log_mutex, NULL);
    log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return EXIT_FAILURE;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, event_producer, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return EXIT_FAILURE;
        }
    }

    // Clean up
    fclose(log_file);
    pthread_mutex_destroy(&log_mutex);

    printf("Event logging complete. Check 'event_log.txt' for details.\n");
    return EXIT_SUCCESS;
}