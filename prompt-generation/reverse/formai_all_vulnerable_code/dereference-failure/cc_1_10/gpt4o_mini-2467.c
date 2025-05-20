//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "system_events.log"
#define BUFFER_SIZE 256

pthread_mutex_t log_mutex;

void log_event(const char *event) {
    pthread_mutex_lock(&log_mutex);

    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        pthread_mutex_unlock(&log_mutex);
        return;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline character

    fprintf(log_file, "[%s] %s\n", time_str, event);
    fclose(log_file);

    pthread_mutex_unlock(&log_mutex);
}

void *simulate_process_creation(void *arg) {
    char event[BUFFER_SIZE];
    // Simulate event
    snprintf(event, BUFFER_SIZE, "Process %d created", *(int *)arg);
    log_event(event);
    return NULL;
}

void *simulate_process_termination(void *arg) {
    char event[BUFFER_SIZE];
    // Simulate event
    snprintf(event, BUFFER_SIZE, "Process %d terminated", *(int *)arg);
    log_event(event);
    return NULL;
}

void *simulate_file_access(void *arg) {
    char event[BUFFER_SIZE];
    // Simulate event
    snprintf(event, BUFFER_SIZE, "File %s accessed", (char *)arg);
    log_event(event);
    return NULL;
}

void *event_generator(void *arg) {
    int process_id = *(int *)arg;

    // Sleep to simulate time delay between events
    sleep(rand() % 5);
    simulate_process_creation(&process_id);

    sleep(rand() % 5);
    simulate_file_access("example.txt");

    sleep(rand() % 5);
    simulate_process_termination(&process_id);

    return NULL;
}

int main() {
    pthread_mutex_init(&log_mutex, NULL);

    srand(time(NULL)); // Seed random number generator

    const int num_processes = 5;
    pthread_t threads[num_processes];
    int process_ids[num_processes];

    // Create threads to simulate events
    for (int i = 0; i < num_processes; i++) {
        process_ids[i] = i + 1; // Assign process ID
        if (pthread_create(&threads[i], NULL, event_generator, &process_ids[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_processes; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&log_mutex);

    printf("Event logging complete. Check %s for logged events.\n", LOG_FILE);
    return 0;
}