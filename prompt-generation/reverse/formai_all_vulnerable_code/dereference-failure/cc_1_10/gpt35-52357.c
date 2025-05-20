//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 5
#define MAX_LOADERS 3

// Global variables
int flightCount = 0;
int loadersInUse = 0;
int baggageCount = 0;

// Struct for each flight's information
struct Flight {
    int id;
    char airline[10];
    int baggageCapacity;
    int numBaggage;
    int* baggageIds;
};

// Struct for each piece of baggage's information
struct Baggage {
    int id;
    int flightId;
    char owner[25];
};

// Struct for each loader's information
struct Loader {
    int id;
    int numBaggageLoaded;
};

// Function to add a new flight to the system
void addFlight(struct Flight flights[], char airline[], int baggageCapacity) {
    flightCount++;
    int newId = flightCount;
    flights[newId - 1].id = newId;
    sprintf(flights[newId - 1].airline, "%s", airline);
    flights[newId - 1].baggageCapacity = baggageCapacity;
}

// Function to randomly generate baggage for a flight based on the flight's baggage capacity
void generateBaggage(struct Flight* flight) {
    int numBaggage = rand() % flight->baggageCapacity + 1;
    flight->numBaggage = numBaggage;
    baggageCount += numBaggage;

    int* baggageIds = malloc(sizeof(int) * numBaggage);
    for (int i = 0; i < numBaggage; i++) {
        baggageIds[i] = baggageCount - numBaggage + i + 1;
        struct Baggage newBaggage = {
            .id = baggageIds[i],
            .flightId = flight->id
        };
        sprintf(newBaggage.owner, "Passenger %d", i + 1);
        printf("Baggage %d added to Flight %d\n", newBaggage.id, newBaggage.flightId);
    }
    flight->baggageIds = baggageIds;
}

// Function to randomly select a loader to start loading baggage
int selectLoader(struct Loader loaders[]) {
    int selectedLoader = -1;
    for (int i = 0; i < MAX_LOADERS; i++) {
        if (loaders[i].numBaggageLoaded == 0) {
            selectedLoader = i;
            break;
        }
    }
    if (selectedLoader == -1) {
        printf("All loaders are in use. Please wait for a loader to become available.\n");
    } else {
        printf("Selecting loader %d.\n", selectedLoader + 1);
        loadersInUse++;
    }
    return selectedLoader;
}

// Function for a loader to load baggage onto an aircraft
void loadBaggage(struct Flight* flight, struct Loader* loader) {
    int numBaggageLoaded = rand() % (flight->numBaggage - loader->numBaggageLoaded) + 1;
    printf("Loader %d has loaded %d of %d pieces of baggage for Flight %d.\n", loader->id + 1, numBaggageLoaded, flight->numBaggage - loader->numBaggageLoaded, flight->id);
    loader->numBaggageLoaded += numBaggageLoaded;
}

int main() {
    struct Flight flights[MAX_FLIGHTS];
    struct Loader loaders[MAX_LOADERS];
    srand(time(0)); // Seed random generator

    // Add flights to the system with their respective baggage capacities
    addFlight(flights, "Delta", 50);
    addFlight(flights, "Southwest", 30);
    addFlight(flights, "United", 40);
    addFlight(flights, "American Airlines", 60);
    addFlight(flights, "JetBlue", 35);

    printf("\n");

    // Generate baggage for each flight
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        generateBaggage(&flights[i]);
        printf("\n");
    }

    // Load baggage onto flights using loaders
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        int loaderSelected = selectLoader(loaders);
        if (loaderSelected != -1) {
            loadBaggage(&flights[i], &loaders[loaderSelected]);
        } else {
            i--;
            continue;
        }
        if (i == MAX_FLIGHTS - 1) {
            printf("All flights have been loaded successfully.\n");
        }
        if (loadersInUse == MAX_LOADERS) {
            printf("All loaders are currently in use. Please wait for a loader to become available.\n");
            while (loadersInUse == MAX_LOADERS) {
                continue;
            }
        }
    }

    return 0;
}