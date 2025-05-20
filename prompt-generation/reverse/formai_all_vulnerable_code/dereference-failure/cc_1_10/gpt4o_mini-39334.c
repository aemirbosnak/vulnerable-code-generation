//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_LOG_MSG_LENGTH 256
#define NUM_THREADS 5
#define NUM_EVENTS 10

pthread_mutex_t log_mutex;

void log_event(const char* message) {
    time_t now;
    time(&now);
    char* time_str = ctime(&now);
    // Remove newline character from time string
    time_str[strlen(time_str) - 1] = '\0';

    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file != NULL) {
        pthread_mutex_lock(&log_mutex);
        fprintf(log_file, "[%s] %s\n", time_str, message);
        pthread_mutex_unlock(&log_mutex);
        fclose(log_file);
    } else {
        perror("Failed to open log file");
    }
}

void* event_generator(void* thread_id) {
    int id = *((int*)thread_id);
    free(thread_id); // Free dynamically allocated memory for thread_id

    char log_msg[MAX_LOG_MSG_LENGTH];

    for (int i = 0; i < NUM_EVENTS; i++) {
        snprintf(log_msg, MAX_LOG_MSG_LENGTH, "Thread %d: Event %d generated.", id, i);
        log_event(log_msg);
        sleep(rand() % 3); // Random sleep to simulate event generation time
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&log_mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        int* thread_id = malloc(sizeof(int)); // Dynamically allocate memory for thread ID
        *thread_id = i + 1; // Thread IDs will start from 1
        if (pthread_create(&threads[i], NULL, event_generator, thread_id) != 0) {
            perror("Failed to create thread");
            free(thread_id); // Free if thread creation fails
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&log_mutex);
    printf("Event logging complete. Check '%s' for details.\n", LOG_FILE);
    return EXIT_SUCCESS;
}