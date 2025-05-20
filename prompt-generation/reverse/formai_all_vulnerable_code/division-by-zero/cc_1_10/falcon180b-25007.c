//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELERS 10
#define MAX_TIME_TRAVEL_EVENTS 100
#define TIME_TRAVEL_EVENT_SIZE 10

typedef struct {
    int traveler_id;
    int start_year;
    int end_year;
} time_travel_event;

void print_event(time_travel_event event) {
    printf("Traveler %d travels from %d to %d\n", event.traveler_id, event.start_year, event.end_year);
}

int main() {
    int num_time_travelers;
    int num_time_travel_events;
    int i, j;
    time_travel_event events[MAX_TIME_TRAVEL_EVENTS];
    int traveler_ids[MAX_TIME_TRAVELERS];

    // Initialize random seed
    srand(time(NULL));

    // Get number of time travelers from user
    printf("Enter the number of time travelers: ");
    scanf("%d", &num_time_travelers);

    // Generate unique traveler IDs
    for (i = 0; i < num_time_travelers; i++) {
        traveler_ids[i] = rand() % 1000;
    }

    // Get number of time travel events from user
    printf("Enter the number of time travel events: ");
    scanf("%d", &num_time_travel_events);

    // Generate time travel events
    for (i = 0; i < num_time_travel_events; i++) {
        events[i].traveler_id = traveler_ids[rand() % num_time_travelers];
        events[i].start_year = rand() % 1000;
        events[i].end_year = rand() % 3000;
    }

    // Print time travel events
    printf("Time travel events:\n");
    for (i = 0; i < num_time_travel_events; i++) {
        print_event(events[i]);
    }

    return 0;
}