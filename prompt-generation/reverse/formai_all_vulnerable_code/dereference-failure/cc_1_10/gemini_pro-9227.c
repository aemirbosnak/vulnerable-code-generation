//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char *event;
} Event;

typedef struct {
    int num_events;
    Event *events;
} Timeline;

Timeline *create_timeline(int num_events) {
    Timeline *timeline = malloc(sizeof(Timeline));
    timeline->num_events = num_events;
    timeline->events = malloc(sizeof(Event) * num_events);
    return timeline;
}

void destroy_timeline(Timeline *timeline) {
    free(timeline->events);
    free(timeline);
}

void add_event(Timeline *timeline, int year, int month, int day, char *event) {
    Event *new_event = malloc(sizeof(Event));
    new_event->date.year = year;
    new_event->date.month = month;
    new_event->date.day = day;
    new_event->event = event;
    timeline->events[timeline->num_events++] = *new_event;
}

void print_timeline(Timeline *timeline) {
    for (int i = 0; i < timeline->num_events; i++) {
        Event *event = &timeline->events[i];
        printf("%d-%02d-%02d: %s\n", event->date.year, event->date.month, event->date.day, event->event);
    }
}

int main() {
    Timeline *timeline = create_timeline(5);
    add_event(timeline, 1985, 10, 26, "Back to the Future is released");
    add_event(timeline, 2015, 10, 21, "Hoverboards are invented");
    add_event(timeline, 2045, 12, 25, "Time travel becomes possible");
    add_event(timeline, 2100, 1, 1, "The world is destroyed by climate change");
    add_event(timeline, 2200, 2, 2, "The world is rebuilt by time travelers");
    print_timeline(timeline);
    destroy_timeline(timeline);
    return 0;
}