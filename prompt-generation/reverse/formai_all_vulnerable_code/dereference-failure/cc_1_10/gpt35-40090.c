//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10

// Structs to store information about flights and bags
typedef struct flight {
    char name[10];
    bool available;
} Flight;

typedef struct bag {
    char tag[10];
    char destination[10];
    int weight;
    bool loaded;
} Bag;

// Function to randomly generate a flight name
char* generateFlightName() {
    char* name = malloc(sizeof(char) * 10);
    const char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    name[0] = letters[rand() % 26];
    name[1] = letters[rand() % 26];
    name[2] = rand() % 10 + '0';
    name[3] = rand() % 10 + '0';
    name[4] = rand() % 10 + '0';
    name[5] = '\0';
    return name;
}

int main() {
    // Initialize flights
    Flight flights[MAX_FLIGHTS];
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        strcpy(flights[i].name, generateFlightName());
        flights[i].available = true;
    }

    // Initialize bags
    Bag bags[MAX_BAGS];
    int numBags = 0;

    // Randomly generate bags and assign them to flights
    srand(time(NULL));
    for (int i = 0; i < MAX_BAGS; i++) {
        Bag bag;
        sprintf(bag.tag, "B%03d", i);
        strcpy(bag.destination, flights[rand() % MAX_FLIGHTS].name);
        bag.weight = rand() % 20 + 10;
        bag.loaded = false;

        bags[numBags++] = bag;
    }

    // Simulate baggage loading process for each flight
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Loading baggage for flight %s...\n", flights[i].name);

        // Check if flight is available and has bags assigned to it
        if (flights[i].available) {
            int numLoadedBags = 0;

            // Load bags onto the flight
            for (int j = 0; j < numBags; j++) {
                Bag bag = bags[j];

                // Check if bag is assigned to the current flight and hasn't been loaded yet
                if (strcmp(bag.destination, flights[i].name) == 0 && !bag.loaded) {
                    printf("Loading bag %s onto flight %s...\n", bag.tag, flights[i].name);
                    bag.loaded = true;
                    bags[j] = bag;
                    numLoadedBags++;
                }
            }

            // Update flight availability and display load statistics
            flights[i].available = false;
            printf("Loaded %d bags onto flight %s.\n", numLoadedBags, flights[i].name);
            printf("Baggage loading complete for flight %s.\n", flights[i].name);
        } else {
            printf("Unable to load baggage for flight %s as it is not available.\n", flights[i].name);
        }
    }

    // Display bags that were not loaded onto any flight
    printf("Bags not loaded onto any flight:\n");
    for (int i = 0; i < numBags; i++) {
        Bag bag = bags[i];
        if (!bag.loaded) {
            printf("%s\n", bag.tag);
        }
    }

    return 0;
}