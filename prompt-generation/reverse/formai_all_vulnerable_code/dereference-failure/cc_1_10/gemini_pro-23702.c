//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_START_TIME 1000000000
#define MAX_EVENT_END_TIME 2000000000

// A single event with start/end times and a descriptive string
typedef struct event_t {
    int start_time;
    int end_time;
    char* description;
} event_t;

// A linked list of events
typedef struct event_list_t {
    event_t* event;
    struct event_list_t* next;
} event_list_t;

// A function to generate a random event
event_t* generate_random_event() {
    event_t* event = malloc(sizeof(event_t));
    event->start_time = rand() % MAX_EVENT_START_TIME;
    event->end_time = rand() % MAX_EVENT_END_TIME;
    event->description = malloc(100);
    sprintf(event->description, "Event %d", rand() % 100);
    return event;
}

// A function to add an event to the event list
void add_event_to_list(event_list_t** list, event_t* event) {
    event_list_t* new_node = malloc(sizeof(event_list_t));
    new_node->event = event;
    new_node->next = *list;
    *list = new_node;
}

// A function to print the event list
void print_event_list(event_list_t* list) {
    while (list != NULL) {
        printf("%s: %d - %d\n", list->event->description, list->event->start_time, list->event->end_time);
        list = list->next;
    }
}

//A function to simulate traveling to a specific time
void travel_to_time(event_list_t* list, int time) {
    event_list_t* current = list;
    while (current != NULL) {
        if (current->event->start_time <= time && current->event->end_time >=time) {
            printf("You have traveled to %d and are currently experiencing the event: %s\n",time, current->event->description);
            return;
        }
        current = current->next;
    }
    printf("You cannot travel to that time. No events are happening at that time.\n");
}

// A function to free the memory allocated for the event list
void free_event_list(event_list_t* list) {
    while (list != NULL) {
        event_list_t* next = list->next;
        free(list->event->description);
        free(list->event);
        free(list);
        list = next;
    }
}

int main() {
    event_list_t* event_list = NULL;

    // Generate 100 random events
    for (int i = 0; i < MAX_EVENTS; i++) {
        event_t* event = generate_random_event();
        add_event_to_list(&event_list, event);
    }

    // Print the event list
    printf("Original Event List:\n");
    print_event_list(event_list);

    // Simulate traveling to a specific time
    int travel_time = 1500000000;
    printf("\nTraveling to time %d\n", travel_time);
    travel_to_time(event_list,travel_time);
    
    // Free the memory allocated for the event list
    free_event_list(event_list);

    return 0;
}