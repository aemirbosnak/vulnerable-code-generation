//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for representing a bag
typedef struct {
    int weight;
    char owner[50];
} Bag;

// Structure for representing a flight
typedef struct {
    char flightNumber[10];
    char departureTime[50];
    char arrivalTime[50];
    int numBags;
    Bag* bags;
} Flight;

// Function to print a bag
void printBag(Bag* bag) {
    printf("Weight: %d\nOwner: %s\n", bag->weight, bag->owner);
}

// Function to add a bag to a flight
void addBag(Flight* flight, Bag* bag) {
    flight->bags = (Bag*)realloc(flight->bags, (flight->numBags + 1) * sizeof(Bag));
    flight->bags[flight->numBags++] = *bag;
}

// Function to handle the baggage for a flight
void handleBaggage(Flight* flight) {
    printf("Flight: %s\nDeparture Time: %s\nArrival Time: %s\n",
           flight->flightNumber, flight->departureTime, flight->arrivalTime);
    for (int i = 0; i < flight->numBags; i++) {
        printBag(&(flight->bags[i]));
    }
}

int main() {
    // Create a flight
    Flight flight1;
    strcpy(flight1.flightNumber, "Flight 1");
    strcpy(flight1.departureTime, "10:00 AM");
    strcpy(flight1.arrivalTime, "2:00 PM");
    flight1.numBags = 0;

    // Create a bag
    Bag bag1;
    bag1.weight = 20;
    strcpy(bag1.owner, "John Smith");

    // Add the bag to the flight
    addBag(&flight1, &bag1);

    // Print the flight details
    handleBaggage(&flight1);

    return 0;
}