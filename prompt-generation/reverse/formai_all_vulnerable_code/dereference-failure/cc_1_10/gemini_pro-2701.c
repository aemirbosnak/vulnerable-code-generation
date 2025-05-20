//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a room in the haunted house
typedef struct room {
    char *description;  // Description of the room
    int num_doors;     // Number of doors in the room
    int *doors;        // Array of door indices
} room;

// Structure to represent a door in the haunted house
typedef struct door {
    int room1;     // Index of the first room connected by the door
    int room2;     // Index of the second room connected by the door
    int locked;    // Boolean indicating whether the door is locked
} door;

// Function to initialize the haunted house
void initialize_haunted_house(room **rooms, door **doors, int num_rooms, int num_doors) {
    // Allocate memory for the rooms
    *rooms = malloc(sizeof(room) * num_rooms);

    // Allocate memory for the doors
    *doors = malloc(sizeof(door) * num_doors);

    // Initialize the rooms
    for (int i = 0; i < num_rooms; i++) {
        (*rooms)[i].description = malloc(100);
        sprintf((*rooms)[i].description, "Room %d", i);
        (*rooms)[i].num_doors = rand() % 4 + 1;
        (*rooms)[i].doors = malloc(sizeof(int) * (*rooms)[i].num_doors);

        // Initialize the doors
        for (int j = 0; j < (*rooms)[i].num_doors; j++) {
            (*doors)[i*num_doors + j].room1 = i;
            (*doors)[i*num_doors + j].room2 = rand() % num_rooms;
            (*doors)[i*num_doors + j].locked = rand() % 2;
        }
    }
}

// Function to print the haunted house
void print_haunted_house(room *rooms, door *doors, int num_rooms, int num_doors) {
    // Print the rooms
    for (int i = 0; i < num_rooms; i++) {
        printf("Room %d:\n", i);
        printf("\tDescription: %s\n", rooms[i].description);
        printf("\tNumber of doors: %d\n", rooms[i].num_doors);

        // Print the doors
        for (int j = 0; j < rooms[i].num_doors; j++) {
            printf("\tDoor %d:\n", j);
            printf("\t\tRoom 1: %d\n", doors[i*num_doors + j].room1);
            printf("\t\tRoom 2: %d\n", doors[i*num_doors + j].room2);
            printf("\t\tLocked: %d\n", doors[i*num_doors + j].locked);
        }
    }
}

// Function to simulate the player exploring the haunted house
void simulate_player(room *rooms, door *doors, int num_rooms, int num_doors) {
    // Initialize the player's position
    int current_room = 0;

    // Loop until the player has explored all the rooms
    while (current_room != -1) {
        // Print the current room
        printf("\nYou are in %s.\n", rooms[current_room].description);

        // Print the available doors
        printf("There are %d doors available:\n", rooms[current_room].num_doors);
        for (int i = 0; i < rooms[current_room].num_doors; i++) {
            printf("\tDoor %d: %s\n", i, rooms[doors[current_room*num_doors + i].room2].description);
        }

        // Get the player's input
        int choice;
        printf("Which door do you want to go through? (-1 to quit): ");
        scanf("%d", &choice);

        // Check if the player wants to quit
        if (choice == -1) {
            current_room = -1;
            continue;
        }

        // Check if the door is locked
        if (doors[current_room*num_doors + choice].locked) {
            printf("The door is locked.\n");
            continue;
        }

        // Move the player to the next room
        current_room = doors[current_room*num_doors + choice].room2;
    }

    // Print a message to indicate that the player has explored all the rooms
    printf("\nYou have explored all the rooms in the haunted house.\n");
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Initialize the haunted house
    room *rooms;
    door *doors;
    int num_rooms = 10;
    int num_doors = 20;
    initialize_haunted_house(&rooms, &doors, num_rooms, num_doors);

    // Print the haunted house
    print_haunted_house(rooms, doors, num_rooms, num_doors);

    // Simulate the player exploring the haunted house
    simulate_player(rooms, doors, num_rooms, num_doors);

    // Free the allocated memory
    for (int i = 0; i < num_rooms; i++) {
        free(rooms[i].description);
        free(rooms[i].doors);
    }
    free(rooms);
    free(doors);

    return 0;
}