//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_TIME 1000000000

struct event {
    int time;
    char* action;
};

int main() {
    int num_events = 0;
    struct event events[MAX_EVENTS];
    char input[100];
    int i, j, k, time, event_time;
    char* action;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter events in the format 'time action', where time is in seconds and action is a string.\n");
    printf("Enter 'done' when finished.\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "done") == 0) {
            break;
        }
        num_events++;
        if (num_events > MAX_EVENTS) {
            printf("Error: Too many events.\n");
            exit(1);
        }
        sscanf(input, "%d %s", &time, action);
        strcpy(events[num_events-1].action, action);
        events[num_events-1].time = time;
    }

    printf("Enter starting time (in seconds): ");
    scanf("%d", &time);

    for (i = 0; i < num_events; i++) {
        event_time = events[i].time;
        if (event_time <= time) {
            printf("%s\n", events[i].action);
        }
    }

    return 0;
}