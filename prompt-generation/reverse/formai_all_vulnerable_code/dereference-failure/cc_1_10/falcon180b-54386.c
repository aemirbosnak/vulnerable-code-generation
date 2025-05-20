//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MAX_TIME_TRAVELS 100
#define MAX_TIME_TRAVEL_LENGTH 100
#define TIME_UNITS_PER_SECOND 1000000

typedef struct {
    int length;
    int *events;
} time_travel;

int main() {
    srand(time(NULL));
    time_travel travels[MAX_TIME_TRAVELS];
    int num_travels = 0;

    while (num_travels < MAX_TIME_TRAVELS) {
        int length = rand() % MAX_TIME_TRAVEL_LENGTH + 1;
        time_travel new_travel;
        new_travel.length = length;
        new_travel.events = malloc(length * sizeof(int));

        for (int i = 0; i < length; i++) {
            new_travel.events[i] = rand() % 1000;
        }

        travels[num_travels++] = new_travel;
    }

    printf("Enter the time travel number you want to simulate (0-%d): ", num_travels - 1);
    scanf("%d", &num_travels);

    time_travel *travel = &travels[num_travels - 1];

    int current_event = 0;
    int64_t current_time = 0;
    int64_t next_event_time = travel->events[current_event] * TIME_UNITS_PER_SECOND;

    while (next_event_time > current_time) {
        current_time += 1000;
        printf("Waiting... ");
    }

    while (current_event < travel->length - 1) {
        printf("Event %d at time %d\n", current_event + 1, travel->events[current_event] * TIME_UNITS_PER_SECOND);
        current_event++;
        next_event_time = travel->events[current_event] * TIME_UNITS_PER_SECOND;
    }

    return 0;
}