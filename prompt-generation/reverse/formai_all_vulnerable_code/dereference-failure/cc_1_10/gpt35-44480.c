//FormAI DATASET v1.0 Category: System event logger ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

#define EVENT_LOG_MAX_SIZE 1000 // Max size of the event log
#define MAX_THREADS 5 // Max number of threads

// Struct to hold the information of an event
typedef struct Event {
    char name[50];
    char desc[200];
    struct timeval time;
} Event;

// Struct to hold the information of an event log
typedef struct EventLog {
    Event events[EVENT_LOG_MAX_SIZE];
    int count;
} EventLog;

// Global variables
pthread_t threads[MAX_THREADS];
int num_threads;
pthread_mutex_t mtx; // Mutex lock for accessing the event log
EventLog event_log;

// Function to add an event to the event log
void log_event(char *name, char *desc) {
    pthread_mutex_lock(&mtx); // Lock the mutex
    if (event_log.count < EVENT_LOG_MAX_SIZE) {
        // Create the new event
        Event new_event;
        strcpy(new_event.name, name);
        strcpy(new_event.desc, desc);
        gettimeofday(&new_event.time, NULL);
        // Add the event to the event log
        event_log.events[event_log.count] = new_event;
        event_log.count++;
    }
    pthread_mutex_unlock(&mtx); // Unlock the mutex after adding an event
}

// Function to print out all the events in the event log
void print_events() {
    pthread_mutex_lock(&mtx); // Lock the mutex
    printf("Event Log:\n");
    for (int i = 0; i < event_log.count; i++) {
        printf("%d. [%s] %s\tTime: %ld.%06ld\n", i+1, event_log.events[i].name, 
                event_log.events[i].desc, event_log.events[i].time.tv_sec, 
                event_log.events[i].time.tv_usec);
    }
    pthread_mutex_unlock(&mtx); // Unlock the mutex after printing all events
}

// Thread function to log events
void *log_event_thread(void *args) {
    int thread_num = *((int *)args);
    char event_name[50];
    sprintf(event_name, "Event%d", thread_num+1);
    char event_desc[200];
    sprintf(event_desc, "Description of Event%d", thread_num+1);
    for (int i = 0; i < 5; i++) { // Log 5 events per thread
        log_event(event_name, event_desc);
        sleep(1); // Sleep for 1 second before logging the next event
    }
    printf("Thread %d finished logging events.\n", thread_num+1);
    free(args);
    pthread_exit(NULL);
}

int main() {
    // Initialize the mutex lock and event log
    pthread_mutex_init(&mtx, NULL);
    event_log.count = 0;

    printf("How many threads should be created? ");
    scanf("%d", &num_threads);
    if (num_threads > MAX_THREADS) {
        printf("Error: number of threads exceeds maximum number of threads %d.\n", MAX_THREADS);
        return 1;
    }

    // Create the threads to log events
    for (int i = 0; i < num_threads; i++) {
        int *p = malloc(sizeof(int));
        *p = i;
        pthread_create(&threads[i], NULL, log_event_thread, p);
    }

    // Join all the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print out the event log
    print_events();

    // Destroy the mutex lock
    pthread_mutex_destroy(&mtx);

    return 0;
}