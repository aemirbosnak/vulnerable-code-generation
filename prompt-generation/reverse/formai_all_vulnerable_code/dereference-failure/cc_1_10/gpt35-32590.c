//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Maximum arrival and departure times for each flight
#define MAX_ARRIVAL_TIME 360
#define MAX_DEPARTURE_TIME 1440

// Struct for each baggage
typedef struct {
    int weight;
    char destination[4];
} Baggage;

// Struct for each passenger
typedef struct {
    int flightNum;
    int arrivalTime;
    int departureTime;
    int baggageCount;
    Baggage *baggageList;
} Passenger;

// Struct for each conveyor belt
typedef struct {
    int capacity;
    Baggage *baggageList;
} ConveyorBelt;

// Function to generate a random number between min and max
int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // Set the random number generator seed to current time

    // User input for number of passengers and conveyor belt capacity
    int numPassengers, conveyorCapacity;
    printf("Enter the number of passengers: ");
    scanf("%d", &numPassengers);
    printf("Enter the conveyor belt capacity: ");
    scanf("%d", &conveyorCapacity);

    // Allocate memory for the passenger list
    Passenger *passengerList = (Passenger *) malloc(sizeof(Passenger) * numPassengers);

    // Generate random flight numbers and arrival/departure times for each passenger
    for (int i = 0; i < numPassengers; i++) {
        passengerList[i].flightNum = generateRandom(100, 999);
        passengerList[i].arrivalTime = generateRandom(0, MAX_ARRIVAL_TIME);
        passengerList[i].departureTime = generateRandom(passengerList[i].arrivalTime, MAX_DEPARTURE_TIME);
    }

    // Allocate memory for baggage lists for each passenger and generate random baggage
    for (int i = 0; i < numPassengers; i++) {
        passengerList[i].baggageCount = generateRandom(1, 3);
        passengerList[i].baggageList = (Baggage *) malloc(sizeof(Baggage) * passengerList[i].baggageCount);
        for (int j = 0; j < passengerList[i].baggageCount; j++) {
            passengerList[i].baggageList[j].weight = generateRandom(20, 50);
            sprintf(passengerList[i].baggageList[j].destination, "%c%c%c", generateRandom(65, 90), generateRandom(65, 90), generateRandom(65, 90));
        }
    }

    // Initialize the conveyor belt with given capacity
    ConveyorBelt conveyor;
    conveyor.capacity = conveyorCapacity;
    conveyor.baggageList = (Baggage *) malloc(sizeof(Baggage) * conveyorCapacity);
    int conveyorCount = 0;

    // Iterate from 0 to the maximum departure time to simulate each minute
    for (int i = 0; i <= MAX_DEPARTURE_TIME; i++) {
        printf("\nTime: %02d:%02d\n", i / 60, i % 60);

        // Add any passenger bags that have arrived and fit on the conveyor belt
        for (int j = 0; j < numPassengers; j++) {
            if (passengerList[j].arrivalTime == i) {
                for (int k = 0; k < passengerList[j].baggageCount; k++) {
                    if (conveyorCount < conveyor.capacity) {
                        conveyor.baggageList[conveyorCount++] = passengerList[j].baggageList[k];
                        printf("Baggage for Flight %d added to conveyor belt\n", passengerList[j].flightNum);
                    } else {
                        printf("Conveyor belt is full, baggage for Flight %d could not be added\n", passengerList[j].flightNum);
                    }
                }
            }
        }

        // Remove any bags that have reached their destination and print the weight and destination
        int removeCount = 0;
        for (int j = 0; j < conveyorCount; j++) {
            if (conveyor.baggageList[j].destination[0] == 'D' && conveyor.baggageList[j].destination[1] == 'E' && conveyor.baggageList[j].destination[2] == 'L') {
                printf("Baggage of weight %d kg has reached its destination of DEL\n", conveyor.baggageList[j].weight);
                removeCount++;
            }
        }
        conveyorCount -= removeCount;

        // Shift the remaining bags on the conveyor belt one space to the left
        for (int j = 0; j < conveyorCount - 1; j++) {
            conveyor.baggageList[j] = conveyor.baggageList[j + 1];
        }
        conveyorCount--;
    }

    // Free allocated memory
    for (int i = 0; i < numPassengers; i++) {
        free(passengerList[i].baggageList);
    }
    free(passengerList);
    free(conveyor.baggageList);

    return 0;
}