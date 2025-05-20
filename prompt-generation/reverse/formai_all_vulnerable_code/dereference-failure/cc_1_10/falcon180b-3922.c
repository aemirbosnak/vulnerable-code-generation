//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    char *description;
} Event;

int main() {
    srand(time(NULL));
    int num_events = rand() % MAX_EVENTS + 1;
    Event events[MAX_EVENTS];

    for (int i = 0; i < num_events; i++) {
        events[i].time = rand() % 1000;
        char *desc = malloc(100 * sizeof(char));
        sprintf(desc, "Event %d", i + 1);
        events[i].description = desc;
    }

    int choice;
    do {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("You have %d events to attend.\n", num_events);
        printf("Enter your choice:\n");
        printf("1. Attend an event\n");
        printf("2. Travel back in time\n");
        printf("3. Travel forward in time\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Which event would you like to attend?\n");
                for (int i = 0; i < num_events; i++) {
                    printf("%d. %s\n", i + 1, events[i].description);
                }
                scanf("%d", &choice);
                if (choice >= 1 && choice <= num_events) {
                    printf("You are now attending Event %s.\n", events[choice - 1].description);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 2:
                printf("How far back in time would you like to travel?\n");
                scanf("%d", &choice);
                time_t new_time = events[0].time - choice;
                struct tm *travel_time = localtime(&new_time);
                printf("You have traveled back in time to %s.\n", asctime(travel_time));
                break;
            case 3:
                printf("How far forward in time would you like to travel?\n");
                scanf("%d", &choice);
                time_t new_time2 = events[0].time + choice;
                struct tm *travel_time2 = localtime(&new_time2);
                printf("You have traveled forward in time to %s.\n", asctime(travel_time2));
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}