//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to store event information
typedef struct {
    int event_id;
    char event_name[100];
    int timestamp;
} Event;

// Function to log an event
void log_event(Event* event) {
    printf("Event %d: %s at %d\n", event->event_id, event->event_name, event->timestamp);
}

// Main function
int main() {
    Event* event1 = (Event*)malloc(sizeof(Event));
    Event* event2 = (Event*)malloc(sizeof(Event));

    srand(time(NULL));
    event1->event_id = rand() % 100;
    event1->event_name[0] = 'E';
    event1->event_name[1] = 'L';
    event1->event_name[2] = 'F';
    event1->event_name[3] = 'M';
    event1->event_name[4] = '\0';
    event1->timestamp = time(NULL);

    event2->event_id = rand() % 100;
    event2->event_name[0] = 'T';
    event2->event_name[1] = 'R';
    event2->event_name[2] = 'A';
    event2->event_name[3] = 'C';
    event2->event_name[4] = 'T';
    event2->event_name[5] = 'I';
    event2->event_name[6] = 'O';
    event2->event_name[7] = 'N';
    event2->event_name[8] = 'E';
    event2->event_name[9] = 'D';
    event2->event_name[10] = 'E';
    event2->event_name[11] = 'R';
    event2->event_name[12] = 'T';
    event2->event_name[13] = 'E';
    event2->event_name[14] = 'N';
    event2->event_name[15] = 'D';
    event2->event_name[16] = 'D';
    event2->event_name[17] = '\0';
    event2->timestamp = time(NULL);

    log_event(event1);
    log_event(event2);

    free(event1);
    free(event2);

    return 0;
}