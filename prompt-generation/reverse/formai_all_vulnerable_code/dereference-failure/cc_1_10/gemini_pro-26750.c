//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of time travel events
#define MAX_EVENTS 100

// Define the maximum number of years that can be travelled
#define MAX_YEARS 100

// Define the structure of a time travel event
typedef struct {
    int year;
    char *description;
} TimeTravelEvent;

// Global array of time travel events
TimeTravelEvent events[MAX_EVENTS];

// Global index of the current event
int currentEvent = 0;

// Function to add a new time travel event
void addEvent(int year, char *description) {
    // Check if the event array is full
    if (currentEvent == MAX_EVENTS) {
        printf("Error: The event array is full.\n");
        return;
    }

    // Check if the year is valid
    if (year < 1900 || year > 2100) {
        printf("Error: The year is invalid.\n");
        return;
    }

    // Add the event to the array
    events[currentEvent].year = year;
    events[currentEvent].description = description;

    // Increment the current event index
    currentEvent++;
}

// Function to simulate time travel
void simulateTimeTravel() {
    // Get the current time
    time_t now = time(NULL);

    // Convert the current time to a tm struct
    struct tm *nowtm = localtime(&now);

    // Get the year from the tm struct
    int currentYear = nowtm->tm_year + 1900;

    // Loop through the time travel events
    for (int i = 0; i < currentEvent; i++) {
        // If the current year is equal to the year of the event
        if (currentYear == events[i].year) {
            // Print the event description
            printf("%s\n", events[i].description);
        }
    }
}

// Main function
int main() {
    // Add some time travel events
    addEvent(1955, "Marty McFly travels back to 1955");
    addEvent(1985, "Marty McFly travels back to 1985");
    addEvent(2015, "Doc Brown travels to 2015");

    // Simulate time travel
    simulateTimeTravel();

    return 0;
}