//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <syslog.h>

#define MAX_THREADS 4
#define MAX_EVENTS 10

// Event structure
typedef struct event {
    int id;
    char *message;
} event_t;

// Thread data structure
typedef struct thread_data {
    int id;
    int num_events;
    event_t *events;
} thread_data_t;

// Thread function
void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    // Log events
    for (int i = 0; i < data->num_events; i++) {
        syslog(LOG_INFO, "%d: %s", data->id, data->events[i].message);
    }

    return NULL;
}

int main() {
    // Initialize event logger
    openlog("my_app", LOG_CONS | LOG_PID, LOG_USER);

    // Create thread data
    thread_data_t data[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        data[i].id = i;
        data[i].num_events = MAX_EVENTS;
        data[i].events = malloc(sizeof(event_t) * MAX_EVENTS);
        for (int j = 0; j < MAX_EVENTS; j++) {
            data[i].events[j].id = j;
            data[i].events[j].message = malloc(50);
            snprintf(data[i].events[j].message, 50, "Event %d-%d", i, j);
        }
    }

    // Create threads
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    // Join threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close event logger
    closelog();

    return 0;
}