//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct Event {
    int year;
    char description[100];
    struct Event *next;
} Event;

Event *head = NULL;

void addEvent(int year, char *description) {
    Event *newEvent = (Event *)malloc(sizeof(Event));
    newEvent->year = year;
    strcpy(newEvent->description, description);
    newEvent->next = head;
    head = newEvent;
}

void printTimeline() {
    Event *current = head;
    while (current != NULL) {
        printf("%d: %s\n", current->year, current->description);
        current = current->next;
    }
}

void travelBackInTime(int years) {
    int currentYear = time(NULL);
    int targetYear = currentYear - years;

    if (head == NULL || head->year > targetYear) {
        printf("Cannot travel back in time that far.\n");
        return;
    }

    Event *current = head;
    while (current != NULL && current->year > targetYear) {
        current = current->next;
    }

    if (current == NULL) {
        printf("An event with the given description does not exist before the targeted year.\n");
        return;
    }

    printf("Traveling back in time to %d...\n", current->year);

    // Change an event here
    strcpy(current->description, "New description");

    printf("Changing event description to: %s\n", current->description);

    // Update the timeline
    Event *temp = head;
    while (temp != NULL && temp != current) {
        temp = temp->next;
    }

    Event *previous = temp;
    previous->next = current->next;
    current->next = temp;

    printf("Timeline updated.\n");

    // Observe the effects on the present
    printTimeline();
}

int main() {
    addEvent(2022, "Building a Time Travel Simulator");
    addEvent(2023, "Testing the Time Travel Simulator");
    addEvent(2024, "Fixing bugs in the Time Travel Simulator");

    printTimeline();

    travelBackInTime(1);

    return 0;
}