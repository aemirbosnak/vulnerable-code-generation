//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
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

typedef struct {
    Event *events;
    int num_events;
} Timeline;

Timeline *create_timeline(int num_events) {
    Timeline *timeline = malloc(sizeof(Timeline));
    timeline->events = malloc(sizeof(Event) * num_events);
    timeline->num_events = num_events;
    return timeline;
}

void destroy_timeline(Timeline *timeline) {
    free(timeline->events);
    free(timeline);
}

void print_timeline(Timeline *timeline) {
    for (int i = 0; i < timeline->num_events; i++) {
        Event *event = &timeline->events[i];
        printf("%d-%d-%d: %s\n", event->date.year, event->date.month, event->date.day, event->description);
    }
}

void add_event(Timeline *timeline, Date date, char *description) {
    Event *event = &timeline->events[timeline->num_events];
    event->date = date;
    event->description = description;
    timeline->num_events++;
}

void travel_to_past(Timeline *timeline, Date date) {
    if (date.year < timeline->events[0].date.year) {
        printf("Cannot travel to a date before the beginning of the timeline.\n");
        return;
    }

    for (int i = 0; i < timeline->num_events; i++) {
        Event *event = &timeline->events[i];
        if (date.year == event->date.year && date.month == event->date.month && date.day == event->date.day) {
            printf("You have traveled to %d-%d-%d.\n", date.year, date.month, date.day);
            printf("Description: %s\n", event->description);
            return;
        }
    }

    printf("No event found on that date.\n");
}

void travel_to_future(Timeline *timeline, Date date) {
    if (date.year > timeline->events[timeline->num_events - 1].date.year) {
        printf("Cannot travel to a date after the end of the timeline.\n");
        return;
    }

    for (int i = timeline->num_events - 1; i >= 0; i--) {
        Event *event = &timeline->events[i];
        if (date.year == event->date.year && date.month == event->date.month && date.day == event->date.day) {
            printf("You have traveled to %d-%d-%d.\n", date.year, date.month, date.day);
            printf("Description: %s\n", event->description);
            return;
        }
    }

    printf("No event found on that date.\n");
}

int main() {
    Timeline *timeline = create_timeline(5);

    add_event(timeline, (Date){1985, 1, 1}, "I was born.");
    add_event(timeline, (Date){2001, 9, 11}, "9/11 attacks.");
    add_event(timeline, (Date){2008, 8, 8}, "Beijing Olympics.");
    add_event(timeline, (Date){2016, 11, 8}, "Donald Trump elected president.");
    add_event(timeline, (Date){2020, 1, 20}, "COVID-19 pandemic begins.");

    print_timeline(timeline);

    Date date;
    printf("Enter a date to travel to (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &date.year, &date.month, &date.day);

    if (date.year < timeline->events[0].date.year) {
        travel_to_past(timeline, date);
    } else if (date.year > timeline->events[timeline->num_events - 1].date.year) {
        travel_to_future(timeline, date);
    } else {
        printf("Invalid date.\n");
    }

    destroy_timeline(timeline);
    return 0;
}