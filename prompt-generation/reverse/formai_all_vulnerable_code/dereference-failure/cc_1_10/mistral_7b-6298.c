//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Event {
    int year;
    int month;
    int day;
    char description[100];
    struct Event *next;
} Event;

Event *head = NULL;
int max_travel_days = 30;

void add_event(int year, int month, int day, char *description) {
    Event *new_event = (Event *)malloc(sizeof(Event));
    new_event->year = year;
    new_event->month = month;
    new_event->day = day;
    strcpy(new_event->description, description);
    new_event->next = head;
    head = new_event;
}

void travel_back_in_time() {
    Event *current = head;
    int days_to_travel = 1;

    if (head == NULL) {
        printf("No past events to travel back to.\n");
        return;
    }

    printf("Current event: %d-%02d-%02d %s\n", current->year, current->month, current->day, current->description);

    while (current != NULL && days_to_travel <= max_travel_days) {
        printf("Traveling back %d days to %d-%02d-%02d %s\n", days_to_travel, current->year, current->month, current->day, current->description);
        days_to_travel++;
        current = current->next;
    }

    if (current == NULL) {
        printf("Maximum travel limit reached.\n");
    } else {
        printf("Current event: %d-%02d-%02d %s\n", current->year, current->month, current->day, current->description);
    }
}

int main() {
    int choice;
    char description[100];

    add_event(2022, 12, 31, "New Year's Eve");
    add_event(2022, 12, 25, "Christmas Day");

    while (1) {
        printf("\nTime Travel Simulator\n");
        printf("1. Travel back in time\n");
        printf("2. Add new event\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travel_back_in_time();
                break;
            case 2:
                printf("Enter year: ");
                scanf("%d", &description[0]);
                description[2] = '-';
                scanf("%d", &description[3]);
                description[5] = '-';
                scanf("%d", &description[6]);
                printf("Enter event description: ");
                scanf("%s", &description[11]);
                add_event(description[0], description[3], description[6], description + 11);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}