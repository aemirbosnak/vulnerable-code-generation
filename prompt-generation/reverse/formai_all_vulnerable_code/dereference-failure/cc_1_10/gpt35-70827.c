//FormAI DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare the log struct to hold information about each event
struct EventLog {
    char *event_name;
    char *event_description;
    char *timestamp;
};

// Define the maximum number of events we can store
#define MAX_EVENTS 100000

// Declare the array of EventLog structs
struct EventLog events[MAX_EVENTS];

// Declare a variable to hold the current number of events
int num_events = 0;

// Function to add a new event to the log
void add_event(char *event_name, char *event_description) {
    
    // Make sure we don't exceed the maximum number of events
    if (num_events >= MAX_EVENTS) {
        printf("Error: maximum number of events exceeded\n");
        return;
    }
    
    // Get the current time as a string
    time_t current_time;
    current_time = time(NULL);
    char *timestamp = ctime(&current_time);
    
    // Allocate memory for the new event
    events[num_events].event_name = malloc(sizeof(char) * strlen(event_name) + 1);
    events[num_events].event_description = malloc(sizeof(char) * strlen(event_description) + 1);
    events[num_events].timestamp = malloc(sizeof(char) * strlen(timestamp) + 1);
    
    // Copy the event name, description, and timestamp to the new event
    strcpy(events[num_events].event_name, event_name);
    strcpy(events[num_events].event_description, event_description);
    strcpy(events[num_events].timestamp, timestamp);
    
    // Increment the number of events
    num_events++;
}

// Function to print a header for the log
void print_header() {
    printf("\n------------------------------------------------\n");
    printf("%-20s %-20s %-50s\n", "Timestamp", "Event Name", "Event Description");
    printf("------------------------------------------------\n");
}

// Function to print a single event
void print_event(int i) {
    printf("%-20s %-20s %-50s\n", events[i].timestamp, events[i].event_name, events[i].event_description);
}

// Function to print the entire log
void print_log() {
    // Print the header
    print_header();
    
    // Print each event
    for (int i = 0; i < num_events; i++) {
        print_event(i);
    }
}

int main() {
    // Add some events to the log
    add_event("System Startup", "The system was successfully started.");
    add_event("Server Connection", "The server connection was established.");
    add_event("Failed Login Attempt", "An invalid login attempt was made.");
    
    // Print the log
    print_log();
    
    // Exit the program
    return 0;
}