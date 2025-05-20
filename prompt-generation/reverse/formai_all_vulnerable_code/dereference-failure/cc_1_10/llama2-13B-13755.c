//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: asynchronous
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>

#define MAX_EVENTS 100
#define MAX_THREADS 5

struct event {
    int id;
    char *message;
};

struct thread_data {
    pthread_t thread;
    int events_processed;
};

void *thread_func(void *data) {
    struct thread_data *td = data;
    int events_left = td->events_processed < MAX_EVENTS ? MAX_EVENTS - td->events_processed : 0;
    while (events_left > 0) {
        int event_id = rand() % MAX_EVENTS;
        char *event_message = "Event #";
        event_message += event_id;
        event_message[sizeof(event_message) - 1] = '\0';
        syslog(LOG_INFO, "%s", event_message);
        td->events_processed++;
        events_left--;
    }
    pthread_exit(NULL);
}

int main() {
    int i;
    struct thread_data td[MAX_THREADS];
    for (i = 0; i < MAX_THREADS; i++) {
        td[i].events_processed = 0;
        pthread_create(&td[i].thread, NULL, thread_func, &td[i]);
    }
    char *events[] = {"Event 1", "Event 2", "Event 3", "Event 4", "Event 5"};
    for (i = 0; i < sizeof(events) / sizeof(char *); i++) {
        syslog(LOG_INFO, "%s", events[i]);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(td[i].thread, NULL);
    }
    return 0;
}