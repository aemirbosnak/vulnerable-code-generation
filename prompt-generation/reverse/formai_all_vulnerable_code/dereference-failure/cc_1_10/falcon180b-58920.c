//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_TIME 1000000000000L

typedef struct event {
    long long int time;
    char* description;
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];
    long long int current_time = 0;
    char input_buffer[1024];
    char* token;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the initial time (in seconds since epoch): ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    current_time = strtoll(input_buffer, NULL, 10);

    while (1) {
        printf("Current time: %lld\n", current_time);
        printf("Enter event (format: <time> <description>): ");
        fgets(input_buffer, sizeof(input_buffer), stdin);

        token = strtok(input_buffer, " ");
        if (token == NULL) {
            printf("Invalid input.\n");
            continue;
        }
        events[num_events].time = strtoll(token, NULL, 10);

        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Invalid input.\n");
            continue;
        }
        strncpy(events[num_events].description, token, sizeof(events[num_events].description) - 1);
        events[num_events].description[sizeof(events[num_events].description) - 1] = '\0';

        num_events++;

        if (num_events >= MAX_EVENTS) {
            printf("Maximum number of events reached.\n");
            break;
        }
    }

    while (1) {
        printf("Enter destination time (in seconds since epoch): ");
        fgets(input_buffer, sizeof(input_buffer), stdin);
        long long int destination_time = strtoll(input_buffer, NULL, 10);

        if (destination_time < current_time) {
            printf("Invalid destination time.\n");
            continue;
        }

        for (int i = 0; i < num_events; i++) {
            if (events[i].time > current_time && events[i].time <= destination_time) {
                printf("%s\n", events[i].description);
            }
        }

        current_time = destination_time;
    }

    return 0;
}