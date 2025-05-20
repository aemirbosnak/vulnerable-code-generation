//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENTS 1000
#define EVENT_SIZE 1024

struct event {
    time_t timestamp;
    char message[EVENT_SIZE];
};

int event_count = 0;
struct event events[MAX_EVENTS];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void add_event(const char* message) {
    pthread_mutex_lock(&lock);
    if (event_count >= MAX_EVENTS) {
        fprintf(stderr, "Event buffer full, dropping event: %s\n", message);
        pthread_mutex_unlock(&lock);
        return;
    }
    strncpy(events[event_count].message, message, EVENT_SIZE);
    events[event_count].timestamp = time(NULL);
    event_count++;
    pthread_mutex_unlock(&lock);
}

void print_events() {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < event_count; i++) {
        fprintf(stdout, "%.24s: %s\n", ctime(&events[i].timestamp), events[i].message);
    }
    pthread_mutex_unlock(&lock);
}

void* monitor_thread(void* arg) {
    FILE* fp;
    char buffer[EVENT_SIZE];

    fp = fopen("/var/log/syslog", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open syslog file: %s\n", strerror(errno));
        return NULL;
    }

    while (fgets(buffer, EVENT_SIZE, fp)!= NULL) {
        add_event(buffer);
    }

    fclose(fp);
    return NULL;
}

int main() {
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, monitor_thread, NULL);

    while (1) {
        sleep(5);
        print_events();
    }

    return 0;
}