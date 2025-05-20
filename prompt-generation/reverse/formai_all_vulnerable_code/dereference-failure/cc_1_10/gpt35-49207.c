//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_BAGS 1000 // Maximum number of bags allowed in the system

typedef struct Baggage {
    int id;             // Unique identifier for each bag
    int weight;         // Weight of the bag in kgs
    bool isArrival;     // True if the bag is being sent from arrivals, false if from departures
} Baggage;

typedef struct EntryStation {
    int id;             // Unique identifier for each entry station
    int capacity;       // Maximum number of bags that can be held in the station at one time
    Baggage *station;   // Array of bags currently in the station
    int numBags;        // Current number of bags in the station
} EntryStation;

typedef struct Conveyor {
    int id;             // Unique identifier for each conveyor
    int speed;          // Speed of the conveyor belt in meters per second
    EntryStation *from; // Entry station that the conveyor is connected to
    EntryStation *to;   // Entry station that the conveyor is sending bags to
    int *conveyorBags;  // Array of bags currently on the conveyor belt
    int numBags;        // Current number of bags on the conveyor belt
} Conveyor;

typedef struct ExitStation {
    int id;             // Unique identifier for each exit station
    EntryStation *from; // Entry station that the exit station is connected to
    int *exitBags;      // Array of bags that have reached the exit station
    int numBags;        // Current number of bags that have reached the exit station
} ExitStation;

void initializeStations(EntryStation **, int);
void initializeConveyors(Conveyor **, int, EntryStation **);
void initializeExitStations(ExitStation **, int, EntryStation **);
void initializeBags(Baggage **, int);
void assignBagsToEntryStation(EntryStation **, Baggage **, int);
bool sendBagOnConveyor(int, Conveyor **, int);
void sendBagsFromEntryStationToConveyor(Conveyor **, int, EntryStation *);
void sendBagsFromConveyorToExitStation(Conveyor **, int, ExitStation *);
void removeBagFromStation(Baggage *, int *);
void removeBagFromConveyor(int, Conveyor *);
void printReport(EntryStation **, Conveyor **, ExitStation **, int, int, int);

int main() {
    int numEntryStations = 2;
    int numConveyors = 1;
    int numExitStations = 2;
    int numBags = 10;

    // Initialize entry stations, conveyors, exit stations, and bags
    EntryStation **entryStations = malloc(numEntryStations * sizeof(EntryStation *));
    initializeStations(entryStations, numEntryStations);
    
    Conveyor **conveyors = malloc(numConveyors * sizeof(Conveyor *));
    initializeConveyors(conveyors, numConveyors, entryStations);
    
    ExitStation **exitStations = malloc(numExitStations * sizeof(ExitStation *));
    initializeExitStations(exitStations, numExitStations, entryStations);
    
    Baggage **bags = malloc(numBags * sizeof(Baggage *));
    initializeBags(bags, numBags);
    
    // Assign bags to entry stations
    assignBagsToEntryStation(entryStations, bags, numBags);
    
    // Send bags from entry stations to conveyors continuously for 60 seconds
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < numEntryStations; j++) {
            sendBagsFromEntryStationToConveyor(conveyors, numConveyors, entryStations[j]);
        }
        sleep(1);
    }
    
    // Send bags from conveyors to exit stations continuously for 60 seconds
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < numConveyors; j++) {
            sendBagsFromConveyorToExitStation(conveyors, numConveyors, exitStations[j]);
        }
        sleep(1);
    }
    
    // Print a final report to show the status of each station
    printReport(entryStations, conveyors, exitStations, numEntryStations, numConveyors, numExitStations);
    
    // Free all memory allocated for stations and bags
    for (int i = 0; i < numEntryStations; i++) {
        free(entryStations[i]->station);
        free(entryStations[i]);
    }
    free(entryStations);
    
    for (int i = 0; i < numConveyors; i++) {
        free(conveyors[i]->conveyorBags);
        free(conveyors[i]);
    }
    free(conveyors);
    
    for (int i = 0; i < numExitStations; i++) {
        free(exitStations[i]->exitBags);
        free(exitStations[i]);
    }
    free(exitStations);
    
    for (int i = 0; i < numBags; i++) {
        free(bags[i]);
    }
    free(bags);
    
    return 0;
}

// Initialize each entry station with a default capacity of 5 bags
void initializeStations(EntryStation **entryStations, int numStations) {
    for (int i = 0; i < numStations; i++) {
        entryStations[i] = malloc(sizeof(EntryStation));
        entryStations[i]->id = i;
        entryStations[i]->capacity = 5;
        entryStations[i]->station = malloc(entryStations[i]->capacity * sizeof(Baggage));
        entryStations[i]->numBags = 0;
    }
}

// Initialize each conveyor with a default speed of 1 m/s and connect it to two entry stations
void initializeConveyors(Conveyor **conveyors, int numConveyors, EntryStation **entryStations) {
    for (int i = 0; i < numConveyors; i++) {
        conveyors[i] = malloc(sizeof(Conveyor));
        conveyors[i]->id = i;
        conveyors[i]->speed = 1;
        conveyors[i]->from = entryStations[i % 2];
        conveyors[i]->to = entryStations[(i % 2) + 1];
        conveyors[i]->conveyorBags = malloc(MAX_BAGS * sizeof(int));
        conveyors[i]->numBags = 0;
    }
}

// Initialize each exit station and connect it to one entry station
void initializeExitStations(ExitStation **exitStations, int numStations, EntryStation **entryStations) {
    for (int i = 0; i < numStations; i++) {
        exitStations[i] = malloc(sizeof(ExitStation));
        exitStations[i]->id = i;
        exitStations[i]->from = entryStations[i % 2];
        exitStations[i]->exitBags = malloc(MAX_BAGS * sizeof(int));
        exitStations[i]->numBags = 0;
    }
}

// Initialize each bag with a random weight and assign it a unique identifier
void initializeBags(Baggage **bags, int numBags) {
    for (int i = 0; i < numBags; i++) {
        bags[i] = malloc(sizeof(Baggage));
        bags[i]->id = i;
        bags[i]->weight = rand() % 20 + 1;
        bags[i]->isArrival = rand() % 2 == 0 ? true : false;
    }
}

// Assign bags to each entry station randomly
void assignBagsToEntryStation(EntryStation **entryStations, Baggage **bags, int numBags) {
    for (int i = 0; i < numBags; i++) {
        int randomStation = rand() % 2;
        if (entryStations[randomStation]->numBags < entryStations[randomStation]->capacity) {
            entryStations[randomStation]->station[entryStations[randomStation]->numBags] = *bags[i];
            entryStations[randomStation]->numBags++;
        }
    }
}

// Send a bag from an entry station to a conveyor if possible
bool sendBagOnConveyor(int bagIndex, Conveyor **conveyors, int numConveyors) {
    for (int i = 0; i < numConveyors; i++) {
        if (conveyors[i]->numBags < MAX_BAGS && conveyors[i]->from->numBags > 0) {
            conveyors[i]->conveyorBags[conveyors[i]->numBags] = conveyors[i]->from->station[bagIndex].id;
            conveyors[i]->numBags++;
            removeBagFromStation(conveyors[i]->from->station, &(conveyors[i]->from->numBags));
            return true;
        }
    }
    return false;
}

// Send all bags from an entry station to the appropriate conveyor
void sendBagsFromEntryStationToConveyor(Conveyor **conveyors, int numConveyors, EntryStation *entryStation) {
    int originalNumBags = entryStation->numBags;
    for (int i = 0; i < originalNumBags;) {
        if (!sendBagOnConveyor(i, conveyors, numConveyors)) {
            i++;
        }
    }
}

// Send a bag from a conveyor to an exit station if possible
void sendBagsFromConveyorToExitStation(Conveyor **conveyors, int numConveyors, ExitStation *exitStation) {
    for (int i = 0; i < numConveyors; i++) {
        if (conveyors[i]->to == exitStation->from && conveyors[i]->numBags > 0 && exitStation->numBags < MAX_BAGS) {
            exitStation->exitBags[exitStation->numBags] = conveyors[i]->conveyorBags[0];
            exitStation->numBags++;
            removeBagFromConveyor(0, conveyors[i]);
        }
    }
}

// Remove a bag from an entry station or exit station
void removeBagFromStation(Baggage *station, int *numBags) {
    for (int i = 0; i < *numBags; i++) {
        station[i] = station[i+1];
    }
    (*numBags)--;
}

// Remove a bag from a conveyor
void removeBagFromConveyor(int bagIndex, Conveyor *conveyor) {
    for (int i = bagIndex; i < conveyor->numBags; i++) {
        conveyor->conveyorBags[i] = conveyor->conveyorBags[i+1];
    }
    conveyor->numBags--;
}

// Print a report showing the number of bags at each station and their total weight
void printReport(EntryStation **entryStations, Conveyor **conveyors, ExitStation **exitStations, int numEntryStations, int numConveyors, int numExitStations) {
    int entryStationWeight = 0;
    int conveyorWeight = 0;
    int exitStationWeight = 0;
    printf("==============================================\n");
    for (int i = 0; i < numEntryStations; i++) {
        printf("Entry Station %d: %d bags\n", entryStations[i]->id, entryStations[i]->numBags);
        for (int j = 0; j < entryStations[i]->numBags; j++) {
            entryStationWeight += entryStations[i]->station[j].weight;
        }
    }
    printf("Total weight of bags in Entry Stations: %d kgs\n", entryStationWeight);
    printf("----------------------------------------------\n");
    for (int i = 0; i < numConveyors; i++) {
        printf("Conveyor %d: %d bags\n", conveyors[i]->id, conveyors[i]->numBags);
        for (int j = 0; j < conveyors[i]->numBags; j++) {
            conveyorWeight += conveyors[i]->conveyorBags[j];
        }
    }
    printf("Total weight of bags on Conveyors: %d kgs\n", conveyorWeight);
    printf("----------------------------------------------\n");
    for (int i = 0; i < numExitStations; i++) {
        printf("Exit Station %d: %d bags\n", exitStations[i]->id, exitStations[i]->numBags);
        for (int j = 0; j < exitStations[i]->numBags; j++) {
            exitStationWeight += exitStations[i]->exitBags[j];
        }
    }
    printf("Total weight of bags in Exit Stations: %d kgs\n", exitStationWeight);
    printf("==============================================\n");
}