//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of events to read from file
#define MAX_EVENTS 100

// Structure to hold event information
struct Event {
    int time;
    char type[20];
    char details[50];
};

int main() {
    // Array of events read from file
    struct Event events[MAX_EVENTS];

    // Read events from file
    FILE *file = fopen("events.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int num_events = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (num_events >= MAX_EVENTS) {
            printf("Too many events in file.\n");
            return 1;
        }
        char *token = strtok(line, ",");
        events[num_events].time = atoi(token);
        token = strtok(NULL, ",");
        strcpy(events[num_events].type, token);
        token = strtok(NULL, ",");
        strcpy(events[num_events].details, token);
        num_events++;
    }
    fclose(file);

    // Sort events by time
    for (int i = 0; i < num_events - 1; i++) {
        for (int j = i + 1; j < num_events; j++) {
            if (events[i].time > events[j].time) {
                struct Event temp = events[i];
                events[i] = events[j];
                events[j] = temp;
            }
        }
    }

    // Check for intrusion events
    int last_valid_time = 0;
    for (int i = 0; i < num_events; i++) {
        if (strcmp(events[i].type, "intrusion") == 0) {
            if (events[i].time - last_valid_time < 10) {
                printf("**INTRUSION DETECTED**\n");
                printf("Time: %d Event Type: %s Details: %s\n", events[i].time, events[i].type, events[i].details);
            } else {
                printf("Intrusion event but too much time since last valid event.\n");
            }
        } else {
            last_valid_time = events[i].time;
        }
    }

    return 0;
}