//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EVENTS 1000

typedef struct event {
    char description[256];
    struct event *next;
    time_t timestamp;
} event_t;

event_t *events = NULL;
int current_position = -1;

void add_event(char *description) {
    event_t *new_event = malloc(sizeof(event_t));
    strcpy(new_event->description, description);
    time(&new_event->timestamp);

    if (events == NULL) {
        events = new_event;
        current_position = 0;
    } else {
        event_t *last = events;
        while (last->next != NULL)
            last = last->next;
        last->next = new_event;
        new_event->next = NULL;
    }
}

void display_events() {
    int i;
    event_t *current = events;

    printf("\nCurrent position: %d\n", current_position);
    printf("Timeline:\n");

    for (i = 0; i <= current_position; i++) {
        printf("%s (%ld)\n", current->description, current->timestamp);
        current = current->next;
    }
}

void travel_back() {
    if (current_position > 0)
        current_position--;
}

void travel_forward() {
    event_t *current = events;

    while (current != NULL && current_position < current_position)
        current = current->next;

    if (current == NULL) {
        printf("Error: Unable to travel further in time.\n");
        return;
    }

    current_position = current_position + 1;
}

int main() {
    char input[256];
    char *token;

    while (1) {
        printf("\n> ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input)] = '\0';

        token = strtok(input, " ");
        if (strcmp(token, "ADD") == 0) {
            token = strtok(NULL, " ");
            add_event(token);
            display_events();
        } else if (strcmp(token, "BACK") == 0) {
            travel_back();
            display_events();
        } else if (strcmp(token, "FORWARD") == 0) {
            travel_forward();
            display_events();
        } else if (strcmp(token, "QUIT") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}