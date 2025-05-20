//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_SIZE 256
#define MAX_LINE_SIZE 512

pthread_mutex_t log_mutex;

void log_event(const char *event) {
    // Lock to ensure thread safety when logging
    pthread_mutex_lock(&log_mutex);

    // Open log file in append mode
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Failed to open log file");
        pthread_mutex_unlock(&log_mutex);
        return;
    }

    // Get current time
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline

    // Write event to log file
    fprintf(fp, "[%s] %s\n", timestamp, event);

    // Clean up
    fclose(fp);
    pthread_mutex_unlock(&log_mutex);
}

void simulate_events() {
    const char *events[] = {
        "User logged in",
        "User performed action A",
        "User performed action B",
        "User logged out",
        "System error occurred",
        "Database updated",
        "File uploaded",
        "User created a new document"
    };

    for (int i = 0; i < 10; i++) {
        int event_index = rand() % (sizeof(events) / sizeof(events[0]));
        log_event(events[event_index]);
        sleep(1); // Sleep for a second between events
    }
}

void *event_generator(void *arg) {
    (void)arg; // Unused parameter
    simulate_events();
    return NULL;
}

int main() {
    // Initialize mutex
    pthread_mutex_init(&log_mutex, NULL);

    // Clear previous log file
    FILE *fp = fopen(LOG_FILE, "w");
    if (fp != NULL) {
        fclose(fp);
    }

    // Create event generator thread
    pthread_t event_thread;
    if (pthread_create(&event_thread, NULL, event_generator, NULL) != 0) {
        perror("Failed to create thread");
        pthread_mutex_destroy(&log_mutex);
        return EXIT_FAILURE;
    }

    // Wait for the event generator thread to finish
    pthread_join(event_thread, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&log_mutex);

    return EXIT_SUCCESS;
}