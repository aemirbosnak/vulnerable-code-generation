//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_TIME 1000

typedef struct {
    int time;
    int type;
    int data;
} Event;

void add_event(Event* events, int num_events, int time, int type, int data) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        exit(1);
    }
    events[num_events].time = time;
    events[num_events].type = type;
    events[num_events].data = data;
    num_events++;
}

void travel_time(Event* events, int num_events, int current_time) {
    while (current_time < MAX_TIME) {
        int i;
        for (i = 0; i < num_events; i++) {
            if (events[i].time == current_time) {
                switch (events[i].type) {
                    case 1:
                        printf("You traveled back in time by %d seconds.\n", events[i].data);
                        break;
                    case 2:
                        printf("You traveled forward in time by %d seconds.\n", events[i].data);
                        break;
                    case 3:
                        printf("You stopped time for %d seconds.\n", events[i].data);
                        break;
                    default:
                        printf("Invalid event type.\n");
                }
            }
        }
        current_time++;
        if (current_time == events[num_events - 1].time) {
            printf("You reached the end of time.\n");
            exit(0);
        }
    }
}

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    add_event(events, num_events, 0, 1, 10);
    add_event(events, num_events, 20, 2, 20);
    add_event(events, num_events, 30, 3, 30);
    add_event(events, num_events, 40, 1, 40);
    add_event(events, num_events, 50, 2, 50);
    add_event(events, num_events, 60, 3, 60);
    add_event(events, num_events, 70, 1, 70);
    add_event(events, num_events, 80, 2, 80);
    add_event(events, num_events, 90, 3, 90);

    travel_time(events, num_events, 0);

    return 0;
}