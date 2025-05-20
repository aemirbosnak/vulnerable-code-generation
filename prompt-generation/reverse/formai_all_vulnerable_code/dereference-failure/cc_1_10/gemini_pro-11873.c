//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Event {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char *description;
};

struct EventQueue {
    struct Event *events;
    int size;
    int capacity;
};

void enqueue(struct EventQueue *queue, struct Event *event) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->events = realloc(queue->events, queue->capacity * sizeof(struct Event));
    }
    queue->events[queue->size++] = *event;
}

struct Event *dequeue(struct EventQueue *queue) {
    if (queue->size == 0) {
        return NULL;
    }
    return &queue->events[--queue->size];
}

int main() {
    srand(time(NULL));

    struct EventQueue eventQueue;
    eventQueue.events = NULL;
    eventQueue.size = 0;
    eventQueue.capacity = 0;

    // Generate 10 random events
    for (int i = 0; i < 10; i++) {
        struct Event event;
        event.year = rand() % 100 + 1900;
        event.month = rand() % 12 + 1;
        event.day = rand() % 28 + 1;
        event.hour = rand() % 24;
        event.minute = rand() % 60;
        event.second = rand() % 60;
        event.description = "Some random event";

        enqueue(&eventQueue, &event);
    }

    // Print the events in chronological order
    while (eventQueue.size > 0) {
        struct Event *event = dequeue(&eventQueue);
        printf("%d-%02d-%02d %02d:%02d:%02d %s\n", event->year, event->month, event->day, event->hour, event->minute, event->second, event->description);
    }

    return 0;
}