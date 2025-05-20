//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a time traveler
typedef struct {
    int year;  // Year of birth
    int month; // Month of birth (1-12)
    int day;   // Day of birth (1-31)
    char *name; // Name of the time traveler
} TimeTraveler;

// Function to create a new time traveler
TimeTraveler *create_time_traveler(int year, int month, int day, char *name) {
    TimeTraveler *time_traveler = malloc(sizeof(TimeTraveler));
    time_traveler->year = year;
    time_traveler->month = month;
    time_traveler->day = day;
    time_traveler->name = name;
    return time_traveler;
}

// Function to print the time traveler's information
void print_time_traveler(TimeTraveler *time_traveler) {
    printf("Name: %s\n", time_traveler->name);
    printf("Year of birth: %d\n", time_traveler->year);
    printf("Month of birth: %d\n", time_traveler->month);
    printf("Day of birth: %d\n", time_traveler->day);
}

// Function to travel through time
void travel_through_time(TimeTraveler *time_traveler, int year) {
    time_traveler->year = year;
    printf("Time traveler %s has traveled to the year %d.\n", time_traveler->name, time_traveler->year);
}

// Main function
int main() {
    // Create a new time traveler
    TimeTraveler *time_traveler = create_time_traveler(1980, 12, 25, "John Doe");

    // Print the time traveler's information
    print_time_traveler(time_traveler);

    // Travel through time
    travel_through_time(time_traveler, 2023);

    // Print the time traveler's information again
    print_time_traveler(time_traveler);

    return 0;
}