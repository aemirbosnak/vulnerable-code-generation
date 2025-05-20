//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms and the maximum number of doors per room
#define MAX_ROOMS 10
#define MAX_DOORS_PER_ROOM 3

// Define the structure of a room
typedef struct Room {
    int number;  // The room number
    int num_doors;  // The number of doors in the room
    int doors[MAX_DOORS_PER_ROOM];  // The doors in the room
} Room;

// Define the structure of the haunted house
typedef struct HauntedHouse {
    int num_rooms;  // The number of rooms in the house
    Room rooms[MAX_ROOMS];  // The rooms in the house
} HauntedHouse;

// Create a new haunted house
HauntedHouse *create_haunted_house() {
    // Allocate memory for the haunted house
    HauntedHouse *house = (HauntedHouse *)malloc(sizeof(HauntedHouse));

    // Set the number of rooms in the house
    house->num_rooms = rand() % MAX_ROOMS + 1;

    // Create the rooms in the house
    for (int i = 0; i < house->num_rooms; i++) {
        // Set the room number
        house->rooms[i].number = i + 1;

        // Set the number of doors in the room
        house->rooms[i].num_doors = rand() % MAX_DOORS_PER_ROOM + 1;

        // Create the doors in the room
        for (int j = 0; j < house->rooms[i].num_doors; j++) {
            // Set the door number
            house->rooms[i].doors[j] = rand() % house->num_rooms + 1;
        }
    }

    // Return the haunted house
    return house;
}

// Destroy a haunted house
void destroy_haunted_house(HauntedHouse *house) {
    // Free the memory for the haunted house
    free(house);
}

// Print a haunted house
void print_haunted_house(HauntedHouse *house) {
    // Print the number of rooms in the house
    printf("The haunted house has %d rooms.\n", house->num_rooms);

    // Print the rooms in the house
    for (int i = 0; i < house->num_rooms; i++) {
        // Print the room number
        printf("Room %d has %d doors:\n", house->rooms[i].number, house->rooms[i].num_doors);

        // Print the doors in the room
        for (int j = 0; j < house->rooms[i].num_doors; j++) {
            printf("  Door %d leads to room %d.\n", j + 1, house->rooms[i].doors[j]);
        }
    }
}

// Simulate a haunted house
void simulate_haunted_house(HauntedHouse *house) {
    // Get the current room
    int current_room = 1;

    // Loop until the player reaches the last room
    while (current_room != house->num_rooms) {
        // Print the current room
        printf("You are in room %d.\n", current_room);

        // Get the doors in the current room
        int *doors = house->rooms[current_room - 1].doors;

        // Get the number of doors in the current room
        int num_doors = house->rooms[current_room - 1].num_doors;

        // Print the doors in the current room
        printf("There are %d doors in this room:\n", num_doors);
        for (int i = 0; i < num_doors; i++) {
            printf("  Door %d leads to room %d.\n", i + 1, doors[i]);
        }

        // Get the player's choice of door
        int choice;
        printf("Which door do you want to go through? ");
        scanf("%d", &choice);

        // Check if the player's choice is valid
        if (choice < 1 || choice > num_doors) {
            printf("Invalid choice. Please choose a door between 1 and %d.\n", num_doors);
        } else {
            // Update the current room
            current_room = doors[choice - 1];
        }
    }

    // Print the last room
    printf("You have reached the last room.\n");
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Create a haunted house
    HauntedHouse *house = create_haunted_house();

    // Print the haunted house
    print_haunted_house(house);

    // Simulate the haunted house
    simulate_haunted_house(house);

    // Destroy the haunted house
    destroy_haunted_house(house);

    return 0;
}