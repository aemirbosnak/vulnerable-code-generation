//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 10
#define MIN_TIME_TRAVELS 1

// Structure to store the time travel data
typedef struct TimeTravel {
    time_t departureTime;
    time_t arrivalTime;
    char destination[50];
} TimeTravel;

// Array to store the time travels
TimeTravel timeTravels[MAX_TIME_TRAVELS];

// Function to generate a random date
time_t generateRandomDate(time_t minDate, time_t maxDate) {
    return minDate + (rand() % (int)(maxDate - minDate + 1));
}

// Function to simulate time travel
void simulateTimeTravel() {
    // Generate a random number of time travels
    int numTimeTravels = MIN_TIME_TRAVELS + rand() % (MAX_TIME_TRAVELS - MIN_TIME_TRAVELS + 1);

    // Generate the time travels
    for (int i = 0; i < numTimeTravels; i++) {
        // Generate the departure time
        timeTravels[i].departureTime = generateRandomDate(0, time(NULL));

        // Generate the arrival time
        timeTravels[i].arrivalTime = generateRandomDate(timeTravels[i].departureTime, time(NULL));

        // Generate the destination
        int randDestination = rand() % 2;
        if (randDestination == 0) {
            strcpy(timeTravels[i].destination, "Past");
        } else {
            strcpy(timeTravels[i].destination, "Future");
        }
    }
}

// Function to print the time travels
void printTimeTravels() {
    for (int i = 0; i < MAX_TIME_TRAVELS; i++) {
        if (timeTravels[i].departureTime != 0) {
            printf("Time Travel %d:\n", i + 1);
            printf("\tDeparture Time: %s", ctime(&timeTravels[i].departureTime));
            printf("\tArrival Time: %s", ctime(&timeTravels[i].arrivalTime));
            printf("\tDestination: %s\n", timeTravels[i].destination);
        }
    }
}

int main() {
    srand(time(NULL));
    simulateTimeTravel();
    printTimeTravels();

    return 0;
}