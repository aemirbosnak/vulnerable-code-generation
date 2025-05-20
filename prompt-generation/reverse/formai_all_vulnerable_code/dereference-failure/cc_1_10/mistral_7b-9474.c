//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1

typedef struct {
    int year;
    char *event;
} event_t;

event_t events[] = {
    {1957, "Sputnik 1, the first artificial Earth satellite, is launched."},
    {1969, "Apollo 11 lands the first humans on the Moon."},
    {1981, "Space Shuttle Columbia is launched, starting the Space Shuttle program."},
    {1991, "Tim Berners-Lee proposes the World Wide Web."},
    {2007, "Apple introduces the iPhone."},
    {2020, "The COVID-19 pandemic spreads globally."},
};

void time_travel(int year) {
    int i;
    for (i = 0; i < sizeof(events) / sizeof(event_t); i++) {
        if (year == events[i].year) {
            printf("Year: %d\nEvent: %s\n", year, events[i].event);
            return;
        }
    }
    printf("Year: %d\nEvent: Unknown.\n", year);
}

void travel_back(int year) {
    if (year < MIN_YEAR || year > MAX_YEAR) {
        fprintf(stderr, "Error: Invalid year. Please enter a year between %d and %d.\n", MIN_YEAR, MAX_YEAR);
        return;
    }

    time_travel(year);
}

int main(int argc, char *argv[]) {
    int year;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <year>\n", argv[0]);
        return 1;
    }

    year = atoi(argv[1]);

    travel_back(year);

    return 0;
}