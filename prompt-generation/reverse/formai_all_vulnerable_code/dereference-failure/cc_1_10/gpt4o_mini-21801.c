//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define NUM_THREADS 5
#define NUM_EVENTS 10

pthread_mutex_t log_mutex;

void get_current_time(char *buffer, size_t buffer_size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, buffer_size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void log_event(int thread_id, const char *event_message) {
    pthread_mutex_lock(&log_mutex); // Lock the mutex before writing to the file
    
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        pthread_mutex_unlock(&log_mutex); // Unlock mutex if file opening fails
        return;
    }
    
    char timestamp[20];
    get_current_time(timestamp, sizeof(timestamp));
    
    fprintf(file, "[%s] Thread %d: %s\n", timestamp, thread_id, event_message);
    fclose(file);
    
    pthread_mutex_unlock(&log_mutex); // Unlock the mutex after writing
}

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    free(arg); // Free the allocated memory for thread ID
    
    for (int i = 0; i < NUM_EVENTS; i++) {
        char event_message[50];
        sprintf(event_message, "Event %d occurred", i + 1);
        log_event(thread_id, event_message);
        usleep(rand() % 100000); // Sleep for a random time to simulate work
    }

    return NULL;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    pthread_mutex_init(&log_mutex, NULL); // Initialize the mutex

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int *thread_id = malloc(sizeof(int)); // Allocate memory for thread ID
        *thread_id = i + 1; // Assign a unique ID to each thread
        if (pthread_create(&threads[i], NULL, thread_function, thread_id) != 0) {
            perror("Failed to create thread");
            free(thread_id);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&log_mutex); // Destroy the mutex
    printf("Logging completed. Check %s for events.\n", LOG_FILE);

    return 0;
}