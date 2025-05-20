//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

// Shared data structures
typedef struct {
    char *message;
    int timestamp;
} Event;

Event *events;
int num_events = 0;
int max_events = 100;

// Mutex to protect shared data
pthread_mutex_t mutex;

// Thread function to log events
void *log_event(void *args) {
    Event *event = (Event *)args;
    
    // Acquire the lock
    pthread_mutex_lock(&mutex);
    
    // Add the event to the log
    events[num_events].message = event->message;
    events[num_events].timestamp = event->timestamp;
    num_events++;
    
    // Release the lock
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    // Initialize shared data structures
    events = (Event *)malloc(max_events * sizeof(Event));
    pthread_mutex_init(&mutex, NULL);
    
    // Create threads to log events
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        Event event;
        event.message = (char *)malloc(100);
        event.timestamp = time(NULL);
        sprintf(event.message, "Event %d", i);
        pthread_create(&threads[i], NULL, log_event, &event);
    }
    
    // Wait for threads to finish
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print the log
    for (int i = 0; i < num_events; i++) {
        printf("%s: %s\n", ctime(&events[i].timestamp), events[i].message);
    }
    
    // Cleanup
    for (int i = 0; i < num_events; i++) {
        free(events[i].message);
    }
    free(events);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}