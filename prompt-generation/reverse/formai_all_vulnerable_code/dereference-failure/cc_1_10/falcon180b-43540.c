//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_NAME_LENGTH 50

typedef struct {
    char name[MAX_EVENT_NAME_LENGTH];
    time_t timestamp;
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];
    char input[MAX_EVENT_NAME_LENGTH];
    time_t current_time;

    // Set the current time to January 1, 2020
    struct tm tm = {0};
    tm.tm_year = 2020 - 1900;
    tm.tm_mon = 0;
    tm.tm_mday = 1;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    time_t start_time = mktime(&tm);
    current_time = start_time;

    while (1) {
        printf("Enter an event name (or leave blank to travel): ");
        fgets(input, MAX_EVENT_NAME_LENGTH, stdin);
        if (strlen(input) == 0) {
            break;
        }
        strcpy(events[num_events].name, input);
        events[num_events].timestamp = current_time;
        num_events++;
        if (num_events >= MAX_EVENTS) {
            printf("Max events (%d) reached.\n", MAX_EVENTS);
            break;
        }
    }

    printf("Traveling back in time...\n");
    for (int i = num_events - 1; i >= 0; i--) {
        current_time = events[i].timestamp;
        tm = *localtime(&current_time);
        printf("Traveling to %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        sleep(1);
    }

    return 0;
}