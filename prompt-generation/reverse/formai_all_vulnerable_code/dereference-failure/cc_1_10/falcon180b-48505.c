//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Time travel simulation
void timeTravel(int year) {
    time_t currentTime;
    struct tm *travelTime;

    // Get the current time
    time(&currentTime);

    // Set the travel time to the given year
    travelTime = localtime(&currentTime);
    travelTime->tm_year = year - 1900;

    // Print the current and travel times
    printf("Current time: %s", asctime(travelTime));
    printf("Traveling to %d...\n", year);

    // Pause for effect
    sleep(1);
}

int main() {
    int choice, year;

    // Time travel options
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Choose a year to travel to:\n");
    printf("1. 1960s\n");
    printf("2. 1980s\n");
    printf("3. 2020s\n");
    printf("4. Custom year\n");

    // Get user choice
    scanf("%d", &choice);

    // Set the travel year based on user choice
    switch (choice) {
        case 1:
            year = 1960;
            break;
        case 2:
            year = 1980;
            break;
        case 3:
            year = 2020;
            break;
        default:
            printf("Enter a year to travel to: ");
            scanf("%d", &year);
            break;
    }

    // Time travel!
    timeTravel(year);

    return 0;
}