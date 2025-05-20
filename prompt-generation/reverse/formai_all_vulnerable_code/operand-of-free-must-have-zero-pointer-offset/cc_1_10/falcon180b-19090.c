//Falcon-180B DATASET v1.0 Category: System event logger ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENT_SIZE 512
#define MAX_EVENTS 1000
#define MAX_THREADS 10

typedef struct event_t {
    time_t timestamp;
    char message[MAX_EVENT_SIZE];
} Event;

typedef struct event_queue_t {
    Event events[MAX_EVENTS];
    int front;
    int rear;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} EventQueue;

EventQueue event_queue;

void init_event_queue() {
    event_queue.front = 0;
    event_queue.rear = -1;
    pthread_mutex_init(&event_queue.mutex, NULL);
    pthread_cond_init(&event_queue.cond, NULL);
}

void enqueue_event(Event event) {
    pthread_mutex_lock(&event_queue.mutex);
    if ((event_queue.rear + 1) % MAX_EVENTS == event_queue.front) {
        printf("Event queue is full!\n");
        pthread_mutex_unlock(&event_queue.mutex);
        return;
    }
    event_queue.rear = (event_queue.rear + 1) % MAX_EVENTS;
    memcpy(&event_queue.events[event_queue.rear], &event, sizeof(Event));
    pthread_mutex_unlock(&event_queue.mutex);
    pthread_cond_signal(&event_queue.cond);
}

Event dequeue_event() {
    Event event;
    pthread_mutex_lock(&event_queue.mutex);
    if (event_queue.front == -1 || event_queue.front > event_queue.rear) {
        pthread_mutex_unlock(&event_queue.mutex);
        return event;
    }
    memcpy(&event, &event_queue.events[event_queue.front], sizeof(Event));
    event_queue.front = (event_queue.front + 1) % MAX_EVENTS;
    pthread_mutex_unlock(&event_queue.mutex);
    return event;
}

void log_event(const char* message) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);
    sprintf(message, "%s %s\n", timestamp, message);
    enqueue_event((Event){.timestamp = now,.message = message});
}

void* logger_thread(void* arg) {
    FILE* log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Failed to open log file!\n");
        return NULL;
    }
    while (1) {
        Event event = dequeue_event();
        fprintf(log_file, "%s", event.message);
        fflush(log_file);
        free(event.message);
    }
    return NULL;
}

int main() {
    init_event_queue();
    int num_threads = 3;
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < num_threads; ++i) {
        pthread_create(&threads[i], NULL, logger_thread, NULL);
    }
    while (1) {
        sleep(1);
        log_event("Hello, world!");
    }
    return 0;
}