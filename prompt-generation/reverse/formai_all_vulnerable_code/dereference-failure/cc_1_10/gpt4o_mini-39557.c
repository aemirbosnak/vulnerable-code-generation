//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_SIZE 256

typedef struct {
    char event[MAX_EVENT_SIZE];
} LogEvent;

pthread_mutex_t log_mutex;
LogEvent log_events[100];
int log_index = 0;
int should_run = 1;

void* log_writer(void* args) {
    FILE* file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Could not open log file");
        return NULL;
    }

    while (should_run) {
        if (log_index > 0) {
            pthread_mutex_lock(&log_mutex);
            for (int i = 0; i < log_index; i++) {
                fprintf(file, "%s\n", log_events[i].event);
                // Clear the event after logging
                memset(log_events[i].event, 0, sizeof(log_events[i].event));
            }
            log_index = 0;
            pthread_mutex_unlock(&log_mutex);
        }
        sleep(1);  // Sleep to avoid busy waiting
    }
    
    fclose(file);
    return NULL;
}

void log_event(const char* event) {
    if (log_index < 100) {
        pthread_mutex_lock(&log_mutex);
        strncpy(log_events[log_index].event, event, MAX_EVENT_SIZE - 1);
        log_events[log_index].event[MAX_EVENT_SIZE - 1] = '\0'; // Ensure null-termination
        log_index++;
        pthread_mutex_unlock(&log_mutex);
    } else {
        fprintf(stderr, "Log buffer is full. Skipping event: %s\n", event);
    }
}

void get_current_time(char* buffer, size_t size) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(buffer, size, "%d-%02d-%02d %02d:%02d:%02d",
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
             tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void simulate_user_actions() {
    char time_buffer[20];
    for (int i = 0; i < 10; i++) {
        get_current_time(time_buffer, sizeof(time_buffer));
        char event_msg[100];
        snprintf(event_msg, sizeof(event_msg), "[%s] User action: Action %d performed.", time_buffer, i+1);
        log_event(event_msg);
        sleep(rand() % 3 + 1); // Random sleep between actions
    }

    // Simulate an error
    get_current_time(time_buffer, sizeof(time_buffer));
    log_event("An error occurred: Unable to access resources.");
}

int main() {
    srand(time(NULL));
    pthread_t logger_thread;

    pthread_mutex_init(&log_mutex, NULL);
    pthread_create(&logger_thread, NULL, log_writer, NULL);

    simulate_user_actions();

    should_run = 0;  // Signal the log writer to stop
    pthread_join(logger_thread, NULL);
    pthread_mutex_destroy(&log_mutex);

    printf("Event logging completed. Check %s for logs.\n", LOG_FILE);
    return 0;
}