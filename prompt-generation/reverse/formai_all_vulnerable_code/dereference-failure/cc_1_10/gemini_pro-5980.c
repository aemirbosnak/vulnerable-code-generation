//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024
#define MAX_NUM_EVENTS 100

typedef struct {
    char *name;
    char *description;
    int severity;
} Event;

Event *events[MAX_NUM_EVENTS];
int num_events = 0;

void add_event(char *name, char *description, int severity) {
    if (num_events == MAX_NUM_EVENTS) {
        printf("Error: Too many events\n");
        return;
    }

    events[num_events] = malloc(sizeof(Event));
    events[num_events]->name = strdup(name);
    events[num_events]->description = strdup(description);
    events[num_events]->severity = severity;
    num_events++;
}

void print_events() {
    for (int i = 0; i < num_events; i++) {
        printf("%s: %s (severity: %d)\n", events[i]->name, events[i]->description, events[i]->severity);
    }
}

void free_events() {
    for (int i = 0; i < num_events; i++) {
        free(events[i]->name);
        free(events[i]->description);
        free(events[i]);
    }
}

int main() {
    add_event("Login", "A user logged in", 1);
    add_event("Logout", "A user logged out", 1);
    add_event("File access", "A user accessed a file", 2);
    add_event("File modification", "A user modified a file", 3);
    add_event("System command", "A user executed a system command", 4);

    print_events();

    free_events();

    return 0;
}