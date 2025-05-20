//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events that can be simulated
#define MAX_EVENTS 100

// Define the structure of an event
typedef struct event {
    int year;
    int month;
    int day;
    char description[100];
} event;

// Declare an array of events
event events[MAX_EVENTS];

// Initialize the number of events to 0
int num_events = 0;

// Function to add an event to the array
void add_event(int year, int month, int day, char* description) {
    // Check if the array is full
    if (num_events == MAX_EVENTS) {
        printf("Error: The array of events is full.\n");
        return;
    }

    // Add the event to the array
    events[num_events].year = year;
    events[num_events].month = month;
    events[num_events].day = day;
    strcpy(events[num_events].description, description);

    // Increment the number of events
    num_events++;
}

// Function to print the events in the array
void print_events() {
    // Loop through the array of events
    for (int i = 0; i < num_events; i++) {
        // Print the event
        printf("%d-%d-%d: %s\n", events[i].year, events[i].month, events[i].day, events[i].description);
    }
}

// Function to simulate time travel
void time_travel(int year, int month, int day) {
    // Check if the year is valid
    if (year < 1900 || year > 2100) {
        printf("Error: The year is invalid.\n");
        return;
    }

    // Check if the month is valid
    if (month < 1 || month > 12) {
        printf("Error: The month is invalid.\n");
        return;
    }

    // Check if the day is valid
    if (day < 1 || day > 31) {
        printf("Error: The day is invalid.\n");
        return;
    }

    // Set the current time to the specified time
    time_t current_time = time(NULL);
    struct tm *current_tm = localtime(&current_time);
    current_tm->tm_year = year - 1900;
    current_tm->tm_mon = month - 1;
    current_tm->tm_mday = day;
    current_time = mktime(current_tm);

    // Print the current time
    printf("Current time: %s\n", ctime(&current_time));
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Add some random events to the array
    for (int i = 0; i < 10; i++) {
        // Generate a random year, month, and day
        int year = rand() % 100 + 1900;
        int month = rand() % 12 + 1;
        int day = rand() % 31 + 1;

        // Generate a random description
        char description[100];
        sprintf(description, "Event %d", i + 1);

        // Add the event to the array
        add_event(year, month, day, description);
    }

    // Print the events
    print_events();

    // Simulate time travel to a random event
    int event_index = rand() % num_events;
    time_travel(events[event_index].year, events[event_index].month, events[event_index].day);

    return 0;
}