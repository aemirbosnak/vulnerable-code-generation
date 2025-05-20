//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the maximum number of exits per room
#define MAX_EXITS 3

// Define the data structure for a room
typedef struct room {
    int number;          // The room number
    int num_exits;       // The number of exits from the room
    int exits[MAX_EXITS]; // The exit numbers
} room;

// Define the data structure for the haunted house
typedef struct haunted_house {
    int num_rooms;   // The number of rooms in the house
    room rooms[MAX_ROOMS]; // The array of rooms
} haunted_house;

// Create a new haunted house
haunted_house* create_haunted_house() {
    // Allocate memory for the haunted house
    haunted_house* house = (haunted_house*)malloc(sizeof(haunted_house));

    // Set the number of rooms in the house
    house->num_rooms = rand() % MAX_ROOMS + 1;

    // Create each room in the house
    for (int i = 0; i < house->num_rooms; i++) {
        // Set the room number
        house->rooms[i].number = i + 1;

        // Set the number of exits from the room
        house->rooms[i].num_exits = rand() % MAX_EXITS + 1;

        // Create each exit from the room
        for (int j = 0; j < house->rooms[i].num_exits; j++) {
            // Set the exit number
            house->rooms[i].exits[j] = rand() % house->num_rooms + 1;
        }
    }

    // Return the haunted house
    return house;
}

// Print the haunted house
void print_haunted_house(haunted_house* house) {
    // Print the number of rooms in the house
    printf("The haunted house has %d rooms.\n", house->num_rooms);

    // Print each room in the house
    for (int i = 0; i < house->num_rooms; i++) {
        // Print the room number
        printf("Room %d:\n", house->rooms[i].number);

        // Print the number of exits from the room
        printf("  Number of exits: %d\n", house->rooms[i].num_exits);

        // Print each exit from the room
        for (int j = 0; j < house->rooms[i].num_exits; j++) {
            printf("  Exit %d: %d\n", j + 1, house->rooms[i].exits[j]);
        }
    }
}

// Free the memory allocated for the haunted house
void free_haunted_house(haunted_house* house) {
    // Free the memory allocated for the rooms
    free(house->rooms);

    // Free the memory allocated for the haunted house
    free(house);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new haunted house
    haunted_house* house = create_haunted_house();

    // Print the haunted house
    print_haunted_house(house);

    // Free the memory allocated for the haunted house
    free_haunted_house(house);

    return 0;
}