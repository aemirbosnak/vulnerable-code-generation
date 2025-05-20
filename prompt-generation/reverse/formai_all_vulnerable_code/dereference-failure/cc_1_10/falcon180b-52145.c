//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_EVENTS 100
#define MAX_TIME 100000
#define MAX_DISTANCE 1000000

typedef struct {
    int id;
    int time;
    int distance;
    struct {
        int id;
        int time;
        int distance;
    } *next;
} Event;

Event *events = NULL;
int current_time = 0;
int current_distance = 0;

void add_event(int id, int time, int distance) {
    Event *new_event = (Event*)malloc(sizeof(Event));
    new_event->id = id;
    new_event->time = time;
    new_event->distance = distance;
    new_event->next = NULL;

    if (events == NULL) {
        events = new_event;
    } else {
        Event *last_event = events;
        while (last_event->next!= NULL) {
            last_event = last_event->next;
        }
        last_event->next = new_event;
    }
}

int get_event_time(int id) {
    Event *event = events;
    while (event!= NULL) {
        if (event->id == id) {
            return event->time;
        }
        event = event->next;
    }
    return -1;
}

int get_event_distance(int id) {
    Event *event = events;
    while (event!= NULL) {
        if (event->id == id) {
            return event->distance;
        }
        event = event->next;
    }
    return -1;
}

void update_time_distance() {
    current_time++;
    current_distance++;

    Event *event = events;
    while (event!= NULL) {
        if (event->time == current_time) {
            current_distance += event->distance;
        }
        event = event->next;
    }
}

int main() {
    srand(time(NULL));

    int num_events = rand() % MAX_EVENTS + 1;
    for (int i = 0; i < num_events; i++) {
        int id = rand() % 1000 + 1;
        int time = rand() % MAX_TIME + 1;
        int distance = rand() % MAX_DISTANCE + 1;
        add_event(id, time, distance);
    }

    int start_id = rand() % 1000 + 1;
    int end_id = rand() % 1000 + 1;

    int start_time = get_event_time(start_id);
    int end_time = get_event_time(end_id);
    int start_distance = get_event_distance(start_id);
    int end_distance = get_event_distance(end_id);

    printf("Starting at event %d with a distance of %d\n", start_id, start_distance);
    printf("Ending at event %d with a distance of %d\n", end_id, end_distance);

    while (current_time < start_time) {
        update_time_distance();
    }

    while (current_time < end_time) {
        update_time_distance();
        printf("Current time: %d, current distance: %d\n", current_time, current_distance);
    }

    return 0;
}