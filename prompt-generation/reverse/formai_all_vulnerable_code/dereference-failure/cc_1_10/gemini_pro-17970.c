//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a room in the haunted house
typedef struct room {
    int num_doors;  // Number of doors in the room
    int *doors;    // Array of door indices
    int has_ghost; // Boolean indicating whether the room has a ghost
} room;

// Structure to represent the haunted house
typedef struct haunted_house {
    int num_rooms; // Number of rooms in the house
    room *rooms;   // Array of rooms
} haunted_house;

// Function to create a haunted house with a given number of rooms
haunted_house *create_haunted_house(int num_rooms) {
    // Allocate memory for the haunted house
    haunted_house *house = malloc(sizeof(haunted_house));
    house->num_rooms = num_rooms;

    // Allocate memory for the array of rooms
    house->rooms = malloc(sizeof(room) * num_rooms);

    // Initialize each room
    for (int i = 0; i < num_rooms; i++) {
        // Generate a random number of doors for the room
        house->rooms[i].num_doors = rand() % 4 + 1;

        // Allocate memory for the array of doors
        house->rooms[i].doors = malloc(sizeof(int) * house->rooms[i].num_doors);

        // Initialize each door to -1 (indicating that it is not connected to any other room)
        for (int j = 0; j < house->rooms[i].num_doors; j++) {
            house->rooms[i].doors[j] = -1;
        }

        // Randomly select a door to be the entrance to the room
        int entrance = rand() % house->rooms[i].num_doors;
        house->rooms[i].doors[entrance] = 0;

        // Randomly select a door to be the exit from the room
        int exit = rand() % house->rooms[i].num_doors;
        while (exit == entrance) {
            exit = rand() % house->rooms[i].num_doors;
        }
        house->rooms[i].doors[exit] = num_rooms + 1;

        // Randomly decide whether the room has a ghost
        house->rooms[i].has_ghost = rand() % 2;
    }

    // Return the haunted house
    return house;
}

// Function to print the haunted house
void print_haunted_house(haunted_house *house) {
    // Print the number of rooms in the house
    printf("The haunted house has %d rooms.\n", house->num_rooms);

    // Print each room
    for (int i = 0; i < house->num_rooms; i++) {
        // Print the room number
        printf("Room %d:\n", i + 1);

        // Print the number of doors in the room
        printf("  Number of doors: %d\n", house->rooms[i].num_doors);

        // Print the doors in the room
        printf("  Doors: ");
        for (int j = 0; j < house->rooms[i].num_doors; j++) {
            printf("%d ", house->rooms[i].doors[j]);
        }
        printf("\n");

        // Print whether the room has a ghost
        if (house->rooms[i].has_ghost) {
            printf("  Has ghost: yes\n");
        } else {
            printf("  Has ghost: no\n");
        }
    }
}

// Function to free the memory allocated for the haunted house
void free_haunted_house(haunted_house *house) {
    // Free the memory allocated for each room
    for (int i = 0; i < house->num_rooms; i++) {
        free(house->rooms[i].doors);
    }

    // Free the memory allocated for the array of rooms
    free(house->rooms);

    // Free the memory allocated for the haunted house
    free(house);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a haunted house with 10 rooms
    haunted_house *house = create_haunted_house(10);

    // Print the haunted house
    print_haunted_house(house);

    // Free the memory allocated for the haunted house
    free_haunted_house(house);

    return 0;
}