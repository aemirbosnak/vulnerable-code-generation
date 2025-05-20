//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIME 1000000

typedef struct {
    time_t time;
    char *description;
} Event;

int main(void) {
    srand(time(NULL));

    Event events[MAX_EVENTS];
    int num_events = 0;

    printf("Welcome to the Time Travel Simulator!\n");

    while (num_events < MAX_EVENTS) {
        Event new_event;
        new_event.time = rand() % MAX_TIME;
        new_event.description = (char *)malloc(50 * sizeof(char));
        sprintf(new_event.description, "Event %d occurred at time %ld.", num_events + 1, new_event.time);
        events[num_events] = new_event;
        num_events++;
    }

    int target_event;
    printf("Enter the number of the event you want to travel to: ");
    scanf("%d", &target_event);

    if (target_event >= 1 && target_event <= num_events) {
        time_t target_time = events[target_event - 1].time;
        time_t current_time = time(NULL);

        if (target_time > current_time) {
            printf("You cannot travel to an event in the future.\n");
        } else {
            time_t elapsed_time = target_time - current_time;
            sleep(elapsed_time);

            printf("You have traveled back in time to event %d.\n", target_event);
        }
    } else {
        printf("Invalid event number.\n");
    }

    return 0;
}