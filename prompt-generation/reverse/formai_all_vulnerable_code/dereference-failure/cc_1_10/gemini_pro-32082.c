//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 10

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char *description;
} TimeTravelEvent;

TimeTravelEvent *timeTravelEvents[MAX_TIME_TRAVELS];

int numTimeTravelEvents = 0;

void addTimeTravelEvent(int year, int month, int day, char *description) {
    if (numTimeTravelEvents >= MAX_TIME_TRAVELS) {
        printf("Error: too many time travel events.\n");
        return;
    }

    TimeTravelEvent *event = malloc(sizeof(TimeTravelEvent));
    event->date.year = year;
    event->date.month = month;
    event->date.day = day;
    event->description = description;

    timeTravelEvents[numTimeTravelEvents] = event;
    numTimeTravelEvents++;
}

void printTimeTravelEvents() {
    for (int i = 0; i < numTimeTravelEvents; i++) {
        TimeTravelEvent *event = timeTravelEvents[i];
        printf("%d-%d-%d: %s\n", event->date.year, event->date.month, event->date.day, event->description);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Add some random time travel events
    addTimeTravelEvent(1955, 11, 12, "Met Elvis Presley");
    addTimeTravelEvent(1969, 7, 20, "Attended the moon landing");
    addTimeTravelEvent(1985, 10, 26, "Saw the Berlin Wall fall");
    addTimeTravelEvent(2001, 9, 11, "Witnessed the 9/11 attacks");
    addTimeTravelEvent(2020, 3, 13, "Declared a pandemic");

    // Print the time travel events
    printTimeTravelEvents();

    return 0;
}