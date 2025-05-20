//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct Event {
    int time;
    char description[100];
    struct Event *next;
} Event;

Event *head = NULL;
int current_time = 0;

void print_events() {
    Event *e = head;
    printf("Events:\n");
    while (e != NULL) {
        printf("%d: %s\n", e->time, e->description);
        e = e->next;
    }
}

void add_event(const char *desc) {
    Event *new_event = (Event *)calloc(1, sizeof(Event));
    strcpy(new_event->description, desc);
    new_event->time = current_time;
    new_event->next = head;
    head = new_event;
}

void travel_back_in_time(int num_steps) {
    if (num_steps > current_time) {
        printf("Error: Cannot travel back in time more than current time.\n");
        return;
    }

    current_time -= num_steps;
    printf("Traveled back in time %d steps to %d.\n", num_steps, current_time);
}

int main() {
    clock_t start = clock();

    add_event("Dennis Ritchie invents C language.");
    add_event("Brian Kernighan writes the first edition of The C Programming Language.");
    add_event("Unix Time-sharing System is released.");
    add_event("The C Programming Language, 2nd Edition is published.");

    print_events();

    travel_back_in_time(2);
    print_events();

    travel_back_in_time(1);
    print_events();

    travel_back_in_time(1);
    print_events();

    clock_t end = clock();
    double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds.\n", time_elapsed);

    return 0;
}