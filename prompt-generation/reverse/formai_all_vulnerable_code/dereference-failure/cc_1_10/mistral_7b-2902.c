//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_TIME 1000000000000LL
#define TIME_INCREMENT 1000000000LL

typedef struct {
    char name[32];
    int age;
    char event[128];
} TimeEvent;

void print_event(const TimeEvent *event) {
    printf("%s (%ld years old): %s\n", event->name, event->age, event->event);
}

void travel_back_in_time(long int time, TimeEvent *buffer) {
    long int current_time = time;
    long int next_time;
    int index = 0;

    while (current_time > 0 && index < 10) {
        next_time = current_time - TIME_INCREMENT;

        TimeEvent *event = malloc(sizeof(TimeEvent));
        strcpy(event->name, "Unknown");
        event->age = 0;
        strcpy(event->event, "");

        if (asctime(localtime(&next_time))[0] != '\n') {
            strcpy(event->name, ctime(&next_time));
            event->age = (int) ((current_time - next_time) / (long int) (365.25 * 24 * 60 * 60 * 1000));
            strcpy(event->event, "Born");
        } else {
            strcpy(event->event, "Unknown event occurred");
        }

        buffer[index++] = *event;
        current_time = next_time;
    }

    if (index == 0) {
        printf("Could not find any event within the given time range.\n");
    } else {
        for (int i = index - 1; i >= 0; i--) {
            print_event(&buffer[i]);
        }
    }

    for (int i = 0; i < index; i++) {
        free(buffer + i);
    }
}

int main() {
    long int target_time = 1492000000000LL; // Year 1492
    TimeEvent buffer[10];

    printf("Traveling back in time to %ld...\n", target_time);
    travel_back_in_time(target_time, buffer);

    return 0;
}