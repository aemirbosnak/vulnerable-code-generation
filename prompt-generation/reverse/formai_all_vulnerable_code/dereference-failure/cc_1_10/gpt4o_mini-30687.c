//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FLIGHTS 5
#define MAX_BAGS_PER_FLIGHT 10
#define MAX_STRING_SIZE 20

typedef struct Bag {
    int bagId;
    char passengerName[MAX_STRING_SIZE];
    struct Bag *next;
} Bag;

typedef struct Flight {
    int flightId;
    char flightName[MAX_STRING_SIZE];
    Bag *bags;
    struct Flight *next;
} Flight;

Flight *flights = NULL;

void addFlight(int flightId, const char *flightName) {
    Flight *newFlight = (Flight *)malloc(sizeof(Flight));
    newFlight->flightId = flightId;
    strcpy(newFlight->flightName, flightName);
    newFlight->bags = NULL;
    newFlight->next = flights;
    flights = newFlight;
}

void addBag(int flightId, int bagId, const char *passengerName) {
    Flight *current = flights;
    while (current) {
        if (current->flightId == flightId) {
            Bag *newBag = (Bag *)malloc(sizeof(Bag));
            newBag->bagId = bagId;
            strcpy(newBag->passengerName, passengerName);
            newBag->next = current->bags;
            current->bags = newBag;
            printf("Added bag %d for %s to flight %d (%s)\n", bagId, passengerName, flightId, current->flightName);
            return;
        }
        current = current->next;
    }
    printf("Flight %d not found!\n", flightId);
}

void unloadBags(int flightId) {
    Flight *current = flights;
    while (current) {
        if (current->flightId == flightId) {
            printf("Unloading bags for flight %d (%s)\n", flightId, current->flightName);
            Bag *bagCurrent = current->bags;
            while (bagCurrent) {
                printf("Unloaded bag ID: %d for passenger: %s\n", bagCurrent->bagId, bagCurrent->passengerName);
                Bag *temp = bagCurrent;
                bagCurrent = bagCurrent->next;
                free(temp);
            }
            current->bags = NULL; // Resetting bag list
            return;
        }
        current = current->next;
    }
    printf("Flight %d not found for unloading!\n", flightId);
}

void displayFlights() {
    Flight *current = flights;
    printf("\nAvailable Flights:\n");
    while (current) {
        printf("Flight ID: %d, Flight Name: %s\n", current->flightId, current->flightName);
        current = current->next;
    }
}

void freeFlights() {
    Flight *current = flights;
    while (current) {
        Bag *bagCurrent = current->bags;
        while (bagCurrent) {
            Bag *temp = bagCurrent;
            bagCurrent = bagCurrent->next;
            free(temp);
        }
        Flight *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    addFlight(101, "Flight A");
    addFlight(102, "Flight B");
    addFlight(103, "Flight C");

    addBag(101, 1, "Alice");
    addBag(101, 2, "Bob");
    addBag(102, 3, "Charlie");
    addBag(103, 4, "David");
    addBag(102, 5, "Eve");

    displayFlights();

    close:
    unloadBags(101);
    unloadBags(102);
    unloadBags(103);

    freeFlights();
    printf("All baggage handled and cleared. Exiting system.\n");
    
    return 0;
}