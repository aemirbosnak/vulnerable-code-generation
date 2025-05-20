//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIPS 5

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char destination[50];
    char purpose[100];
} TimeTravelTrip;

void initializeTrip(TimeTravelTrip *trip) {
    // Get the current date
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    // Initialize the trip date to current date
    trip->date.year = current_time->tm_year + 1900; // tm_year is years since 1900
    trip->date.month = current_time->tm_mon + 1;    // tm_mon is months since January (0-11)
    trip->date.day = current_time->tm_mday;         // tm_mday is day of the month (1-31)
    
    // Initialize destination and purpose
    snprintf(trip->destination, sizeof(trip->destination), "Unknown Destination");
    snprintf(trip->purpose, sizeof(trip->purpose), "To explore time");
}

void displayTrip(const TimeTravelTrip *trip) {
    printf("Time Travel Trip Details:\n");
    printf("Date: %04d-%02d-%02d\n", trip->date.year, trip->date.month, trip->date.day);
    printf("Destination: %s\n", trip->destination);
    printf("Purpose: %s\n\n", trip->purpose);
}

void travelToDate(TimeTravelTrip *trip, int year, int month, int day, const char *destination, const char *purpose) {
    trip->date.year = year;
    trip->date.month = month;
    trip->date.day = day;
    
    snprintf(trip->destination, sizeof(trip->destination), "%s", destination);
    snprintf(trip->purpose, sizeof(trip->purpose), "%s", purpose);
}

void simulateTimeTravel(TimeTravelTrip *trips, int tripCount) {
    for (int i = 0; i < tripCount; i++) {
        printf("Simulating trip %d...\n", i + 1);
        displayTrip(&trips[i]);
    }
}

int main() {
    TimeTravelTrip trips[MAX_TRIPS];
    
    // Initialize trips
    for (int i = 0; i < MAX_TRIPS; i++) {
        initializeTrip(&trips[i]);
    }

    // Define some trips
    travelToDate(&trips[0], 2050, 12, 25, "Mars Colony", "Christmas Celebration");
    travelToDate(&trips[1], 1969, 7, 20, "Moon", "Witness the Apollo 11 landing");
    travelToDate(&trips[2], 1023, 10, 17, "Viking Village", "Experience the Viking lifestyle");
    travelToDate(&trips[3], 1776, 7, 4, "Philadelphia", "Join the signing of Declaration of Independence");
    travelToDate(&trips[4], 3000, 1, 1, "Utopia", "Explore a future society");

    // Simulate time travel
    printf("Welcome to the Time Travel Simulator!\n\n");
    simulateTimeTravel(trips, MAX_TRIPS);

    return 0;
}