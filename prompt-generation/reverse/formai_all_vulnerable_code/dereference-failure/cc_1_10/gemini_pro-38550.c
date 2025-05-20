//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

struct event {
    int time;
    char *description;
};

struct time_traveler {
    int current_time;
    struct event *events[MAX_EVENTS];
    int num_events;
};

void add_event(struct time_traveler *traveler, int time, char *description) {
    if (traveler->num_events >= MAX_EVENTS) {
        printf("Error: too many events\n");
        return;
    }

    traveler->events[traveler->num_events] = malloc(sizeof(struct event));
    traveler->events[traveler->num_events]->time = time;
    traveler->events[traveler->num_events]->description = description;
    traveler->num_events++;
}

void print_events(struct time_traveler *traveler) {
    for (int i = 0; i < traveler->num_events; i++) {
        printf("%d: %s\n", traveler->events[i]->time, traveler->events[i]->description);
    }
}

void time_travel(struct time_traveler *traveler, int time) {
    if (time < 0 || time > traveler->current_time) {
        printf("Error: invalid time\n");
        return;
    }

    traveler->current_time = time;

    printf("Time travel successful!\n");
    printf("Current time: %d\n", traveler->current_time);
    print_events(traveler);
}

int main() {
    // Initialize the time traveler
    struct time_traveler traveler;
    traveler.current_time = 0;
    traveler.num_events = 0;

    // Add some events to the traveler's timeline
    add_event(&traveler, 10, "Meet with the President");
    add_event(&traveler, 20, "Go to the future");
    add_event(&traveler, 30, "Come back to the present");

    // Print the traveler's current timeline
    printf("Current timeline:\n");
    print_events(&traveler);

    // Time travel to the future
    time_travel(&traveler, 20);

    // Print the traveler's new timeline
    printf("New timeline:\n");
    print_events(&traveler);

    // Time travel back to the present
    time_travel(&traveler, 30);

    // Print the traveler's final timeline
    printf("Final timeline:\n");
    print_events(&traveler);

    return 0;
}