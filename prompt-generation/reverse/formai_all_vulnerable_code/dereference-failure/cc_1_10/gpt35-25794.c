//FormAI DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Create a struct for the system event
typedef struct Event {
    char* message;
    time_t timestamp;
} Event;

// Create a queue to store events
typedef struct Queue {
    Event* events;
    int head;
    int tail;
    int count;
    int maxSize;
} Queue;

// Function to initialize the queue
void initQueue(Queue* queue, int maxSize) {
    queue->maxSize = maxSize;
    queue->events = (Event*)malloc(maxSize * sizeof(Event));
    queue->head = 0;
    queue->tail = -1;
    queue->count = 0;
}

// Function to check if the queue is full
int isQueueFull(Queue* queue) {
    if(queue->count == queue->maxSize) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* queue) {
    if(queue->count == 0) {
        return 1;
    }
    return 0;
}

// Function to add an event to the queue
void enqueue(Queue* queue, char* message) {
    // Check if the queue is full
    if(isQueueFull(queue)) {
        printf("Queue is full, cannot add event.\n");
        return;
    }

    // Increment the tail index and add the event
    queue->tail = (queue->tail + 1) % queue->maxSize;
    queue->events[queue->tail].message = message;
    queue->events[queue->tail].timestamp = time(NULL);

    // Increment the count
    queue->count++;
}

// Function to remove an event from the queue
Event dequeue(Queue* queue) {
    // Check if the queue is empty
    if(isQueueEmpty(queue)) {
        printf("Queue is empty, cannot remove event.\n");
        Event event;
        event.timestamp = -1;
        return event;
    }

    // Get the event at the head index
    Event event = queue->events[queue->head];

    // Increment the head index and decrement the count
    queue->head = (queue->head + 1) % queue->maxSize;
    queue->count--;

    return event;
}

int main() {
    Queue eventQueue;
    initQueue(&eventQueue, 10);

    // Add some events to the queue
    printf("Adding events to the queue...\n");
    enqueue(&eventQueue, "System started.");
    enqueue(&eventQueue, "User logged in.");
    enqueue(&eventQueue, "File saved.");
    enqueue(&eventQueue, "File deleted.");
    enqueue(&eventQueue, "User logged out.");
    printf("\n");

    // Remove and print the events from the queue
    printf("Removing events from the queue...\n");
    while(!isQueueEmpty(&eventQueue)) {
        Event event = dequeue(&eventQueue);
        printf("%s\n", event.message);
    }
    printf("\n");

    // Add more events to the queue
    printf("Adding more events to the queue...\n");
    enqueue(&eventQueue, "System shut down.");
    enqueue(&eventQueue, "Restarting system.");
    printf("\n");

    // Remove and print the events from the queue
    printf("Removing events from the queue...\n");
    while(!isQueueEmpty(&eventQueue)) {
        Event event = dequeue(&eventQueue);
        printf("%s\n", event.message);
    }
    printf("\n");

    return 0;
}