//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateHauntedHouse(int numRooms, int numDoors, int numWindows, int numDecorations) {
    int room[numRooms][2]; // Array to store room information (1 for empty, 0 for occupied)
    int door[numDoors]; // Array to store door locations
    int window[numWindows]; // Array to store window locations
    int decoration[numDecorations]; // Array to store decoration locations

    // Randomly generate door and window locations
    for (int i = 0; i < numDoors; i++) {
        door[i] = rand() % numRooms; // Randomly select a room number
    }
    for (int i = 0; i < numWindows; i++) {
        window[i] = rand() % numRooms; // Randomly select a room number
    }

    // Randomly generate decoration locations
    for (int i = 0; i < numDecorations; i++) {
        decoration[i] = rand() % numRooms; // Randomly select a room number
    }

    // Populate room array with empty or occupied status based on random number generator
    for (int i = 0; i < numRooms; i++) {
        int numOccupied = rand() % 10;
        if (numOccupied == 0) { // No occupants in this room
            room[i][0] = 1; // Room is empty
        } else { // Random number of occupants in this room
            for (int j = 1; j < numOccupied; j++) {
                int numDecorations = rand() % numDecorations; // Random number of decorations
                decoration[numDecorations] = i; // Place decoration in this room
                room[i][0] = 0; // Room is occupied
            }
        }
    }

    // Print out the haunted house information
    printf("Haunted House Simulator\n");
    printf("----------------------\n");
    printf("Number of Rooms: %d\n", numRooms);
    printf("Number of Doors: %d\n", numDoors);
    printf("Number of Windows: %d\n", numWindows);
    printf("Number of Decorations: %d\n\n", numDecorations);

    printf("Rooms:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d:\n", i + 1);
        printf("Empty = 1, Occupied = 0\n");
        printf("Room %d contains %d door(s) and %d window(s):\n", i + 1, door[i], window[i]);
        printf("Door(s):\n");
        for (int j = 0; j < door[i]; j++) {
            printf("%d\n", j + 1);
        }
        printf("Window(s):\n");
        for (int j = 0; j < window[i]; j++) {
            printf("%d\n", j + 1);
        }
        printf("Decorations:\n");
        for (int j = 0; j < decoration[i]; j++) {
            printf("%d\n", j + 1);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int numRooms = 10;
    int numDoors = 5;
    int numWindows = 3;
    int numDecorations = 7;

    generateHauntedHouse(numRooms, numDoors, numWindows, numDecorations);

    return 0;
}