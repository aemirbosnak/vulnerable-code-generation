//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of time jumps
#define MAX_JUMPS 10

// Define the minimum and maximum years for time jumps
#define MIN_YEAR 1900
#define MAX_YEAR 2100

// Define the array of historical events and their years
const char* events[] = {
    "The Wright brothers fly the first airplane (1903)",
    "World War I begins (1914)",
    "The Great Depression begins (1929)",
    "World War II begins (1939)",
    "The United States drops an atomic bomb on Hiroshima (1945)",
    "The United States lands a man on the moon (1969)",
    "The Berlin Wall falls (1989)",
    "The internet is invented (1991)",
    "The 9/11 attacks occur (2001)",
    "The first iPhone is released (2007)",
};

// Generate a random year between the minimum and maximum years
int generate_random_year() {
    return (rand() % (MAX_YEAR - MIN_YEAR + 1)) + MIN_YEAR;
}

// Print the current time and the list of historical events
void print_time_and_events(time_t t, int year) {
    printf("Current time: %s\n", ctime(&t));
    printf("Historical events:\n");
    for (int i = 0; i < 10; i++) {
        if (events[i][year] != '\0') {
            printf("%s\n", events[i][year]);
        }
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the current time
    time_t t = time(NULL);

    // Print the current time and the list of historical events
    print_time_and_events(t, 1970);

    // Loop through the maximum number of time jumps
    for (int i = 0; i < MAX_JUMPS; i++) {
        // Generate a random year
        int year = generate_random_year();
        printf("Time jump to %d\n", year);
        t += (year - 1970) * 31556926;
        print_time_and_events(t, year);
        printf("\n");
    }

    return 0;
}