//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char *description;
} Event;

Event *events;
int num_events;

void add_event(int year, int month, int day, char *description) {
    Event *new_event = malloc(sizeof(Event));
    new_event->date.year = year;
    new_event->date.month = month;
    new_event->date.day = day;
    new_event->description = description;

    events = realloc(events, (num_events + 1) * sizeof(Event));
    events[num_events++] = *new_event;
}

void print_events() {
    for (int i = 0; i < num_events; i++) {
        printf("%d-%d-%d: %s\n", events[i].date.year, events[i].date.month, events[i].date.day, events[i].description);
    }
}

int main() {
    srand(time(NULL));

    add_event(2023, 1, 1, "New Year's Day");
    add_event(2023, 4, 7, "Easter Sunday");
    add_event(2023, 5, 29, "Memorial Day");
    add_event(2023, 7, 4, "Independence Day");
    add_event(2023, 9, 5, "Labor Day");
    add_event(2023, 11, 24, "Thanksgiving Day");
    add_event(2023, 12, 25, "Christmas Day");

    print_events();

    return 0;
}